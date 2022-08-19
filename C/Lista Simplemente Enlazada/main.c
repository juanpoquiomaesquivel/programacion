#include "LSE.h"
#include <stdio.h>
#include <stdlib.h>

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
    Nodo *lse = NULL;
    int n = sizeof(lista) / sizeof(lista[0]), opcion = SALIR, posicion = 0;
    E *dato = NULL, *x = NULL;

    while (1)
    {
        puts("\n\t\t.: LISTA SIMPLEMENTE ENLAZADA :.\n");

        for (int i = 0; i < n; i++)
            printf("[%d] : %s\n", i, lista[i]);

        printf("\n>> ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case SALIR:
            puts("[SISTEMA] :- <Programa terminado>");
            return;
        case INSERTAR_AL_INICIO:
            printf(">> ");
            dato = (E *)malloc(sizeof(E));
            scanf("%d", dato);
            insertarAlInicio(&lse, dato);
            dato = NULL;
            break;
        case INSERTAR_AL_FINAL:
            printf(">> ");
            dato = (E *)malloc(sizeof(E));
            scanf("%d", dato);
            insertarAlFinal(&lse, dato);
            dato = NULL;
            break;
        case INSERTAR_ANTES_DE:
            printf(">> ");
            dato = (E *)malloc(sizeof(E));
            scanf("%d", dato);
            printf(">> ");
            x = (E *)malloc(sizeof(E));
            scanf("%d", x);
            insertarAntesDe(&lse, dato, x);
            dato = NULL;
            free(x);
            x = NULL;
            break;
        case INSERTAR_DESPUES_DE:
            printf(">> ");
            dato = (E *)malloc(sizeof(E));
            scanf("%d", dato);
            printf(">> ");
            x = (E *)malloc(sizeof(E));
            scanf("%d", x);
            insertarDespuesDe(&lse, dato, x);
            dato = NULL;
            free(x);
            x = NULL;
            break;
        case REEMPLAZAR_EN:
            printf(">> ");
            dato = (E *)malloc(sizeof(E));
            scanf("%d", dato);
            printf(">> ");
            x = (E *)malloc(sizeof(E));
            scanf("%d", x);
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
            printf(">> ");
            x = (E *)malloc(sizeof(E));
            scanf("%d", x);
            eliminarAntesDe(&lse, x);
            free(x);
            x = NULL;
            break;
        case ELIMINAR_DESPUES_DE:
            printf(">> ");
            x = (E *)malloc(sizeof(E));
            scanf("%d", x);
            eliminarDespuesDe(&lse, x);
            free(x);
            x = NULL;
            break;
        case ELIMINAR_EN:
            printf(">> ");
            x = (E *)malloc(sizeof(E));
            scanf("%d", x);
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
            printf(">> ");
            x = (E *)malloc(sizeof(E));
            scanf("%d", x);

            if (obtenerAntesDe(lse, x) != NULL)
                printf("%d\n", *(E *)(obtenerAntesDe(lse, x)));

            free(x);
            x = NULL;
            break;
        case OBTENER_DESPUES_DE:
            printf(">> ");
            x = (E *)malloc(sizeof(E));
            scanf("%d", x);

            if (obtenerDespuesDe(lse, x) != NULL)
                printf("%d\n", *(E *)(obtenerDespuesDe(lse, x)));

            free(x);
            x = NULL;
            break;
        case OBTENER_EN:
            printf(">> ");
            scanf("%d", &posicion);

            if (obtenerEn(lse, posicion) != NULL)
                printf("%d\n", *(E *)(obtenerEn(lse, posicion)));
            break;
        case BUSCAR:
            printf(">> ");
            x = (E *)malloc(sizeof(E));
            scanf("%d", x);
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
            puts("[SISTEMA] :- <Opcion incorrecta>");
        }
    }
}