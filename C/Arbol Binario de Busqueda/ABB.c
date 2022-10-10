#include "ABB.h"
#include "Libreria.h"
#include "Pila.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

jxab_Nodo *jxab_crearNodo(void *dato)
{
    jxab_Nodo *nuevo = (jxab_Nodo *)malloc(sizeof(jxab_Nodo));
    errorDeMemoria(nuevo);
    nuevo->dato = dato;
    nuevo->padre = NULL;
    nuevo->hi = NULL;
    nuevo->hd = NULL;

    return nuevo;
}

void jxab_borrarNodo(jxab_Nodo *nodo, void (*del)(void *p))
{
    del(nodo->dato);
    free(nodo);
}

bool jxab_insertar(jxab_Nodo **raiz, void *dato, int (*cmp)(const void *p, const void *q))
{
    if (jxab_estaVacio(*raiz))
        *raiz = jxab_crearNodo(dato);
    else
    {
        jxab_Nodo *p = *raiz;
        jxab_Nodo *padre = NULL;
        int flag = 0;

        do
        {
            padre = p;
            flag = cmp(dato, p->dato);

            if (flag < 0)
                p = p->hi;
            else if (flag > 0)
                p = p->hd;
        } while (p != NULL && flag);

        if (flag)
        {
            jxab_Nodo *nuevo = jxab_crearNodo(dato);

            if (flag < 0)
                padre->hi = nuevo;
            else
                padre->hd = nuevo;
        }
    }
}

bool jxab_buscar(jxab_Nodo *raiz, void *dato, int (*cmp)(const void *p, const void *q))
{
    jxab_Nodo *p = raiz;
    int flag = 0;

    while (p != NULL)
    {
        flag = cmp(dato, p->dato);

        if (flag < 0)
            p = p->hi;
        else if (flag > 0)
            p = p->hd;
        else
            return true;
    }

    return false;
}

bool jxab_reemplazar(jxab_Nodo **raiz, void *dato, int (*cmp)(const void *p, const void *q), void (*del)(void *p))
{
    jxab_Nodo *p = *raiz;
    int flag = 0;

    while (p != NULL)
    {
        flag = cmp(dato, p->dato);

        if (flag < 0)
            p = p->hi;
        else if (flag > 0)
            p = p->hd;
        else
        {
            del(p->dato);
            p->dato = dato;

            return true;
        }
    }

    return false;
}

bool jxab_borrar(jxab_Nodo **raiz, void (*del)(void *p))
{
    if (!jxab_estaVacio(*raiz))
    {
        jxab_Nodo *p = *raiz;
        jxp_Pila pila = {.del = NULL, .str = NULL, .tope = NULL};
        jxp_empilar(&pila, p);

        do {
            p = jxp_cima(&pila);
            jxp_depilar(&pila);

            if (p->hd != NULL)
                jxp_empilar(&pila, p->hd);
            
            if (p->hi != NULL)
                jxp_empilar(&pila, p->hi);

            p->padre = NULL;
            p->hi = NULL;
            p->hd = NULL;

            jxab_borrarNodo(p, del);
        } while (!jxp_estaVacia(&pila));

        *raiz = NULL;

        return true;
    }
    else
        return false;
}

void jxab_preOrden(jxab_Nodo *raiz, char *(*str)(const void *p))
{
    if (!jxab_estaVacio(raiz))
    {
        preorden(raiz, str);
        puts("");
    }
}

void jxab_inOrden(jxab_Nodo *raiz, char *(*str)(const void *p))
{
    if (!jxab_estaVacio(raiz))
    {
        inorden(raiz, str);
        puts("");
    }
}

void jxab_posOrden(jxab_Nodo *raiz, char *(*str)(const void *p))
{
    if (!jxab_estaVacio(raiz))
    {
        posorden(raiz, str);
        puts("");
    }
}

void preorden(jxab_Nodo *nodo, char *(*str)(const void *p))
{
    if (nodo != NULL)
    {
        char *txt = str(nodo->dato);

        printf("%s -> ", txt);
        free(txt);
        preorden(nodo->hi, str);
        preorden(nodo->hd, str);
    }
}

void inorden(jxab_Nodo *nodo, char *(*str)(const void *p))
{
    if (nodo != NULL)
    {
        char *txt = str(nodo->dato);

        inorden(nodo->hi, str);
        printf("%s -> ", txt);
        free(txt);
        inorden(nodo->hd, str);
    }
}

void posorden(jxab_Nodo *nodo, char *(*str)(const void *p))
{
    if (nodo != NULL)
    {
        char *txt = str(nodo->dato);

        posorden(nodo->hi, str);
        posorden(nodo->hd, str);
        printf("%s -> ", txt);
        free(txt);
    }
}

bool jxab_estaVacio(jxab_Nodo *raiz)
{
    return raiz == NULL;
}