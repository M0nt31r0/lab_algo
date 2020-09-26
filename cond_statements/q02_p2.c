#include <stdio.h>


int main(int argc, char *argv[])
{
    int n;
    printf("\t.:NEGATIVO PARA POSITIVO:.\n");
    printf("Digite um valor inteiro qualquer: ");
    scanf("%i",&n);

    if(n<=0)
    {
        n *= -1;
    }    
    printf("n: %i",n);
    return 0;
}
