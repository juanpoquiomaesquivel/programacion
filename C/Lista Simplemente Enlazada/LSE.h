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
    void (*del)(void *p);
    int (*cmp)(const void *p, const void *q);
    char *(*str)(const void *p);
    jxls_Nodo *cabeza;
} jxls_LSE;

jxls_Nodo *jxls_crearNodo(void *dato);
void jxls_borrarNodo(jxls_Nodo *nodo, void (*del)(void *p));
void jxls_insertarAlInicio(jxls_LSE *lse, void *dato);
void jxls_insertarAlFinal(jxls_LSE *lse, void *dato);
bool jxls_insertarAntesDe(jxls_LSE *lse, void *dato, void *x);
bool jxls_insertarDespuesDe(jxls_LSE *lse, void *dato, void *x);
bool jxls_reemplazarEn(jxls_LSE *lse, void *dato, void *x);
bool jxls_eliminarElPrimero(jxls_LSE *lse);
bool jxls_eliminarElUltimo(jxls_LSE *lse);
bool jxls_eliminarAntesDe(jxls_LSE *lse, void *x);
bool jxls_eliminarDespuesDe(jxls_LSE *lse, void *x);
bool jxls_eliminarEn(jxls_LSE *lse, void *x);
void *jxls_obtenerElPrimero(jxls_LSE *lse);
void *jxls_obtenerElUltimo(jxls_LSE *lse);
void *jxls_obtenerAntesDe(jxls_LSE *lse, void *x);
void *jxls_obtenerDespuesDe(jxls_LSE *lse, void *x);
void *jxls_obtenerEn(jxls_LSE *lse, int posicion);
int jxls_buscar(jxls_LSE *lsem, void *x);
bool jxls_borrar(jxls_LSE *lse);
void jxls_mostrar(jxls_LSE *lse);
bool jxls_estaVacia(jxls_LSE *lse);

#endif