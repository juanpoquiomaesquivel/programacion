#include "Pila.h"
#include <stdio.h>
#include <stdlib.h>

Nodo *nodo(T dato)
{
    Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));

    if (nuevo == NULL)
    {
        perror("[SISTEMA] :- <Memoria insuficiente> ");
        exit(EXIT_FAILURE);
    }

    nuevo->dato = dato;
    nuevo->abajo = NULL;

    return nuevo;
}

void empilar(Nodo **tope, T dato)
{
    Nodo *nuevo = nodo(dato);

    if (!estaVacia(*tope))
        nuevo->abajo = *tope;

    *tope = nuevo;
}

void depilar(Nodo **tope)
{
    if (!estaVacia(*tope))
    {
        Nodo *p = *tope;
        *tope = (*tope)->abajo;
        free(p->dato);
        free(p);
    }
}

T cima(Nodo *tope)
{
    if (!estaVacia(tope))
        return tope->dato;
    else
        return NULL;
}

void borrar(Nodo **tope)
{
    Nodo *p = *tope;

    while (p != NULL)
    {
        *tope = (*tope)->abajo;
        free(p->dato);
        free(p);
        p = *tope;
    }
}

void mostrar(Nodo *tope)
{
    Nodo *p = tope;

    while (p != NULL)
    {
        printf("%d\n", *(E *)(p->dato));
        p = p->abajo;
    }
}

bool estaVacia(Nodo *tope)
{
    return tope == NULL;
}