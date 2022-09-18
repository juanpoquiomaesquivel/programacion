#ifndef _LSE_H_
#define _LSE_H_

#include <stdbool.h>
#include "Libreria.h"

typedef struct jxls_nodo
{
    void *dato;
    struct jxls_nodo *siguiente;
} jxls_Nodo;

typedef struct jxls_lse
{
    jxls_Nodo *cabeza;
} jxls_LSE;

jxls_Nodo *jxls_crearNodo(void *dato);
void jxls_borrarNodo(jxls_Nodo *nodo, void (*del)(void *p));
void jxls_insertarAlInicio(jxls_Nodo **cabeza, void *dato);
void jxls_insertarAlFinal(jxls_Nodo **cabeza, void *dato);
bool jxls_insertarAntesDe(jxls_Nodo **cabeza, void *dato, void *x, bool (*cmp)(const void *p, const void *q));
bool jxls_insertarDespuesDe(jxls_Nodo **cabeza, void *dato, void *x, bool (*cmp)(const void *p, const void *q));
bool jxls_reemplazarEn(jxls_Nodo *cabeza, void *dato, void *x, void (*del)(void *p), bool (*cmp)(const void *p, const void *q));
bool jxls_eliminarElPrimero(jxls_Nodo **cabeza, void (*del)(void *p));
bool jxls_eliminarElUltimo(jxls_Nodo **cabeza, void (*del)(void *p));
bool jxls_eliminarAntesDe(jxls_Nodo **cabeza, void *x, void (*del)(void *p), bool (*cmp)(const void *p, const void *q));
bool jxls_eliminarDespuesDe(jxls_Nodo **cabeza, void *x, void (*del)(void *p), bool (*cmp)(const void *p, const void *q));
bool jxls_eliminarEn(jxls_Nodo **cabeza, void *x, void (*del)(void *p), bool (*cmp)(const void *p, const void *q));
void *jxls_obtenerElPrimero(jxls_Nodo *cabeza);
void *jxls_obtenerElUltimo(jxls_Nodo *cabeza);
void *jxls_obtenerAntesDe(jxls_Nodo *cabeza, void *x, bool (*cmp)(const void *p, const void *q));
void *jxls_obtenerDespuesDe(jxls_Nodo *cabeza, void *x, bool (*cmp)(const void *p, const void *q));
void *jxls_obtenerEn(jxls_Nodo *cabeza, int posicion);
int jxls_buscar(jxls_Nodo *cabeza, void *x, bool (*cmp)(const void *p, const void *q));
bool jxls_borrar(jxls_Nodo **cabeza, void (*del)(void *p));
void jxls_mostrar(jxls_Nodo *cabeza, char *(*str)(const void *p));
bool jxls_estaVacia(jxls_Nodo *cabeza);

#endif