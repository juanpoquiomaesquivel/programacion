#include "Libreria.h"
#include <stdio.h>
#include <stdlib.h>

#ifdef FLUSH_BUFFER
void flush()
{
    if (!feof(stdin) && !ferror(stdin))
        while (getchar() != '\n')
            ;
}
#endif

#ifdef ERROR_MEMORY
void error(void *ptr)
{
    if (ptr == NULL)
    {
        perror(NO_MEMORY);
        exit(EXIT_FAILURE);
    }
}
#endif