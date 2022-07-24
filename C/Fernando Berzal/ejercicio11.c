#include <stdio.h>

int main()
{
    double dolares = 157.89;
    double tipoDeCambio = 0.97899331;
    double euros;
    double pesetas = 166.386;
    double beneficios = 0.015;

    printf("# Ingrese la cantidad de dolares a cambiar: ");
    scanf("%lf", &dolares);

    printf("# Ingrese el tipo de cambio: ");
    scanf("%lf", &tipoDeCambio);

    euros = dolares * tipoDeCambio;
    beneficios *= euros;
    euros -= beneficios;
    pesetas *= euros;

    printf("\nTipo de cambio: %.3lf\n", tipoDeCambio);
    printf("Cantidad en euros menos beneficios: %.3lf\n", euros);
    printf("Cantidad en pesetas: %.3lf\n", pesetas);
    printf("Beneficios del cambista: %.3lf\n", beneficios);

    return 0;
}