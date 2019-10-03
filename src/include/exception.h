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
                        if (!res) { list_add(&current);  } \
                        if (!res) 

#define catch(exc)   else if (res == exc) \

#define default_catch   else  {\
                        fprintf(stderr, "Default exception handler!"); \
                        list_remove();   \
                        if (jmp_list->head) \
                            memcpy(&current, jmp_list->head->data, sizeof(jmp_buf)); \
                        ex_quan = old_quan; \
                        }

#define throw(exc)   longjmp(current, exc)


typedef int _cexception;

const _cexception ex_init() {
    const _cexception res = ++ex_quan;
    return res;
}


#endif 
