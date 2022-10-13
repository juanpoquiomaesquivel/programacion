#include "Cola.h"
#include "Libreria.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

jxc_Nodo *jxc_crearNodo(void *dato)
{
    jxc_Nodo *nuevo = (jxc_Nodo *)malloc(sizeof(jxc_Nodo));
    errorDeMemoria(nuevo);
    nuevo->dato = dato;
    nuevo->siguiente = NULL;

    return nuevo;
}

void jxc_borrarNodo(jxc_Nodo *nodo, void (*del)(void *p))
{
    if (del != NULL)
        del(nodo->dato);
    
    free(nodo);
}

void jxc_encolar(jxc_Cola *cola, void *dato)
{
    jxc_Nodo *nuevo = jxc_crearNodo(dato);

    if (jxc_estaVacia(cola))
        cola->cabeza = nuevo;
    else
    {
        jxc_Nodo *p = cola->cabeza;

        while (p->siguiente != NULL)
            p = p->siguiente;

        p->siguiente = nuevo;
    }
}

bool jxc_decolar(jxc_Cola *cola)
{
    if (!jxc_estaVacia(cola))
    {
        jxc_Nodo *p = cola->cabeza;
        cola->cabeza = cola->cabeza->siguiente;
        jxc_borrarNodo(p, cola->del);

        return true;
    }
    else
        return false;
}

void *jxc_frente(jxc_Cola *cola)
{
    if (!jxc_estaVacia(cola))
        return cola->cabeza->dato;
    else
        return NULL;
}

void *jx_ultimo(jxc_Cola *cola)
{
    if (!jxc_estaVacia(cola))
    {
        jxc_Nodo *p = cola->cabeza;

        while (p->siguiente != NULL)
            p = p->siguiente;

        return p->dato;
    }
    else
        return NULL;
}

bool jxc_borrar(jxc_Cola *cola)
{
    if (!jxc_estaVacia(cola))
    {
        jxc_Nodo *p;

        do
        {
            p = cola->cabeza;
            cola->cabeza = cola->cabeza->siguiente;
            jxc_borrarNodo(p, cola->del);
        } while (cola->cabeza != NULL);

        return true;
    }
    else
        return false;
}

void jxc_mostrar(jxc_Cola *cola)
{
    printf("COLA => { ");

    if (!jxc_estaVacia(cola))
    {
        jxc_Nodo *p = cola->cabeza;
        char *txt;

        do
        {
            txt = cola->str(p->dato);
            printf("%s -> ", txt);
            free(txt);
            p = p->siguiente;
        } while (p != NULL);
    }

    puts(" }");
}

bool jxc_estaVacia(jxc_Cola *cola)
{
    return cola->cabeza == NULL;
}