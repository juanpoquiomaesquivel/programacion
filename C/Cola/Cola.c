#include "Cola.h"
#include "Libreria.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

jxc_Nodo *jxc_crearNodo(T dato)
{
    jxc_Nodo *nuevo = (jxc_Nodo *)malloc(sizeof(jxc_Nodo));
    errorDeMemoria(nuevo);
    nuevo->dato = dato;
    nuevo->siguiente = NULL;

    return nuevo;
}

void jxc_encolar(jxc_Nodo **cabeza, T dato)
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

bool jxc_decolar(jxc_Nodo **cabeza)
{
    if (!jxc_estaVacia(*cabeza))
    {
        jxc_Nodo *p = *cabeza;
        *cabeza = (*cabeza)->siguiente;
        free(p->dato);
        free(p);

        return true;
    }

    return false;
}

T jxc_frente(jxc_Nodo *cabeza)
{
    if (!jxc_estaVacia(cabeza))
        return cabeza->dato;
    else
        return NULL;
}

T jx_ultimo(jxc_Nodo *cabeza)
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

bool jxc_borrar(jxc_Nodo **cabeza)
{
    if (!jxc_estaVacia(*cabeza))
    {
        jxc_Nodo *p;

        do
        {
            p = *cabeza;
            *cabeza = (*cabeza)->siguiente;
            free(p->dato);
            free(p);
        } while (*cabeza != NULL);

        return true;
    }

    return false;
}

void jxc_mostrar(jxc_Nodo *cabeza)
{
    printf("COLA => { ");

    if (!jxc_estaVacia(cabeza))
    {
        jxc_Nodo *p = cabeza;

        do
        {
            printf("%d -> ", *(E *)(p->dato));
            p = p->siguiente;
        } while (p != NULL);
    }

    puts(" }");
}

bool jxc_estaVacia(jxc_Nodo *cabeza)
{
    return cabeza == NULL;
}