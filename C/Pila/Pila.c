#include "Pila.h"
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
    nuevo->abajo = NULL;

    return nuevo;
}

void empilar(struct Nodo **tope, T dato)
{
    struct Nodo *nuevo = nodo(dato);

    if (!estaVacia(*tope))
        nuevo->abajo = *tope;

    *tope = nuevo;
}

void depilar(struct Nodo **tope)
{
    if (!estaVacia(*tope))
    {
        struct Nodo *p = *tope;
        *tope = (*tope)->abajo;
        free(p->dato);
        free(p);
    }
}

T cima(struct Nodo *tope)
{
    if (!estaVacia(tope))
        return tope->dato;
    else
        return NULL;
}

void borrar(struct Nodo **tope)
{
    struct Nodo *p = *tope;

    while (p != NULL)
    {
        *tope = (*tope)->abajo;
        free(p->dato);
        free(p);
        p = *tope;
    }
}

void mostrar(struct Nodo *tope)
{
    struct Nodo *p = tope;

    while (p != NULL)
    {
        printf("%d\n", *(int *)(p->dato));
        p = p->abajo;
    }
}

int estaVacia(struct Nodo *tope)
{
    return tope == NULL;
}