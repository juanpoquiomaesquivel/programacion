#ifndef _COLA_H_
#define _COLA_H_

#ifndef BOOL
#define BOOL
typedef enum
{
    false,
    true
} bool;
#endif

#ifndef NO_MEMORY
#define NO_MEMORY "[SISTEMA] :- <No hay memoria suficiente> "
#endif

#ifndef FLUSH
#define FLUSH
void flush();
#endif

#ifndef ERROR_MEMORY
#define ERROR_MEMORY
void error(void *ptr);
#endif

typedef void *T;
typedef int E;
typedef struct nodo
{
    T dato;
    struct nodo *siguiente;
} Nodo;

Nodo *nodo(T dato);
void encolar(Nodo **cabeza, T dato);
void decolar(Nodo **cabeza);
T frente(Nodo *cabeza);
T ultimo(Nodo *cabeza);
void borrar(Nodo **cabeza);
void mostrar(Nodo *cabeza);
bool estaVacia(Nodo *cabeza);

#endif