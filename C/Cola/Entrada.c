#include "Entrada.h"
#include "Libreria.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef LEER_ENTRADA
#ifndef FUNCION_LEER_ENTRADA
#define FUNCION_LEER_ENTRADA
T leerEntrada(const char *formato)
{
    T ptr;

    if (strcmp(formato, "%s"))
    {
        if (!strcmp(formato, "%d"))
            ptr = malloc(sizeof(int));
        else if (!strcmp(formato, "%hd"))
            ptr = malloc(sizeof(short int));
        else if (!strcmp(formato, "%ld"))
            ptr = malloc(sizeof(long int));
        else if (!strcmp(formato, "%f"))
            ptr = malloc(sizeof(float));
        else if (!strcmp(formato, "%lf"))
            ptr = malloc(sizeof(double));
        else if (!strcmp(formato, "%Lf"))
            ptr = malloc(sizeof(long double));
        else if (!strcmp(formato, "%c"))
            ptr = malloc(sizeof(char));

        errorDeMemoria(ptr);
        int x = -1;

        do
        {
            printf(">> ");

            if (!strcmp(formato, "%d"))
            {
                if (!(x = scanf(formato, (int *)ptr)))
                    puts(MS_INGRESE_INT);
            }
            else if (!strcmp(formato, "%hd"))
            {
                if (!(x = scanf(formato, (short int *)ptr)))
                    puts(MS_INGRESE_SHORT_INT);
            }
            else if (!strcmp(formato, "%ld"))
            {
                if (!(x = scanf(formato, (long int *)ptr)))
                    puts(MS_INGRESE_LONG_INT);
            }
            else if (!strcmp(formato, "%f"))
            {
                if (!(x = scanf(formato, (float *)ptr)))
                    puts(MS_INGRESE_FLOAT);
            }
            else if (!strcmp(formato, "%lf"))
            {
                if (!(x = scanf(formato, (double *)ptr)))
                    puts(MS_INGRESE_DOUBLE);
            }
            else if (!strcmp(formato, "%Lf"))
            {
                if (!(x = scanf(formato, (long double *)ptr)))
                    puts(MS_INGRESE_LONG_DOUBLE);
            }
            else if (!strcmp(formato, "%c"))
                x = scanf(formato, (char *)ptr);

            limpiarBuffer();
        } while (!x);
    }
    else
    {
        printf(">> ");
        char buffer[LONGITUD_DE_ENTRADA_STRING];
        fgets(buffer, LONGITUD_DE_ENTRADA_STRING, stdin);
        buffer[strcspn(buffer, "\n")] = '\0';
        ptr = strdup(buffer);
        errorDeMemoria(ptr);
    }

    return ptr;
}
#endif
#endif