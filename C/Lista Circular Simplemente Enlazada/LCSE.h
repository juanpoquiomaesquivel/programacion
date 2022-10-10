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
    void (*del)(void *p);
    int (*cmp)(const void *p, const void *q);
    char *(*str)(const void *p);
    jxlcs_Nodo *cabeza;
} jxlcs_LCSE;

jxlcs_Nodo *jxlcs_crearNodo(void *dato);
void jxlcs_borrarNodo(jxlcs_Nodo *nodo, void (*del)(void *p));
void jxlcs_insertarAlInicio(jxlcs_LCSE *lcse, void *dato);
void jxlcs_insertarAlFinal(jxlcs_LCSE *lcse, void *dato);
bool jxlcs_insertarAntesDe(jxlcs_LCSE *lcse, void *dato, void *x);
bool jxlcs_insertarDespuesDe(jxlcs_LCSE *lcse, void *dato, void *x);
bool jxlcs_reemplazarEn(jxlcs_LCSE *lcse, void *dato, void *x);
bool jxlcs_eliminarElPrimero(jxlcs_LCSE *lcse);
bool jxlcs_eliminarElUltimo(jxlcs_LCSE *lcse);
bool jxlcs_eliminarAntesDe(jxlcs_LCSE *lcse, void *x);
bool jxlcs_eliminarDespuesDe(jxlcs_LCSE *lcse, void *x);
bool jxlcs_eliminarEn(jxlcs_LCSE *lcse, void *x);
void *jxlcs_obtenerElPrimero(jxlcs_LCSE *lcse);
void *jxlcs_obtenerElUltimo(jxlcs_LCSE *lcse);
void *jxlcs_obtenerAntesDe(jxlcs_LCSE *lcse, void *x);
void *jxlcs_obtenerDespuesDe(jxlcs_LCSE *lcse, void *x);
void *jxlcs_obtenerEn(jxlcs_LCSE *lcse, int posicion);
int jxlcs_buscar(jxlcs_LCSE *lcse, void *x);
bool jxlcs_borrar(jxlcs_LCSE *lcse);
void jxlcs_mostrar(jxlcs_LCSE *lcse);
bool jxlcs_estaVacia(jxlcs_LCSE *lcse);

#endif