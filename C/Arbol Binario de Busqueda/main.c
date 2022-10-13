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
    REEMPLAZAR,
    PREORDEN,
    INORDEN,
    POSORDEN,
    PORNIVEL,
    BORRAR,
    MOSTRAR
};

const char lista[][100] = {"Salir",
                           "Insertar",
                           "Eliminar",
                           "Buscar",
                           "Reemplazar",
                           "Preorden",
                           "Inorden",
                           "Posorden",
                           "Por nivel",
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
    jxab_ABB abb = {.del = borrarPersona, .cmp = compararPersona, .str = mostrarPersona, .raiz = NULL};
    void *dato = NULL, *x = NULL;

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
            jxab_borrar(&abb);
            free(opcion);
            puts(MS_PROGRAMA_FINALIZADO);

            return;
        case INSERTAR:
            dato = crearPersona();
            jxab_insertar(&abb, dato);
            dato = NULL;
            break;
        case BUSCAR:
            x = crearPersona();
            printf("%s\n", (jxab_buscar(&abb, x) ? "true" : "false"));
            borrarPersona(x);
            x = NULL;
            break;
        case PREORDEN:
            jxab_preorden(&abb);
            break;
        case INORDEN:
            jxab_inorden(&abb);
            break;
        case POSORDEN:
            jxab_posorden(&abb);
            break;
        case PORNIVEL:
            jxab_porNivel(&abb);
            break;
        case BORRAR:
            printf("%s\n", (jxab_borrar(&abb) ? "true" : "false"));
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