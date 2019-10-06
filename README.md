# Try-Throw-Catch
Custom Try-Throw-Catch implementation written in C by 'setjmp' and 'longjmp' mechanisms

## Usage

These exceptions uses C library functions setjmp and longjmp to operate. It can support real-time system (like embedded). It supports to handling ( multi-level try-catch-throw, _/see exception.c);

_'Handling:'

'''bash 

    void Example(void*) {
        // make _cexception *a* variable
        // TODO smth, set problem
        if (problem)
            throw(*a*);
    }

'''

## Limitations

This library ( _'exception.h'_ ) uses dynamic structure LinkedList ( implement in _'exceptlist.h' )

* Don't use directly [ return ] and [goto] from [ Try-Catch ] block (it may result to memory leaks)
* Memory allocated by [ malloc ] (and his relatives) don't automatically free when an error is thrown (programmer is responsible for clearing the memory)

## Intefrace

*  [ const cexception exc ] - create exception type variable exc (using before try-catch block
* 

