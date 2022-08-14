#include "Cola.h"
#include <stdio.h>
#include <stdlib.h>

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

void menu();

int main(int argc, char const *argv[])
{
    menu();

    return EXIT_SUCCESS;
}

void menu()
{
    struct Nodo *cola = NULL;
    int opcion = SALIR;
    E *dato = NULL;
    char lista[][100] = {"Salir",
                         "Encolar",
                         "Decolar",
                         "Frente",
                         "Ultimo",
                         "Borrar",
                         "Mostrar"};

    while (1)
    {
        puts("\n\t\t.: COLA :.\n");

        for (int i = 0; i < sizeof(lista) / 100; i++)
            printf("[%d] : %s\n", i, lista[i]);

        printf("\n>> ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case SALIR:
            puts("[SISTEMA] :- <Programa terminado>");
            return;
        case ENCOLAR:
            printf(">> ");
            dato = (E *)malloc(sizeof(E));
            scanf("%d", dato);
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
            puts("[SISTEMA] :- <Opcion incorrecta>");
        }
    }
}