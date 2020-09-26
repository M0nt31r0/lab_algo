#include <stdio.h>


int main(int argc, char *argv[])
{
    int n;
    printf("Digite um valor inteiro qualquer: ");
    scanf("%i",&n);
    
    // So sera printado na tela se n <= 3
    if(!(n>3))
    {
        printf("Valor digitado: ");
        printf("%i",n);
    }   
    return 0;
}
