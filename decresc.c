#include <stdio.h>

int main(int argc, char *argv[])
{
    int a,b;

    printf("Valor de a: ");
    scanf("%i",&a);
    printf("Valor de b: ");
    scanf("%i",&b);

    if(a>b)
    {
        printf("Ordem decrescente: %i %i\n",a,b);
    }
    else
    {
        printf("Ordem decrescente: %i %i\n",b,a);
    }
    return 0;
}
