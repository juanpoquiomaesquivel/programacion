#ifndef _LCDE_H_
#define _LCDE_H_

#include <stdbool.h>
#include "Libreria.h"

typedef struct jxlcd_nodo
{
    void *dato;
    struct jxlcd_nodo *anterior;
    struct jxlcd_nodo *siguiente;
} jxlcd_Nodo;

typedef struct jxlcd_lcde
{
    jxlcd_Nodo *cabeza;
} jxlcd_LCDE;

jxlcd_Nodo *jxlcd_crearNodo(void *dato);
void jxlcd_borrarNodo(jxlcd_Nodo *nodo, void (*del)(void *p));
void jxlcd_insertarAlInicio(jxlcd_Nodo **cabeza, void *dato);
void jxlcd_insertarAlFinal(jxlcd_Nodo **cabeza, void *dato);
bool jxlcd_insertarAntesDe(jxlcd_Nodo **cabeza, void *dato, void *x, bool (*cmp)(const void *p, const void *q));
bool jxlcd_insertarDespuesDe(jxlcd_Nodo **cabeza, void *dato, void *x, bool (*cmp)(const void *p, const void *q));
bool jxlcd_reemplazarEn(jxlcd_Nodo *cabeza, void *dato, void *x, void (*del)(void *p), bool (*cmp)(const void *p, const void *q));
bool jxlcd_eliminarElPrimero(jxlcd_Nodo **cabeza, void (*del)(void *p));
bool jxlcd_eliminarElUltimo(jxlcd_Nodo **cabeza, void (*del)(void *p));
bool jxlcd_eliminarAntesDe(jxlcd_Nodo **cabeza, void *x, void (*del)(void *p), bool (*cmp)(const void *p, const void *q));
bool jxlcd_eliminarDespuesDe(jxlcd_Nodo **cabeza, void *x, void (*del)(void *p), bool (*cmp)(const void *p, const void *q));
bool jxlcd_eliminarEn(jxlcd_Nodo **cabeza, void *x, void (*del)(void *p), bool (*cmp)(const void *p, const void *q));
void *jxlcd_obtenerElPrimero(jxlcd_Nodo *cabeza);
void *jxlcd_obtenerElUltimo(jxlcd_Nodo *cabeza);
void *jxlcd_obtenerAntesDe(jxlcd_Nodo *cabeza, void *x, bool (*cmp)(const void *p, const void *q));
void *jxlcd_obtenerDespuesDe(jxlcd_Nodo *cabeza, void *x, bool (*cmp)(const void *p, const void *q));
void *jxlcd_obtenerEn(jxlcd_Nodo *cabeza, int posicion);
int jxlcd_buscar(jxlcd_Nodo *cabeza, void *x, bool (*cmp)(const void *p, const void *q));
bool jxlcd_borrar(jxlcd_Nodo **cabeza, void (*del)(void *p));
void jxlcd_mostrar(jxlcd_Nodo *cabeza, char *(*str)(const void *p));
bool jxlcd_estaVacia(jxlcd_Nodo *cabeza);

#endif