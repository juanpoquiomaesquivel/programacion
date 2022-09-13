#include "LDE.h"
#include "Libreria.h"
#include <stdio.h>
#include <stdlib.h>

Nodo *nuevoNodo(T dato)
{
    Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));

    if (nuevo == NULL)
    {
        perror("[SISTEMA] :- <Memoria insuficiente> ");
        exit(EXIT_FAILURE);
    }

    nuevo->dato = dato;
    nuevo->anterior = NULL;
    nuevo->siguiente = NULL;

    return nuevo;
}

void insertarAlInicio(Nodo **cabeza, T dato)
{
    Nodo *nuevo = nuevoNodo(dato);

    if (!estaVacia(*cabeza))
    {
        nuevo->siguiente = *cabeza;
        (*cabeza)->anterior = nuevo;
    }

    *cabeza = nuevo;
}

void insertarAlFinal(Nodo **cabeza, T dato)
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
        nuevo->anterior = p;
    }
}

void insertarAntesDe(Nodo **cabeza, T dato, T x)
{
    if (!estaVacia(*cabeza))
    {
        Nodo *p = *cabeza;

        while (p->siguiente != NULL && *(E *)(p->dato) != *(E *)x)
            p = p->siguiente;

        if (*(E *)(p->dato) == *(E *)x)
        {
            Nodo *nuevo = nuevoNodo(dato);
            nuevo->siguiente = p;

            if (p == *cabeza)
            {
                nuevo->siguiente = *cabeza;
                (*cabeza)->anterior = nuevo;
                *cabeza = nuevo;
            }
            else
            {
                p->anterior->siguiente = nuevo;
                nuevo->anterior = p->anterior;
                nuevo->siguiente = p;
                p->anterior = nuevo;
            }
        }
    }
}

void insertarDespuesDe(Nodo **cabeza, T dato, T x)
{
    if (!estaVacia(*cabeza))
    {
        Nodo *p = *cabeza;

        while (p->siguiente != NULL && *(E *)(p->dato) != *(E *)(x))
            p = p->siguiente;

        if (*(E *)(p->dato) == *(E *)(x))
        {
            Nodo *nuevo = nuevoNodo(dato);

            if (p->siguiente != NULL)
            {
                nuevo->siguiente = p->siguiente;
                p->siguiente->anterior = nuevo;
            }

            p->siguiente = nuevo;
            nuevo->anterior = p;
        }
    }
}

void reemplazarEn(Nodo *cabeza, T dato, T x)
{
    if (!estaVacia(cabeza))
    {
        Nodo *p = cabeza;

        while (p->siguiente != NULL && *(E *)(p->dato) != *(E *)(x))
            p = p->siguiente;

        if (*(E *)(p->dato) == *(E *)(x))
        {
            free(p->dato);
            p->dato = dato;
        }
    }
}

void eliminarElPrimero(Nodo **cabeza)
{
    if (!estaVacia(*cabeza))
    {
        Nodo *p = *cabeza;
        *cabeza = (*cabeza)->siguiente;

        if (*cabeza != NULL)
            (*cabeza)->anterior = NULL;

        free(p->dato);
        free(p);
    }
}

void eliminarElUltimo(Nodo **cabeza)
{
    if (!estaVacia(*cabeza))
    {
        Nodo *p = *cabeza;

        while (p->siguiente != NULL)
            p = p->siguiente;

        if (p == *cabeza)
            *cabeza = NULL;
        else
            p->anterior->siguiente = NULL;

        free(p->dato);
        free(p);
    }
}

void eliminarAntesDe(Nodo **cabeza, T x)
{
    if (!estaVacia(*cabeza))
    {
        Nodo *p = *cabeza;

        while (p->siguiente != NULL && *(E *)(p->dato) != *(E *)(x))
            p = p->siguiente;

        if (*(E *)(p->dato) == *(E *)(x))
            if (p != *cabeza)
            {
                Nodo *_p = p->anterior;

                if (_p == *cabeza)
                {
                    *cabeza = p;
                    (*cabeza)->anterior = NULL;
                }
                else
                {
                    _p->anterior->siguiente = p;
                    p->anterior = _p->anterior;
                }

                free(_p->dato);
                free(_p);
            }
    }
}

void eliminarDespuesDe(Nodo **cabeza, T x)
{
    if (!estaVacia(*cabeza))
    {
        Nodo *p = *cabeza;

        while (p->siguiente != NULL && *(E *)(p->dato) != *(E *)(x))
            p = p->siguiente;

        if (*(E *)(p->dato) == *(E *)(x))
            if (p->siguiente != NULL)
            {
                Nodo *p_ = p->siguiente;
                p->siguiente = p_->siguiente;

                if (p_->siguiente != NULL)
                    p_->siguiente->anterior = p;

                free(p_->dato);
                free(p_);
            }
    }
}

void eliminarEn(Nodo **cabeza, T x)
{
    if (!estaVacia(*cabeza))
    {
        Nodo *p = *cabeza;

        while (p->siguiente != NULL && *(E *)(p->dato) != *(E *)(x))
            p = p->siguiente;

        if (*(E *)(p->dato) == *(E *)(x))
        {
            if (p == *cabeza)
            {
                *cabeza = (*cabeza)->siguiente;

                if (*cabeza != NULL)
                    (*cabeza)->anterior = NULL;
            }
            else
            {
                p->anterior->siguiente = p->siguiente;

                if (p->siguiente != NULL)
                    p->siguiente->anterior = p->anterior;
            }

            free(p->dato);
            free(p);
        }
    }
}

T obtenerElPrimero(Nodo *cabeza)
{
    if (!estaVacia(cabeza))
        return cabeza->dato;

    return NULL;
}

T obtenerElUltimo(Nodo *cabeza)
{
    if (!estaVacia(cabeza))
    {
        Nodo *p = cabeza;

        while (p->siguiente != NULL)
            p = p->siguiente;

        return p->dato;
    }

    return NULL;
}

T obtenerAntesDe(Nodo *cabeza, T x)
{
    if (!estaVacia(cabeza))
    {
        Nodo *p = cabeza;

        while (p->siguiente != NULL && *(E *)(p->dato) != *(E *)(x))
            p = p->siguiente;

        if (*(E *)(p->dato) == *(E *)(x))
            if (p != cabeza)
                return p->anterior->dato;
    }

    return NULL;
}

T obtenerDespuesDe(Nodo *cabeza, T x)
{
    if (!estaVacia(cabeza))
    {
        Nodo *p = cabeza;

        while (p->siguiente != NULL && *(E *)(p->dato) != *(E *)(x))
            p = p->siguiente;

        if (*(E *)(p->dato) == *(E *)(x))
            if (p->siguiente != NULL)
                return p->siguiente->dato;
    }

    return NULL;
}

T obtenerEn(Nodo *cabeza, int posicion)
{
    if (!estaVacia(cabeza))
    {
        Nodo *p = cabeza;
        int i = 0;

        while (p->siguiente != NULL && i != posicion)
        {
            p = p->siguiente;
            i++;
        }

        if (i == posicion)
            return p->dato;
    }

    return NULL;
}

int buscar(Nodo *cabeza, T x)
{
    if (!estaVacia(cabeza))
    {
        Nodo *p = cabeza;
        int i = 0;

        while (p->siguiente != NULL && *(E *)(p->dato) != *(E *)(x))
        {
            p = p->siguiente;
            i++;
        }

        if (*(E *)(p->dato) == *(E *)(x))
            return i;
    }

    return -1;
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
        printf("%d ", *(int *)(p->dato));
        p = p->siguiente;
    }

    puts("");
}

bool estaVacia(Nodo *cabeza)
{
    return cabeza == NULL;
}