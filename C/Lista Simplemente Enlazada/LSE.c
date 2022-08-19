#include "LSE.h"
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
    nuevo->siguiente = NULL;

    return nuevo;
}

void insertarAlInicio(Nodo **cabeza, T dato)
{
    Nodo *nuevo = nodo(dato);

    if (!estaVacia(*cabeza))
        nuevo->siguiente = *cabeza;

    *cabeza = nuevo;
}

void insertarAlFinal(Nodo **cabeza, T dato)
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

void insertarAntesDe(Nodo **cabeza, T dato, T x)
{
    if (!estaVacia(*cabeza))
    {
        Nodo *p = *cabeza;
        Nodo *_p = NULL;

        while (p->siguiente != NULL && *(E *)(p->dato) != *(E *)x)
        {
            _p = p;
            p = p->siguiente;
        }

        if (*(E *)(p->dato) == *(E *)x)
        {
            Nodo *nuevo = nodo(dato);
            nuevo->siguiente = p;

            if (p == *cabeza)
                *cabeza = nuevo;
            else
                _p->siguiente = nuevo;
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
            Nodo *nuevo = nodo(dato);

            if (p->siguiente != NULL)
                nuevo->siguiente = p->siguiente;

            p->siguiente = nuevo;
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
        free(p->dato);
        free(p);
    }
}

void eliminarElUltimo(Nodo **cabeza)
{
    if (!estaVacia(*cabeza))
    {
        Nodo *p = *cabeza;
        Nodo *_p = NULL;

        while (p->siguiente != NULL)
        {
            _p = p;
            p = p->siguiente;
        }

        if (p == *cabeza)
            *cabeza = NULL;
        else
            _p->siguiente = NULL;

        free(p->dato);
        free(p);
    }
}

void eliminarAntesDe(Nodo **cabeza, T x)
{
    if (!estaVacia(*cabeza))
    {
        Nodo *p = *cabeza;
        Nodo *_p = NULL;
        Nodo *__p = NULL;

        while (p->siguiente != NULL && *(E *)(p->dato) != *(E *)(x))
        {
            __p = _p;
            _p = p;
            p = p->siguiente;
        }

        if (*(E *)(p->dato) == *(E *)(x))
            if (p != *cabeza)
            {
                if (_p == *cabeza)
                    *cabeza = p;
                else
                    __p->siguiente = p;

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
        Nodo *_p = NULL;

        while (p->siguiente != NULL && *(E *)(p->dato) != *(E *)(x))
        {
            _p = p;
            p = p->siguiente;
        }

        if (*(E *)(p->dato) == *(E *)(x))
        {
            if (p == *cabeza)
                *cabeza = (*cabeza)->siguiente;
            else
                _p->siguiente = p->siguiente;

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
        Nodo *_p = NULL;

        while (p->siguiente != NULL && *(E *)(p->dato) != *(E *)(x))
        {
            _p = p;
            p = p->siguiente;
        }

        if (*(E *)(p->dato) == *(E *)(x))
            if (p != cabeza)
                return _p->dato;
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