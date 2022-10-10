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
    if (del != NULL)
        del(nodo->dato);

    free(nodo);
}

void jxls_insertarAlInicio(jxls_LSE *lse, void *dato)
{
    jxls_Nodo *nuevo = jxls_crearNodo(dato);

    if (!jxls_estaVacia(lse))
        nuevo->siguiente = lse->cabeza;

    lse->cabeza = nuevo;
}

void jxls_insertarAlFinal(jxls_LSE *lse, void *dato)
{
    jxls_Nodo *nuevo = jxls_crearNodo(dato);

    if (jxls_estaVacia(lse))
        lse->cabeza = nuevo;
    else
    {
        jxls_Nodo *p = lse->cabeza;

        while (p->siguiente != NULL)
            p = p->siguiente;

        p->siguiente = nuevo;
    }
}

bool jxls_insertarAntesDe(jxls_LSE *lse, void *dato, void *x)
{
    if (!jxls_estaVacia(lse))
    {
        jxls_Nodo *p = lse->cabeza;
        jxls_Nodo *_p = NULL;

        while (p->siguiente != NULL && lse->cmp(p->dato, x))
        {
            _p = p;
            p = p->siguiente;
        }

        if (!lse->cmp(p->dato, x))
        {
            jxls_Nodo *nuevo = jxls_crearNodo(dato);
            nuevo->siguiente = p;

            if (p == lse->cabeza)
                lse->cabeza = nuevo;
            else
                _p->siguiente = nuevo;

            return true;
        }
    }

    return false;
}

bool jxls_insertarDespuesDe(jxls_LSE *lse, void *dato, void *x)
{
    if (!jxls_estaVacia(lse))
    {
        jxls_Nodo *p = lse->cabeza;

        while (p->siguiente != NULL && lse->cmp(p->dato, x))
            p = p->siguiente;

        if (!lse->cmp(p->dato, x))
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

bool jxls_reemplazarEn(jxls_LSE *lse, void *dato, void *x)
{
    if (!jxls_estaVacia(lse))
    {
        jxls_Nodo *p = lse->cabeza;

        while (p->siguiente != NULL && lse->cmp(p->dato, x))
            p = p->siguiente;

        if (!lse->cmp(p->dato, x))
        {
            lse->del(p->dato);
            p->dato = dato;

            return true;
        }
    }

    return false;
}

bool jxls_eliminarElPrimero(jxls_LSE *lse)
{
    if (!jxls_estaVacia(lse))
    {
        jxls_Nodo *p = lse->cabeza;
        lse->cabeza = lse->cabeza->siguiente;
        jxls_borrarNodo(p, lse->del);

        return true;
    }
    else
        return false;
}

bool jxls_eliminarElUltimo(jxls_LSE *lse)
{
    if (!jxls_estaVacia(lse))
    {
        jxls_Nodo *p = lse->cabeza;
        jxls_Nodo *_p = NULL;

        while (p->siguiente != NULL)
        {
            _p = p;
            p = p->siguiente;
        }

        if (p == lse->cabeza)
            lse->cabeza = NULL;
        else
            _p->siguiente = NULL;

        jxls_borrarNodo(p, lse->del);

        return true;
    }
    else
        return false;
}

bool jxls_eliminarAntesDe(jxls_LSE *lse, void *x)
{
    if (!jxls_estaVacia(lse))
    {
        jxls_Nodo *p = lse->cabeza;
        jxls_Nodo *_p = NULL;
        jxls_Nodo *__p = NULL;

        while (p->siguiente != NULL && lse->cmp(p->dato, x))
        {
            __p = _p;
            _p = p;
            p = p->siguiente;
        }

        if (!lse->cmp(p->dato, x))
            if (p != lse->cabeza)
            {
                if (_p == lse->cabeza)
                    lse->cabeza = p;
                else
                    __p->siguiente = p;

                jxls_borrarNodo(_p, lse->del);

                return true;
            }
    }

    return false;
}

bool jxls_eliminarDespuesDe(jxls_LSE *lse, void *x)
{
    if (!jxls_estaVacia(lse))
    {
        jxls_Nodo *p = lse->cabeza;

        while (p->siguiente != NULL && lse->cmp(p->dato, x))
            p = p->siguiente;

        if (!lse->cmp(p->dato, x))
            if (p->siguiente != NULL)
            {
                jxls_Nodo *p_ = p->siguiente;
                p->siguiente = p_->siguiente;
                jxls_borrarNodo(p_, lse->del);

                return true;
            }
    }

    return false;
}

bool jxls_eliminarEn(jxls_LSE *lse, void *x)
{
    if (!jxls_estaVacia(lse))
    {
        jxls_Nodo *p = lse->cabeza;
        jxls_Nodo *_p = NULL;

        while (p->siguiente != NULL && lse->cmp(p->dato, x))
        {
            _p = p;
            p = p->siguiente;
        }

        if (!lse->cmp(p->dato, x))
        {
            if (p == lse->cabeza)
                lse->cabeza = lse->cabeza->siguiente;
            else
                _p->siguiente = p->siguiente;

            jxls_borrarNodo(p, lse->del);

            return true;
        }
    }

    return false;
}

void *jxls_obtenerElPrimero(jxls_LSE *lse)
{
    if (!jxls_estaVacia(lse))
        return lse->cabeza->dato;

    return NULL;
}

void *jxls_obtenerElUltimo(jxls_LSE *lse)
{
    if (!jxls_estaVacia(lse))
    {
        jxls_Nodo *p = lse->cabeza;

        while (p->siguiente != NULL)
            p = p->siguiente;

        return p->dato;
    }

    return NULL;
}

void *jxls_obtenerAntesDe(jxls_LSE *lse, void *x)
{
    if (!jxls_estaVacia(lse))
    {
        jxls_Nodo *p = lse->cabeza;
        jxls_Nodo *_p = NULL;

        while (p->siguiente != NULL && lse->cmp(p->dato, x))
        {
            _p = p;
            p = p->siguiente;
        }

        if (!lse->cmp(p->dato, x))
            if (p != lse->cabeza)
                return _p->dato;
    }

    return NULL;
}

void *jxls_obtenerDespuesDe(jxls_LSE *lse, void *x)
{
    if (!jxls_estaVacia(lse))
    {
        jxls_Nodo *p = lse->cabeza;

        while (p->siguiente != NULL && lse->cmp(p->dato, x))
            p = p->siguiente;

        if (!lse->cmp(p->dato, x))
            if (p->siguiente != NULL)
                return p->siguiente->dato;
    }

    return NULL;
}

void *jxls_obtenerEn(jxls_LSE *lse, int posicion)
{
    if (!jxls_estaVacia(lse))
    {
        jxls_Nodo *p = lse->cabeza;
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

int jxls_buscar(jxls_LSE *lse, void *x)
{
    if (!jxls_estaVacia(lse))
    {
        jxls_Nodo *p = lse->cabeza;
        int i = 0;

        while (p->siguiente != NULL && lse->cmp(p->dato, x))
        {
            p = p->siguiente;
            i++;
        }

        if (!lse->cmp(p->dato, x))
            return i;
    }

    return -1;
}

bool jxls_borrar(jxls_LSE *lse)
{
    if (!jxls_estaVacia(lse))
    {
        jxls_Nodo *p;

        do
        {
            p = lse->cabeza;
            lse->cabeza = lse->cabeza->siguiente;
            jxls_borrarNodo(p, lse->del);
        } while (lse->cabeza != NULL);

        return true;
    }
    else
        return false;
}

void jxls_mostrar(jxls_LSE *lse)
{
    printf("LSE => { ");

    if (!jxls_estaVacia(lse))
    {
        jxls_Nodo *p = lse->cabeza;
        char *txt;

        do
        {
            txt = lse->str(p->dato);
            printf("%s -> ", txt);
            free(txt);
            p = p->siguiente;
        } while (p != NULL);
    }

    puts(" }");
}

bool jxls_estaVacia(jxls_LSE *lse)
{
    return lse->cabeza == NULL;
}