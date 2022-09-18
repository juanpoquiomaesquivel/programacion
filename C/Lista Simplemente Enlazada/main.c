#include <stdio.h>
#include <stdlib.h>
#include "Entrada.h"
#include "Libreria.h"
#include "LSE.h"
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
    jxls_LSE lse = {.cabeza = NULL};
    void *dato = NULL, *x = NULL;
    int *posicion = NULL;

    while (true)
    {
        system("cls");
        puts("\n\t\t.: LISTA SIMPLEMENTE ENLAZADA :.\n");

        for (size_t i = 0; i < n; i++)
            printf("[%d] : %s\n", i, lista[i]);

        puts("");
        opcion = (short int *)leerEntrada("%hd", "Ingrese una opcion");

        switch (*opcion)
        {
        case SALIR:
            jxls_borrar(&lse.cabeza, borrarPersona);
            free(opcion);
            puts(MS_PROGRAMA_FINALIZADO);

            return;
        case INSERTAR_AL_INICIO:
            dato = crearPersona();
            jxls_insertarAlInicio(&lse.cabeza, dato);
            dato = NULL;
            break;
        case INSERTAR_AL_FINAL:
            dato = crearPersona();
            jxls_insertarAlFinal(&lse.cabeza, dato);
            dato = NULL;
            break;
        case INSERTAR_ANTES_DE:
            dato = crearPersona();
            x = crearPersona();
            printf("%s\n", (jxls_insertarAntesDe(&lse.cabeza, dato, x, compararPersona) ? "true" : "false"));
            dato = NULL;
            borrarPersona(x);
            x = NULL;
            break;
        case INSERTAR_DESPUES_DE:
            dato = crearPersona();
            x = crearPersona();
            printf("%s\n", (jxls_insertarDespuesDe(&lse.cabeza, dato, x, compararPersona) ? "true" : "false"));
            dato = NULL;
            borrarPersona(x);
            x = NULL;
            break;
        case REEMPLAZAR_EN:
            dato = crearPersona();
            x = crearPersona();
            printf("%s\n", (jxls_reemplazarEn(lse.cabeza, dato, x, borrarPersona, compararPersona) ? "true" : "false"));
            dato = NULL;
            borrarPersona(x);
            x = NULL;
            break;
        case ELIMINAR_EL_PRIMERO:
            printf("%s\n", (jxls_eliminarElPrimero(&lse.cabeza, borrarPersona) ? "true" : "false"));
            break;
        case ELIMINAR_EL_ULTIMO:
            printf("%s\n", (jxls_eliminarElUltimo(&lse.cabeza, borrarPersona) ? "true" : "false"));
            break;
        case ELIMINAR_ANTES_DE:
            x = crearPersona();
            printf("%s\n", (jxls_eliminarAntesDe(&lse.cabeza, x, borrarPersona, compararPersona) ? "true" : "false"));
            borrarPersona(x);
            x = NULL;
            break;
        case ELIMINAR_DESPUES_DE:
            x = crearPersona();
            printf("%s\n", (jxls_eliminarDespuesDe(&lse.cabeza, x, borrarPersona, compararPersona) ? "true" : "false"));
            borrarPersona(x);
            x = NULL;
            break;
        case ELIMINAR_EN:
            x = crearPersona();
            printf("%s\n", (jxls_eliminarEn(&lse.cabeza, x, borrarPersona, compararPersona) ? "true" : "false"));
            borrarPersona(x);
            x = NULL;
            break;
        case OBTENER_EL_PRIMERO:
            dato = jxls_obtenerElPrimero(lse.cabeza);
            (dato != NULL) ? printf("%s\n", mostrarPersona(dato)) : puts("NULL");
            dato = NULL;
            break;
        case OBTENER_EL_ULTIMO:
            dato = jxls_obtenerElUltimo(lse.cabeza);
            (dato != NULL) ? printf("%s\n", mostrarPersona(dato)) : puts("NULL");
            dato = NULL;
            break;
        case OBTENER_ANTES_DE:
            x = crearPersona();
            dato = jxls_obtenerAntesDe(lse.cabeza, x, compararPersona);
            (dato != NULL) ? printf("%s\n", mostrarPersona(dato)) : puts("NULL");
            dato = NULL;
            borrarPersona(x);
            x = NULL;
            break;
        case OBTENER_DESPUES_DE:
            x = crearPersona();
            dato = jxls_obtenerDespuesDe(lse.cabeza, x, compararPersona);
            (dato != NULL) ? printf("%s\n", mostrarPersona(dato)) : puts("NULL");
            dato = NULL;
            borrarPersona(x);
            x = NULL;
            break;
        case OBTENER_EN:
            posicion = leerEntrada("%d", "Ingrese una posicion");
            dato = jxls_obtenerEn(lse.cabeza, *posicion);
            (dato != NULL) ? printf("%s\n", mostrarPersona(dato)) : puts("NULL");
            dato = NULL;
            free(posicion);
            posicion = NULL;
            break;
        case BUSCAR:
            x = crearPersona();
            printf("%d\n", jxls_buscar(lse.cabeza, x, compararPersona));
            borrarPersona(x);
            x = NULL;
            break;
        case BORRAR:
            printf("%s\n", (jxls_borrar(&lse.cabeza, borrarPersona) ? "true" : "false"));
            break;
        case MOSTRAR:
            jxls_mostrar(lse.cabeza, mostrarPersona);
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