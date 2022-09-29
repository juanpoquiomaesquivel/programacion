#include "ABB.h"
#include "Libreria.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

jxab_Nodo *jxab_crearNodo(void *dato)
{
    jxab_Nodo *nuevo = (jxab_Nodo *)malloc(sizeof(jxab_Nodo));
    errorDeMemoria(nuevo);
    nuevo->dato = dato;
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
        raiz = jxab_crearNodo(dato);
    else
    {
        jxab_Nodo *p = *raiz;

        while (p != NULL)
        {
            if (p->hd == NULL && p->hi == NULL)
            {
                if (cmp(dato, p->dato) > 0)
                {
                    p->hd = jxab_crearNodo(dato);
                    p = NULL;
                } else
                {
                    p->hi = jxab_crearNodo(dato);
                    p = NULL;
                }
            }
        }
    }
}

bool jxab_estaVacio(jxab_Nodo *raiz)
{
    return raiz == NULL;
}