#include "Ordenamiento.h"
#include <stdio.h>
#include <stdlib.h>

enum
{
    SALIR,
    BURBUJA,
    INSERCION_DIRECTA,
    SELECCION_DIRECTA,
    SHELL,
    BORRAR,
    MOSTRAR
};

const char lista[][100] = {"Salir",
                           "Burbuja",
                           "Insercion Directa",
                           "Seleccion Directa",
                           "Shell",
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
    int N = 5;
    int *vector = crearVector(N), *auxVector = NULL;
    int n = sizeof(lista) / sizeof(lista[0]), opcion = SALIR;

    while (true)
    {
        puts("\n\t\t.: ALGORITMOS DE ORDENAMIENTO :.\n");

        for (int i = 0; i < n; i++)
            printf("[%d] : %s\n", i, lista[i]);

        printf("\n>> ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case SALIR:
            liberarVector(&vector);
            puts("[SISTEMA] :- <Programa terminado>");
            return;
        case BURBUJA:
            auxVector = burbuja(vector, N);
            break;
        case INSERCION_DIRECTA:
            auxVector = insercionDirecta(vector, N);
            break;
        case SELECCION_DIRECTA:
            auxVector = seleccionDirecta(vector, N);
            break;
        case SHELL:
            auxVector = shell(vector, N);
            break;
        case BORRAR:
            break;
        case MOSTRAR:
            break;
        default:
            puts("[SISTEMA] :- <Opcion incorrecta>");
        }

        mostrar(vector, N);
        mostrar(auxVector, N);
        liberarVector(&auxVector);
    }
}