#include "Arreglo.h"
#include "Libreria.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

jxv_Nodo *jxv_crearNodo(void *dato)
{
    jxv_Nodo *nuevo = (jxv_Nodo *)malloc(sizeof(jxv_Nodo));
    errorDeMemoria(nuevo);
    nuevo->dato = dato;
    nuevo->siguiente = NULL;
}