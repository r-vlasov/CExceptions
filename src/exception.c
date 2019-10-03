#include <stdio.h>
#include "include/exception.h"

int main()
{
    exception_init();
    const _cexception ex1 = ex_create();
    const _cexception ex2 = ex_create();
    const _cexception ex3 = ex_create();
    const _cexception ex4 = ex_create();

    try 
    {
        fprintf(stderr, "start\n");

        const _cexception ext1 = ex_create();
        const _cexception ext2 = ex_create();
        const _cexception ext3 = ex_create();
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
            fprintf(stderr, "%d\n", ext3);
      //      end_handling;
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

/*
int main() {

    int num1;
    int num2;
    int var = 2;
    exception_init();
    while(var--)
    {
        scanf("%d %d", &num1, &num2);
 
        fprintf(stderr,"num1 + num2 = %d\n", num1 + num2);
        fprintf(stderr,"num1 / num2 = ");
 
        try //код, который может привести к ошибке, располагается тут
        {  
            if (num2 == 0)
            {
                throw(1); //генерировать целое число 123
            }
            fprintf(stderr, "%d\n", num1 / num2);   
        }
        catch(1)
        {
            fprintf(stderr, "Ошибка №%d - на 0 делить нельзя!!!!", 1);
        }
        default_catch;
 
        fprintf(stderr, "num1 - num2 = %d",num1 - num2);
    };;
}
*/