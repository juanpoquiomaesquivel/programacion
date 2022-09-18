#include "Libreria.h"
#include <stdio.h>
#include <stdlib.h>

#ifdef ERROR_DE_MEMORIA
#ifndef FUNCION_ERROR_DE_MEMORIA
#define FUNCION_ERROR_DE_MEMORIA
void errorDeMemoria(void *ptr)
{
    if (ptr == NULL)
    {
        perror(MS_INSUFICIENTE_MEMORIA);
        exit(EXIT_FAILURE);
    }
}
#endif
#endif

#ifdef LIMPIAR_BUFFER
#ifndef FUNCION_LIMPIAR_BUFFER
#define FUNCION_LIMPIAR_BUFFER
void limpiarBuffer()
{
    if (!feof(stdin) && !ferror(stdin))
        while (getchar() != '\n')
            ;
}
#endif
#endif