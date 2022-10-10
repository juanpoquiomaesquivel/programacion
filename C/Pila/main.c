#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "Entrada.h"
#include "Libreria.h"
#include "Persona.h"
#include "Pila.h"

enum
{
    SALIR,
    EMPILAR,
    DEPILAR,
    CIMA,
    BORRAR,
    MOSTRAR
};

const char lista[][100] = {"Salir",
                           "Empilar",
                           "Depilar",
                           "Cima",
                           "Borrar",
                           "Mostrar"};

void menu();

int main(int argc, char const *argv[])
{
    menu();

    return EXIT_SUCCESS;
}

void menu()
{
    const size_t n = sizeof(lista) / sizeof(lista[0]);
    short int *opcion = NULL;
    jxp_Pila pila = {.del = borrarPersona, .str = mostrarPersona, .tope = NULL};
    void *dato = NULL;

    while (true)
    {
        system("cls");
        puts("\n\t\t.: PILA :.\n");

        for (size_t i = 0; i < n; i++)
            printf("[%d] : %s\n", i, lista[i]);

        puts("");
        opcion = (short int *)leerEntrada("%hd", "Ingrese una opcion");

        switch (*opcion)
        {
        case SALIR:
            jxp_borrar(&pila);
            free(opcion);
            puts(MS_PROGRAMA_FINALIZADO);

            return;
        case EMPILAR:
            dato = crearPersona();
            jxp_empilar(&pila, dato);
            dato = NULL;
            break;
        case DEPILAR:
            printf("%s\n", jxp_depilar(&pila) ? "true" : "false");
            break;
        case CIMA:
            dato = jxp_cima(&pila);
            (dato != NULL) ? printf("%s\n", mostrarPersona(dato)) : puts("NULL");
            dato = NULL;
            break;
        case BORRAR:
            printf("%s\n", (jxp_borrar(&pila) ? "true" : "false"));
            break;
        case MOSTRAR:
            jxp_mostrar(&pila);
            break;
        default:
            puts(MS_OPCION_INCORRECTA);
        }

        free(opcion);
        opcion = NULL;
        puts(MS_OPCION_CONTINUAR);
        limpiarBuffer();
    }
}