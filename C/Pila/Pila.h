#ifndef _PILA_H_
#define _PILA_H_

typedef void *T;
typedef int E;
typedef struct nodo
{
    T dato;
    struct nodo *abajo;
} Nodo;
typedef enum
{
    false,
    true
} bool;

Nodo *nodo(T dato);
void empilar(Nodo **tope, T dato);
void depilar(Nodo **tope);
T cima(Nodo *tope);
void borrar(Nodo **tope);
void mostrar(Nodo *tope);
bool estaVacia(Nodo *tope);

#endif