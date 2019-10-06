# Try-Throw-Catch
Custom Try-Throw-Catch implementation written in C by 'setjmp' and 'longjmp' mechanisms

## Usage

These exceptions uses C library functions setjmp and longjmp to operate. It can support real-time system (like embedded)

'Handling:'
'''bash 
    void Example(void*) {
        // make _cexception *a* variable
        // TODO smth, set problem
        if (problem)
            throw(*a*);
    }
'''


