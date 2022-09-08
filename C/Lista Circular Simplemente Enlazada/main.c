#include <stdio.h>
#include <stdlib.h>
#include "Entrada.h"
#include "LCSE.h"
#include "Libreria.h"

enum
{
    SALIR,
    INSERTAR_AL_INICIO,
    INSERTAR_AL_FINAL,
    INSERTAR_ANTES_DE,
    INSERTAR_DESPUES_DE,
    REEMPLAZAR_EN,
    ELIMINAR_EL_PRIMERO,
    ELIMINAR_EL_ULTIMO,
    ELIMINAR_ANTES_DE,
    ELIMINAR_DESPUES_DE,
    ELIMINAR_EN,
    OBTENER_EL_PRIMERO,
    OBTENER_EL_ULTIMO,
    OBTENER_ANTES_DE,
    OBTENER_DESPUES_DE,
    OBTENER_EN,
    BUSCAR,
    BORRAR,
    MOSTRAR
};

const char lista[][100] = {"Salir",
                           "Insertar al inicio",
                           "Insertar al final",
                           "Insertar antes de",
                           "Insertar despues de",
                           "Reemplazar en",
                           "Eliminar el primero",
                           "Eliminar el ultimo",
                           "Eliminar antes de",
                           "Eliminar despues de",
                           "Eliminar en",
                           "Obtener el primero",
                           "Obtener el ultimo",
                           "Obtener antes de",
                           "Obtener despues de",
                           "Obtener en",
                           "Buscar",
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
    const unsigned int n = sizeof(lista) / sizeof(lista[0]);
    short int *opcion = NULL;
    Nodo *lcse = NULL;
    E *dato = NULL, *x = NULL;
    int *posicion = NULL;

    while (true)
    {
        system("cls");
        puts("\n\t\t.: LISTA CIRCULAR SIMPLEMENTE ENLAZADA :.\n");

        for (int i = 0; i < n; i++)
            printf("[%d] : %s\n", i, lista[i]);

        puts("");
        opcion = lectura("%hd");

        switch (*opcion)
        {
        case SALIR:
            borrar(&lcse);
            free(opcion);
            puts(EXIT_OPTION);

            return;
        case INSERTAR_AL_INICIO:
            dato = lectura("%d");
            insertarAlInicio(&lcse, dato);
            dato = NULL;
            break;
        case INSERTAR_AL_FINAL:
            dato = lectura("%d");
            insertarAlFinal(&lcse, dato);
            dato = NULL;
            break;
        case INSERTAR_ANTES_DE:
            dato = lectura("%d");
            x = lectura("%d");
            insertarAntesDe(&lcse, dato, x);
            dato = NULL;
            free(x);
            x = NULL;
            break;
        case INSERTAR_DESPUES_DE:
            dato = lectura("%d");
            x = lectura("%d");
            insertarDespuesDe(&lcse, dato, x);
            dato = NULL;
            free(x);
            x = NULL;
            break;
        case REEMPLAZAR_EN:
            dato = lectura("%d");
            x = lectura("%d");
            reemplazarEn(lcse, dato, x);
            dato = NULL;
            free(x);
            x = NULL;
            break;
        case ELIMINAR_EL_PRIMERO:
            eliminarElPrimero(&lcse);
            break;
        case ELIMINAR_EL_ULTIMO:
            eliminarElUltimo(&lcse);
            break;
        case ELIMINAR_ANTES_DE:
            x = lectura("%d");
            eliminarAntesDe(&lcse, x);
            free(x);
            x = NULL;
            break;
        case ELIMINAR_DESPUES_DE:
            x = lectura("%d");
            eliminarDespuesDe(&lcse, x);
            free(x);
            x = NULL;
            break;
        case ELIMINAR_EN:
            x = lectura("%d");
            eliminarEn(&lcse, x);
            free(x);
            x = NULL;
            break;
        case OBTENER_EL_PRIMERO:
            if (obtenerElPrimero(lcse) != NULL)
                printf("%d\n", *(E *)(obtenerElPrimero(lcse)));
            break;
        case OBTENER_EL_ULTIMO:
            if (obtenerElUltimo(lcse) != NULL)
                printf("%d\n", *(E *)(obtenerElUltimo(lcse)));
            break;
        case OBTENER_ANTES_DE:
            x = lectura("%d");

            if (obtenerAntesDe(lcse, x) != NULL)
                printf("%d\n", *(E *)(obtenerAntesDe(lcse, x)));

            free(x);
            x = NULL;
            break;
        case OBTENER_DESPUES_DE:
            x = lectura("%d");

            if (obtenerDespuesDe(lcse, x) != NULL)
                printf("%d\n", *(E *)(obtenerDespuesDe(lcse, x)));

            free(x);
            x = NULL;
            break;
        case OBTENER_EN:
            posicion = lectura("%d");

            if (obtenerEn(lcse, *posicion) != NULL)
                printf("%d\n", *(E *)(obtenerEn(lcse, *posicion)));

            free(posicion);
            posicion = NULL;
            break;
        case BUSCAR:
            x = lectura("%d");
            printf("%d\n", buscar(lcse, x));
            free(x);
            x = NULL;
            break;
        case BORRAR:
            borrar(&lcse);
            break;
        case MOSTRAR:
            mostrar(lcse);
            break;
        default:
            puts(NO_OPTION);
        }

        free(opcion);
        opcion = NULL;
        puts(CONTINUE_OPTION);
        flush_buffer();
    }
}