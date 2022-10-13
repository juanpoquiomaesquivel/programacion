#include "ABB.h"
#include "Cola.h"
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
    if (del != NULL)
        del(nodo->dato);

    free(nodo);
}

bool jxab_insertar(jxab_ABB *abb, void *dato)
{
    if (jxab_estaVacio(abb))
        abb->raiz = jxab_crearNodo(dato);
    else
    {
        jxab_Nodo *p = abb->raiz;
        jxab_Nodo *padre = NULL;
        int flag = 0;

        do
        {
            padre = p;
            flag = abb->cmp(dato, p->dato);

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

            nuevo->padre = padre;
        }
    }
}

bool jxab_buscar(jxab_ABB *abb, void *x)
{
    jxab_Nodo *p = abb->raiz;
    int flag = 0;

    while (p != NULL)
    {
        flag = abb->cmp(x, p->dato);

        if (flag < 0)
            p = p->hi;
        else if (flag > 0)
            p = p->hd;
        else
            return true;
    }

    return false;
}

bool jxab_reemplazar(jxab_ABB *abb, void *dato, void *x)
{
    jxab_Nodo *p = abb->raiz;
    int flag = 0;

    while (p != NULL)
    {
        flag = abb->cmp(x, p->dato);

        if (flag < 0)
            p = p->hi;
        else if (flag > 0)
            p = p->hd;
        else
        {
            abb->del(p->dato);
            p->dato = dato;

            return true;
        }
    }

    return false;
}

void jxab_preorden(jxab_ABB *abb)
{
    printf("ABB:PREORDEN { ");

    if (!jxab_estaVacio(abb))
    {
        jxab_Nodo *p = abb->raiz;
        jxp_Pila pila = {.del = NULL, .str = NULL, .tope = NULL};
        jxp_empilar(&pila, p);
        char *txt;

        do
        {
            p = jxp_cima(&pila);
            jxp_depilar(&pila);
            txt = abb->str(p->dato);
            printf("%s -> ", txt);
            free(txt);

            if (p->hd != NULL)
                jxp_empilar(&pila, p->hd);
            
            if (p->hi != NULL)
                jxp_empilar(&pila, p->hi);
        } while (!jxp_estaVacia(&pila));
    }

    puts(" }");
}

void jxab_inorden(jxab_ABB *abb)
{
    printf("ABB:INORDEN { ");

    if (!jxab_estaVacio(abb))
    {
        jxab_Nodo *p = abb->raiz;
        jxp_Pila pila = {.del = NULL, .str = NULL, .tope = NULL};
        char *txt;

        do
        {
            while (p != NULL)
            {
                jxp_empilar(&pila, p);
                p = p->hi;
            }

            p = jxp_cima(&pila);
            jxp_depilar(&pila);
            txt = abb->str(p->dato);
            printf("%s -> ", txt);
            free(txt);
            p = p->hd;
        } while (p != NULL || !jxp_estaVacia(&pila));
    }

    puts(" }");
}

void jxab_posorden(jxab_ABB *abb)
{
    printf("ABB:POSORDEN { ");

    if (!jxab_estaVacio(abb))
    {
        jxab_Nodo *p = abb->raiz;
        jxp_Pila pila1 = {.del = NULL, .str = NULL, .tope = NULL};
        jxp_Pila pila2 = {.del = NULL, .str = NULL, .tope = NULL};
        jxp_empilar(&pila1, p);
        char *txt;

        do
        {
            p = jxp_cima(&pila1);
            jxp_depilar(&pila1);
            jxp_empilar(&pila2, p);

            if (p->hi != NULL)
                jxp_empilar(&pila1, p->hi);
            
            if (p->hd != NULL)
                jxp_empilar(&pila1, p->hd);
        } while (!jxp_estaVacia(&pila1));

        while (!jxp_estaVacia(&pila2))
        {
            p = jxp_cima(&pila2);
            jxp_depilar(&pila2);
            txt = abb->str(p->dato);
            printf("%s -> ", txt);
            free(txt);
        }
    }

    puts(" }");
}

void jxab_porNivel(jxab_ABB *abb)
{
    printf("ABB:POR NIVEL { ");

    if (!jxab_estaVacio(abb))
    {
        jxab_Nodo *p = NULL;
        jxc_Cola cola = {.del = NULL, .str = NULL, .cabeza = NULL};
        jxc_encolar(&cola, abb->raiz);
        char *txt;

        do {
            p = jxc_frente(&cola);
            jxc_decolar(&cola);
            txt = abb->str(p->dato);
            printf("%s -> ", txt);
            free(txt);

            if (p->hi != NULL)
                jxc_encolar(&cola, p->hi);

            if (p->hd != NULL)
                jxc_encolar(&cola, p->hd);
        } while (!jxc_estaVacia(&cola));
    }

    puts(" }");
}

bool jxab_borrar(jxab_ABB *abb)
{
    if (!jxab_estaVacio(abb))
    {
        jxab_Nodo *p = abb->raiz;
        jxp_Pila pila = {.del = NULL, .str = NULL, .tope = NULL};
        jxp_empilar(&pila, p);

        do
        {
            p = jxp_cima(&pila);
            jxp_depilar(&pila);

            if (p->hd != NULL)
                jxp_empilar(&pila, p->hd);

            if (p->hi != NULL)
                jxp_empilar(&pila, p->hi);

            p->padre = NULL;
            p->hi = NULL;
            p->hd = NULL;
            jxab_borrarNodo(p, abb->del);
        } while (!jxp_estaVacia(&pila));

        abb->raiz = NULL;

        return true;
    }
    else
        return false;
}

bool jxab_estaVacio(jxab_ABB *abb)
{
    return abb->raiz == NULL;
}