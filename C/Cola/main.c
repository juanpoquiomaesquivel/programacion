#include "Cola.h"
#include "Entrada.h"
#include <stdio.h>
#include <stdlib.h>

#ifndef LEN_STR
#define LEN_STR 100
#endif

#ifndef EXIT_OPTION
#define EXIT_OPTION "[SISTEMA] :- <Programa finalizado>"
#endif

#ifndef NO_OPTION
#define NO_OPTION "[SISTEMA] :- <Opcion incorrecta>"
#endif

#ifndef CONTINUE_OPTION
#define CONTINUE_OPTION "[SISTEMA] :- <Presione ENTER para continuar>"
#endif

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

const char lista[][LEN_STR] = {"Salir",
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
    short int opcion = SALIR;
    Nodo *cola = NULL;
    E *dato = NULL;

    while (true)
    {
        system("cls");
        puts("\n\t\t.: COLA :.\n");

        for (int i = 0; i < n; i++)
            printf("[%d] : %s\n", i, lista[i]);

        printf("\n>> ");
        scanf("%hd", &opcion);
        flush();

        switch (opcion)
        {
        case SALIR:
            borrar(&cola);
            puts(EXIT_OPTION);

            return;
        case ENCOLAR:
            leerInteger(&dato);
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

        puts(CONTINUE_OPTION);
        flush();
    }
}