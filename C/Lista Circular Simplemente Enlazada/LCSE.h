#ifndef _LCSE_H_
#define _LCSE_H_

#include <stdbool.h>
#include "Libreria.h"

typedef struct jxlcs_nodo
{
    void *dato;
    struct jxlcs_nodo *siguiente;
} jxlcs_Nodo;

typedef struct jxlcs_lcse
{
    jxlcs_Nodo *cabeza;
} jxlcs_LCSE;

jxlcs_Nodo *jxlcs_crearNodo(void *dato);
void jxlcs_borrarNodo(jxlcs_Nodo *nodo, void (*del)(void *p));
void jxlcs_insertarAlInicio(jxlcs_Nodo **cabeza, void *dato);
void jxlcs_insertarAlFinal(jxlcs_Nodo **cabeza, void *dato);
bool jxlcs_insertarAntesDe(jxlcs_Nodo **cabeza, void *dato, void *x, bool (*cmp)(const void *p, const void *q));
bool jxlcs_insertarDespuesDe(jxlcs_Nodo **cabeza, void *dato, void *x, bool (*cmp)(const void *p, const void *q));
bool jxlcs_reemplazarEn(jxlcs_Nodo *cabeza, void *dato, void *x, void (*del)(void *p), bool (*cmp)(const void *p, const void *q));
bool jxlcs_eliminarElPrimero(jxlcs_Nodo **cabeza, void (*del)(void *p));
bool jxlcs_eliminarElUltimo(jxlcs_Nodo **cabeza, void (*del)(void *p));
bool jxlcs_eliminarAntesDe(jxlcs_Nodo **cabeza, void *x, void (*del)(void *p), bool (*cmp)(const void *p, const void *q));
bool jxlcs_eliminarDespuesDe(jxlcs_Nodo **cabeza, void *x, void (*del)(void *p), bool (*cmp)(const void *p, const void *q));
bool jxlcs_eliminarEn(jxlcs_Nodo **cabeza, void *x, void (*del)(void *p), bool (*cmp)(const void *p, const void *q));
void *jxlcs_obtenerElPrimero(jxlcs_Nodo *cabeza);
void *jxlcs_obtenerElUltimo(jxlcs_Nodo *cabeza);
void *jxlcs_obtenerAntesDe(jxlcs_Nodo *cabeza, void *x, bool (*cmp)(const void *p, const void *q));
void *jxlcs_obtenerDespuesDe(jxlcs_Nodo *cabeza, void *x, bool (*cmp)(const void *p, const void *q));
void *jxlcs_obtenerEn(jxlcs_Nodo *cabeza, int posicion);
int jxlcs_buscar(jxlcs_Nodo *cabeza, void *x, bool (*cmp)(const void *p, const void *q));
bool jxlcs_borrar(jxlcs_Nodo **cabeza, void (*del)(void *p));
void jxlcs_mostrar(jxlcs_Nodo *cabeza, char *(*str)(const void *p));
bool jxlcs_estaVacia(jxlcs_Nodo *cabeza);

#endif