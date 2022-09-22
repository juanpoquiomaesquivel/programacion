#ifndef _ARREGLO_H_
#define _ARREGLO_H_

typedef struct jxv_nodo
{
    void *dato;
    struct jxv_nodo *siguiente;
} jxv_Nodo;

typedef struct jxv_vector
{
    jxv_Nodo *cabeza;
} jxv_Vector;

jxv_Nodo *jxv_crearNodo(void *dato);

#endif