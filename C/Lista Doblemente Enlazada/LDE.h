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
    void (*del)(void *p);
    int (*cmp)(const void *p, const void *q);
    char *(*str)(const void *p);
    jxld_Nodo *cabeza;
} jxld_LDE;

jxld_Nodo *jxld_crearNodo(void *dato);
void jxld_borrarNodo(jxld_Nodo *nodo, void (*del)(void *p));
void jxld_insertarAlInicio(jxld_LDE *lde, void *dato);
void jxld_insertarAlFinal(jxld_LDE *lde, void *dato);
bool jxld_insertarAntesDe(jxld_LDE *lde, void *dato, void *x);
bool jxld_insertarDespuesDe(jxld_LDE *lde, void *dato, void *x);
bool jxld_reemplazarEn(jxld_LDE *lde, void *dato, void *x);
bool jxld_eliminarElPrimero(jxld_LDE *lde);
bool jxld_eliminarElUltimo(jxld_LDE *lde);
bool jxld_eliminarAntesDe(jxld_LDE *lde, void *x);
bool jxld_eliminarDespuesDe(jxld_LDE *lde, void *x);
bool jxld_eliminarEn(jxld_LDE *lde, void *x);
void *jxld_obtenerElPrimero(jxld_LDE *lde);
void *jxld_obtenerElUltimo(jxld_LDE *lde);
void *jxld_obtenerAntesDe(jxld_LDE *lde, void *x);
void *jxld_obtenerDespuesDe(jxld_LDE *lde, void *x);
void *jxld_obtenerEn(jxld_LDE *lde, int posicion);
int jxld_buscar(jxld_LDE *lde, void *x);
bool jxld_borrar(jxld_LDE *lde);
void jxld_mostrar(jxld_LDE *lde);
bool jxld_estaVacia(jxld_LDE *lde);

#endif