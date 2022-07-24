#include <stdio.h>

int main()
{
    double F;
    double C = 36.784;

    printf("# Ingrese el valor de \'C\' (en grados Celsius): ");
    scanf("%lf", &C);

    F = ((double)9 / 5) * C + 32;

    printf("\n%.3lf grados Celsius es, en grados Farenheit, igual a: %.3lf\n", C, F);

    return 0;
}