#include <stdio.h>
#include <stdlib.h>
#include "Entrada.h"
#include "Libreria.h"
#include "Pila.h"

enum
{
    SALIR,
    EMPILAR,
    DEPILAR,
    CIMA,
    BORRAR,
    MOSTRAR
};

const char lista[][100] = {"Salir",
                           "Empilar",
                           "Depilar",
                           "Cima",
                           "Borrar",
                           "Mostrar"};

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
    Nodo *pila = NULL;
    E *dato = NULL;

    while (true)
    {
        system("cls");
        puts("\n\t\t.: PILA :.\n");

        for (int i = 0; i < n; i++)
            printf("[%d] : %s\n", i, lista[i]);

        puts("");
        opcion = lectura("%hd");

        switch (*opcion)
        {
        case SALIR:
            borrar(&pila);
            free(opcion);
            puts(EXIT_OPTION);

            return;
        case EMPILAR:
            dato = lectura("%d");
            empilar(&pila, dato);
            dato = NULL;
            break;
        case DEPILAR:
            depilar(&pila);
            break;
        case CIMA:
            if (cima(pila) != NULL)
                printf("%d\n", *(E *)(cima(pila)));
            break;
        case BORRAR:
            borrar(&pila);
            break;
        case MOSTRAR:
            mostrar(pila);
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