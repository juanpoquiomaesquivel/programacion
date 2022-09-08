#include <stdio.h>
#include <stdlib.h>
#include "Cola.h"
#include "Entrada.h"
#include "Libreria.h"

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
    const unsigned int n = sizeof(lista) / sizeof(lista[0]);
    short int *opcion = NULL;
    Nodo *cola = NULL;
    E *dato = NULL;

    while (true)
    {
        system("cls");
        puts("\n\t\t.: COLA :.\n");

        for (int i = 0; i < n; i++)
            printf("[%d] : %s\n", i, lista[i]);

        puts("");
        opcion = lectura("%hd");

        switch (*opcion)
        {
        case SALIR:
            borrar(&cola);
            free(opcion);
            puts(EXIT_OPTION);

            return;
        case ENCOLAR:
            dato = lectura("%d");
            encolar(&cola, dato);
            dato = NULL;
            break;
        case DECOLAR:
            decolar(&cola);
            break;
        case FRENTE:
            if (frente(cola) != NULL)
                printf("%d\n", *(E *)(frente(cola)));
            break;
        case ULTIMO:
            if (ultimo(cola) != NULL)
                printf("%d\n", *(E *)(ultimo(cola)));
            break;
        case BORRAR:
            borrar(&cola);
            break;
        case MOSTRAR:
            mostrar(cola);
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