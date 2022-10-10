#include "LCDE.h"
#include "Libreria.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

jxlcd_Nodo *jxlcd_crearNodo(void *dato)
{
    jxlcd_Nodo *nuevo = (jxlcd_Nodo *)malloc(sizeof(jxlcd_Nodo));
    errorDeMemoria(nuevo);
    nuevo->dato = dato;
    nuevo->anterior = NULL;
    nuevo->siguiente = NULL;

    return nuevo;
}

void jxlcd_borrarNodo(jxlcd_Nodo *nodo, void (*del)(void *p))
{
    if (del != NULL)
        del(nodo->dato);
    
    free(nodo);
}

void jxlcd_insertarAlInicio(jxlcd_LCDE *lcde, void *dato)
{
    jxlcd_Nodo *nuevo = jxlcd_crearNodo(dato);

    if (jxlcd_estaVacia(lcde))
    {
        lcde->cabeza = nuevo;
        lcde->cabeza->anterior = lcde->cabeza;
        lcde->cabeza->siguiente = lcde->cabeza;
    }
    else
    {
        jxlcd_Nodo *p = lcde->cabeza->anterior;
        nuevo->anterior = p;
        nuevo->siguiente = lcde->cabeza;
        lcde->cabeza->anterior = nuevo;
        lcde->cabeza = nuevo;
        p->siguiente = lcde->cabeza;
    }
}

void jxlcd_insertarAlFinal(jxlcd_LCDE *lcde, void *dato)
{
    jxlcd_Nodo *nuevo = jxlcd_crearNodo(dato);

    if (jxlcd_estaVacia(lcde))
    {
        lcde->cabeza = nuevo;
        lcde->cabeza->anterior = lcde->cabeza;
        lcde->cabeza->siguiente = lcde->cabeza;
    }
    else
    {
        jxlcd_Nodo *p = lcde->cabeza->anterior;
        lcde->cabeza->anterior = nuevo;
        p->siguiente = nuevo;
        nuevo->anterior = p;
        nuevo->siguiente = lcde->cabeza;
    }
}

bool jxlcd_insertarAntesDe(jxlcd_LCDE *lcde, void *dato, void *x)
{
    if (!jxlcd_estaVacia(lcde))
    {
        jxlcd_Nodo *p = lcde->cabeza;

        while (p->siguiente != lcde->cabeza && lcde->cmp(p->dato, x))
            p = p->siguiente;

        if (!lcde->cmp(p->dato, x))
        {
            jxlcd_Nodo *nuevo = jxlcd_crearNodo(dato);

            if (p == lcde->cabeza)
            {
                jxlcd_Nodo *q = lcde->cabeza->anterior;
                nuevo->anterior = q;
                nuevo->siguiente = lcde->cabeza;
                lcde->cabeza->anterior = nuevo;
                lcde->cabeza = nuevo;
                q->siguiente = lcde->cabeza;
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

bool jxlcd_insertarDespuesDe(jxlcd_LCDE *lcde, void *dato, void *x)
{
    if (!jxlcd_estaVacia(lcde))
    {
        jxlcd_Nodo *p = lcde->cabeza;

        while (p->siguiente != lcde->cabeza && lcde->cmp(p->dato, x))
            p = p->siguiente;

        if (!lcde->cmp(p->dato, x))
        {
            jxlcd_Nodo *nuevo = jxlcd_crearNodo(dato);

            if (p->siguiente == lcde->cabeza)
            {
                p->siguiente = nuevo;
                nuevo->anterior = p;
                nuevo->siguiente = lcde->cabeza;
                lcde->cabeza->anterior = nuevo;
            }
            else
            {
                nuevo->anterior = p;
                nuevo->siguiente = p->siguiente;
                p->siguiente->anterior = nuevo;
                p->siguiente = nuevo;
            }

            return true;
        }
    }

    return false;
}

bool jxlcd_reemplazarEn(jxlcd_LCDE *lcde, void *dato, void *x)
{
    if (!jxlcd_estaVacia(lcde))
    {
        jxlcd_Nodo *p = lcde->cabeza;

        while (p->siguiente != lcde->cabeza && lcde->cmp(p->dato, x))
            p = p->siguiente;

        if (!lcde->cmp(p->dato, x))
        {
            lcde->del(p->dato);
            p->dato = dato;

            return true;
        }
    }

    return false;
}

bool jxlcd_eliminarElPrimero(jxlcd_LCDE *lcde)
{
    if (!jxlcd_estaVacia(lcde))
    {
        jxlcd_Nodo *p = lcde->cabeza;

        if (lcde->cabeza->siguiente == lcde->cabeza)
            lcde->cabeza = NULL;
        else
        {
            jxlcd_Nodo *q = lcde->cabeza->anterior;
            lcde->cabeza = lcde->cabeza->siguiente;
            lcde->cabeza->anterior = q;
            q->siguiente = lcde->cabeza;
        }

        jxlcd_borrarNodo(p, lcde->del);

        return true;
    }
    else
        return false;
}

bool jxlcd_eliminarElUltimo(jxlcd_LCDE *lcde)
{
    if (!jxlcd_estaVacia(lcde))
    {
        jxlcd_Nodo *p = lcde->cabeza->anterior;

        if (p == lcde->cabeza)
            lcde->cabeza = NULL;
        else
        {
            lcde->cabeza->anterior = p->anterior;
            p->anterior->siguiente = lcde->cabeza;
        }

        jxlcd_borrarNodo(p, lcde->del);
        
        return true;
    }
    else
        return false;
}

bool jxlcd_eliminarAntesDe(jxlcd_LCDE *lcde, void *x)
{
    if (!jxlcd_estaVacia(lcde))
    {
        jxlcd_Nodo *p = lcde->cabeza;

        while (p->siguiente != lcde->cabeza && lcde->cmp(p->dato, x))
            p = p->siguiente;

        if (!lcde->cmp(p->dato, x))
        {
            if (p == lcde->cabeza)
            {
                if (p->siguiente == lcde->cabeza)
                {
                    lcde->cabeza = NULL;
                    jxlcd_borrarNodo(p, lcde->del);
                }
                else
                {
                    jxlcd_Nodo *q = lcde->cabeza->anterior;
                    q->anterior->siguiente = lcde->cabeza;
                    lcde->cabeza->anterior = q->anterior;
                    jxlcd_borrarNodo(q, lcde->del);
                }
            }
            else
            {
                jxlcd_Nodo *_p = p->anterior;

                if (_p == lcde->cabeza)
                {
                    jxlcd_Nodo *q = lcde->cabeza->anterior;
                    lcde->cabeza = lcde->cabeza->siguiente;
                    lcde->cabeza->anterior = q;
                    q->siguiente = lcde->cabeza;
                }
                else
                {
                    _p->anterior->siguiente = p;
                    p->anterior = _p->anterior;
                }

                jxlcd_borrarNodo(_p, lcde->del);
            }

            return true;
        }
    }

    return false;
}

bool jxlcd_eliminarDespuesDe(jxlcd_LCDE *lcde, void *x)
{
    if (!jxlcd_estaVacia(lcde))
    {
        jxlcd_Nodo *p = lcde->cabeza;

        while (p->siguiente != lcde->cabeza && lcde->cmp(p->dato, x))
            p = p->siguiente;

        if (!lcde->cmp(p->dato, x))
        {
            jxlcd_Nodo *p_ = p->siguiente;

            if (p->siguiente == lcde->cabeza)
            {
                if (p == lcde->cabeza)
                {
                    lcde->cabeza = NULL;
                    jxlcd_borrarNodo(p, lcde->del);
                }
                else
                {
                    lcde->cabeza = lcde->cabeza->siguiente;
                    lcde->cabeza->anterior = p;
                    p->siguiente = lcde->cabeza;
                    jxlcd_borrarNodo(p_, lcde->del);
                }
            }
            else
            {
                p->siguiente = p_->siguiente;
                p_->siguiente->anterior = p;
                jxlcd_borrarNodo(p_, lcde->del);
            }

            return true;
        }
    }

    return false;
}

bool jxlcd_eliminarEn(jxlcd_LCDE *lcde, void *x)
{
    if (!jxlcd_estaVacia(lcde))
    {
        jxlcd_Nodo *p = lcde->cabeza;

        while (p->siguiente != lcde->cabeza && lcde->cmp(p->dato, x))
            p = p->siguiente;

        if (!lcde->cmp(p->dato, x))
        {
            if (p == lcde->cabeza)
            {
                if (p->siguiente == lcde->cabeza)
                    lcde->cabeza = NULL;
                else
                {
                    jxlcd_Nodo *q = lcde->cabeza->anterior;
                    lcde->cabeza = lcde->cabeza->siguiente;
                    lcde->cabeza->anterior = q;
                    q->siguiente = lcde->cabeza;
                }
            }
            else
            {
                p->anterior->siguiente = p->siguiente;
                p->siguiente->anterior = p->anterior;
            }

            jxlcd_borrarNodo(p, lcde->del);

            return true;
        }
    }

    return false;
}

void *jxlcd_obtenerElPrimero(jxlcd_LCDE *lcde)
{
    if (!jxlcd_estaVacia(lcde))
        return lcde->cabeza->dato;

    return NULL;
}

void *jxlcd_obtenerElUltimo(jxlcd_LCDE *lcde)
{
    if (!jxlcd_estaVacia(lcde))
        return lcde->cabeza->anterior->dato;

    return NULL;
}

void *jxlcd_obtenerAntesDe(jxlcd_LCDE *lcde, void *x)
{
    if (!jxlcd_estaVacia(lcde))
    {
        jxlcd_Nodo *p = lcde->cabeza;

        while (p->siguiente != lcde->cabeza && lcde->cmp(p->dato, x))
            p = p->siguiente;

        if (!lcde->cmp(p->dato, x))
            return p->anterior->dato;
    }

    return NULL;
}

void *jxlcd_obtenerDespuesDe(jxlcd_LCDE *lcde, void *x)
{
    if (!jxlcd_estaVacia(lcde))
    {
        jxlcd_Nodo *p = lcde->cabeza;

        while (p->siguiente != lcde->cabeza && lcde->cmp(p->dato, x))
            p = p->siguiente;

        if (!lcde->cmp(p->dato, x))
            return p->siguiente->dato;
    }

    return NULL;
}

void *jxlcd_obtenerEn(jxlcd_LCDE *lcde, int posicion)
{
    if (!jxlcd_estaVacia(lcde))
    {
        jxlcd_Nodo *p = lcde->cabeza;
        int i = 0;

        while (p->siguiente != lcde->cabeza && i != posicion)
        {
            p = p->siguiente;
            i++;
        }

        if (i == posicion)
            return p->dato;
    }

    return NULL;
}

int jxlcd_buscar(jxlcd_LCDE *lcde, void *x)
{
    if (!jxlcd_estaVacia(lcde))
    {
        jxlcd_Nodo *p = lcde->cabeza;
        int i = 0;

        while (p->siguiente != lcde->cabeza && lcde->cmp(p->dato, x))
        {
            p = p->siguiente;
            i++;
        }

        if (!lcde->cmp(p->dato, x))
            return i;
    }

    return -1;
}

bool jxlcd_borrar(jxlcd_LCDE *lcde)
{
    if (!jxlcd_estaVacia(lcde))
    {
        jxlcd_Nodo *p;
        jxlcd_Nodo *q = lcde->cabeza->anterior;
        q->siguiente = NULL;

        do
        {
            p = lcde->cabeza;
            lcde->cabeza = lcde->cabeza->siguiente;
            jxlcd_borrarNodo(p, lcde->del);
        } while (lcde->cabeza != NULL);

        return true;
    }
    else
        return false;
}

void jxlcd_mostrar(jxlcd_LCDE *lcde)
{
    printf("LCDE => { ");

    if (!jxlcd_estaVacia(lcde))
    {
        jxlcd_Nodo *p = lcde->cabeza;
        char *txt;

        do
        {
            txt = lcde->str(p->dato);
            printf("%s -> ", txt);
            free(txt);
            p = p->siguiente;
        } while (p != lcde->cabeza);
    }

    puts(" }");
}

bool jxlcd_estaVacia(jxlcd_LCDE *lcde)
{
    return lcde->cabeza == NULL;
}