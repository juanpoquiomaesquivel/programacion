#include <stdio.h>
#include <stdlib.h>
#include "Arreglo.h"
#include "Entrada.h"
#include "Libreria.h"

enum
{
    SALIR,
    VECTOR_CREAR,
    VECTOR_LIBERAR,
    VECTOR_MOSTRAR,
    MATRIZ_CREAR,
    MATRIZ_LIBERAR,
    MATRIZ_MOSTRAR
};

const char lista[][100] = {
    "Salir",
    "Crear Vector",
    "Liberar Vector",
    "Mostrar Vector",
    "Crear Matriz",
    "Liberar Matriz",
    "Mostrar Matriz"};

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
    const unsigned int N = 10, filas = 5, columnas = 5;
    int *vector = NULL;
    int **matriz = NULL;

    while (true)
    {
        system("cls");
        puts("\n\t\t.: ARREGLO :.\n");

        for (int i = 0; i < n; i++)
            printf("[%d] : %s\n", i, lista[i]);

        puts("");
        opcion = lectura("%hd");

        switch (*opcion)
        {
        case SALIR:
            liberarVector(&vector);
            liberarMatriz(&matriz, filas);
            free(opcion);
            puts(EXIT_OPTION);

            return;
        case VECTOR_CREAR:
            liberarVector(&vector);
            vector = crearVector(N);
            break;
        case VECTOR_LIBERAR:
            liberarVector(&vector);
        case VECTOR_MOSTRAR:
            mostrarVector(vector, N);
            break;
        case MATRIZ_CREAR:
            liberarMatriz(&matriz, filas);
            matriz = crearMatriz(filas, columnas);
            break;
        case MATRIZ_LIBERAR:
            liberarMatriz(&matriz, filas);
        case MATRIZ_MOSTRAR:
            mostrarMatriz(matriz, filas, columnas);
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