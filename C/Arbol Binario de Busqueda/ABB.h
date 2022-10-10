#ifndef _ABB_H_
#define _ABB_H_

#include <stdbool.h>

typedef struct jxab_nodo
{
    void *dato;
    struct jxab_nodo *padre;
    struct jxab_nodo *hi;
    struct jxab_nodo *hd;
} jxab_Nodo;

typedef struct jxab_abb
{
    jxab_Nodo *raiz;
} jxab_ABB;

jxab_Nodo *jxab_crearNodo(void *dato);
void jxab_borrarNodo(jxab_Nodo *nodo, void (*del)(void *p));
bool jxab_insertar(jxab_Nodo **raiz, void *dato, int (*cmp)(const void *p, const void *q));


void jxab_preOrden(jxab_Nodo *raiz, char *(*str)(const void *p));
void jxab_inOrden(jxab_Nodo *raiz, char *(*str)(const void *p));
void jxab_posOrden(jxab_Nodo *raiz, char *(*str)(const void *p));

void preorden(jxab_Nodo *nodo, char *(*str)(const void *p));
void inorden(jxab_Nodo *nodo, char *(*str)(const void *p));
void posorden(jxab_Nodo *nodo, char *(*str)(const void *p));

bool jxab_borrar(jxab_Nodo **raiz, void (*del)(void *p));
bool jxab_estaVacio(jxab_Nodo *raiz);

#endif