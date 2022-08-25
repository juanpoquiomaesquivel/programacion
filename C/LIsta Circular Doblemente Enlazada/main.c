#include "LCDE.h"
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
    Nodo *lcde = NULL;
    unsigned int n = sizeof(lista) / sizeof(lista[0]);
    int opcion = SALIR, posicion = 0;
    E *dato = NULL, *x = NULL;

    while (true)
    {
        puts("\n\t\t.: LISTA CIRCULAR DOBLEMENTE ENLAZADA :.\n");

        for (int i = 0; i < n; i++)
            printf("[%d] : %s\n", i, lista[i]);

        printf("\n>> ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case SALIR:
            borrar(&lcde);
            puts("[SISTEMA] :- <Programa terminado>");
            return;
        case INSERTAR_AL_INICIO:
            printf(">> ");
            dato = (E *)malloc(sizeof(E));
            scanf("%d", dato);
            insertarAlInicio(&lcde, dato);
            dato = NULL;
            break;
        case INSERTAR_AL_FINAL:
            printf(">> ");
            dato = (E *)malloc(sizeof(E));
            scanf("%d", dato);
            insertarAlFinal(&lcde, dato);
            dato = NULL;
            break;
        case INSERTAR_ANTES_DE:
            printf(">> ");
            dato = (E *)malloc(sizeof(E));
            scanf("%d", dato);
            printf(">> ");
            x = (E *)malloc(sizeof(E));
            scanf("%d", x);
            insertarAntesDe(&lcde, dato, x);
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
            insertarDespuesDe(&lcde, dato, x);
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
            reemplazarEn(lcde, dato, x);
            dato = NULL;
            free(x);
            x = NULL;
            break;
        case ELIMINAR_EL_PRIMERO:
            eliminarElPrimero(&lcde);
            break;
        case ELIMINAR_EL_ULTIMO:
            eliminarElUltimo(&lcde);
            break;
        case ELIMINAR_ANTES_DE:
            printf(">> ");
            x = (E *)malloc(sizeof(E));
            scanf("%d", x);
            eliminarAntesDe(&lcde, x);
            free(x);
            x = NULL;
            break;
        case ELIMINAR_DESPUES_DE:
            printf(">> ");
            x = (E *)malloc(sizeof(E));
            scanf("%d", x);
            eliminarDespuesDe(&lcde, x);
            free(x);
            x = NULL;
            break;
        case ELIMINAR_EN:
            printf(">> ");
            x = (E *)malloc(sizeof(E));
            scanf("%d", x);
            eliminarEn(&lcde, x);
            free(x);
            x = NULL;
            break;
        case OBTENER_EL_PRIMERO:
            if (obtenerElPrimero(lcde) != NULL)
                printf("%d\n", *(E *)(obtenerElPrimero(lcde)));
            break;
        case OBTENER_EL_ULTIMO:
            if (obtenerElUltimo(lcde) != NULL)
                printf("%d\n", *(E *)(obtenerElUltimo(lcde)));
            break;
        case OBTENER_ANTES_DE:
            printf(">> ");
            x = (E *)malloc(sizeof(E));
            scanf("%d", x);

            if (obtenerAntesDe(lcde, x) != NULL)
                printf("%d\n", *(E *)(obtenerAntesDe(lcde, x)));

            free(x);
            x = NULL;
            break;
        case OBTENER_DESPUES_DE:
            printf(">> ");
            x = (E *)malloc(sizeof(E));
            scanf("%d", x);

            if (obtenerDespuesDe(lcde, x) != NULL)
                printf("%d\n", *(E *)(obtenerDespuesDe(lcde, x)));

            free(x);
            x = NULL;
            break;
        case OBTENER_EN:
            printf(">> ");
            scanf("%d", &posicion);

            if (obtenerEn(lcde, posicion) != NULL)
                printf("%d\n", *(E *)(obtenerEn(lcde, posicion)));
            break;
        case BUSCAR:
            printf(">> ");
            x = (E *)malloc(sizeof(E));
            scanf("%d", x);
            printf("%d\n", buscar(lcde, x));
            free(x);
            x = NULL;
            break;
        case BORRAR:
            borrar(&lcde);
            break;
        case MOSTRAR:
            mostrar(lcde);
            break;
        default:
            puts("[SISTEMA] :- <Opcion incorrecta>");
        }
    }
}