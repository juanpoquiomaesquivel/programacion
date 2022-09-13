#include "LCDE.h"
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

    if (estaVacia(*cabeza))
    {
        *cabeza = nuevo;
        (*cabeza)->anterior = *cabeza;
        (*cabeza)->siguiente = *cabeza;
    }
    else
    {
        Nodo *p = (*cabeza)->anterior;
        nuevo->anterior = p;
        nuevo->siguiente = *cabeza;
        (*cabeza)->anterior = nuevo;
        *cabeza = nuevo;
        p->siguiente = *cabeza;
    }
}

void insertarAlFinal(Nodo **cabeza, T dato)
{
    Nodo *nuevo = nuevoNodo(dato);

    if (estaVacia(*cabeza))
    {
        *cabeza = nuevo;
        (*cabeza)->anterior = *cabeza;
        (*cabeza)->siguiente = *cabeza;
    }
    else
    {
        Nodo *p = (*cabeza)->anterior;
        (*cabeza)->anterior = nuevo;
        p->siguiente = nuevo;
        nuevo->anterior = p;
        nuevo->siguiente = *cabeza;
    }
}

void insertarAntesDe(Nodo **cabeza, T dato, T x)
{
    if (!estaVacia(*cabeza))
    {
        Nodo *p = *cabeza;

        while (p->siguiente != *cabeza && *(E *)(p->dato) != *(E *)(x))
            p = p->siguiente;

        if (*(E *)(p->dato) == *(E *)(x))
        {
            Nodo *nuevo = nuevoNodo(dato);

            if (p == *cabeza)
            {
                Nodo *q = (*cabeza)->anterior;
                nuevo->anterior = q;
                nuevo->siguiente = *cabeza;
                (*cabeza)->anterior = nuevo;
                *cabeza = nuevo;
                q->siguiente = *cabeza;
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

        while (p->siguiente != *cabeza && *(E *)(p->dato) != *(E *)(x))
            p = p->siguiente;

        if (*(E *)(p->dato) == *(E *)(x))
        {
            Nodo *nuevo = nuevoNodo(dato);

            if (p->siguiente == *cabeza)
            {
                p->siguiente = nuevo;
                nuevo->anterior = p;
                nuevo->siguiente = *cabeza;
                (*cabeza)->anterior = nuevo;
            }
            else
            {
                nuevo->anterior = p;
                nuevo->siguiente = p->siguiente;
                p->siguiente->anterior = nuevo;
                p->siguiente = nuevo;
            }
        }
    }
}

void reemplazarEn(Nodo *cabeza, T dato, T x)
{
    if (!estaVacia(cabeza))
    {
        Nodo *p = cabeza;

        while (p->siguiente != cabeza && *(E *)(p->dato) != *(E *)(x))
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

        if ((*cabeza)->siguiente == *cabeza)
            *cabeza = NULL;
        else
        {
            Nodo *q = (*cabeza)->anterior;
            *cabeza = (*cabeza)->siguiente;
            (*cabeza)->anterior = q;
            q->siguiente = *cabeza;
        }

        free(p->dato);
        free(p);
    }
}

void eliminarElUltimo(Nodo **cabeza)
{
    if (!estaVacia(*cabeza))
    {
        Nodo *p = (*cabeza)->anterior;

        if (p == *cabeza)
            *cabeza = NULL;
        else
        {
            (*cabeza)->anterior = p->anterior;
            p->anterior->siguiente = *cabeza;
        }

        free(p->dato);
        free(p);
    }
}

void eliminarAntesDe(Nodo **cabeza, T x)
{
    if (!estaVacia(*cabeza))
    {
        Nodo *p = *cabeza;

        while (p->siguiente != *cabeza && *(E *)(p->dato) != *(E *)(x))
            p = p->siguiente;

        if (*(E *)(p->dato) == *(E *)(x))
        {
            if (p == *cabeza)
            {
                if (p->siguiente == *cabeza)
                {
                    *cabeza = NULL;
                    free(p->dato);
                    free(p);
                }
                else
                {
                    Nodo *q = (*cabeza)->anterior;
                    q->anterior->siguiente = *cabeza;
                    (*cabeza)->anterior = q->anterior;
                    free(q->dato);
                    free(q);
                }
            }
            else
            {
                Nodo *_p = p->anterior;

                if (_p == *cabeza)
                {
                    Nodo *q = (*cabeza)->anterior;
                    *cabeza = (*cabeza)->siguiente;
                    (*cabeza)->anterior = q;
                    q->siguiente = *cabeza;
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
}

void eliminarDespuesDe(Nodo **cabeza, T x)
{
    if (!estaVacia(*cabeza))
    {
        Nodo *p = *cabeza;

        while (p->siguiente != *cabeza && *(E *)(p->dato) != *(E *)(x))
            p = p->siguiente;

        if (*(E *)(p->dato) == *(E *)(x))
        {
            Nodo *p_ = p->siguiente;

            if (p->siguiente == *cabeza)
            {
                if (p == *cabeza)
                {
                    *cabeza = NULL;
                    free(p->dato);
                    free(p);
                }
                else
                {
                    *cabeza = (*cabeza)->siguiente;
                    (*cabeza)->anterior = p;
                    p->siguiente = *cabeza;
                    free(p_->dato);
                    free(p_);
                }
            }
            else
            {
                p->siguiente = p_->siguiente;
                p_->siguiente->anterior = p;
                free(p_->dato);
                free(p_);
            }
        }
    }
}

void eliminarEn(Nodo **cabeza, T x)
{
    if (!estaVacia(*cabeza))
    {
        Nodo *p = *cabeza;

        while (p->siguiente != *cabeza && *(E *)(p->dato) != *(E *)(x))
            p = p->siguiente;

        if (*(E *)(p->dato) == *(E *)(x))
        {
            if (p == *cabeza)
            {
                if (p->siguiente == *cabeza)
                    *cabeza = NULL;
                else
                {
                    Nodo *q = (*cabeza)->anterior;
                    *cabeza = (*cabeza)->siguiente;
                    (*cabeza)->anterior = q;
                    q->siguiente = *cabeza;
                }
            }
            else
            {
                p->anterior->siguiente = p->siguiente;
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
        return cabeza->anterior->dato;

    return NULL;
}

T obtenerAntesDe(Nodo *cabeza, T x)
{
    if (!estaVacia(cabeza))
    {
        Nodo *p = cabeza;

        while (p->siguiente != cabeza && *(E *)(p->dato) != *(E *)(x))
            p = p->siguiente;

        if (*(E *)(p->dato) == *(E *)(x))
            return p->anterior->dato;
    }

    return NULL;
}

T obtenerDespuesDe(Nodo *cabeza, T x)
{
    if (!estaVacia(cabeza))
    {
        Nodo *p = cabeza;

        while (p->siguiente != cabeza && *(E *)(p->dato) != *(E *)(x))
            p = p->siguiente;

        if (*(E *)(p->dato) == *(E *)(x))
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

        while (p->siguiente != cabeza && i != posicion)
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

        while (p->siguiente != cabeza && *(E *)(p->dato) != *(E *)(x))
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
    if (!estaVacia(*cabeza))
    {
        Nodo *p = *cabeza;
        Nodo *q = (*cabeza)->anterior;
        q->siguiente = NULL;

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
    if (!estaVacia(cabeza))
    {
        Nodo *p = cabeza;

        do
        {
            printf("%d ", *(int *)(p->dato));
            p = p->siguiente;
        } while (p != cabeza);

        puts("");
    }
}

bool estaVacia(Nodo *cabeza)
{
    return cabeza == NULL;
}