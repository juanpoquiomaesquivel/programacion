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
    del(nodo->dato);
    free(nodo);
}

void jxlcs_insertarAlInicio(jxlcs_Nodo **cabeza, void *dato)
{
    jxlcs_Nodo *nuevo = jxlcs_crearNodo(dato);

    if (jxlcs_estaVacia(*cabeza))
    {
        *cabeza = nuevo;
        (*cabeza)->siguiente = *cabeza;
    }
    else
    {
        jxlcs_Nodo *p = *cabeza;

        while (p->siguiente != *cabeza)
            p = p->siguiente;

        nuevo->siguiente = *cabeza;
        *cabeza = nuevo;
        p->siguiente = *cabeza;
    }
}

void jxlcs_insertarAlFinal(jxlcs_Nodo **cabeza, void *dato)
{
    jxlcs_Nodo *nuevo = jxlcs_crearNodo(dato);

    if (jxlcs_estaVacia(*cabeza))
    {
        *cabeza = nuevo;
        (*cabeza)->siguiente = *cabeza;
    }
    else
    {
        jxlcs_Nodo *p = *cabeza;

        while (p->siguiente != *cabeza)
            p = p->siguiente;

        p->siguiente = nuevo;
        nuevo->siguiente = *cabeza;
    }
}

bool jxlcs_insertarAntesDe(jxlcs_Nodo **cabeza, void *dato, void *x, bool (*cmp)(const void *p, const void *q))
{
    if (!jxlcs_estaVacia(*cabeza))
    {
        jxlcs_Nodo *p = *cabeza;
        jxlcs_Nodo *_p = NULL;

        while (p->siguiente != *cabeza && !cmp(p->dato, x))
        {
            _p = p;
            p = p->siguiente;
        }

        if (cmp(p->dato, x))
        {
            jxlcs_Nodo *nuevo = jxlcs_crearNodo(dato);

            if (p == *cabeza)
            {
                jxlcs_Nodo *q = *cabeza;

                while (q->siguiente != *cabeza)
                    q = q->siguiente;

                nuevo->siguiente = *cabeza;
                *cabeza = nuevo;
                q->siguiente = *cabeza;
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

bool jxlcs_insertarDespuesDe(jxlcs_Nodo **cabeza, void *dato, void *x, bool (*cmp)(const void *p, const void *q))
{
    if (!jxlcs_estaVacia(*cabeza))
    {
        jxlcs_Nodo *p = *cabeza;

        while (p->siguiente != *cabeza && !cmp(p->dato, x))
            p = p->siguiente;

        if (cmp(p->dato, x))
        {
            jxlcs_Nodo *nuevo = jxlcs_crearNodo(dato);

            if (p->siguiente == *cabeza)
            {
                p->siguiente = nuevo;
                nuevo->siguiente = *cabeza;
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

bool jxlcs_reemplazarEn(jxlcs_Nodo *cabeza, void *dato, void *x, void (*del)(void *p), bool (*cmp)(const void *p, const void *q))
{
    if (!jxlcs_estaVacia(cabeza))
    {
        jxlcs_Nodo *p = cabeza;

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

bool jxlcs_eliminarElPrimero(jxlcs_Nodo **cabeza, void (*del)(void *p))
{
    if (!jxlcs_estaVacia(*cabeza))
    {
        jxlcs_Nodo *p = *cabeza;

        if ((*cabeza)->siguiente == *cabeza)
            *cabeza = NULL;
        else
        {
            jxlcs_Nodo *q = *cabeza;

            while (q->siguiente != *cabeza)
                q = q->siguiente;

            *cabeza = (*cabeza)->siguiente;
            q->siguiente = *cabeza;
        }

        jxlcs_borrarNodo(p, del);

        return true;
    }
    else
        return false;
}

bool jxlcs_eliminarElUltimo(jxlcs_Nodo **cabeza, void (*del)(void *p))
{
    if (!jxlcs_estaVacia(*cabeza))
    {
        jxlcs_Nodo *p = *cabeza;
        jxlcs_Nodo *_p = NULL;

        while (p->siguiente != *cabeza)
        {
            _p = p;
            p = p->siguiente;
        }

        if (p == *cabeza)
            *cabeza = NULL;
        else
            _p->siguiente = *cabeza;

        jxlcs_borrarNodo(p, del);

        return true;
    }
    else
        return false;
}

bool jxlcs_eliminarAntesDe(jxlcs_Nodo **cabeza, void *x, void (*del)(void *p), bool (*cmp)(const void *p, const void *q))
{
    if (!jxlcs_estaVacia(*cabeza))
    {
        jxlcs_Nodo *p = *cabeza;
        jxlcs_Nodo *_p = NULL;
        jxlcs_Nodo *__p = NULL;

        while (p->siguiente != *cabeza && !cmp(p->dato, x))
        {
            __p = _p;
            _p = p;
            p = p->siguiente;
        }

        if (cmp(p->dato, x))
        {
            if (p == *cabeza)
            {
                if (p->siguiente == *cabeza)
                {
                    *cabeza = NULL;
                    jxlcs_borrarNodo(p, del);
                }
                else
                {
                    jxlcs_Nodo *q = *cabeza;
                    jxlcs_Nodo *_q = NULL;

                    while (q->siguiente != *cabeza)
                    {
                        _q = q;
                        q = q->siguiente;
                    }

                    _q->siguiente = *cabeza;
                    jxlcs_borrarNodo(q, del);
                }
            }
            else
            {
                if (_p == *cabeza)
                {
                    jxlcs_Nodo *q = *cabeza;

                    while (q->siguiente != *cabeza)
                        q = q->siguiente;

                    *cabeza = (*cabeza)->siguiente;
                    q->siguiente = *cabeza;
                }
                else
                    __p->siguiente = p;

                jxlcs_borrarNodo(_p, del);
            }

            return true;
        }
    }

    return false;
}

bool jxlcs_eliminarDespuesDe(jxlcs_Nodo **cabeza, void *x, void (*del)(void *p), bool (*cmp)(const void *p, const void *q))
{
    if (!jxlcs_estaVacia(*cabeza))
    {
        jxlcs_Nodo *p = *cabeza;

        while (p->siguiente != *cabeza && !cmp(p->dato, x))
            p = p->siguiente;

        if (cmp(p->dato, x))
        {
            jxlcs_Nodo *p_ = p->siguiente;

            if (p->siguiente == *cabeza)
            {
                if (p == *cabeza)
                {
                    *cabeza = NULL;
                    jxlcs_borrarNodo(p, del);
                }
                else
                {
                    *cabeza = (*cabeza)->siguiente;
                    p->siguiente = *cabeza;
                    jxlcs_borrarNodo(p_, del);
                }
            }
            else
            {
                p->siguiente = p_->siguiente;
                jxlcs_borrarNodo(p_, del);
            }

            return true;
        }
    }

    return false;
}

bool jxlcs_eliminarEn(jxlcs_Nodo **cabeza, void *x, void (*del)(void *p), bool (*cmp)(const void *p, const void *q))
{
    if (!jxlcs_estaVacia(*cabeza))
    {
        jxlcs_Nodo *p = *cabeza;
        jxlcs_Nodo *_p = NULL;

        while (p->siguiente != *cabeza && !cmp(p->dato, x))
        {
            _p = p;
            p = p->siguiente;
        }

        if (cmp(p->dato, x))
        {
            if (p == *cabeza)
            {
                if (p->siguiente == *cabeza)
                    *cabeza = NULL;
                else
                {
                    jxlcs_Nodo *q = *cabeza;

                    while (q->siguiente != *cabeza)
                        q = q->siguiente;

                    *cabeza = (*cabeza)->siguiente;
                    q->siguiente = *cabeza;
                }
            }
            else
                _p->siguiente = p->siguiente;

            jxlcs_borrarNodo(p, del);

            return true;
        }
    }

    return false;
}

void *jxlcs_obtenerElPrimero(jxlcs_Nodo *cabeza)
{
    if (!jxlcs_estaVacia(cabeza))
        return cabeza->dato;

    return NULL;
}

void *jxlcs_obtenerElUltimo(jxlcs_Nodo *cabeza)
{
    if (!jxlcs_estaVacia(cabeza))
    {
        jxlcs_Nodo *p = cabeza;

        while (p->siguiente != cabeza)
            p = p->siguiente;

        return p->dato;
    }

    return NULL;
}

void *jxlcs_obtenerAntesDe(jxlcs_Nodo *cabeza, void *x, bool (*cmp)(const void *p, const void *q))
{
    if (!jxlcs_estaVacia(cabeza))
    {
        jxlcs_Nodo *p = cabeza;
        jxlcs_Nodo *_p = NULL;

        while (p->siguiente != cabeza && !cmp(p->dato, x))
        {
            _p = p;
            p = p->siguiente;
        }

        if (cmp(p->dato, x))
        {
            if (p == cabeza)
            {
                jxlcs_Nodo *q = cabeza;

                while (q->siguiente != cabeza)
                    q = q->siguiente;

                return q->dato;
            }
            else
                return _p->dato;
        }
    }

    return NULL;
}

void *jxlcs_obtenerDespuesDe(jxlcs_Nodo *cabeza, void *x, bool (*cmp)(const void *p, const void *q))
{
    if (!jxlcs_estaVacia(cabeza))
    {
        jxlcs_Nodo *p = cabeza;

        while (p->siguiente != cabeza && !cmp(p->dato, x))
            p = p->siguiente;

        if (cmp(p->dato, x))
            return p->siguiente->dato;
    }

    return NULL;
}

void *jxlcs_obtenerEn(jxlcs_Nodo *cabeza, int posicion)
{
    if (!jxlcs_estaVacia(cabeza))
    {
        jxlcs_Nodo *p = cabeza;
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

int jxlcs_buscar(jxlcs_Nodo *cabeza, void *x, bool (*cmp)(const void *p, const void *q))
{
    if (!jxlcs_estaVacia(cabeza))
    {
        jxlcs_Nodo *p = cabeza;
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

bool jxlcs_borrar(jxlcs_Nodo **cabeza, void (*del)(void *p))
{
    if (!jxlcs_estaVacia(*cabeza))
    {
        jxlcs_Nodo *p;
        jxlcs_Nodo *q = *cabeza;

        while (q->siguiente != *cabeza)
            q = q->siguiente;

        q->siguiente = NULL;

        do
        {
            p = *cabeza;
            *cabeza = (*cabeza)->siguiente;
            jxlcs_borrarNodo(p, del);
        } while (*cabeza != NULL);

        return true;
    }
    else
        return false;
}

void jxlcs_mostrar(jxlcs_Nodo *cabeza, char *(*str)(const void *p))
{
    printf("LCSE => { ");

    if (!jxlcs_estaVacia(cabeza))
    {
        jxlcs_Nodo *p = cabeza;
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

bool jxlcs_estaVacia(jxlcs_Nodo *cabeza)
{
    return cabeza == NULL;
}