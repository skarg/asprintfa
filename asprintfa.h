/**
 * @file
 * @author Steve Karg
 * @date December 2019
 * @brief Combine alloca and asprintf as asprintfa
 *
 * @section DESCRIPTION
 *
 * The asprintfa function uses alloca() to create buffer 
 * from c-stack RAM of exactly the right size and perform a 
 * sprintf into that buffer.

 * To use this function, first declare a data store:
 * {@code
 * char *name = NULL;
 * char len = 0;
 * }
 *
 * Then use asprintfa as you would for any sprintf usage without having
 * to decide how large a buffer to use to hold the string:
 * {@code
 *     len = asprintfa(&name, "Hello World!\n");
 *     puts(name);
 * }
 *
 * @note The alloca() function allocates memory space in the stack
 * frame of the caller.  This temporary space is automatically freed
 * when the function that called alloca() returns to its caller.
 *
 * @note The alloca function is a BSD extension.
 */
#ifndef _ASPRINTFA_H_
#define _ASPRINTFA_H_
#include <stdio.h>

#if defined(_MSC_VER)
#include <malloc.h>
#ifndef alloca
#define alloca _alloca
#endif
#elif defined(__GNUC__)
#include <alloca.h>
#endif

/**
 * @brief function to use c-stack RAM to create a string within function scope 
 * @param PTR - a pointer to a local character pointer
 * @param ... - vsprintf format specifiers and variable arguments
 * @return Upon successful completion, the sprintf() function shall return 
 *  the number of bytes written to the PTR, excluding the terminating null byte.
 *  If an output error was encountered, these functions shall return a negative value 
 *  and set errno to indicate the error.
 */
#define asprintfa(PTR, ...) \
    sprintf((*(PTR)) = alloca(1 + snprintf(NULL, 0, __VA_ARGS__)), __VA_ARGS__)

#endif
