#include "LSE.h"
#include "Libreria.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

jxls_Nodo *jxls_crearNodo(void *dato)
{
    jxls_Nodo *nuevo = (jxls_Nodo *)malloc(sizeof(jxls_Nodo));
    errorDeMemoria(nuevo);
    nuevo->dato = dato;
    nuevo->siguiente = NULL;

    return nuevo;
}

void jxls_borrarNodo(jxls_Nodo *nodo, void (*del)(void *p))
{
    del(nodo->dato);
    free(nodo);
}

void jxls_insertarAlInicio(jxls_Nodo **cabeza, void *dato)
{
    jxls_Nodo *nuevo = jxls_crearNodo(dato);

    if (!jxls_estaVacia(*cabeza))
        nuevo->siguiente = *cabeza;

    *cabeza = nuevo;
}

void jxls_insertarAlFinal(jxls_Nodo **cabeza, void *dato)
{
    jxls_Nodo *nuevo = jxls_crearNodo(dato);

    if (jxls_estaVacia(*cabeza))
        *cabeza = nuevo;
    else
    {
        jxls_Nodo *p = *cabeza;

        while (p->siguiente != NULL)
            p = p->siguiente;

        p->siguiente = nuevo;
    }
}

bool jxls_insertarAntesDe(jxls_Nodo **cabeza, void *dato, void *x, bool (*cmp)(const void *p, const void *q))
{
    if (!jxls_estaVacia(*cabeza))
    {
        jxls_Nodo *p = *cabeza;
        jxls_Nodo *_p = NULL;

        while (p->siguiente != NULL && !cmp(p->dato, x))
        {
            _p = p;
            p = p->siguiente;
        }

        if (cmp(p->dato, x))
        {
            jxls_Nodo *nuevo = jxls_crearNodo(dato);
            nuevo->siguiente = p;

            if (p == *cabeza)
                *cabeza = nuevo;
            else
                _p->siguiente = nuevo;

            return true;
        }
    }

    return false;
}

bool jxls_insertarDespuesDe(jxls_Nodo **cabeza, void *dato, void *x, bool (*cmp)(const void *p, const void *q))
{
    if (!jxls_estaVacia(*cabeza))
    {
        jxls_Nodo *p = *cabeza;

        while (p->siguiente != NULL && !cmp(p->dato, x))
            p = p->siguiente;

        if (cmp(p->dato, x))
        {
            jxls_Nodo *nuevo = jxls_crearNodo(dato);

            if (p->siguiente != NULL)
                nuevo->siguiente = p->siguiente;

            p->siguiente = nuevo;

            return true;
        }
    }

    return false;
}

bool jxls_reemplazarEn(jxls_Nodo *cabeza, void *dato, void *x, void (*del)(void *p), bool (*cmp)(const void *p, const void *q))
{
    if (!jxls_estaVacia(cabeza))
    {
        jxls_Nodo *p = cabeza;

        while (p->siguiente != NULL && !cmp(p->dato, x))
            p = p->siguiente;

        if (cmp(p->dato, x))
        {
            del(p->dato);
            p->dato = dato;

            return true;
        }
    }

    return false;
}

bool jxls_eliminarElPrimero(jxls_Nodo **cabeza, void (*del)(void *p))
{
    if (!jxls_estaVacia(*cabeza))
    {
        jxls_Nodo *p = *cabeza;
        *cabeza = (*cabeza)->siguiente;
        jxls_borrarNodo(p, del);

        return true;
    }
    else
        return false;
}

bool jxls_eliminarElUltimo(jxls_Nodo **cabeza, void (*del)(void *p))
{
    if (!jxls_estaVacia(*cabeza))
    {
        jxls_Nodo *p = *cabeza;
        jxls_Nodo *_p = NULL;

        while (p->siguiente != NULL)
        {
            _p = p;
            p = p->siguiente;
        }

        if (p == *cabeza)
            *cabeza = NULL;
        else
            _p->siguiente = NULL;

        jxls_borrarNodo(p, del);

        return true;
    }
    else
        return false;
}

bool jxls_eliminarAntesDe(jxls_Nodo **cabeza, void *x, void (*del)(void *p), bool (*cmp)(const void *p, const void *q))
{
    if (!jxls_estaVacia(*cabeza))
    {
        jxls_Nodo *p = *cabeza;
        jxls_Nodo *_p = NULL;
        jxls_Nodo *__p = NULL;

        while (p->siguiente != NULL && !cmp(p->dato, x))
        {
            __p = _p;
            _p = p;
            p = p->siguiente;
        }

        if (cmp(p->dato, x))
            if (p != *cabeza)
            {
                if (_p == *cabeza)
                    *cabeza = p;
                else
                    __p->siguiente = p;

                jxls_borrarNodo(_p, del);

                return true;
            }
    }

    return false;
}

bool jxls_eliminarDespuesDe(jxls_Nodo **cabeza, void *x, void (*del)(void *p), bool (*cmp)(const void *p, const void *q))
{
    if (!jxls_estaVacia(*cabeza))
    {
        jxls_Nodo *p = *cabeza;

        while (p->siguiente != NULL && !cmp(p->dato, x))
            p = p->siguiente;

        if (cmp(p->dato, x))
            if (p->siguiente != NULL)
            {
                jxls_Nodo *p_ = p->siguiente;
                p->siguiente = p_->siguiente;
                jxls_borrarNodo(p_, del);

                return true;
            }
    }

    return false;
}

bool jxls_eliminarEn(jxls_Nodo **cabeza, void *x, void (*del)(void *p), bool (*cmp)(const void *p, const void *q))
{
    if (!jxls_estaVacia(*cabeza))
    {
        jxls_Nodo *p = *cabeza;
        jxls_Nodo *_p = NULL;

        while (p->siguiente != NULL && !cmp(p->dato, x))
        {
            _p = p;
            p = p->siguiente;
        }

        if (cmp(p->dato, x))
        {
            if (p == *cabeza)
                *cabeza = (*cabeza)->siguiente;
            else
                _p->siguiente = p->siguiente;

            jxls_borrarNodo(p, del);

            return true;
        }
    }

    return false;
}

void *jxls_obtenerElPrimero(jxls_Nodo *cabeza)
{
    if (!jxls_estaVacia(cabeza))
        return cabeza->dato;

    return NULL;
}

void *jxls_obtenerElUltimo(jxls_Nodo *cabeza)
{
    if (!jxls_estaVacia(cabeza))
    {
        jxls_Nodo *p = cabeza;

        while (p->siguiente != NULL)
            p = p->siguiente;

        return p->dato;
    }

    return NULL;
}

void *jxls_obtenerAntesDe(jxls_Nodo *cabeza, void *x, bool (*cmp)(const void *p, const void *q))
{
    if (!jxls_estaVacia(cabeza))
    {
        jxls_Nodo *p = cabeza;
        jxls_Nodo *_p = NULL;

        while (p->siguiente != NULL && !cmp(p->dato, x))
        {
            _p = p;
            p = p->siguiente;
        }

        if (cmp(p->dato, x))
            if (p != cabeza)
                return _p->dato;
    }

    return NULL;
}

void *jxls_obtenerDespuesDe(jxls_Nodo *cabeza, void *x, bool (*cmp)(const void *p, const void *q))
{
    if (!jxls_estaVacia(cabeza))
    {
        jxls_Nodo *p = cabeza;

        while (p->siguiente != NULL && !cmp(p->dato, x))
            p = p->siguiente;

        if (cmp(p->dato, x))
            if (p->siguiente != NULL)
                return p->siguiente->dato;
    }

    return NULL;
}

void *jxls_obtenerEn(jxls_Nodo *cabeza, int posicion)
{
    if (!jxls_estaVacia(cabeza))
    {
        jxls_Nodo *p = cabeza;
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

int jxls_buscar(jxls_Nodo *cabeza, void *x, bool (*cmp)(const void *p, const void *q))
{
    if (!jxls_estaVacia(cabeza))
    {
        jxls_Nodo *p = cabeza;
        int i = 0;

        while (p->siguiente != NULL && !cmp(p->dato, x))
        {
            p = p->siguiente;
            i++;
        }

        if (cmp(p->dato, x))
            return i;
    }

    return -1;
}

bool jxls_borrar(jxls_Nodo **cabeza, void (*del)(void *p))
{
    if (!jxls_estaVacia(*cabeza))
    {
        jxls_Nodo *p;

        do
        {
            p = *cabeza;
            *cabeza = (*cabeza)->siguiente;
            jxls_borrarNodo(p, del);
        } while (*cabeza != NULL);

        return true;
    }
    else
        return false;
}

void jxls_mostrar(jxls_Nodo *cabeza, char *(*str)(const void *p))
{
    printf("LSE => { ");

    if (!jxls_estaVacia(cabeza))
    {
        jxls_Nodo *p = cabeza;
        char *txt;

        do
        {
            txt = str(p->dato);
            printf("%s -> ", txt);
            free(txt);
            p = p->siguiente;
        } while (p != NULL);
    }

    puts(" }");
}

bool jxls_estaVacia(jxls_Nodo *cabeza)
{
    return cabeza == NULL;
}