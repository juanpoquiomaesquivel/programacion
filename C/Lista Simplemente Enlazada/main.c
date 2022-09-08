#include <stdio.h>
#include <stdlib.h>
#include "Entrada.h"
#include "Libreria.h"
#include "LSE.h"

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
    Nodo *lse = NULL;
    E *dato = NULL, *x = NULL;
    int *posicion = NULL;

    while (true)
    {
        system("cls");
        puts("\n\t\t.: LISTA SIMPLEMENTE ENLAZADA :.\n");

        for (int i = 0; i < n; i++)
            printf("[%d] : %s\n", i, lista[i]);

        puts("");
        opcion = lectura("%hd");

        switch (*opcion)
        {
        case SALIR:
            borrar(&lse);
            free(opcion);
            puts(EXIT_OPTION);

            return;
        case INSERTAR_AL_INICIO:
            dato = lectura("%d");
            insertarAlInicio(&lse, dato);
            dato = NULL;
            break;
        case INSERTAR_AL_FINAL:
            dato = lectura("%d");
            insertarAlFinal(&lse, dato);
            dato = NULL;
            break;
        case INSERTAR_ANTES_DE:
            dato = lectura("%d");
            x = lectura("%d");
            insertarAntesDe(&lse, dato, x);
            dato = NULL;
            free(x);
            x = NULL;
            break;
        case INSERTAR_DESPUES_DE:
            dato = lectura("%d");
            x = lectura("%d");
            insertarDespuesDe(&lse, dato, x);
            dato = NULL;
            free(x);
            x = NULL;
            break;
        case REEMPLAZAR_EN:
            dato = lectura("%d");
            x = lectura("%d");
            reemplazarEn(lse, dato, x);
            dato = NULL;
            free(x);
            x = NULL;
            break;
        case ELIMINAR_EL_PRIMERO:
            eliminarElPrimero(&lse);
            break;
        case ELIMINAR_EL_ULTIMO:
            eliminarElUltimo(&lse);
            break;
        case ELIMINAR_ANTES_DE:
            x = lectura("%d");
            eliminarAntesDe(&lse, x);
            free(x);
            x = NULL;
            break;
        case ELIMINAR_DESPUES_DE:
            x = lectura("%d");
            eliminarDespuesDe(&lse, x);
            free(x);
            x = NULL;
            break;
        case ELIMINAR_EN:
            x = lectura("%d");
            eliminarEn(&lse, x);
            free(x);
            x = NULL;
            break;
        case OBTENER_EL_PRIMERO:
            if (obtenerElPrimero(lse) != NULL)
                printf("%d\n", *(E *)(obtenerElPrimero(lse)));
            break;
        case OBTENER_EL_ULTIMO:
            if (obtenerElUltimo(lse) != NULL)
                printf("%d\n", *(E *)(obtenerElUltimo(lse)));
            break;
        case OBTENER_ANTES_DE:
            x = lectura("%d");

            if (obtenerAntesDe(lse, x) != NULL)
                printf("%d\n", *(E *)(obtenerAntesDe(lse, x)));

            free(x);
            x = NULL;
            break;
        case OBTENER_DESPUES_DE:
            x = lectura("%d");

            if (obtenerDespuesDe(lse, x) != NULL)
                printf("%d\n", *(E *)(obtenerDespuesDe(lse, x)));

            free(x);
            x = NULL;
            break;
        case OBTENER_EN:
            posicion = lectura("%d");

            if (obtenerEn(lse, *posicion) != NULL)
                printf("%d\n", *(E *)(obtenerEn(lse, *posicion)));

            free(posicion);
            posicion = NULL;
            break;
        case BUSCAR:
            x = lectura("%d");
            printf("%d\n", buscar(lse, x));
            free(x);
            x = NULL;
            break;
        case BORRAR:
            borrar(&lse);
            break;
        case MOSTRAR:
            mostrar(lse);
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