#include "Pila.h"
#include <stdio.h>
#include <stdlib.h>

enum
{
    SALIR,
    EMPILAR,
    DEPILAR,
    CIMA,
    BORRAR,
    MOSTRAR
};

void menu();

int main(int argc, char const *argv[])
{
    menu();

    return EXIT_SUCCESS;
}

void menu()
{
    struct Nodo *pila = NULL;
    int opcion = SALIR, *dato = NULL;
    char lista[][100] = {"Salir",
                         "Empilar",
                         "Depilar",
                         "Cima",
                         "Borrar",
                         "Mostrar"};

    while (1)
    {
        puts("\n\t\t.: PILA :.\n");

        for (int i = 0; i < 6; i++)
            printf("[%d] : %s\n", i, lista[i]);

        printf("\n>> ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case SALIR:
            puts("[SISTEMA] :- <Programa terminado>");
            return;
        case EMPILAR:
            printf(">> ");
            dato = (int *)malloc(sizeof(int));
            scanf("%d", dato);
            empilar(&pila, dato);
            dato = NULL;
            break;
        case DEPILAR:
            depilar(&pila);
            break;
        case CIMA:
            if (cima(pila) != NULL)
                printf("%d\n", *(int *)(cima(pila)));
            break;
        case BORRAR:
            borrar(&pila);
            break;
        case MOSTRAR:
            mostrar(pila);
            break;
        default:
            puts("[SISTEMA] :- <Opcion incorrecta>");
        }
    }
}