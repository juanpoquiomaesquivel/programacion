#ifndef _ORDENAMIENTO_H_
#define _ORDENAMIENTO_H_

typedef enum
{
    false,
    true
} bool;

int *crearVector(int n);
void liberarVector(int **vector);
void mostrar(int *vector, int n);
int *burbuja(int *vector, int n);
int *insercionDirecta(int *vector, int n);
int *seleccionDirecta(int *vector, int n);
int *shell(int *vector, int n);
void reduceQuickSort(int *subVector, int inicio, int fin);
int *quickSort(int *vector, int n);
void swap(int *a, int *b);
void heapify(int *subVector, int n, int i);
int *heapSort(int *vector, int n);
void merge(int *subVector, int l, int m, int r);
void mergeSorting(int *subVector, int l, int r);
int *mergeSort(int *vector, int n);

#endif