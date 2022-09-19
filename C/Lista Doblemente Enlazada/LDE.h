#ifndef _LDE_H_
#define _LDE_H_

#include <stdbool.h>
#include "Libreria.h"

typedef struct jxld_nodo
{
    void *dato;
    struct jxld_nodo *anterior;
    struct jxld_nodo *siguiente;
} jxld_Nodo;

typedef struct jxld_lde
{
    jxld_Nodo *cabeza;
} jxld_LDE;

jxld_Nodo *jxld_crearNodo(void *dato);
void jxld_borrarNodo(jxld_Nodo *nodo, void (*del)(void *p));
void jxld_insertarAlInicio(jxld_Nodo **cabeza, void *dato);
void jxld_insertarAlFinal(jxld_Nodo **cabeza, void *dato);
bool jxld_insertarAntesDe(jxld_Nodo **cabeza, void *dato, void *x, bool (*cmp)(const void *p, const void *q));
bool jxld_insertarDespuesDe(jxld_Nodo **cabeza, void *dato, void *x, bool (*cmp)(const void *p, const void *q));
bool jxld_reemplazarEn(jxld_Nodo *cabeza, void *dato, void *x, void (*del)(void *p), bool (*cmp)(const void *p, const void *q));
bool jxld_eliminarElPrimero(jxld_Nodo **cabeza, void (*del)(void *p));
bool jxld_eliminarElUltimo(jxld_Nodo **cabeza, void (*del)(void *p));
bool jxld_eliminarAntesDe(jxld_Nodo **cabeza, void *x, void (*del)(void *p), bool (*cmp)(const void *p, const void *q));
bool jxld_eliminarDespuesDe(jxld_Nodo **cabeza, void *x, void (*del)(void *p), bool (*cmp)(const void *p, const void *q));
bool jxld_eliminarEn(jxld_Nodo **cabeza, void *x, void (*del)(void *p), bool (*cmp)(const void *p, const void *q));
void *jxld_obtenerElPrimero(jxld_Nodo *cabeza);
void *jxld_obtenerElUltimo(jxld_Nodo *cabeza);
void *jxld_obtenerAntesDe(jxld_Nodo *cabeza, void *x, bool (*cmp)(const void *p, const void *q));
void *jxld_obtenerDespuesDe(jxld_Nodo *cabeza, void *x, bool (*cmp)(const void *p, const void *q));
void *jxld_obtenerEn(jxld_Nodo *cabeza, int posicion);
int jxld_buscar(jxld_Nodo *cabeza, void *x, bool (*cmp)(const void *p, const void *q));
bool jxld_borrar(jxld_Nodo **cabeza, void (*del)(void *p));
void jxld_mostrar(jxld_Nodo *cabeza, char *(*str)(const void *p));
bool jxld_estaVacia(jxld_Nodo *cabeza);

#endif