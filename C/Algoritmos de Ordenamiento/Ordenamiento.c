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
    if (vector != NULL)
    {
        printf("vector[] = {");

        for (int i = 0; i < n; i++)
            printf("<%d> : %d, ", i, vector[i]);

        puts("}");
    }
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

void reduceQuickSort(int *subVector, int inicio, int fin)
{
    int izq = inicio, der = fin, pos = inicio;
    bool band = true;

    while (band)
    {
        int aux;
        band = false;

        while (subVector[pos] <= subVector[der] && pos != der)
            der--;

        if (pos != der)
        {
            aux = subVector[pos];
            subVector[pos] = subVector[der];
            subVector[der] = aux;
            pos = der;

            while (subVector[pos] >= subVector[izq] && pos != izq)
                izq++;

            if (pos != izq)
            {
                aux = subVector[pos];
                subVector[pos] = subVector[izq];
                subVector[izq] = aux;
                pos = izq;
                band = true;
            }
        }
    }

    if (pos - 1 > inicio)
        reduceQuickSort(subVector, inicio, pos - 1);

    if (fin > pos + 1)
        reduceQuickSort(subVector, pos + 1, fin);
}

int *quickSort(int *vector, int n)
{
    int *auxVector = (int *)malloc(n * sizeof(int));
    memcpy(auxVector, vector, n * sizeof(int));
    reduceQuickSort(auxVector, 0, n - 1);

    return auxVector;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int *subVector, int n, int i)
{
    // Find largest among root, left child and right child
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && subVector[left] > subVector[largest])
        largest = left;

    if (right < n && subVector[right] > subVector[largest])
        largest = right;

    // Swap and continue heapifying if root is not largest
    if (largest != i)
    {
        swap(&subVector[i], &subVector[largest]);
        heapify(subVector, n, largest);
    }
}

int *heapSort(int *vector, int n)
{
    int *auxVector = (int *)malloc(n * sizeof(int));
    memcpy(auxVector, vector, n * sizeof(int));
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(auxVector, n, i);

    // Heap sort
    for (int i = n - 1; i >= 0; i--)
    {
        swap(&auxVector[0], &auxVector[i]);

        // Heapify root element to get highest element at root again
        heapify(auxVector, i, 0);
    }

    return auxVector;
}

void merge(int *subVector, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = subVector[l + i];

    for (j = 0; j < n2; j++)
        R[j] = subVector[m + 1 + j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            subVector[k] = L[i];
            i++;
        }
        else
        {
            subVector[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
     are any */
    while (i < n1)
    {
        subVector[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
     are any */
    while (j < n2)
    {
        subVector[k] = R[j];
        j++;
        k++;
    }
}

void mergeSorting(int *subVector, int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSorting(subVector, l, m);
        mergeSorting(subVector, m + 1, r);

        merge(subVector, l, m, r);
    }
}

int *mergeSort(int *vector, int n)
{
    int *auxVector = (int *)malloc(n * sizeof(int));
    memcpy(auxVector, vector, n * sizeof(int));
    mergeSorting(auxVector, 0, n - 1);

    return auxVector;
}