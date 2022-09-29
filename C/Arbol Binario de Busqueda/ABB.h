#ifndef _ABB_H_
#define _ABB_H_

#include <stdbool.h>

typedef struct jxab_nodo
{
    void *dato;
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

#endif