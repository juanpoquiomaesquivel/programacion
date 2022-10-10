#ifndef _PILA_H_
#define _PILA_H_

#include <stdbool.h>
#include "Libreria.h"

typedef struct jxp_nodo
{
    void *dato;
    struct jxp_nodo *abajo;
} jxp_Nodo;

typedef struct jxp_pila
{
    void (*del)(void *p);
    char *(*str)(const void *p);
    jxp_Nodo *tope;
} jxp_Pila;

jxp_Nodo *jxp_crearNodo(void *dato);
void jxp_borrarNodo(jxp_Nodo *nodo, void (*del)(void *p));
void jxp_empilar(jxp_Pila *pila, void *dato);
bool jxp_depilar(jxp_Pila *pila);
void *jxp_cima(jxp_Pila *pila);
bool jxp_borrar(jxp_Pila *pila);
void jxp_mostrar(jxp_Pila *pila);
bool jxp_estaVacia(jxp_Pila *pila);

#endif