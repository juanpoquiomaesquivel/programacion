#include "LDE.h"
#include "Libreria.h"
#include <stdio.h>
#include <stdlib.h>

jxld_Nodo *jxld_crearNodo(void *dato)
{
    jxld_Nodo *nuevo = (jxld_Nodo *)malloc(sizeof(jxld_Nodo));
    errorDeMemoria(nuevo);
    nuevo->dato = dato;
    nuevo->anterior = NULL;
    nuevo->siguiente = NULL;

    return nuevo;
}

void jxld_borrarNodo(jxld_Nodo *nodo, void (*del)(void *p))
{
    del(nodo->dato);
    free(nodo);
}

void jxld_insertarAlInicio(jxld_Nodo **cabeza, void *dato)
{
    jxld_Nodo *nuevo = jxld_crearNodo(dato);

    if (!jxld_estaVacia(*cabeza))
    {
        nuevo->siguiente = *cabeza;
        (*cabeza)->anterior = nuevo;
    }

    *cabeza = nuevo;
}

void jxld_insertarAlFinal(jxld_Nodo **cabeza, void *dato)
{
    jxld_Nodo *nuevo = jxld_crearNodo(dato);

    if (jxld_estaVacia(*cabeza))
        *cabeza = nuevo;
    else
    {
        jxld_Nodo *p = *cabeza;

        while (p->siguiente != NULL)
            p = p->siguiente;

        p->siguiente = nuevo;
        nuevo->anterior = p;
    }
}

bool jxld_insertarAntesDe(jxld_Nodo **cabeza, void *dato, void *x, bool (*cmp)(const void *p, const void *q))
{
    if (!jxld_estaVacia(*cabeza))
    {
        jxld_Nodo *p = *cabeza;

        while (p->siguiente != NULL && !cmp(p->dato, x))
            p = p->siguiente;

        if (cmp(p->dato, x))
        {
            jxld_Nodo *nuevo = jxld_crearNodo(dato);
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

            return true;
        }
    }

    return false;
}

bool jxld_insertarDespuesDe(jxld_Nodo **cabeza, void *dato, void *x, bool (*cmp)(const void *p, const void *q))
{
    if (!jxld_estaVacia(*cabeza))
    {
        jxld_Nodo *p = *cabeza;

        while (p->siguiente != NULL && !cmp(p->dato, x))
            p = p->siguiente;

        if (cmp(p->dato, x))
        {
            jxld_Nodo *nuevo = jxld_crearNodo(dato);

            if (p->siguiente != NULL)
            {
                nuevo->siguiente = p->siguiente;
                p->siguiente->anterior = nuevo;
            }

            p->siguiente = nuevo;
            nuevo->anterior = p;

            return true;
        }
    }

    return false;
}

bool jxld_reemplazarEn(jxld_Nodo *cabeza, void *dato, void *x, void (*del)(void *p), bool (*cmp)(const void *p, const void *q))
{
    if (!jxld_estaVacia(cabeza))
    {
        jxld_Nodo *p = cabeza;

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

bool jxld_eliminarElPrimero(jxld_Nodo **cabeza, void (*del)(void *p))
{
    if (!jxld_estaVacia(*cabeza))
    {
        jxld_Nodo *p = *cabeza;
        *cabeza = (*cabeza)->siguiente;

        if (*cabeza != NULL)
            (*cabeza)->anterior = NULL;

        jxld_borrarNodo(p, del);

        return true;
    }
    else
        return false;
}

bool jxld_eliminarElUltimo(jxld_Nodo **cabeza, void (*del)(void *p))
{
    if (!jxld_estaVacia(*cabeza))
    {
        jxld_Nodo *p = *cabeza;

        while (p->siguiente != NULL)
            p = p->siguiente;

        if (p == *cabeza)
            *cabeza = NULL;
        else
            p->anterior->siguiente = NULL;

        jxld_borrarNodo(p, del);

        return true;
    }
    else
        return false;
}

bool jxld_eliminarAntesDe(jxld_Nodo **cabeza, void *x, void (*del)(void *p), bool (*cmp)(const void *p, const void *q))
{
    if (!jxld_estaVacia(*cabeza))
    {
        jxld_Nodo *p = *cabeza;

        while (p->siguiente != NULL && !cmp(p->dato, x))
            p = p->siguiente;

        if (cmp(p->dato, x))
            if (p != *cabeza)
            {
                jxld_Nodo *_p = p->anterior;

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

                jxld_borrarNodo(_p, del);

                return true;
            }
    }

    return false;
}

bool jxld_eliminarDespuesDe(jxld_Nodo **cabeza, void *x, void (*del)(void *p), bool (*cmp)(const void *p, const void *q))
{
    if (!jxld_estaVacia(*cabeza))
    {
        jxld_Nodo *p = *cabeza;

        while (p->siguiente != NULL && !cmp(p->dato, x))
            p = p->siguiente;

        if (cmp(p->dato, x))
            if (p->siguiente != NULL)
            {
                jxld_Nodo *p_ = p->siguiente;
                p->siguiente = p_->siguiente;

                if (p_->siguiente != NULL)
                    p_->siguiente->anterior = p;

                jxld_borrarNodo(p_, del);

                return true;
            }
    }

    return false;
}

bool jxld_eliminarEn(jxld_Nodo **cabeza, void *x, void (*del)(void *p), bool (*cmp)(const void *p, const void *q))
{
    if (!jxld_estaVacia(*cabeza))
    {
        jxld_Nodo *p = *cabeza;

        while (p->siguiente != NULL && !cmp(p->dato, x))
            p = p->siguiente;

        if (cmp(p->dato, x))
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

            jxld_borrarNodo(p, del);

            return true;
        }
    }
}

void *jxld_obtenerElPrimero(jxld_Nodo *cabeza)
{
    if (!jxld_estaVacia(cabeza))
        return cabeza->dato;

    return NULL;
}

void *jxld_obtenerElUltimo(jxld_Nodo *cabeza)
{
    if (!jxld_estaVacia(cabeza))
    {
        jxld_Nodo *p = cabeza;

        while (p->siguiente != NULL)
            p = p->siguiente;

        return p->dato;
    }

    return NULL;
}

void *jxld_obtenerAntesDe(jxld_Nodo *cabeza, void *x, bool (*cmp)(const void *p, const void *q))
{
    if (!jxld_estaVacia(cabeza))
    {
        jxld_Nodo *p = cabeza;

        while (p->siguiente != NULL && !cmp(p->dato, x))
            p = p->siguiente;

        if (cmp(p->dato, x))
            if (p != cabeza)
                return p->anterior->dato;
    }

    return NULL;
}

void *jxld_obtenerDespuesDe(jxld_Nodo *cabeza, void *x, bool (*cmp)(const void *p, const void *q))
{
    if (!jxld_estaVacia(cabeza))
    {
        jxld_Nodo *p = cabeza;

        while (p->siguiente != NULL && !cmp(p->dato, x))
            p = p->siguiente;

        if (cmp(p->dato, x))
            if (p->siguiente != NULL)
                return p->siguiente->dato;
    }

    return NULL;
}

void *jxld_obtenerEn(jxld_Nodo *cabeza, int posicion)
{
    if (!jxld_estaVacia(cabeza))
    {
        jxld_Nodo *p = cabeza;
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

int jxld_buscar(jxld_Nodo *cabeza, void *x, bool (*cmp)(const void *p, const void *q))
{
    if (!jxld_estaVacia(cabeza))
    {
        jxld_Nodo *p = cabeza;
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

bool jxld_borrar(jxld_Nodo **cabeza, void (*del)(void *p))
{
    if (!jxld_estaVacia(*cabeza))
    {
        jxld_Nodo *p;

        do
        {
            p = *cabeza;
            *cabeza = (*cabeza)->siguiente;
            jxld_borrarNodo(p, del);
        } while (*cabeza != NULL);

        return true;
    }
    else
        return false;
}

void jxld_mostrar(jxld_Nodo *cabeza, char *(*str)(const void *p))
{
    printf("LDE => { ");

    if (!jxld_estaVacia(cabeza))
    {
        jxld_Nodo *p = cabeza;
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

bool jxld_estaVacia(jxld_Nodo *cabeza)
{
    return cabeza == NULL;
}