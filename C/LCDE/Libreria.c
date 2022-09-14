#include "Libreria.h"
#include <stdio.h>
#include <stdlib.h>

#ifdef FLUSH_BUFFER
#ifndef FUNCTION_FLUSH_BUFFER
#define FUNCTION_FLUSH_BUFFER
void flush_buffer()
{
    if (!feof(stdin) && !ferror(stdin))
        while (getchar() != '\n')
            ;
}
#endif
#endif

#ifdef MEMORY_ERROR
#ifndef FUNCTION_MEMORY_ERROR
#define FUNCTION_MEMORY_ERROR
void memory_error(void *ptr)
{
    if (ptr == NULL)
    {
        perror(NO_MEMORY);
        exit(EXIT_FAILURE);
    }
}
#endif
#endif