#ifndef _PILA_H_
#define _PILA_H_

typedef void *T;

struct Nodo
{
    T dato;
    struct Nodo *abajo;
};

struct Nodo *nodo(T dato);
void empilar(struct Nodo **tope, T dato);
void depilar(struct Nodo **tope);
T cima(struct Nodo *tope);
void borrar(struct Nodo **tope);
void mostrar(struct Nodo *tope);
int estaVacia(struct Nodo *tope);

#endif