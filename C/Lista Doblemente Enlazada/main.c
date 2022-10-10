#include <stdio.h>
#include <stdlib.h>
#include "Entrada.h"
#include "LDE.h"
#include "Libreria.h"
#include "Persona.h"

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
    const size_t n = sizeof(lista) / sizeof(lista[0]);
    short int *opcion = NULL;
    jxld_LDE lde = {.del = borrarPersona, .cmp = compararPersona, .str = mostrarPersona, .cabeza = NULL};
    void *dato = NULL, *x = NULL;
    int *posicion = NULL;

    while (true)
    {
        system("cls");
        puts("\n\t\t.: LISTA DOBLEMENTE ENLAZADA :.\n");

        for (int i = 0; i < n; i++)
            printf("[%d] : %s\n", i, lista[i]);

        puts("");
        opcion = (short int *)leerEntrada("%hd", "Ingrese una opcion");

        switch (*opcion)
        {
        case SALIR:
            jxld_borrar(&lde);
            free(opcion);
            puts(MS_PROGRAMA_FINALIZADO);

            return;
        case INSERTAR_AL_INICIO:
            dato = crearPersona();
            jxld_insertarAlInicio(&lde, dato);
            dato = NULL;
            break;
        case INSERTAR_AL_FINAL:
            dato = crearPersona();
            jxld_insertarAlFinal(&lde, dato);
            dato = NULL;
            break;
        case INSERTAR_ANTES_DE:
            dato = crearPersona();
            x = crearPersona();
            printf("%s\n", (jxld_insertarAntesDe(&lde, dato, x) ? "true" : "false"));
            dato = NULL;
            borrarPersona(x);
            x = NULL;
            break;
        case INSERTAR_DESPUES_DE:
            dato = crearPersona();
            x = crearPersona();
            printf("%s\n", (jxld_insertarDespuesDe(&lde, dato, x) ? "true" : "false"));
            dato = NULL;
            borrarPersona(x);
            x = NULL;
            break;
        case REEMPLAZAR_EN:
            dato = crearPersona();
            x = crearPersona();
            printf("%s\n", (jxld_reemplazarEn(&lde, dato, x) ? "true" : "false"));
            dato = NULL;
            borrarPersona(x);
            x = NULL;
            break;
        case ELIMINAR_EL_PRIMERO:
            printf("%s\n", (jxld_eliminarElPrimero(&lde) ? "true" : "false"));
            break;
        case ELIMINAR_EL_ULTIMO:
            printf("%s\n", (jxld_eliminarElUltimo(&lde) ? "true" : "false"));
            break;
        case ELIMINAR_ANTES_DE:
            x = crearPersona();
            printf("%s\n", (jxld_eliminarAntesDe(&lde, x) ? "true" : "false"));
            borrarPersona(x);
            x = NULL;
            break;
        case ELIMINAR_DESPUES_DE:
            x = crearPersona();
            printf("%s\n", (jxld_eliminarDespuesDe(&lde, x) ? "true" : "false"));
            borrarPersona(x);
            x = NULL;
            break;
        case ELIMINAR_EN:
            x = crearPersona();
            printf("%s\n", (jxld_eliminarEn(&lde, x) ? "true" : "false"));
            borrarPersona(x);
            x = NULL;
            break;
        case OBTENER_EL_PRIMERO:
            dato = jxld_obtenerElPrimero(&lde);
            (dato != NULL) ? printf("%s\n", mostrarPersona(dato)) : puts("NULL");
            dato = NULL;
            break;
        case OBTENER_EL_ULTIMO:
            dato = jxld_obtenerElUltimo(&lde);
            (dato != NULL) ? printf("%s\n", mostrarPersona(dato)) : puts("NULL");
            dato = NULL;
            break;
        case OBTENER_ANTES_DE:
            x = crearPersona();
            dato = jxld_obtenerAntesDe(&lde, x);
            (dato != NULL) ? printf("%s\n", mostrarPersona(dato)) : puts("NULL");
            dato = NULL;
            borrarPersona(x);
            x = NULL;
            break;
        case OBTENER_DESPUES_DE:
            x = crearPersona();
            dato = jxld_obtenerDespuesDe(&lde, x);
            (dato != NULL) ? printf("%s\n", mostrarPersona(dato)) : puts("NULL");
            dato = NULL;
            borrarPersona(x);
            x = NULL;
            break;
        case OBTENER_EN:
            posicion = leerEntrada("%d", "Ingrese una posicion");
            dato = jxld_obtenerEn(&lde, *posicion);
            (dato != NULL) ? printf("%s\n", mostrarPersona(dato)) : puts("NULL");
            dato = NULL;
            free(posicion);
            posicion = NULL;
            break;
        case BUSCAR:
            x = crearPersona();
            printf("%d\n", jxld_buscar(&lde, x));
            borrarPersona(x);
            x = NULL;
            break;
        case BORRAR:
            printf("%s\n", (jxld_borrar(&lde) ? "true" : "false"));
            break;
        case MOSTRAR:
            jxld_mostrar(&lde);
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