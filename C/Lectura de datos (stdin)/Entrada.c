#include "Entrada.h"
#include "Libreria.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *lectura(const char *formato)
{
    void *ptr;

    if (strcmp(formato, "%s"))
    {
        if (!strcmp(formato, "%d"))
            ptr = (int *)malloc(sizeof(int));
        else if (!strcmp(formato, "%lf"))
            ptr = (double *)malloc(sizeof(double));
        else if (!strcmp(formato, "%f"))
            ptr = (float *)malloc(sizeof(float));
        else if (!strcmp(formato, "%c"))
            ptr = (char *)malloc(sizeof(char));
        else if (!strcmp(formato, "%hd"))
            ptr = (short int *)malloc(sizeof(short int));

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
            else if (!strcmp(formato, "%lf"))
            {
                if (!(x = scanf(formato, (double *)ptr)))
                    puts("[SISTEMA] :- <Ingrese valor 'double'>");
            }
            else if (!strcmp(formato, "%f"))
            {
                if (!(x = scanf(formato, (float *)ptr)))
                    puts("[SISTEMA] :- <Ingrese valor 'float'>");
            }
            else if (!strcmp(formato, "%c"))
            {
                if (!(x = scanf(formato, (char *)ptr)))
                    puts("[SISTEMA] :- <Ingrese valor 'char'>");
            }
            else if (!strcmp(formato, "%hd"))
            {
                if (!(x = scanf(formato, (short int *)ptr)))
                    puts("[SISTEMA] :- <Ingrese valor 'short int'>");
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