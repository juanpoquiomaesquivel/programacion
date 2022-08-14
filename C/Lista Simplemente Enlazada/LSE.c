#include "LSE.h"
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

void insertarAlInicio(struct Nodo **cabeza, T dato)
{
    struct Nodo *nuevo = nodo(dato);

    if (!estaVacia(*cabeza))
        nuevo->siguiente = *cabeza;

    *cabeza = nuevo;
}

void insertarAlFinal(struct Nodo **cabeza, T dato)
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

void insertarAntesDe(struct Nodo **cabeza, T dato, T x)
{
    if (!estaVacia(*cabeza))
    {
        struct Nodo *p = *cabeza;
        struct Nodo *_p = NULL;

        while (p->siguiente != NULL && *(E *)(p->dato) != *(E *)x)
        {
            _p = p;
            p = p->siguiente;
        }

        if (*(E *)(p->dato) == *(E *)x)
        {
            struct Nodo *nuevo = nodo(dato);
            nuevo->siguiente = p;

            if (p == *cabeza)
                *cabeza = nuevo;
            else
                _p->siguiente = nuevo;
        }
    }
}

void insertarDespuesDe(struct Nodo **cabeza, T dato, T x)
{
    if (!estaVacia(*cabeza))
    {
        struct Nodo *p = *cabeza;

        while (p->siguiente != NULL && *(E *)(p->dato) != *(E *)(x))
            p = p->siguiente;

        if (*(E *)(p->dato) == *(E *)(x))
        {
            struct Nodo *nuevo = nodo(dato);

            if (p->siguiente != NULL)
                nuevo->siguiente = p->siguiente;

            p->siguiente = nuevo;
        }
    }
}

void reemplazarEn(struct Nodo *cabeza, T dato, T x)
{
    if (!estaVacia(cabeza))
    {
        struct Nodo *p = cabeza;

        while (p->siguiente != NULL && *(E *)(p->dato) != *(E *)(x))
            p = p->siguiente;

        if (*(E *)(p->dato) == *(E *)(x))
        {    
            free(p->dato);
            p->dato = dato;
        }
    }
}

void eliminarElPrimero(struct Nodo **cabeza)
{
    if (!estaVacia(*cabeza))
    {
        struct Nodo *p = *cabeza;
        *cabeza = (*cabeza)->siguiente;
        free(p->dato);
        free(p);
    }
}

void eliminarElUltimo(struct Nodo **cabeza)
{
    if (!estaVacia(*cabeza))
    {
        struct Nodo *p = *cabeza;
        struct Nodo *_p = NULL;

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

void eliminarAntesDe(struct Nodo **cabeza, T x)
{
    if (!estaVacia(*cabeza))
    {
        struct Nodo *p = *cabeza;
        struct Nodo *_p = NULL;
        struct Nodo *__p = NULL;

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

void eliminarDespuesDe(struct Nodo **cabeza, T x)
{
    if (!estaVacia(*cabeza))
    {
        struct Nodo *p = *cabeza;

        while (p->siguiente != NULL && *(E *)(p->dato) != *(E *)(x))
            p = p->siguiente;

        if (*(E *)(p->dato) == *(E *)(x))
            if (p->siguiente != NULL)
            {
                struct Nodo *p_ = p->siguiente;
                p->siguiente = p_->siguiente;
                free(p_->dato);
                free(p_);
            }
    }
}

void eliminarEn(struct Nodo **cabeza, T x)
{
    if (!estaVacia(*cabeza))
    {
        struct Nodo *p = *cabeza;
        struct Nodo *_p = NULL;

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

T obtenerElPrimero(struct Nodo *cabeza)
{
    if (!estaVacia(cabeza))
        return cabeza->dato;

    return NULL;
}

T obtenerElUltimo(struct Nodo *cabeza)
{
    if (!estaVacia(cabeza))
    {
        struct Nodo *p = cabeza;

        while (p->siguiente != NULL)
            p = p->siguiente;

        return p->dato;
    }

    return NULL;
}

T obtenerAntesDe(struct Nodo *cabeza, T x)
{
    if (!estaVacia(cabeza))
    {
        struct Nodo *p = cabeza;
        struct Nodo *_p = NULL;

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

T obtenerDespuesDe(struct Nodo *cabeza, T x)
{
    if (!estaVacia(cabeza))
    {
        struct Nodo *p = cabeza;

        while (p->siguiente != NULL && *(E *)(p->dato) != *(E *)(x))
            p = p->siguiente;

        if (*(E *)(p->dato) == *(E *)(x))
            if (p->siguiente != NULL)
                return p->siguiente->dato;
    }

    return NULL;
}

T obtenerEn(struct Nodo *cabeza, int posicion)
{
    if (!estaVacia(cabeza))
    {
        struct Nodo *p = cabeza;
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

int buscar(struct Nodo *cabeza, T x)
{
    if (!estaVacia(cabeza))
    {
        struct Nodo *p = cabeza;
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