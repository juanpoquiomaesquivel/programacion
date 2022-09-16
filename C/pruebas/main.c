#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "Persona.h"

/* typedef struct estudiante
{
    int age;
} Estudiante;

bool comparator(const void *p, const void *q)
{
    Estudiante *ep = (Estudiante *)p;
    Estudiante *eq = (Estudiante *)q;

    return ep->age > eq->age;
}

void swap(void *p, void *q)
{
    Estudiante *ep = (Estudiante *)p;
    Estudiante *eq = (Estudiante *)q;

    void *aux = p;
    p = q;
    q = aux;
}

void burbuja(void *vector, size_t n, size_t size, bool (*func)(const void *p, const void *q))
{
    void *aux;

    for (size_t i = 1; i < n; i++)
        for (size_t j = n - 1; j >= i; j--)
            if (func(vector + (j - 1) * size, vector + j * size))
            {
                aux = vector + (j - 1) * size;
                vector + ((j - 1) * size) = vector + (j * size);
                vector + (j * size) = aux;
            }
}

int main(int argc, char const *argv[])
{
    return 0;
}
 */

/*typedef struct jxv_nodoVector
{
    void *dato;
    struct jxv_nodoVector *anterior;
    struct jxv_nodoVector *siguiente;
} jxv_NodoVector;

typedef struct jxv_vector
{
    jxv_NodoVector *cabeza;
} jxv_Vector;

jxv_NodoVector *jxv_nuevoNodoVector(void *dato);
void jxv_liberarNodoVector(void *ptr);
jxv_Vector *jxv_nuevoVector();
void jxv_insertar(jxv_Vector **vector, void *dato);
void jxv_mostrar(jxv_Vector *vector);
bool jxv_estaVacio(jxv_Vector *vector);

int main(int argc, char const *argv[])
{
    jxv_Vector *v = jxv_nuevoVector();
    int var = 48;
    jxv_insertar(&v, &var);
    jxv_mostrar(v);
    jxv_mostrar(v);

    return 0;
}

jxv_NodoVector *jxv_nuevoNodoVector(void *dato)
{
    jxv_NodoVector *nodo = (jxv_NodoVector *)malloc(sizeof(jxv_NodoVector));

    if (nodo == NULL)
        system("EXIT_FAILURE");

    nodo->dato = dato;
    nodo->anterior = NULL;
    nodo->siguiente = NULL;
}

jxv_Vector *jxv_nuevoVector()
{
    jxv_Vector *vector = (jxv_Vector *)malloc(sizeof(jxv_Vector));

    if (vector == NULL)
        system("EXIT_FAILURE");

    vector->cabeza = NULL;

    return vector;
}

void jxv_insertar(jxv_Vector **vector, void *dato)
{
    jxv_NodoVector *nuevo = jxv_nuevoNodoVector(dato);

    if (jxv_estaVacio(*vector))
        *vector = jxv_nuevoVector();

    if ((*vector)->cabeza == NULL)
        (*vector)->cabeza = nuevo;
    else
    {
        jxv_NodoVector *p = (*vector)->cabeza;

        while (p->siguiente != NULL)
            p = p->siguiente;

        p->siguiente = nuevo;
    }
}

bool jxv_eliminar(jxv_Vector **vector, const int posicion)
{
    if (!jxv_estaVacio(vector))
    {
        int i = 0;
        jxv_NodoVector *p = (*vector)->cabeza;

        while (p->siguiente != NULL && i != posicion)
        {
            p = p->siguiente;
            i++;
        }

        if (i == posicion)
        {
            if (p == (*vector)->cabeza)
                (*vector)->cabeza = (*vector)->cabeza->siguiente;
            else
                p = p->siguiente;

            jxv_liberarNodoVector(p);

            return true;
        }
    }

    return false;
}

void jxv_mostrar(jxv_Vector *vector)
{
    if (!jxv_estaVacio(vector))
    {
        jxv_NodoVector *p = vector->cabeza;
        printf("VECTOR => { ");

        while (p != NULL)
        {
            printf("%d ", *(int *)p->dato);
            p = p->siguiente;
        }

        puts(" }");
    }
}

bool jxv_estaVacio(jxv_Vector *vector)
{
    return vector == NULL;
};

void show(void *arr, size_t num, size_t size, char *(*showMethod)(const void *p))
{
    for (size_t i = 0; i < num; i++)
    {
        printf("%s ", showMethod(arr + i * size));
    }
}*/

typedef struct estudiante
{
    int edad;
    char nombre[20];
} Estudiante;

char *mostrarEstudiante(const void *p)
{
    Estudiante *e = (Estudiante *)p;

    return e->nombre;
}

void show(void *arr, size_t num, size_t size, char *(*showMethod)(const void *p))
{
    for (size_t i = 0; i < num; i++)
    {
        printf("%s ", showMethod(arr + i * size));
    }
}

int comparator(const void *a, const void *b)
{
    Estudiante *p = (Estudiante *)a;
    Estudiante *q = (Estudiante *)b;

    return p->edad - q->edad;
}

int main(int argc, char const *argv[])
{
    /*int n = 3;
    Estudiante *es = (Estudiante *)malloc(n * sizeof(Estudiante));

    //*es = (Estudiante){.edad = 13, .nombre = "Paco"};
    // char *texto = "Julieta";
    (es + 0)->edad = 45;
    strcpy((es + 0)->nombre, "Julieta");

    (es + 1)->edad = 15;
    strcpy((es + 1)->nombre, "Pamela");

    (es + 2)->edad = 25;
    strcpy((es + 2)->nombre, "Roca");

    qsort(es, n, sizeof(es[0]), comparator);
    show((void *)es, n, sizeof(es[0]), mostrarEstudiante);
    return 0;*/

    Persona *p = crearPersona();

    return 0;
}
