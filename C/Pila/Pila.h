#ifndef _PILA_H_
#define _PILA_H_

#include <stdbool.h>
#include "Libreria.h"

typedef struct jxp_nodo
{
    T dato;
    struct jxp_nodo *abajo;
} jxp_Nodo;

typedef struct jxp_pila
{
    jxp_Nodo *tope;
} jxp_Pila;

jxp_Nodo *jxp_crearNodo(T dato);
void jxp_empilar(jxp_Nodo **tope, T dato);
bool jxp_depilar(jxp_Nodo **tope);
T jxp_cima(jxp_Nodo *tope);
bool jxp_borrar(jxp_Nodo **tope);
void jxp_mostrar(jxp_Nodo *tope);
bool jxp_estaVacia(jxp_Nodo *tope);

#endif