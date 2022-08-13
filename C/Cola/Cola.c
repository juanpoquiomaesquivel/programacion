#include "Cola.h"
#include <stdio.h>
#include <stdlib.h>

struct Nodo *nodo(T dato)
{
    struct Nodo *nuevo = (struct Nodo *)malloc(sizeof(struct Nodo));

    if (nuevo == NULL)
    {
        free(nuevo);
        exit(EXIT_FAILURE);
    }

    nuevo->dato = dato;
    nuevo->siguiente = NULL;

    return nuevo;
}

void encolar(struct Nodo **cabeza, T dato)
{
    struct Nodo *nuevo = nodo(dato);

    if (estaVacia(*cabeza))
        *cabeza = nuevo;
    else
    {
        struct Nodo *p = *cabeza;

        while (p->siguiente != NULL)
            p = p->siguiente;

        p->siguiente = nuevo;
    }
}

void decolar(struct Nodo **cabeza)
{
    if (!estaVacia(*cabeza))
    {
        struct Nodo *p = *cabeza;
        *cabeza = (*cabeza)->siguiente;
        free(p->dato);
        free(p);
    }
}

T frente(struct Nodo *cabeza)
{
    if (!estaVacia(cabeza))
        return cabeza->dato;
    else
        return NULL;
}

T ultimo(struct Nodo *cabeza)
{
    if (!estaVacia(cabeza))
    {
        struct Nodo *p = cabeza;

        while (p->siguiente != NULL)
            p = p->siguiente;

        return p->dato;
    }
    else
        return NULL;
}

void borrar(struct Nodo **cabeza)
{
    struct Nodo *p = *cabeza;

    while (p != NULL)
    {
        *cabeza = (*cabeza)->siguiente;
        free(p->dato);
        free(p);
        p = *cabeza;
    }
}

void mostrar(struct Nodo *cabeza)
{
    struct Nodo *p = cabeza;

    while (p != NULL)
    {
        printf("%d ", *(int *)(p->dato));
        p = p->siguiente;
    }

    puts("");
}

int estaVacia(struct Nodo *cabeza)
{
    return cabeza == NULL;
}