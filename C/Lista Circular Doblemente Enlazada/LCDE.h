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
    void (*del)(void *p);
    int (*cmp)(const void *p, const void *q);
    char *(*str)(const void *p);
    jxlcd_Nodo *cabeza;
} jxlcd_LCDE;

jxlcd_Nodo *jxlcd_crearNodo(void *dato);
void jxlcd_borrarNodo(jxlcd_Nodo *nodo, void (*del)(void *p));
void jxlcd_insertarAlInicio(jxlcd_LCDE *lcde, void *dato);
void jxlcd_insertarAlFinal(jxlcd_LCDE *lcde, void *dato);
bool jxlcd_insertarAntesDe(jxlcd_LCDE *lcde, void *dato, void *x);
bool jxlcd_insertarDespuesDe(jxlcd_LCDE *lcde, void *dato, void *x);
bool jxlcd_reemplazarEn(jxlcd_LCDE *lcde, void *dato, void *x);
bool jxlcd_eliminarElPrimero(jxlcd_LCDE *lcde);
bool jxlcd_eliminarElUltimo(jxlcd_LCDE *lcde);
bool jxlcd_eliminarAntesDe(jxlcd_LCDE *lcde, void *x);
bool jxlcd_eliminarDespuesDe(jxlcd_LCDE *lcde, void *x);
bool jxlcd_eliminarEn(jxlcd_LCDE *lcde, void *x);
void *jxlcd_obtenerElPrimero(jxlcd_LCDE *lcde);
void *jxlcd_obtenerElUltimo(jxlcd_LCDE *lcde);
void *jxlcd_obtenerAntesDe(jxlcd_LCDE *lcde, void *x);
void *jxlcd_obtenerDespuesDe(jxlcd_LCDE *lcde, void *x);
void *jxlcd_obtenerEn(jxlcd_LCDE *lcde, int posicion);
int jxlcd_buscar(jxlcd_LCDE *lcde, void *x);
bool jxlcd_borrar(jxlcd_LCDE *lcde);
void jxlcd_mostrar(jxlcd_LCDE *lcde);
bool jxlcd_estaVacia(jxlcd_LCDE *lcde);

#endif