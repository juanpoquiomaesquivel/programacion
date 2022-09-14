#include "Arreglo.h"
#include "Libreria.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *crearVector(const unsigned int n)
{
    int *vector = (int *)malloc(n * sizeof(int));
    memory_error(vector);
    srand(time(NULL));
    int M = 1, N = 100;

    for (int i = 0; i < n; i++)
        vector[i] = rand() % (N - M + 1) + M;

    return vector;
}

void liberarVector(int **vector)
{
    if (*vector != NULL)
    {
        free(*vector);
        *vector = NULL;
    }
}

void mostrarVector(int *vector, const unsigned int n)
{
    printf("VECTOR => [ ");

    if (vector != NULL)
    {

        for (int i = 0; i < n; i++)
            printf("<%d> : %d, ", i, vector[i]);
    }

    puts(" ]");
}

int **crearMatriz(const unsigned int filas, const unsigned int columnas)
{
    int **matriz = (int **)malloc(filas * sizeof(int *));
    memory_error(matriz);

    for (int i = 0; i < columnas; i++)
    {
        matriz[i] = (int *)malloc(columnas * sizeof(int));
        memory_error(matriz[i]);
    }

    srand(time(NULL));
    int M = 1, N = 100;

    for (int i = 0; i < filas; i++)
        for (int j = 0; j < columnas; j++)
            matriz[i][j] = rand() % (N - M + 1) + M;

    return matriz;
}

void liberarMatriz(int ***matriz, const unsigned int filas)
{
    if (*matriz != NULL)
    {
        for (int i = 0; i < filas; i++)
            free((*matriz)[i]);

        free(*matriz);
        *matriz = NULL;
    }
}

void mostrarMatriz(int **matriz, const unsigned int filas, const unsigned int columnas)
{
    printf("MATRIZ => [ ");

    if (matriz != NULL)
    {

        for (int i = 0; i < filas; i++)
        {
            printf("[ ");

            for (int j = 0; j < columnas; j++)
                printf("<%d, %d> : %d, ", i, j, matriz[i][j]);

            printf(" ], ");
        }
    }

    puts(" ]");
}