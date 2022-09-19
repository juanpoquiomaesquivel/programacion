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
    del(nodo->dato);
    free(nodo);
}

void jxlcd_insertarAlInicio(jxlcd_Nodo **cabeza, void *dato)
{
    jxlcd_Nodo *nuevo = jxlcd_crearNodo(dato);

    if (jxlcd_estaVacia(*cabeza))
    {
        *cabeza = nuevo;
        (*cabeza)->anterior = *cabeza;
        (*cabeza)->siguiente = *cabeza;
    }
    else
    {
        jxlcd_Nodo *p = (*cabeza)->anterior;
        nuevo->anterior = p;
        nuevo->siguiente = *cabeza;
        (*cabeza)->anterior = nuevo;
        *cabeza = nuevo;
        p->siguiente = *cabeza;
    }
}

void jxlcd_insertarAlFinal(jxlcd_Nodo **cabeza, void *dato)
{
    jxlcd_Nodo *nuevo = jxlcd_crearNodo(dato);

    if (jxlcd_estaVacia(*cabeza))
    {
        *cabeza = nuevo;
        (*cabeza)->anterior = *cabeza;
        (*cabeza)->siguiente = *cabeza;
    }
    else
    {
        jxlcd_Nodo *p = (*cabeza)->anterior;
        (*cabeza)->anterior = nuevo;
        p->siguiente = nuevo;
        nuevo->anterior = p;
        nuevo->siguiente = *cabeza;
    }
}

bool jxlcd_insertarAntesDe(jxlcd_Nodo **cabeza, void *dato, void *x, bool (*cmp)(const void *p, const void *q))
{
    if (!jxlcd_estaVacia(*cabeza))
    {
        jxlcd_Nodo *p = *cabeza;

        while (p->siguiente != *cabeza && !cmp(p->dato, x))
            p = p->siguiente;

        if (cmp(p->dato, x))
        {
            jxlcd_Nodo *nuevo = jxlcd_crearNodo(dato);

            if (p == *cabeza)
            {
                jxlcd_Nodo *q = (*cabeza)->anterior;
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

            return true;
        }
    }

    return false;
}

bool jxlcd_insertarDespuesDe(jxlcd_Nodo **cabeza, void *dato, void *x, bool (*cmp)(const void *p, const void *q))
{
    if (!jxlcd_estaVacia(*cabeza))
    {
        jxlcd_Nodo *p = *cabeza;

        while (p->siguiente != *cabeza && !cmp(p->dato, x))
            p = p->siguiente;

        if (cmp(p->dato, x))
        {
            jxlcd_Nodo *nuevo = jxlcd_crearNodo(dato);

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

            return true;
        }
    }

    return false;
}

bool jxlcd_reemplazarEn(jxlcd_Nodo *cabeza, void *dato, void *x, void (*del)(void *p), bool (*cmp)(const void *p, const void *q))
{
    if (!jxlcd_estaVacia(cabeza))
    {
        jxlcd_Nodo *p = cabeza;

        while (p->siguiente != cabeza && !cmp(p->dato, x))
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

bool jxlcd_eliminarElPrimero(jxlcd_Nodo **cabeza, void (*del)(void *p))
{
    if (!jxlcd_estaVacia(*cabeza))
    {
        jxlcd_Nodo *p = *cabeza;

        if ((*cabeza)->siguiente == *cabeza)
            *cabeza = NULL;
        else
        {
            jxlcd_Nodo *q = (*cabeza)->anterior;
            *cabeza = (*cabeza)->siguiente;
            (*cabeza)->anterior = q;
            q->siguiente = *cabeza;
        }

        jxlcd_borrarNodo(p, del);

        return true;
    }
    else
        return false;
}

bool jxlcd_eliminarElUltimo(jxlcd_Nodo **cabeza, void (*del)(void *p))
{
    if (!jxlcd_estaVacia(*cabeza))
    {
        jxlcd_Nodo *p = (*cabeza)->anterior;

        if (p == *cabeza)
            *cabeza = NULL;
        else
        {
            (*cabeza)->anterior = p->anterior;
            p->anterior->siguiente = *cabeza;
        }

        free(p->dato);
        jxlcd_borrarNodo(p, del);
        
        return true;
    }
    else
        return false;
}

bool jxlcd_eliminarAntesDe(jxlcd_Nodo **cabeza, void *x, void (*del)(void *p), bool (*cmp)(const void *p, const void *q))
{
    if (!jxlcd_estaVacia(*cabeza))
    {
        jxlcd_Nodo *p = *cabeza;

        while (p->siguiente != *cabeza && !cmp(p->dato, x))
            p = p->siguiente;

        if (cmp(p->dato, x))
        {
            if (p == *cabeza)
            {
                if (p->siguiente == *cabeza)
                {
                    *cabeza = NULL;
                    jxlcd_borrarNodo(p, del);
                }
                else
                {
                    jxlcd_Nodo *q = (*cabeza)->anterior;
                    q->anterior->siguiente = *cabeza;
                    (*cabeza)->anterior = q->anterior;
                    jxlcd_borrarNodo(q, del);
                }
            }
            else
            {
                jxlcd_Nodo *_p = p->anterior;

                if (_p == *cabeza)
                {
                    jxlcd_Nodo *q = (*cabeza)->anterior;
                    *cabeza = (*cabeza)->siguiente;
                    (*cabeza)->anterior = q;
                    q->siguiente = *cabeza;
                }
                else
                {
                    _p->anterior->siguiente = p;
                    p->anterior = _p->anterior;
                }

                jxlcd_borrarNodo(_p, del);
            }

            return true;
        }
    }

    return false;
}

bool jxlcd_eliminarDespuesDe(jxlcd_Nodo **cabeza, void *x, void (*del)(void *p), bool (*cmp)(const void *p, const void *q))
{
    if (!jxlcd_estaVacia(*cabeza))
    {
        jxlcd_Nodo *p = *cabeza;

        while (p->siguiente != *cabeza && !cmp(p->dato, x))
            p = p->siguiente;

        if (cmp(p->dato, x))
        {
            jxlcd_Nodo *p_ = p->siguiente;

            if (p->siguiente == *cabeza)
            {
                if (p == *cabeza)
                {
                    *cabeza = NULL;
                    jxlcd_borrarNodo(p, del);
                }
                else
                {
                    *cabeza = (*cabeza)->siguiente;
                    (*cabeza)->anterior = p;
                    p->siguiente = *cabeza;
                    jxlcd_borrarNodo(p_, del);
                }
            }
            else
            {
                p->siguiente = p_->siguiente;
                p_->siguiente->anterior = p;
                jxlcd_borrarNodo(p_, del);
            }

            return true;
        }
    }

    return false;
}

bool jxlcd_eliminarEn(jxlcd_Nodo **cabeza, void *x, void (*del)(void *p), bool (*cmp)(const void *p, const void *q))
{
    if (!jxlcd_estaVacia(*cabeza))
    {
        jxlcd_Nodo *p = *cabeza;

        while (p->siguiente != *cabeza && !cmp(p->dato, x))
            p = p->siguiente;

        if (cmp(p->dato, x))
        {
            if (p == *cabeza)
            {
                if (p->siguiente == *cabeza)
                    *cabeza = NULL;
                else
                {
                    jxlcd_Nodo *q = (*cabeza)->anterior;
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

            jxlcd_borrarNodo(p, del);

            return true;
        }
    }

    return false;
}

void *jxlcd_obtenerElPrimero(jxlcd_Nodo *cabeza)
{
    if (!jxlcd_estaVacia(cabeza))
        return cabeza->dato;

    return NULL;
}

void *jxlcd_obtenerElUltimo(jxlcd_Nodo *cabeza)
{
    if (!jxlcd_estaVacia(cabeza))
        return cabeza->anterior->dato;

    return NULL;
}

void *jxlcd_obtenerAntesDe(jxlcd_Nodo *cabeza, void *x, bool (*cmp)(const void *p, const void *q))
{
    if (!jxlcd_estaVacia(cabeza))
    {
        jxlcd_Nodo *p = cabeza;

        while (p->siguiente != cabeza && !cmp(p->dato, x))
            p = p->siguiente;

        if (cmp(p->dato, x))
            return p->anterior->dato;
    }

    return NULL;
}

void *jxlcd_obtenerDespuesDe(jxlcd_Nodo *cabeza, void *x, bool (*cmp)(const void *p, const void *q))
{
    if (!jxlcd_estaVacia(cabeza))
    {
        jxlcd_Nodo *p = cabeza;

        while (p->siguiente != cabeza && !cmp(p->dato, x))
            p = p->siguiente;

        if (cmp(p->dato, x))
            return p->siguiente->dato;
    }

    return NULL;
}

void *jxlcd_obtenerEn(jxlcd_Nodo *cabeza, int posicion)
{
    if (!jxlcd_estaVacia(cabeza))
    {
        jxlcd_Nodo *p = cabeza;
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

int jxlcd_buscar(jxlcd_Nodo *cabeza, void *x, bool (*cmp)(const void *p, const void *q))
{
    if (!jxlcd_estaVacia(cabeza))
    {
        jxlcd_Nodo *p = cabeza;
        int i = 0;

        while (p->siguiente != cabeza && !cmp(p->dato, x))
        {
            p = p->siguiente;
            i++;
        }

        if (cmp(p->dato, x))
            return i;
    }

    return -1;
}

bool jxlcd_borrar(jxlcd_Nodo **cabeza, void (*del)(void *p))
{
    if (!jxlcd_estaVacia(*cabeza))
    {
        jxlcd_Nodo *p;
        jxlcd_Nodo *q = (*cabeza)->anterior;
        q->siguiente = NULL;

        do
        {
            p = *cabeza;
            *cabeza = (*cabeza)->siguiente;
            jxlcd_borrarNodo(p, del);
        } while (*cabeza != NULL);

        return true;
    }
    else
        return false;
}

void jxlcd_mostrar(jxlcd_Nodo *cabeza, char *(*str)(const void *p))
{
    printf("LCDE => { ");

    if (!jxlcd_estaVacia(cabeza))
    {
        jxlcd_Nodo *p = cabeza;
        char *txt;

        do
        {
            txt = str(p->dato);
            printf("%s -> ", txt);
            free(txt);
            p = p->siguiente;
        } while (p != cabeza);
    }

    puts(" }");
}

bool jxlcd_estaVacia(jxlcd_Nodo *cabeza)
{
    return cabeza == NULL;
}