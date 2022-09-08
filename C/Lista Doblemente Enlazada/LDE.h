#ifndef _LDE_H_
#define _LDE_H_

#include "Libreria.h"

typedef void *T;
typedef int E;
typedef struct nodo
{
    T dato;
    struct nodo *anterior;
    struct nodo *siguiente;
} Nodo;

Nodo *nodo(T dato);
void insertarAlInicio(Nodo **cabeza, T dato);
void insertarAlFinal(Nodo **cabeza, T dato);
void insertarAntesDe(Nodo **cabeza, T dato, T x);
void insertarDespuesDe(Nodo **cabeza, T dato, T x);
void reemplazarEn(Nodo *cabeza, T dato, T x);
void eliminarElPrimero(Nodo **cabeza);
void eliminarElUltimo(Nodo **cabeza);
void eliminarAntesDe(Nodo **cabeza, T x);
void eliminarDespuesDe(Nodo **cabeza, T x);
void eliminarEn(Nodo **cabeza, T x);
T obtenerElPrimero(Nodo *cabeza);
T obtenerElUltimo(Nodo *cabeza);
T obtenerAntesDe(Nodo *cabeza, T x);
T obtenerDespuesDe(Nodo *cabeza, T x);
T obtenerEn(Nodo *cabeza, int posicion);
int buscar(Nodo *cabeza, T x);
void borrar(Nodo **cabeza);
void mostrar(Nodo *cabeza);
bool estaVacia(Nodo *cabeza);

#endif