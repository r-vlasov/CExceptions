#ifndef __EXCEPTION_H
#define __EXCEPTION_H

#include <setjmp.h>
#include <string.h>
#include "exceptlist.h"

static jmp_buf current;
static int ex_quan = 0;
static int global_init = 0;
#define try \
                        int res = setjmp(current); \
                        int old_quan = ex_quan; \
                        if (!res) { list_add(&current); }\
                        if (!res) 

#define catch(exc)      else if (res == exc)

#define throw(exc)      longjmp(current, exc)

#define default_throw   longjmp(current, ex_quan+1)

#define default_catch(str)   \
                        else  {\
                        fprintf(stderr, str); \
                        }\
                        end_handling; 


#define end_handling    list_remove();   \
                        if (jmp_list->head) \
                            memcpy(&current, jmp_list->head->data, sizeof(jmp_buf)); \
                        ex_quan = old_quan;


// Exception handling interface
typedef int cexception;

static void exception_init() {
    jmp_list = list_create();
}

const cexception ex_create() {
    if (!global_init) {
            exception_init();
            global_init = 1;
    }
    const cexception res = ++ex_quan;
    return res;
}


#endif 
