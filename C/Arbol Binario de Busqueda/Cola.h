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
    void (*del)(void *p);
    char *(*str)(const void *p);
    jxc_Nodo *cabeza;
} jxc_Cola;

jxc_Nodo *jxc_crearNodo(void *dato);
void jxc_borrarNodo(jxc_Nodo *nodo, void (*del)(void *p));
void jxc_encolar(jxc_Cola *cola, void *dato);
bool jxc_decolar(jxc_Cola *cola);
void *jxc_frente(jxc_Cola *cola);
void *jx_ultimo(jxc_Cola *cola);
bool jxc_borrar(jxc_Cola *cola);
void jxc_mostrar(jxc_Cola *cola);
bool jxc_estaVacia(jxc_Cola *cola);

#endif