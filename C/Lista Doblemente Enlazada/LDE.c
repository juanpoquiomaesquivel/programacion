#include "LDE.h"
#include "Libreria.h"
#include <stdbool.h>
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
    if (del != NULL)
        del(nodo->dato);
    
    free(nodo);
}

void jxld_insertarAlInicio(jxld_LDE *lde, void *dato)
{
    jxld_Nodo *nuevo = jxld_crearNodo(dato);

    if (!jxld_estaVacia(lde))
    {
        nuevo->siguiente = lde->cabeza;
        lde->cabeza->anterior = nuevo;
    }

    lde->cabeza = nuevo;
}

void jxld_insertarAlFinal(jxld_LDE *lde, void *dato)
{
    jxld_Nodo *nuevo = jxld_crearNodo(dato);

    if (jxld_estaVacia(lde))
        lde->cabeza = nuevo;
    else
    {
        jxld_Nodo *p = lde->cabeza;

        while (p->siguiente != NULL)
            p = p->siguiente;

        p->siguiente = nuevo;
        nuevo->anterior = p;
    }
}

bool jxld_insertarAntesDe(jxld_LDE *lde, void *dato, void *x)
{
    if (!jxld_estaVacia(lde))
    {
        jxld_Nodo *p = lde->cabeza;

        while (p->siguiente != NULL && lde->cmp(p->dato, x))
            p = p->siguiente;

        if (!lde->cmp(p->dato, x))
        {
            jxld_Nodo *nuevo = jxld_crearNodo(dato);
            nuevo->siguiente = p;

            if (p == lde->cabeza)
            {
                nuevo->siguiente = lde->cabeza;
                lde->cabeza->anterior = nuevo;
                lde->cabeza = nuevo;
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

bool jxld_insertarDespuesDe(jxld_LDE *lde, void *dato, void *x)
{
    if (!jxld_estaVacia(lde))
    {
        jxld_Nodo *p = lde->cabeza;

        while (p->siguiente != NULL && lde->cmp(p->dato, x))
            p = p->siguiente;

        if (!lde->cmp(p->dato, x))
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

bool jxld_reemplazarEn(jxld_LDE *lde, void *dato, void *x)
{
    if (!jxld_estaVacia(lde))
    {
        jxld_Nodo *p = lde->cabeza;

        while (p->siguiente != NULL && lde->cmp(p->dato, x))
            p = p->siguiente;

        if (!lde->cmp(p->dato, x))
        {
            lde->del(p->dato);
            p->dato = dato;

            return true;
        }
    }

    return false;
}

bool jxld_eliminarElPrimero(jxld_LDE *lde)
{
    if (!jxld_estaVacia(lde))
    {
        jxld_Nodo *p = lde->cabeza;
        lde->cabeza = lde->cabeza->siguiente;

        if (lde->cabeza != NULL)
            lde->cabeza->anterior = NULL;

        jxld_borrarNodo(p, lde->del);

        return true;
    }
    else
        return false;
}

bool jxld_eliminarElUltimo(jxld_LDE *lde)
{
    if (!jxld_estaVacia(lde))
    {
        jxld_Nodo *p = lde->cabeza;

        while (p->siguiente != NULL)
            p = p->siguiente;

        if (p == lde->cabeza)
            lde->cabeza = NULL;
        else
            p->anterior->siguiente = NULL;

        jxld_borrarNodo(p, lde->del);

        return true;
    }
    else
        return false;
}

bool jxld_eliminarAntesDe(jxld_LDE *lde, void *x)
{
    if (!jxld_estaVacia(lde))
    {
        jxld_Nodo *p = lde->cabeza;

        while (p->siguiente != NULL && lde->cmp(p->dato, x))
            p = p->siguiente;

        if (!lde->cmp(p->dato, x))
            if (p != lde->cabeza)
            {
                jxld_Nodo *_p = p->anterior;

                if (_p == lde->cabeza)
                {
                    lde->cabeza = p;
                    lde->cabeza->anterior = NULL;
                }
                else
                {
                    _p->anterior->siguiente = p;
                    p->anterior = _p->anterior;
                }

                jxld_borrarNodo(_p, lde->del);

                return true;
            }
    }

    return false;
}

bool jxld_eliminarDespuesDe(jxld_LDE *lde, void *x)
{
    if (!jxld_estaVacia(lde))
    {
        jxld_Nodo *p = lde->cabeza;

        while (p->siguiente != NULL && lde->cmp(p->dato, x))
            p = p->siguiente;

        if (!lde->cmp(p->dato, x))
            if (p->siguiente != NULL)
            {
                jxld_Nodo *p_ = p->siguiente;
                p->siguiente = p_->siguiente;

                if (p_->siguiente != NULL)
                    p_->siguiente->anterior = p;

                jxld_borrarNodo(p_, lde->del);

                return true;
            }
    }

    return false;
}

bool jxld_eliminarEn(jxld_LDE *lde, void *x)
{
    if (!jxld_estaVacia(lde))
    {
        jxld_Nodo *p = lde->cabeza;

        while (p->siguiente != NULL && lde->cmp(p->dato, x))
            p = p->siguiente;

        if (!lde->cmp(p->dato, x))
        {
            if (p == lde->cabeza)
            {
                lde->cabeza = lde->cabeza->siguiente;

                if (lde->cabeza != NULL)
                    lde->cabeza->anterior = NULL;
            }
            else
            {
                p->anterior->siguiente = p->siguiente;

                if (p->siguiente != NULL)
                    p->siguiente->anterior = p->anterior;
            }

            jxld_borrarNodo(p, lde->del);

            return true;
        }
    }
}

void *jxld_obtenerElPrimero(jxld_LDE *lde)
{
    if (!jxld_estaVacia(lde))
        return lde->cabeza->dato;

    return NULL;
}

void *jxld_obtenerElUltimo(jxld_LDE *lde)
{
    if (!jxld_estaVacia(lde))
    {
        jxld_Nodo *p = lde->cabeza;

        while (p->siguiente != NULL)
            p = p->siguiente;

        return p->dato;
    }

    return NULL;
}

void *jxld_obtenerAntesDe(jxld_LDE *lde, void *x)
{
    if (!jxld_estaVacia(lde))
    {
        jxld_Nodo *p = lde->cabeza;

        while (p->siguiente != NULL && lde->cmp(p->dato, x))
            p = p->siguiente;

        if (!lde->cmp(p->dato, x))
            if (p != lde->cabeza)
                return p->anterior->dato;
    }

    return NULL;
}

void *jxld_obtenerDespuesDe(jxld_LDE *lde, void *x)
{
    if (!jxld_estaVacia(lde))
    {
        jxld_Nodo *p = lde->cabeza;

        while (p->siguiente != NULL && lde->cmp(p->dato, x))
            p = p->siguiente;

        if (!lde->cmp(p->dato, x))
            if (p->siguiente != NULL)
                return p->siguiente->dato;
    }

    return NULL;
}

void *jxld_obtenerEn(jxld_LDE *lde, int posicion)
{
    if (!jxld_estaVacia(lde))
    {
        jxld_Nodo *p = lde->cabeza;
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

int jxld_buscar(jxld_LDE *lde, void *x)
{
    if (!jxld_estaVacia(lde))
    {
        jxld_Nodo *p = lde->cabeza;
        int i = 0;

        while (p->siguiente != NULL && lde->cmp(p->dato, x))
        {
            p = p->siguiente;
            i++;
        }

        if (!lde->cmp(p->dato, x))
            return i;
    }

    return -1;
}

bool jxld_borrar(jxld_LDE *lde)
{
    if (!jxld_estaVacia(lde))
    {
        jxld_Nodo *p;

        do
        {
            p = lde->cabeza;
            lde->cabeza = lde->cabeza->siguiente;
            jxld_borrarNodo(p, lde->del);
        } while (lde->cabeza != NULL);

        return true;
    }
    else
        return false;
}

void jxld_mostrar(jxld_LDE *lde)
{
    printf("LDE => { ");

    if (!jxld_estaVacia(lde))
    {
        jxld_Nodo *p = lde->cabeza;
        char *txt;

        do
        {
            txt = lde->str(p->dato);
            printf("%s -> ", txt);
            free(txt);
            p = p->siguiente;
        } while (p != NULL);
    }

    puts(" }");
}

bool jxld_estaVacia(jxld_LDE *lde)
{
    return lde->cabeza == NULL;
}