#ifndef _COLA_H_
#define _COLA_H_

#include <stdbool.h>
#include "Libreria.h"

typedef struct jxc_nodo
{
    void *dato;
    struct jxc_nodo *siguiente;
} jxc_Nodo;

typedef struct jxc_cola
{
    jxc_Nodo *cabeza;
} jxc_Cola;

jxc_Nodo *jxc_crearNodo(void *dato);
void jxc_borrarNodo(jxc_Nodo *nodo, void (*del)(void *p));
void jxc_encolar(jxc_Nodo **cabeza, void *dato);
bool jxc_decolar(jxc_Nodo **cabeza, void (*del)(void *p));
void *jxc_frente(jxc_Nodo *cabeza);
void *jx_ultimo(jxc_Nodo *cabeza);
bool jxc_borrar(jxc_Nodo **cabeza, void (*del)(void *p));
void jxc_mostrar(jxc_Nodo *cabeza, char *(*str)(const void *p));
bool jxc_estaVacia(jxc_Nodo *cabeza);

#endif