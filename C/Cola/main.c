#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Cola.h"
#include "Entrada.h"
#include "Libreria.h"
#include "Persona.h"

enum
{
    SALIR,
    ENCOLAR,
    DECOLAR,
    FRENTE,
    ULTIMO,
    BORRAR,
    MOSTRAR
};

const char lista[][100] = {"Salir",
                           "Encolar",
                           "Decolar",
                           "Frente",
                           "Ultimo",
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
    jxc_Cola cola = {.del = borrarPersona, .str = mostrarPersona, .cabeza = NULL};
    void *dato = NULL;

    while (true)
    {
        system("cls");
        puts("\n\t\t.: COLA :.\n");

        for (size_t i = 0; i < n; i++)
            printf("[%d] : %s\n", i, lista[i]);

        puts("");
        opcion = (short int *)leerEntrada("%hd", "Ingrese una opcion");

        switch (*opcion)
        {
        case SALIR:
            jxc_borrar(&cola);
            free(opcion);
            puts(MS_PROGRAMA_FINALIZADO);

            return;
        case ENCOLAR:
            dato = crearPersona();
            jxc_encolar(&cola, dato);
            dato = NULL;
            break;
        case DECOLAR:
            printf("%s\n", (jxc_decolar(&cola) ? "true" : "false"));
            break;
        case FRENTE:
            dato = jxc_frente(&cola);
            (dato != NULL) ? printf("%s\n", mostrarPersona(dato)) : puts("NULL");
            dato = NULL;
            break;
        case ULTIMO:
            dato = jx_ultimo(&cola);
            (dato != NULL) ? printf("%s\n", mostrarPersona(dato)) : puts("NULL");
            dato = NULL;
            break;
        case BORRAR:
            printf("%s\n", (jxc_borrar(&cola) ? "true" : "false"));
            break;
        case MOSTRAR:
            jxc_mostrar(&cola);
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