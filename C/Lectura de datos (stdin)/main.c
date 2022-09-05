#include "Entrada.h"
#include "Libreria.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum
{
    SALIR,
    INTEGER,
    DOUBLE,
    FLOAT,
    STRING,
    CHAR,
};

const char lista[][100] = {"Salir",
                           "Leer 'int'",
                           "Leer 'double'",
                           "Leer 'float'",
                           "Leer 'string'",
                           "Leer 'char'"};

void menu();

int main(int argc, char const *argv[])
{
    menu();

    return EXIT_SUCCESS;
}

void menu()
{
    const unsigned int n = sizeof(lista) / sizeof(lista[0]);
    short int *opcion = NULL;
    int *entero = NULL;
    double *real = NULL;
    float *flotante = NULL;
    char *cadena = NULL;
    char *caracter = NULL;

    while (true)
    {
        system("cls");
        puts("\n\t\t.: LECTURA DE DATOS (stdin) :.\n");

        for (int i = 0; i < n; i++)
            printf("[%d] : %s\n", i, lista[i]);

        puts("");
        opcion = lectura("%hd");

        switch (*opcion)
        {
        case SALIR:
            free(opcion);
            puts(EXIT_OPTION);

            return;
        case INTEGER:
            entero = lectura("%d");
            printf(":- El valor 'int' es: %d\n", *entero);
            free(entero);
            entero = NULL;
            break;
        case DOUBLE:
            real = lectura("%lf");
            printf(":- El valor 'double' es: %lf\n", *real);
            free(real);
            real = NULL;
            break;
        case FLOAT:
            flotante = lectura("%f");
            printf(":- El valor 'float' es: %f\n", *flotante);
            free(flotante);
            flotante = NULL;
            break;
        case STRING:
            cadena = lectura("%s");
            printf(":- El valor 'string' es: %s\n", cadena);
            free(cadena);
            cadena = NULL;
            break;
        case CHAR:
            caracter = lectura("%c");
            printf(":- El valor 'char' es: %c\n", *caracter);
            free(caracter);
            caracter = NULL;
            break;
        default:
            puts(NO_OPTION);
        }

        free(opcion);
        opcion = NULL;
        puts(CONTINUE_OPTION);
        flush_buffer();
    }
}
