#include "Libreria.h"
#include <stdio.h>
#include <stdlib.h>

#ifdef FLUSH_BUFFER
void flush_buffer()
{
    if (!feof(stdin) && !ferror(stdin))
        while (getchar() != '\n')
            ;
}
#endif

#ifdef MEMORY_ERROR
void memory_error(void *ptr)
{
    if (ptr == NULL)
    {
        perror(NO_MEMORY);
        exit(EXIT_FAILURE);
    }
}
#endif