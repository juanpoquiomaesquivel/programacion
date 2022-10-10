#include "Pila.h"
#include "Libreria.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

jxp_Nodo *jxp_crearNodo(void *dato)
{
    jxp_Nodo *nuevo = (jxp_Nodo *)malloc(sizeof(jxp_Nodo));
    errorDeMemoria(nuevo);
    nuevo->dato = dato;
    nuevo->abajo = NULL;

    return nuevo;
}

void jxp_borrarNodo(jxp_Nodo *nodo, void (*del)(void *p))
{
    if (del != NULL)
        del(nodo->dato);

    free(nodo);
}

void jxp_empilar(jxp_Pila *pila, void *dato)
{
    jxp_Nodo *nuevo = jxp_crearNodo(dato);

    if (!jxp_estaVacia(pila))
        nuevo->abajo = pila->tope;

    pila->tope = nuevo;
}

bool jxp_depilar(jxp_Pila *pila)
{
    if (!jxp_estaVacia(pila))
    {
        jxp_Nodo *p = pila->tope;
        pila->tope = pila->tope->abajo;
        jxp_borrarNodo(p, pila->del);

        return true;
    }
    else
        return false;
}

void *jxp_cima(jxp_Pila *pila)
{
    if (!jxp_estaVacia(pila))
        return pila->tope->dato;
    else
        return NULL;
}

bool jxp_borrar(jxp_Pila *pila)
{
    if (!jxp_estaVacia(pila))
    {
        jxp_Nodo *p;

        do
        {
            p = pila->tope;
            pila->tope = pila->tope->abajo;
            jxp_borrarNodo(p, pila->del);
        } while (pila->tope != NULL);

        return true;
    }
    else
        return false;
}

void jxp_mostrar(jxp_Pila *pila)
{
    printf("PILA => { ");

    if (!jxp_estaVacia(pila))
    {
        jxp_Nodo *p = pila->tope;
        char *txt;

        do
        {
            txt = pila->str(p->dato);
            printf("%s -> ", txt);
            free(txt);
            p = p->abajo;
        } while (p != NULL);
    }

    puts(" }");
}

bool jxp_estaVacia(jxp_Pila *pila)
{
    return pila->tope == NULL;
}