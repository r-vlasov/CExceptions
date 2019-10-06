#include <stdio.h>
#include "include/exception.h"

int main()
{
  //  exception_init();
    const _cexception ex1 = ex_create();
    const _cexception ex2 = ex_create();
    const _cexception ex6 = ex_create();
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
            default_throw;
        }
        catch(ext1){
            fprintf(stderr, "1\n");
        }
        catch(ext2){
            fprintf(stderr, "2\n");
        }
        catch(ext3){
            fprintf(stderr, "%d\n", ext3);
            
        }
        default_catch("MYFIRST");

        fprintf(stderr, "Hello\n");
        fprintf(stderr, "%d\n", ex2);
        throw(ex6);
    }
    catch(ex1){
        fprintf(stderr, "1\n");
    }
    catch(ex2){
        fprintf(stderr, "2\n");
    }
    catch(ex6){
        fprintf(stderr, "6\n");
    }
    catch(ex4){
        fprintf(stderr, "4\n");
    }
    default_catch("MYBAD");
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
