#include <stdio.h>
#include <stdlib.h>
#include "Arreglo.h"
#include "Entrada.h"
#include "Libreria.h"
#include "Ordenamiento.h"

enum
{
    SALIR,
    BURBUJA,
    INSERCION_DIRECTA,
    SELECCION_DIRECTA,
    SHELL,
    QUICK_SORT,
    HEAP_SORT,
    MERGE_SORT
};

const char lista[][100] = {"Salir",
                           "Burbuja",
                           "Insercion Directa",
                           "Seleccion Directa",
                           "Shell",
                           "Quick Sort",
                           "Heap Sort",
                           "Merge Sort"};

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
    const unsigned int N = 10;
    int *vector = crearVector(N), *auxVector = NULL;

    while (true)
    {
        system("cls");
        puts("\n\t\t.: ALGORITMOS DE ORDENAMIENTO :.\n");

        for (int i = 0; i < n; i++)
            printf("[%d] : %s\n", i, lista[i]);

        puts("");
        opcion = lectura("%hd");

        switch (*opcion)
        {
        case SALIR:
            liberarVector(&vector);
            free(opcion);
            puts(EXIT_OPTION);

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
        case QUICK_SORT:
            auxVector = quickSort(vector, N);
            break;
        case HEAP_SORT:
            auxVector = heapSort(vector, N);
            break;
        case MERGE_SORT:
            auxVector = mergeSort(vector, N);
            break;
        default:
            puts(NO_OPTION);
        }

        mostrarVector(vector, N);
        mostrarVector(auxVector, N);
        liberarVector(&auxVector);
        free(opcion);
        opcion = NULL;
        puts(CONTINUE_OPTION);
        flush_buffer();
    }
}