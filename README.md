# asprintfa

Combine alloca and asprintf as asprintfa

The asprintfa function uses alloca() to create buffer
from c-stack RAM of exactly the right size and perform a
sprintf into that buffer.

To use this function, first declare a data store.
Then use asprintfa as you would for any sprintf usage
without having to decide how large a buffer to use
to hold the string:

    #include "asprintfa.h"

    int main(void) {
        char *name = NULL;
        char len = 0;
    
        len = asprintfa(&name, "Hello World!\n");
        puts(name);
        
        return 0;
    }

The alloca() function allocates memory space in the stack
frame of the caller.  This temporary space is automatically freed
when the function that called alloca() returns to its caller.
 
The alloca function is a BSD extension.

Special thanks to [Sam](https://blog.sam.liddicott.com/2015/07/marriage-of-alloca-and-asprintf.html) for the details.
