#ifndef _LSE_H_
#define _LSE_H_

typedef void *T;
typedef int E;

struct Nodo
{
    T dato;
    struct Nodo *siguiente;
};

struct Nodo *nodo(T dato);
void insertarAlInicio(struct Nodo **cabeza, T dato);
void insertarAlFinal(struct Nodo **cabeza, T dato);
void insertarAntesDe(struct Nodo **cabeza, T dato, T x);
void insertarDespuesDe(struct Nodo **cabeza, T dato, T x);
void reemplazarEn(struct Nodo *cabeza, T dato, T x);
void eliminarElPrimero(struct Nodo **cabeza);
void eliminarElUltimo(struct Nodo **cabeza);
void eliminarAntesDe(struct Nodo **cabeza, T x);
void eliminarDespuesDe(struct Nodo **cabeza, T x);
void eliminarEn(struct Nodo **cabeza, T x);
T obtenerElPrimero(struct Nodo *cabeza);
T obtenerElUltimo(struct Nodo *cabeza);
T obtenerAntesDe(struct Nodo *cabeza, T x);
T obtenerDespuesDe(struct Nodo *cabeza, T x);
T obtenerEn(struct Nodo *cabeza, int posicion);
int buscar(struct Nodo *cabeza, T x);
void borrar(struct Nodo **cabeza);
void mostrar(struct Nodo *cabeza);
int estaVacia(struct Nodo *cabeza);

#endif