#include "Entrada.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef LEN_STR
#define LEN_STR 100
#endif

#ifndef EXIT_OPTION
#define EXIT_OPTION "[SISTEMA] :- <Programa finalizado>"
#endif

#ifndef NO_OPTION
#define NO_OPTION "[SISTEMA] :- <Opcion incorrecta>"
#endif

#ifndef CONTINUE_OPTION
#define CONTINUE_OPTION "[SISTEMA] :- <Presione ENTER para continuar>"
#endif

enum
{
    SALIR,
    INTEGER,
    DOUBLE,
    FLOAT,
    STRING,
    CHAR,
};

const char lista[][LEN_STR] = {"Salir",
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
    short int opcion = SALIR;
    int *var_i = NULL;
    double *var_d = NULL;
    float *var_f = NULL;
    char *var_s = NULL;
    char *var_c = NULL;

    while (true)
    {
        system("cls");
        puts("\n\t\t.: LECTURA DE DATOS (stdin) :.\n");

        for (int i = 0; i < n; i++)
            printf("[%d] : %s\n", i, lista[i]);

        printf("\n>> ");
        scanf("%hd", &opcion);
        flush();

        switch (opcion)
        {
        case SALIR:
            puts(EXIT_OPTION);

            return;
        case INTEGER:
            leerInteger(&var_i);
            printf(":- El valor 'int' es: %d\n", *var_i);
            free(var_i);
            var_i = NULL;
            break;
        case DOUBLE:
            leerDouble(&var_d);
            printf(":- El valor 'double' es: %lf\n", *var_d);
            free(var_d);
            var_d = NULL;
            break;
        case FLOAT:
            leerFloat(&var_f);
            printf(":- El valor 'float' es: %f\n", *var_f);
            free(var_f);
            var_f = NULL;
            break;
        case STRING:
            leerString(&var_s);
            printf(":- El valor 'string' es: %s\n", var_s);
            free(var_s);
            var_s = NULL;
            break;
        case CHAR:
            leerChar(&var_c);
            printf(":- El valor 'char' es: %c\n", *var_c);
            free(var_c);
            var_c = NULL;
            break;
        default:
            puts(NO_OPTION);
        }

        puts(CONTINUE_OPTION);
        flush();
    }
}
