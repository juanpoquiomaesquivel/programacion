#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct p
{
    char nom[20];
    char dni[20];
    int edad;
} PER;

int cmp(const void *a, const void *b)
{
    PER p1 = *(PER *)a;
    PER p2 = *(PER *)b;

    printf("%d\n", strcmp(p1.nom, p2.nom));
    printf("%d\n", strcmp(p1.dni, p2.dni));
    printf("%d\n", p1.edad - p2.edad);

    return 0;
}

int main(int argc, char const *argv[])
{
    PER p1 = {.nom = "JUAN", "75471208", 20};
    PER p2 = {.nom = "juan", "75471202", 22};

    cmp(&p1, &p2);

    return 0;
}
