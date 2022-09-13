#include "Entrada.h"
#include "Libreria.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef LECTURA
#ifndef FUNCTION_LECTURA
#define FUNCTION_LECTURA
void *lectura(const char *formato)
{
    void *ptr;

    if (strcmp(formato, "%s"))
    {
        if (!strcmp(formato, "%d"))
            ptr = (int *)malloc(sizeof(int));
        else if (!strcmp(formato, "%hd"))
            ptr = (short int *)malloc(sizeof(short int));
        else if (!strcmp(formato, "%ld"))
            ptr = (long int *)malloc(sizeof(long int));
        else if (!strcmp(formato, "%f"))
            ptr = (float *)malloc(sizeof(float));
        else if (!strcmp(formato, "%lf"))
            ptr = (double *)malloc(sizeof(double));
        else if (!strcmp(formato, "%Lf"))
            ptr = (long double *)malloc(sizeof(long double));
        else if (!strcmp(formato, "%c"))
            ptr = (char *)malloc(sizeof(char));

        memory_error(ptr);
        int x = -1;

        do
        {
            printf(">> ");

            if (!strcmp(formato, "%d"))
            {
                if (!(x = scanf(formato, (int *)ptr)))
                    puts("[SISTEMA] :- <Ingrese valor 'int'>");
            }
            else if (!strcmp(formato, "%hd"))
            {
                if (!(x = scanf(formato, (short int *)ptr)))
                    puts("[SISTEMA] :- <Ingrese valor 'short int'>");
            }
            else if (!strcmp(formato, "%ld"))
            {
                if (!(x = scanf(formato, (long int *)ptr)))
                    puts("[SISTEMA] :- <Ingrese valor 'long int'>");
            }
            else if (!strcmp(formato, "%f"))
            {
                if (!(x = scanf(formato, (float *)ptr)))
                    puts("[SISTEMA] :- <Ingrese valor 'float'>");
            }
            else if (!strcmp(formato, "%lf"))
            {
                if (!(x = scanf(formato, (double *)ptr)))
                    puts("[SISTEMA] :- <Ingrese valor 'double'>");
            }
            else if (!strcmp(formato, "%Lf"))
            {
                if (!(x = scanf(formato, (long double *)ptr)))
                    puts("[SISTEMA] :- <Ingrese valor 'long double'>");
            }
            else if (!strcmp(formato, "%c"))
            {
                if (!(x = scanf(formato, (char *)ptr)))
                    puts("[SISTEMA] :- <Ingrese valor 'char'>");
            }

            flush_buffer();
        } while (!x);
    }
    else
    {
        printf(">> ");
        char buffer[LEN_STR_INPUT];
        fgets(buffer, LEN_STR_INPUT, stdin);
        buffer[strcspn(buffer, "\n")] = '\0';
        ptr = strdup(buffer);
        memory_error(ptr);
    }

    return ptr;
}
#endif
#endif