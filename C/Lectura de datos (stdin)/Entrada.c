#include "Entrada.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef FLUSH
#ifndef FLUSH_FUNCTION
#define FLUSH_FUNCTION
void flush()
{
    if (!feof(stdin) && !ferror(stdin))
        while (getchar() != '\n')
            ;
}
#endif
#endif

#ifdef ERROR_MEMORY
#ifndef ERROR_MEMORY_FUNCTION
#define ERROR_MEMORY_FUNCTION
void error(void *ptr)
{
    if (ptr == NULL)
    {
        perror(NO_MEMORY);
        exit(EXIT_FAILURE);
    }
}
#endif
#endif

void leerInteger(int **var)
{
    int x;
    int *ptr = (int *)malloc(sizeof(int));
    error(ptr);
    lectura(ptr, "%d");
    *var = ptr;
}

void leerDouble(double **var)
{
    int x;
    double *ptr = (double *)malloc(sizeof(double));
    error(ptr);
    lectura(ptr, "%lf");
    *var = ptr;
}

void leerFloat(float **var)
{
    int x;
    float *ptr = (float *)malloc(sizeof(float));
    error(ptr);
    lectura(ptr, "%f");
    *var = ptr;
}

void leerString(char **var)
{
    printf(">> ");
    char buffer[LEN_STR_INPUT];
    fgets(buffer, LEN_STR_INPUT, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
    *var = strdup(buffer);
}

void leerChar(char **var)
{
    int x;
    char *ptr = (char *)malloc(sizeof(char));
    error(ptr);
    lectura(ptr, "%c");
    *var = ptr;
}

void lectura(void *ptr, const char *formato)
{
    int x = -1;

    do
    {
        printf(">> ");

        if (strcmp(formato, "%d") == 0)
        {
            if ((x = scanf(formato, (int *)ptr)) == 0)
                puts("[SISTEMA] :- <Ingrese valor 'int'>");
        }
        else if (strcmp(formato, "%lf") == 0)
        {
            if ((x = scanf(formato, (double *)ptr)) == 0)
                puts("[SISTEMA] :- <Ingrese valor 'double'>");
        }
        else if (strcmp(formato, "%f") == 0)
        {
            if ((x = scanf(formato, (float *)ptr)) == 0)
                puts("[SISTEMA] :- <Ingrese valor 'float'>");
        }
        else if (strcmp(formato, "%c") == 0)
        {
            if ((x = scanf(formato, (char *)ptr)) == 0)
                puts("[SISTEMA] :- <Ingrese valor 'char'>");
        }

        flush();
    } while (x == 0);
}