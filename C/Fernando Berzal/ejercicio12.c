#include <stdio.h>
#include <math.h>

int main()
{
    double x1, x2, xc;
    double a = 7.5;
    double b = 1.3;
    double c = 1.8;
    double delta;

    printf("# Ingrese el valor de \'a\': ");
    scanf("%lf", &a);
    printf("# Ingrese el valor de \'b\': ");
    scanf("%lf", &b);
    printf("# Ingrese el valor de \'c\': ");
    scanf("%lf", &c);

    delta = pow(b, 2) - 4 * a * c;

    if (delta > 0)
    {
        printf("\nSolucion de raices reales distintas.\n");

        x1 = (-b + sqrt(delta)) / (2 * a);
        x2 = (-b - sqrt(delta)) / (2 * a);

        printf("x1 = %.3lf y x2 = %.3lf\n", x1, x2);
    }
    else if (delta == 0)
    {
        printf("\nSolucion de raices reales de multiplicidad doble.\n");

        x1 = (-b + sqrt(delta)) / (2 * a);

        printf("x = %.3lf", x1);
    }
    else
    {
        printf("\nSolucion de raices complejas conjugadas.\n");

        x1 = (-b) / (2 * a);
        xc = (sqrt(-delta)) / (2 * a);

        printf("x1 = %.3lf + i%.3lf y x2 = %.3lf - i%.3lf\n", x1, xc, x1, xc);
    }

    return 0;
}
