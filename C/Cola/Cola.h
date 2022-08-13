#ifndef _COLA_H_
#define _COLA_H_

typedef void *T;

struct Nodo
{
    T dato;
    struct Nodo *siguiente;
};

struct Nodo *nodo(T dato);
void encolar(struct Nodo **cabeza, T dato);
void decolar(struct Nodo **cabeza);
T frente(struct Nodo *cabeza);
T ultimo(struct Nodo *cabeza);
void borrar(struct Nodo **cabeza);
void mostrar(struct Nodo *cabeza);
int estaVacia(struct Nodo *cabeza);

#endif