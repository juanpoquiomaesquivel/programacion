#include "Ordenamiento.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int *crearVector(int n)
{
    int *vector = (int *)malloc(n * sizeof(int));

    if (vector == NULL)
    {
        perror("[SISTEMA] :- <Memoria insuficiente> ");
        exit(EXIT_FAILURE);
    }

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

void mostrar(int *vector, int n)
{
    printf("vector[] = {");

    for (int i = 0; i < n; i++)
        printf("<%d> : %d, ", i, vector[i]);

    puts("}");
}

int *burbuja(int *vector, int n)
{
    int *auxVector = (int *)malloc(n * sizeof(int));
    memcpy(auxVector, vector, n * sizeof(int));
    int aux;

    for (int i = 1; i < n; i++)
        for (int j = n - 1; j >= i; j--)
            if (auxVector[j - 1] > auxVector[j])
            {
                aux = auxVector[j - 1];
                auxVector[j - 1] = auxVector[j];
                auxVector[j] = aux;
            }

    return auxVector;
}

int *insercionDirecta(int *vector, int n)
{
    int *auxVector = (int *)malloc(n * sizeof(int));
    memcpy(auxVector, vector, n * sizeof(int));
    int aux, k;

    for (int i = 0; i < n; i++)
    {
        aux = auxVector[i];
        k = i - 1;

        while (k >= 0 && aux < auxVector[k])
        {
            auxVector[k + 1] = auxVector[k];
            k--;
        }

        auxVector[k + 1] = aux;
    }

    return auxVector;
}

int *seleccionDirecta(int *vector, int n)
{
    int *auxVector = (int *)malloc(n * sizeof(int));
    memcpy(auxVector, vector, n * sizeof(int));
    int menor, k;

    for (int i = 0; i < n - 1; i++)
    {
        menor = auxVector[i];
        k = i;

        for (int j = i + 1; j < n; j++)
            if (auxVector[j] < menor)
            {
                menor = auxVector[j];
                k = j;
            }

        auxVector[k] = auxVector[i];
        auxVector[i] = menor;
    }

    return auxVector;
}

int *shell(int *vector, int n)
{
    int *auxVector = (int *)malloc(n * sizeof(int));
    memcpy(auxVector, vector, n * sizeof(int));
    int razon = n + 1;
    bool band;

    while (razon > 1)
    {
        razon = razon / 2;
        band = true;

        while (band)
        {
            int i = 0, aux;
            band = false;

            while (i + razon <= n - 1)
            {
                if (auxVector[i] > auxVector[i + razon])
                {
                    aux = auxVector[i];
                    auxVector[i] = auxVector[i + razon];
                    auxVector[i + razon] = aux;
                    band = true;
                }

                i++;
            }
        }
    }

    return auxVector;
}