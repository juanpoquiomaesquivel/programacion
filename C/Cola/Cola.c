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
    del(nodo->dato);
    free(nodo);
}

void jxc_encolar(jxc_Nodo **cabeza, void *dato)
{
    jxc_Nodo *nuevo = jxc_crearNodo(dato);

    if (jxc_estaVacia(*cabeza))
        *cabeza = nuevo;
    else
    {
        jxc_Nodo *p = *cabeza;

        while (p->siguiente != NULL)
            p = p->siguiente;

        p->siguiente = nuevo;
    }
}

bool jxc_decolar(jxc_Nodo **cabeza, void (*del)(void *p))
{
    if (!jxc_estaVacia(*cabeza))
    {
        jxc_Nodo *p = *cabeza;
        *cabeza = (*cabeza)->siguiente;
        jxc_borrarNodo(p, del);

        return true;
    }

    return false;
}

void *jxc_frente(jxc_Nodo *cabeza)
{
    if (!jxc_estaVacia(cabeza))
        return cabeza->dato;
    else
        return NULL;
}

void *jx_ultimo(jxc_Nodo *cabeza)
{
    if (!jxc_estaVacia(cabeza))
    {
        jxc_Nodo *p = cabeza;

        while (p->siguiente != NULL)
            p = p->siguiente;

        return p->dato;
    }
    else
        return NULL;
}

bool jxc_borrar(jxc_Nodo **cabeza, void (*del)(void *p))
{
    if (!jxc_estaVacia(*cabeza))
    {
        jxc_Nodo *p;

        do
        {
            p = *cabeza;
            *cabeza = (*cabeza)->siguiente;
            jxc_borrarNodo(p, del);
        } while (*cabeza != NULL);

        return true;
    }

    return false;
}

void jxc_mostrar(jxc_Nodo *cabeza, char *(*str)(const void *p))
{
    printf("COLA => { ");

    if (!jxc_estaVacia(cabeza))
    {
        jxc_Nodo *p = cabeza;
        char *txt;

        do
        {
            txt = str(p->dato);
            printf("%s -> ", txt);
            free(txt);
            p = p->siguiente;
        } while (p != NULL);
    }

    puts(" }");
}

bool jxc_estaVacia(jxc_Nodo *cabeza)
{
    return cabeza == NULL;
}