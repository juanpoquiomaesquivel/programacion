#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Entrada.h"
#include "Libreria.h"

enum
{
    SALIR,
    INTEGER,
    FLOAT,
    DOUBLE,
    STRING,
    CHAR,
};

const char lista[][100] = {"Salir",
                           "Leer 'int'",
                           "Leer 'float'",
                           "Leer 'double'",
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
    const size_t n = sizeof(lista) / sizeof(lista[0]);
    short int *opcion = NULL;
    void *variable = NULL;

    while (true)
    {
        system("cls");
        puts("\n\t\t.: LECTURA DE DATOS (stdin) :.\n");

        for (size_t i = 0; i < n; i++)
            printf("[%d] : %s\n", i, lista[i]);

        puts("");
        opcion = (short int *)leerEntrada("%hd");

        switch (*opcion)
        {
        case SALIR:
            free(opcion);
            puts(MS_PROGRAMA_FINALIZADO);

            return;
        case INTEGER:
            variable = leerEntrada("%d");
            printf("El valor 'int' es: %d\n", *(int *)variable);
            break;
        case FLOAT:
            variable = leerEntrada("%f");
            printf("El valor 'float' es: %f\n", *(float *)variable);
            break;
        case DOUBLE:
            variable = leerEntrada("%lf");
            printf("El valor 'double' es: %lf\n", *(double *)variable);
            break;
        case STRING:
            variable = leerEntrada("%s");
            printf("El valor 'string' es: %s\n", (char *)variable);
            break;
        case CHAR:
            variable = leerEntrada("%c");
            printf("El valor 'char' es: %c\n", *(char *)variable);
            break;
        default:
            puts(MS_OPCION_INCORRECTA);
        }

        free(variable);
        variable = NULL;
        free(opcion);
        opcion = NULL;
        puts(MS_OPCION_CONTINUAR);
        limpiarBuffer();
    }
}
