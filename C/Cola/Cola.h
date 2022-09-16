#ifndef _COLA_H_
#define _COLA_H_

#include <stdbool.h>
#include "Libreria.h"

typedef struct jxc_nodo
{
    T dato;
    struct jxc_nodo *siguiente;
} jxc_Nodo;

typedef struct jxc_cola
{
    jxc_Nodo *cabeza;
} jxc_Cola;

jxc_Nodo *jxc_crearNodo(T dato);
void jxc_encolar(jxc_Nodo **cabeza, T dato);
bool jxc_decolar(jxc_Nodo **cabeza);
T jxc_frente(jxc_Nodo *cabeza);
T jx_ultimo(jxc_Nodo *cabeza);
bool jxc_borrar(jxc_Nodo **cabeza);
void jxc_mostrar(jxc_Nodo *cabeza);
bool jxc_estaVacia(jxc_Nodo *cabeza);

#endif