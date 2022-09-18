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
    jxp_Nodo *tope;
} jxp_Pila;

jxp_Nodo *jxp_crearNodo(void *dato);
void jxp_borrarNodo(jxp_Nodo *nodo, void (*func)(void *p));
void jxp_empilar(jxp_Nodo **tope, void *dato);
bool jxp_depilar(jxp_Nodo **tope, void (*func)(void *p));
void *jxp_cima(jxp_Nodo *tope);
bool jxp_borrar(jxp_Nodo **tope, void (*func)(void *p));
void jxp_mostrar(jxp_Nodo *tope, char *(*func)(const void *p));
bool jxp_estaVacia(jxp_Nodo *tope);

#endif