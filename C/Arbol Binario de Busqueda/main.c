#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ABB.h"
#include "Entrada.h"
#include "Libreria.h"
#include "Persona.h"

enum
{
    SALIR,
    INSERTAR,
    ELIMINAR,
    BUSCAR,
    PREORDEN,
    POSORDEN,
    INORDEN,
    BORRAR,
    MOSTRAR
};

const char lista[][100] = {"Salir",
                           "Insertar",
                           "Eliminar",
                           "Buscar",
                           "Preorden",
                           "Posorden",
                           "Inorden",
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
    jxab_ABB abb = {.raiz = NULL};
    void *dato = NULL;

    while (true)
    {
        system("pause");
        system("cls");
        puts("\n\t\t.: ARBOL BINARIO DE BUSQUEDA :.\n");

        for (size_t i = 0; i < n; i++)
            printf("[%d] : %s\n", i, lista[i]);

        puts("");
        opcion = (short int *)leerEntrada("%hd", "Ingrese una opcion");

        switch (*opcion)
        {
        case SALIR:
            jxab_borrar(&abb.raiz, borrarPersona);
            free(opcion);
            puts(MS_PROGRAMA_FINALIZADO);

            return;
        case INSERTAR:
            dato = crearPersona();
            jxab_insertar(&abb.raiz, dato, compararPersona);
            dato = NULL;
            break; /*
         case ELIMINAR:
             printf("%s\n", (jxab_eliminar(&abb.raiz, borrarPersona) ? "true" : "false"));
             break;
         case FRENTE:
             dato = jxc_frente(abb.raiz);
             (dato != NULL) ? printf("%s\n", mostrarPersona(dato)) : puts("NULL");
             dato = NULL;
             break;
         case ULTIMO:
             dato = jx_ultimo(abb.raiz);
             (dato != NULL) ? printf("%s\n", mostrarPersona(dato)) : puts("NULL");
             dato = NULL;
             break;
         case BORRAR:
             printf("%s\n", (jxc_borrar(&abb.raiz, borrarPersona) ? "true" : "false"));
             break;
         case MOSTRAR:
             jxc_mostrar(abb.raiz, mostrarPersona);
             break;*/
        case PREORDEN:
            jxab_preOrden(abb.raiz, mostrarPersona);
            break;
        case INORDEN:
            jxab_inOrden(abb.raiz, mostrarPersona);
            break;
        case POSORDEN:
            jxab_posOrden(abb.raiz, mostrarPersona);
            break;
         case BORRAR:
             printf("%s\n", (jxab_borrar(&abb.raiz, borrarPersona) ? "true" : "false"));
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