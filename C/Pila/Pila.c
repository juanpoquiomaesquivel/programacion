#include "Pila.h"
#include "Libreria.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

jxp_Nodo *jxp_crearNodo(T dato)
{
    jxp_Nodo *nuevo = (jxp_Nodo *)malloc(sizeof(jxp_Nodo));
    errorDeMemoria(nuevo);
    nuevo->dato = dato;
    nuevo->abajo = NULL;

    return nuevo;
}

void jxp_empilar(jxp_Nodo **tope, T dato)
{
    jxp_Nodo *nuevo = jxp_crearNodo(dato);

    if (!jxp_estaVacia(*tope))
        nuevo->abajo = *tope;

    *tope = nuevo;
}

bool jxp_depilar(jxp_Nodo **tope)
{
    if (!jxp_estaVacia(*tope))
    {
        jxp_Nodo *p = *tope;
        *tope = (*tope)->abajo;
        free(p->dato);
        free(p);

        return true;
    }
    
    return false;
}

T jxp_cima(jxp_Nodo *tope)
{
    if (!jxp_estaVacia(tope))
        return tope->dato;
    else
        return NULL;
}

bool jxp_borrar(jxp_Nodo **tope)
{
    if (!jxp_estaVacia(*tope))
    {
        jxp_Nodo *p;

        do
        {
            p = *tope;
            *tope = (*tope)->abajo;
            free(p->dato);
            free(p);
        } while (*tope != NULL);

        return true;
    }

    return false;
}

void jxp_mostrar(jxp_Nodo *tope)
{
    printf("PILA => { ");

    if (!jxp_estaVacia(tope))
    {
        jxp_Nodo *p = tope;

        do
        {
            printf("%d -> ", *(E *)(p->dato));
            p = p->abajo;
        } while (p != NULL);
    }

    puts(" }");
}

bool jxp_estaVacia(jxp_Nodo *tope)
{
    return tope == NULL;
}