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

#endif