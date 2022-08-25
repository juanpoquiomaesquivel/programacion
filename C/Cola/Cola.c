#include "Cola.h"
#include <stdio.h>
#include <stdlib.h>

#ifdef FLUSH
#ifndef FLUSH_FUNCTION
#define FLUSH_FUNCTION
void flush()
{
    if (!feof(stdin) && !ferror(stdin))
        while (getchar() != '\n')
            ;
}
#endif
#endif

#ifdef ERROR_MEMORY
#ifndef ERROR_MEMORY_FUNCTION
#define ERROR_MEMORY_FUNCTION
void error(void *ptr)
{
    if (ptr == NULL)
    {
        perror(NO_MEMORY);
        exit(EXIT_FAILURE);
    }
}
#endif
#endif

Nodo *nodo(T dato)
{
    Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));

    if (nuevo == NULL)
    {
        perror(NO_MEMORY);
        exit(EXIT_FAILURE);
    }

    nuevo->dato = dato;
    nuevo->siguiente = NULL;

    return nuevo;
}

void encolar(Nodo **cabeza, T dato)
{
    Nodo *nuevo = nodo(dato);

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
    Nodo *p = *cabeza;

    while (p != NULL)
    {
        *cabeza = (*cabeza)->siguiente;
        free(p->dato);
        free(p);
        p = *cabeza;
    }
}

void mostrar(Nodo *cabeza)
{
    Nodo *p = cabeza;

    while (p != NULL)
    {
        printf("%d ", *(E *)(p->dato));
        p = p->siguiente;
    }

    puts("");
}

bool estaVacia(Nodo *cabeza)
{
    return cabeza == NULL;
}