#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

enum
{
    false,
    true
};
enum
{
    SALIR,
    CONCATENAR,
    COMPARAR,
    COPIAR,
    MINUSCULAS,
    MAYUSCULAS,
    LIMPIAR
};

const char lista[][MAX] = {"Salir",
                           "Concatenar",
                           "Comparar",
                           "Copiar",
                           "Minusculas",
                           "Mayusculas",
                           "Limpiar"};

void menu();
void concatenar(const char *src1, const char *src2);
void comparar(const char *src1, const char *src2);
void copiar(const char *src);
void minusculas(const char *src);
void mayusculas(const char *src);
void limpiar(const char *src);
void leerInteger(int **var);
void leerString(char **var);

int main(int argc, char const *argv[])
{
    menu();

    return EXIT_SUCCESS;
}

void menu()
{
    unsigned int n = sizeof(lista) / sizeof(lista[0]);
    int opcion = SALIR;
    char *src1, *src2;

    puts("LECTURA(src1)");
    leerString(&src1);
    puts("LECTURA(src2)");
    leerString(&src2);

    while (true)
    {
        puts("\n\t\t.: CADENA DE CARACTERES :.\n");

        for (int i = 0; i < n; i++)
            printf("[%d] : %s\n", i, lista[i]);

        puts("");
        leerInteger(&opcion);

        switch (opcion)
        {
        case SALIR:
            free(src1);
            free(src2);
            puts("[SISTEMA] :- <Programa finalizado>");
            return;
        case CONCATENAR:
            concatenar(src1, src2);
            break;
        case COMPARAR:
            comparar(src1, src2);
            break;
        case COPIAR:
            copiar(src1);
            break;
        case MINUSCULAS:
            minusculas(src1);
            break;
        case MAYUSCULAS:
            mayusculas(src1);
            break;
        case LIMPIAR:
            limpiar(src1);
            break;
        default:
            puts("[SISTEMA] :- <Opcion incorrecta>");
        }
    }
}

void concatenar(const char *src1, const char *src2)
{
    size_t len_src1 = strlen(src1);
    size_t len_src2 = strlen(src2);
    char *dest = (char *)malloc((len_src1 + len_src2 + 1) * sizeof(char));
    *dest = '\0';
    strcat(dest, src1);
    strcat(dest, src2);
    printf("-> %s\n", dest);
    free(dest);
}

void comparar(const char *src1, const char *src2)
{
    if (strcmp(src1, src2) == 0)
        puts("-> Cadenas iguales.");
    else
        puts("-> Cadena diferentes.");
}

void copiar(const char *src)
{
    size_t len_src = strlen(src);
    char *dest = (char *)malloc((len_src + 1) * sizeof(char));
    strcpy(dest, src);
    printf("-> %s\n", dest);
    free(dest);
}

void minusculas(const char *src)
{
    size_t len_src = strlen(src);
    char *dest = (char *)malloc((len_src + 1) * sizeof(char));

    for (int i = 0; i < len_src; i++)
        dest[i] = tolower((unsigned char)src[i]);

    dest[len_src] = '\0';
    printf("-> %s\n", dest);
    free(dest);
}

void mayusculas(const char *src)
{
    size_t len_src = strlen(src);
    char *dest = (char *)malloc((len_src + 1) * sizeof(char));

    for (int i = 0; i < len_src; i++)
        dest[i] = toupper((unsigned char)src[i]);

    dest[len_src] = '\0';
    printf("-> %s\n", dest);
    free(dest);
}

void limpiar(const char *src)
{
    size_t len_src = strlen(src);
    char cadena[len_src + 1];
    char caracteres[] = "123456789";
    strcpy(cadena, src);

    int indiceCadena = 0, indiceCadenaLimpia = 0;
    int deberiaAgregarCaracter = 1;

    while (cadena[indiceCadena])
    {
        deberiaAgregarCaracter = 1;
        int indiceCaracteres = 0;

        while (caracteres[indiceCaracteres])
        {
            if (cadena[indiceCadena] == caracteres[indiceCaracteres])
                deberiaAgregarCaracter = 0;

            indiceCaracteres++;
        }

        if (deberiaAgregarCaracter)
        {
            cadena[indiceCadenaLimpia] = cadena[indiceCadena];
            indiceCadenaLimpia++;
        }

        indiceCadena++;
    }

    cadena[indiceCadenaLimpia] = '\0';
    char *dest = strdup(cadena);
    printf("-> %s\n", dest);
    free(dest);
}