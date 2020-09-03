#include <stdio.h>


int main(int argc, char *argv[])
{
    int a,b;
    printf("\t.:DIFERENCA ENTRE DOIS NUMEROS:.\n");
    printf("Digite 2 valores inteiros: \n");
    scanf("%i%i",&a,&b);
    if(a>b)
    {
        b = a - b;
    }
    else
    {
        b = b - a;
    }
    printf("Diferenca: %i",b);
    return 0;
}
