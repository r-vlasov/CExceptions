# Try-Throw-Catch
Custom Try-Throw-Catch implementation written in C by _setjmp_ and _longjmp_ mechanisms

## Usage

These exceptions uses C library functions setjmp and longjmp to operate. It can support real-time system (like embedded). It supports to handling ( multi-level try-catch-throw, _see exception.c_);

__Handling:__
'''

    void Example(void*) {
        // make _cexception *a* variable
        // TODO smth, set problem
        if (problem)
            throw(*a*);
    }
'''

## Limitations

This library ( _'exception.h'_ ) uses dynamic structure LinkedList ( implement in _'exceptlist.h'_ )

* Don't use directly  **return**  and **goto** from Try-Catch block (it may result to memory leaks)
* Memory allocated by **malloc** (and his relatives) don't automatically free when an error is thrown (programmer is responsible for clearing the memory)

## Intefrace

* **const cexception exc = ex_****create()** - create exception type variable exc (using before try-catch block
* **try { /* TODO SMTH */  }** - try block
* **throw ( exception )** - throw the exception *exception* from try block. *Exception* should be defined before *try block*
* **catch ( exception ) { /* TODO SMTH */ }** - catch the exception thrown from try block (*by throw(exception*)
* **default_****catch (char *string )** - catch exceptions which are not implemented in previous catch-blocks. It prints line *string*. Should be define after *try-catch blocks*

