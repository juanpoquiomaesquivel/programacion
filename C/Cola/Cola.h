#ifndef _COLA_H_
#define _COLA_H_

typedef void *T;
typedef int E;
typedef struct nodo
{
    T dato;
    struct nodo *siguiente;
} Nodo;
typedef enum
{
    false,
    true
} bool;

Nodo *nodo(T dato);
void encolar(Nodo **cabeza, T dato);
void decolar(Nodo **cabeza);
T frente(Nodo *cabeza);
T ultimo(Nodo *cabeza);
void borrar(Nodo **cabeza);
void mostrar(Nodo *cabeza);
bool estaVacia(Nodo *cabeza);

#endif