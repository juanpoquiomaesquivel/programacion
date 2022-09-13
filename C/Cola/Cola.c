#include "Cola.h"
#include "Libreria.h"
#include <stdio.h>
#include <stdlib.h>

Nodo *nuevoNodo(T dato)
{
    Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));
    memory_error(nuevo);
    nuevo->dato = dato;
    nuevo->siguiente = NULL;

    return nuevo;
}

void encolar(Nodo **cabeza, T dato)
{
    Nodo *nuevo = nuevoNodo(dato);

    if (estaVacia(*cabeza))
        *cabeza = nuevo;
    else
    {
        Nodo *p = *cabeza;

        while (p->siguiente != NULL)
            p = p->siguiente;

        p->siguiente = nuevo;
    }
}

void decolar(Nodo **cabeza)
{
    if (!estaVacia(*cabeza))
    {
        Nodo *p = *cabeza;
        *cabeza = (*cabeza)->siguiente;
        free(p->dato);
        free(p);
    }
}

T frente(Nodo *cabeza)
{
    if (!estaVacia(cabeza))
        return cabeza->dato;
    else
        return NULL;
}

T ultimo(Nodo *cabeza)
{
    if (!estaVacia(cabeza))
    {
        Nodo *p = cabeza;

        while (p->siguiente != NULL)
            p = p->siguiente;

        return p->dato;
    }
    else
        return NULL;
}

void borrar(Nodo **cabeza)
{
    if (!estaVacia(*cabeza))
    {
        Nodo *p = *cabeza;

        do
        {
            *cabeza = (*cabeza)->siguiente;
            free(p->dato);
            free(p);
            p = *cabeza;
        } while (p != NULL);
    }
}

void mostrar(Nodo *cabeza)
{
    printf("COLA => { ");

    if (!estaVacia(cabeza))
    {
        Nodo *p = cabeza;

        do
        {
            printf("%d -> ", *(E *)(p->dato));
            p = p->siguiente;
        } while (p != NULL);
    }

    puts(" }");
}

bool estaVacia(Nodo *cabeza)
{
    return cabeza == NULL;
}