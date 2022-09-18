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

void jxp_borrarNodo(jxp_Nodo *nodo, void (*func)(void *p))
{
    func(nodo->dato);
    free(nodo);
}

void jxp_empilar(jxp_Nodo **tope, void *dato)
{
    jxp_Nodo *nuevo = jxp_crearNodo(dato);

    if (!jxp_estaVacia(*tope))
        nuevo->abajo = *tope;

    *tope = nuevo;
}

bool jxp_depilar(jxp_Nodo **tope, void (*del)(void *p))
{
    if (!jxp_estaVacia(*tope))
    {
        jxp_Nodo *p = *tope;
        *tope = (*tope)->abajo;
        jxp_borrarNodo(p, del);

        return true;
    }

    return false;
}

void *jxp_cima(jxp_Nodo *tope)
{
    if (!jxp_estaVacia(tope))
        return tope->dato;
    else
        return NULL;
}

bool jxp_borrar(jxp_Nodo **tope, void (*del)(void *p))
{
    if (!jxp_estaVacia(*tope))
    {
        jxp_Nodo *p;

        do
        {
            p = *tope;
            *tope = (*tope)->abajo;
            jxp_borrarNodo(p, del);
        } while (*tope != NULL);

        return true;
    }

    return false;
}

void jxp_mostrar(jxp_Nodo *tope, char *(*str)(const void *p))
{
    printf("PILA => { ");

    if (!jxp_estaVacia(tope))
    {
        jxp_Nodo *p = tope;
        char *txt;

        do
        {
            txt = str(p->dato);
            printf("%s -> ", txt);
            free(txt);
            p = p->abajo;
        } while (p != NULL);
    }

    puts(" }");
}

bool jxp_estaVacia(jxp_Nodo *tope)
{
    return tope == NULL;
}