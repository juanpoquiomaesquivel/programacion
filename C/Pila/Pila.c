#include "Pila.h"
#include "Libreria.h"
#include <stdio.h>
#include <stdlib.h>

Nodo *nuevoNodo(T dato)
{
    Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));
    memory_error(nuevo);
    nuevo->dato = dato;
    nuevo->abajo = NULL;

    return nuevo;
}

void empilar(Nodo **tope, T dato)
{
    Nodo *nuevo = nuevoNodo(dato);

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
    if (!estaVacia(*tope))
    {
        Nodo *p;

        do
        {
            p = *tope;
            *tope = (*tope)->abajo;
            free(p->dato);
            free(p);
        } while (*tope != NULL);
    }
}

void mostrar(Nodo *tope)
{
    printf("PILA => { ");

    if (!estaVacia(tope))
    {
        Nodo *p = tope;

        do
        {
            printf("%d -> ", *(E *)(p->dato));
            p = p->abajo;
        } while (p != NULL);
    }

    puts(" }");
}

bool estaVacia(Nodo *tope)
{
    return tope == NULL;
}