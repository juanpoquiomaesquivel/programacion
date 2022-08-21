#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *dato;
} Nodo;

int main(int argc, char const *argv[])
{
    int *d = (int *)malloc(sizeof(int));
    printf("#1 puntD : %p, value: %d\n", d, *d);
    printf("Ingrese el valor de 'd': ");
    scanf("%d", d);
    printf("#2 puntD : %p, value: %d\n", d, *d);

    Nodo *n = (Nodo *)malloc(sizeof(Nodo));
    n->dato = d;
    printf("#3 puntN : %p, puntN->dato : %p, value: %d\n", n, n->dato, *(n->dato));

    free(n->dato);
    free(n);
    
    printf("#4 puntN : %p, puntN->dato : %p, value: %d\n", n, n->dato, *(n->dato));
    printf("#5 puntD : %p, value: %d\n", d, *d);


    return 0;
}
