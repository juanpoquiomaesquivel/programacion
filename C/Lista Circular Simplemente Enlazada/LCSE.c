#include "LCSE.h"
#include "Libreria.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

jxlcs_Nodo *jxlcs_crearNodo(void *dato)
{
    jxlcs_Nodo *nuevo = (jxlcs_Nodo *)malloc(sizeof(jxlcs_Nodo));
    errorDeMemoria(nuevo);
    nuevo->dato = dato;
    nuevo->siguiente = NULL;

    return nuevo;
}

void jxlcs_borrarNodo(jxlcs_Nodo *nodo, void (*del)(void *p))
{
    if (del != NULL)
        del(nodo->dato);
    
    free(nodo);
}

void jxlcs_insertarAlInicio(jxlcs_LCSE *lcse, void *dato)
{
    jxlcs_Nodo *nuevo = jxlcs_crearNodo(dato);

    if (jxlcs_estaVacia(lcse))
    {
        lcse->cabeza = nuevo;
        lcse->cabeza->siguiente = lcse->cabeza;
    }
    else
    {
        jxlcs_Nodo *p = lcse->cabeza;

        while (p->siguiente != lcse->cabeza)
            p = p->siguiente;

        nuevo->siguiente = lcse->cabeza;
        lcse->cabeza = nuevo;
        p->siguiente = lcse->cabeza;
    }
}

void jxlcs_insertarAlFinal(jxlcs_LCSE *lcse, void *dato)
{
    jxlcs_Nodo *nuevo = jxlcs_crearNodo(dato);

    if (jxlcs_estaVacia(lcse))
    {
        lcse->cabeza = nuevo;
        lcse->cabeza->siguiente = lcse->cabeza;
    }
    else
    {
        jxlcs_Nodo *p = lcse->cabeza;

        while (p->siguiente != lcse->cabeza)
            p = p->siguiente;

        p->siguiente = nuevo;
        nuevo->siguiente = lcse->cabeza;
    }
}

bool jxlcs_insertarAntesDe(jxlcs_LCSE *lcse, void *dato, void *x)
{
    if (!jxlcs_estaVacia(lcse))
    {
        jxlcs_Nodo *p = lcse->cabeza;
        jxlcs_Nodo *_p = NULL;

        while (p->siguiente != lcse->cabeza && lcse->cmp(p->dato, x))
        {
            _p = p;
            p = p->siguiente;
        }

        if (!lcse->cmp(p->dato, x))
        {
            jxlcs_Nodo *nuevo = jxlcs_crearNodo(dato);

            if (p == lcse->cabeza)
            {
                jxlcs_Nodo *q = lcse->cabeza;

                while (q->siguiente != lcse->cabeza)
                    q = q->siguiente;

                nuevo->siguiente = lcse->cabeza;
                lcse->cabeza = nuevo;
                q->siguiente = lcse->cabeza;
            }
            else
            {
                _p->siguiente = nuevo;
                nuevo->siguiente = p;
            }

            return true;
        }
    }

    return false;
}

bool jxlcs_insertarDespuesDe(jxlcs_LCSE *lcse, void *dato, void *x)
{
    if (!jxlcs_estaVacia(lcse))
    {
        jxlcs_Nodo *p = lcse->cabeza;

        while (p->siguiente != lcse->cabeza && lcse->cmp(p->dato, x))
            p = p->siguiente;

        if (!lcse->cmp(p->dato, x))
        {
            jxlcs_Nodo *nuevo = jxlcs_crearNodo(dato);

            if (p->siguiente == lcse->cabeza)
            {
                p->siguiente = nuevo;
                nuevo->siguiente = lcse->cabeza;
            }
            else
            {
                nuevo->siguiente = p->siguiente;
                p->siguiente = nuevo;
            }

            return true;
        }
    }

    return false;
}

bool jxlcs_reemplazarEn(jxlcs_LCSE *lcse, void *dato, void *x)
{
    if (!jxlcs_estaVacia(lcse))
    {
        jxlcs_Nodo *p = lcse->cabeza;

        while (p->siguiente != lcse->cabeza && lcse->cmp(p->dato, x))
            p = p->siguiente;

        if (!lcse->cmp(p->dato, x))
        {
            lcse->del(p->dato);
            p->dato = dato;

            return true;
        }
    }

    return false;
}

bool jxlcs_eliminarElPrimero(jxlcs_LCSE *lcse)
{
    if (!jxlcs_estaVacia(lcse))
    {
        jxlcs_Nodo *p = lcse->cabeza;

        if (lcse->cabeza->siguiente == lcse->cabeza)
            lcse->cabeza = NULL;
        else
        {
            jxlcs_Nodo *q = lcse->cabeza;

            while (q->siguiente != lcse->cabeza)
                q = q->siguiente;

            lcse->cabeza = lcse->cabeza->siguiente;
            q->siguiente = lcse->cabeza;
        }

        jxlcs_borrarNodo(p, lcse->del);

        return true;
    }
    else
        return false;
}

bool jxlcs_eliminarElUltimo(jxlcs_LCSE *lcse)
{
    if (!jxlcs_estaVacia(lcse))
    {
        jxlcs_Nodo *p = lcse->cabeza;
        jxlcs_Nodo *_p = NULL;

        while (p->siguiente != lcse->cabeza)
        {
            _p = p;
            p = p->siguiente;
        }

        if (p == lcse->cabeza)
            lcse->cabeza = NULL;
        else
            _p->siguiente = lcse->cabeza;

        jxlcs_borrarNodo(p, lcse->del);

        return true;
    }
    else
        return false;
}

bool jxlcs_eliminarAntesDe(jxlcs_LCSE *lcse, void *x)
{
    if (!jxlcs_estaVacia(lcse))
    {
        jxlcs_Nodo *p = lcse->cabeza;
        jxlcs_Nodo *_p = NULL;
        jxlcs_Nodo *__p = NULL;

        while (p->siguiente != lcse->cabeza && lcse->cmp(p->dato, x))
        {
            __p = _p;
            _p = p;
            p = p->siguiente;
        }

        if (!lcse->cmp(p->dato, x))
        {
            if (p == lcse->cabeza)
            {
                if (p->siguiente == lcse->cabeza)
                {
                    lcse->cabeza = NULL;
                    jxlcs_borrarNodo(p, lcse->del);
                }
                else
                {
                    jxlcs_Nodo *q = lcse->cabeza;
                    jxlcs_Nodo *_q = NULL;

                    while (q->siguiente != lcse->cabeza)
                    {
                        _q = q;
                        q = q->siguiente;
                    }

                    _q->siguiente = lcse->cabeza;
                    jxlcs_borrarNodo(q, lcse->del);
                }
            }
            else
            {
                if (_p == lcse->cabeza)
                {
                    jxlcs_Nodo *q = lcse->cabeza;

                    while (q->siguiente != lcse->cabeza)
                        q = q->siguiente;

                    lcse->cabeza = lcse->cabeza->siguiente;
                    q->siguiente = lcse->cabeza;
                }
                else
                    __p->siguiente = p;

                jxlcs_borrarNodo(_p, lcse->del);
            }

            return true;
        }
    }

    return false;
}

bool jxlcs_eliminarDespuesDe(jxlcs_LCSE *lcse, void *x)
{
    if (!jxlcs_estaVacia(lcse))
    {
        jxlcs_Nodo *p = lcse->cabeza;

        while (p->siguiente != lcse->cabeza && lcse->cmp(p->dato, x))
            p = p->siguiente;

        if (!lcse->cmp(p->dato, x))
        {
            jxlcs_Nodo *p_ = p->siguiente;

            if (p->siguiente == lcse->cabeza)
            {
                if (p == lcse->cabeza)
                {
                    lcse->cabeza = NULL;
                    jxlcs_borrarNodo(p, lcse->del);
                }
                else
                {
                    lcse->cabeza = lcse->cabeza->siguiente;
                    p->siguiente = lcse->cabeza;
                    jxlcs_borrarNodo(p_, lcse->del);
                }
            }
            else
            {
                p->siguiente = p_->siguiente;
                jxlcs_borrarNodo(p_, lcse->del);
            }

            return true;
        }
    }

    return false;
}

bool jxlcs_eliminarEn(jxlcs_LCSE *lcse, void *x)
{
    if (!jxlcs_estaVacia(lcse))
    {
        jxlcs_Nodo *p = lcse->cabeza;
        jxlcs_Nodo *_p = NULL;

        while (p->siguiente != lcse->cabeza && lcse->cmp(p->dato, x))
        {
            _p = p;
            p = p->siguiente;
        }

        if (!lcse->cmp(p->dato, x))
        {
            if (p == lcse->cabeza)
            {
                if (p->siguiente == lcse->cabeza)
                    lcse->cabeza = NULL;
                else
                {
                    jxlcs_Nodo *q = lcse->cabeza;

                    while (q->siguiente != lcse->cabeza)
                        q = q->siguiente;

                    lcse->cabeza = lcse->cabeza->siguiente;
                    q->siguiente = lcse->cabeza;
                }
            }
            else
                _p->siguiente = p->siguiente;

            jxlcs_borrarNodo(p, lcse->del);

            return true;
        }
    }

    return false;
}

void *jxlcs_obtenerElPrimero(jxlcs_LCSE *lcse)
{
    if (!jxlcs_estaVacia(lcse))
        return lcse->cabeza->dato;

    return NULL;
}

void *jxlcs_obtenerElUltimo(jxlcs_LCSE *lcse)
{
    if (!jxlcs_estaVacia(lcse))
    {
        jxlcs_Nodo *p = lcse->cabeza;

        while (p->siguiente != lcse->cabeza)
            p = p->siguiente;

        return p->dato;
    }

    return NULL;
}

void *jxlcs_obtenerAntesDe(jxlcs_LCSE *lcse, void *x)
{
    if (!jxlcs_estaVacia(lcse))
    {
        jxlcs_Nodo *p = lcse->cabeza;
        jxlcs_Nodo *_p = NULL;

        while (p->siguiente != lcse->cabeza && lcse->cmp(p->dato, x))
        {
            _p = p;
            p = p->siguiente;
        }

        if (!lcse->cmp(p->dato, x))
        {
            if (p == lcse->cabeza)
            {
                jxlcs_Nodo *q = lcse->cabeza;

                while (q->siguiente != lcse->cabeza)
                    q = q->siguiente;

                return q->dato;
            }
            else
                return _p->dato;
        }
    }

    return NULL;
}

void *jxlcs_obtenerDespuesDe(jxlcs_LCSE *lcse, void *x)
{
    if (!jxlcs_estaVacia(lcse))
    {
        jxlcs_Nodo *p = lcse->cabeza;

        while (p->siguiente != lcse->cabeza && lcse->cmp(p->dato, x))
            p = p->siguiente;

        if (!lcse->cmp(p->dato, x))
            return p->siguiente->dato;
    }

    return NULL;
}

void *jxlcs_obtenerEn(jxlcs_LCSE *lcse, int posicion)
{
    if (!jxlcs_estaVacia(lcse))
    {
        jxlcs_Nodo *p = lcse->cabeza;
        int i = 0;

        while (p->siguiente != lcse->cabeza && i != posicion)
        {
            p = p->siguiente;
            i++;
        }

        if (i == posicion)
            return p->dato;
    }

    return NULL;
}

int jxlcs_buscar(jxlcs_LCSE *lcse, void *x)
{
    if (!jxlcs_estaVacia(lcse))
    {
        jxlcs_Nodo *p = lcse->cabeza;
        int i = 0;

        while (p->siguiente != lcse->cabeza && lcse->cmp(p->dato, x))
        {
            p = p->siguiente;
            i++;
        }

        if (!lcse->cmp(p->dato, x))
            return i;
    }

    return -1;
}

bool jxlcs_borrar(jxlcs_LCSE *lcse)
{
    if (!jxlcs_estaVacia(lcse))
    {
        jxlcs_Nodo *p;
        jxlcs_Nodo *q = lcse->cabeza;

        while (q->siguiente != lcse->cabeza)
            q = q->siguiente;

        q->siguiente = NULL;

        do
        {
            p = lcse->cabeza;
            lcse->cabeza = lcse->cabeza->siguiente;
            jxlcs_borrarNodo(p, lcse->del);
        } while (lcse->cabeza != NULL);

        return true;
    }
    else
        return false;
}

void jxlcs_mostrar(jxlcs_LCSE *lcse)
{
    printf("LCSE => { ");

    if (!jxlcs_estaVacia(lcse))
    {
        jxlcs_Nodo *p = lcse->cabeza;
        char *txt;

        do
        {
            txt = lcse->str(p->dato);
            printf("%s -> ", txt);
            free(txt);
            p = p->siguiente;
        } while (p != lcse->cabeza);
    }

    puts(" }");
}

bool jxlcs_estaVacia(jxlcs_LCSE *lcse)
{
    return lcse->cabeza == NULL;
}