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
    Nodo *pila = NULL;
    int n = sizeof(lista) / sizeof(lista[0]), opcion = SALIR;
    E *dato = NULL;

    while (true)
    {
        puts("\n\t\t.: PILA :.\n");

        for (int i = 0; i < n; i++)
            printf("[%d] : %s\n", i, lista[i]);

        printf("\n>> ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case SALIR:
            borrar(&pila);
            puts("[SISTEMA] :- <Programa terminado>");
            return;
        case EMPILAR:
            printf(">> ");
            dato = (E *)malloc(sizeof(E));
            scanf("%d", dato);
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
            puts("[SISTEMA] :- <Opcion incorrecta>");
        }
    }
}