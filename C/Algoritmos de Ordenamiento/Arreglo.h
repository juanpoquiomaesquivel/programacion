#ifndef _ARREGLO_H_
#define _ARREGLO_H_

int *crearVector(const unsigned int n);
void liberarVector(int **vector);
void mostrarVector(int *vector, const unsigned int n);
int **crearMatriz(const unsigned int filas, const unsigned int columnas);
void liberarMatriz(int ***matriz, const unsigned int filas);
void mostrarMatriz(int **matriz, const unsigned int filas, const unsigned int columnas);

#endif