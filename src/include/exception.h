#ifndef __EXCEPTION_H
#define __EXCEPTION_H
#include <setjmp.h>
#include <string.h>
#include "except_list.h"

static jmp_buf current;
static int ex_quan = 0;

#define try \
                       /* current = malloc(sizeof(jmp_buf)); */\
                        int res = setjmp(current); \
                        int old_quan = ex_quan; \
                        if (!res) { list_add(&current); }\
                        if (!res) 

#define catch(exc)      else if (res == exc) 

#define throw(exc)      longjmp(current, exc)


#define default_catch   else  {\
                        fprintf(stderr, "Default exception handler!"); \
                        end_handling; }


#define end_handling    list_remove();   \
                        if (jmp_list->head) \
                            memcpy(&current, jmp_list->head->data, sizeof(jmp_buf)); \
                        ex_quan = old_quan; 




// Exception handling interface
typedef int _cexception;

const _cexception ex_create() {
    const _cexception res = ++ex_quan;
    return res;
}

void exception_init() {
    jmp_list = list_create();
}



#endif 
