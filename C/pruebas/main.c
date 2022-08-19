#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int *pint;
    puts("Lee por primera vez");
    scanf("%d", pint);
    //int *p = pint;
    //printf("pint = %d, p = %d\n", *pint, *p);
    free(pint);

    puts("\nLee por segunda vez");
    /*scanf("%d", pint);
    printf("pint = %d, p = %d\n", *pint, *p);*/

    return 0;
}
