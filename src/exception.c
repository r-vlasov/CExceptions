#include <stdio.h>
#include "include/exception.h"

int main()
{
    jmp_list = list_create();
    const _cexception ex1 = ex_init();
    const _cexception ex2 = ex_init();
    const _cexception ex3 = ex_init();
    const _cexception ex4 = ex_init();

    try 
    {
        fprintf(stderr, "start\n");

        const _cexception ext1 = ex_init();
        const _cexception ext2 = ex_init();
        const _cexception ext3 = ex_init();
        try 
        {
            fprintf(stderr, "start\n");
            throw(ext3);
        }
        catch(ext1){
            fprintf(stderr, "1\n");
        }
        catch(ext2){
            fprintf(stderr, "2\n");
        }
        catch(ext3){
            fprintf(stderr, "3\n");
        }
        default_catch;
        
        throw(ex2);
    }
    catch(ex1){
        fprintf(stderr, "1\n");
    }
    catch(ex2){
        fprintf(stderr, "2\n");
    }
    catch(ex3){
        fprintf(stderr, "3\n");
    }
    catch(ex4){
        fprintf(stderr, "4\n");
    }
    default_catch;
    return 0;
}

