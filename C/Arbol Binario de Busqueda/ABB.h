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
    void (*del)(void *p);
    int (*cmp)(const void *p, const void *q);
    char *(*str)(const void *p);
    jxab_Nodo *raiz;
} jxab_ABB;

jxab_Nodo *jxab_crearNodo(void *dato);
void jxab_borrarNodo(jxab_Nodo *nodo, void (*del)(void *p));
bool jxab_insertar(jxab_ABB *abb, void *dato);
// bool jxab_eliminar(jxab_ABB *abb, void *dato);
bool jxab_buscar(jxab_ABB *abb, void *x);
bool jxab_reemplazar(jxab_ABB *abb, void *dato, void *x);

void jxab_preorden(jxab_ABB *abb);
void jxab_inorden(jxab_ABB *abb);
void jxab_posorden(jxab_ABB *abb);
void jxab_porNivel(jxab_ABB *abb);

bool jxab_borrar(jxab_ABB *abb);
bool jxab_estaVacio(jxab_ABB *abb);

#endif