#include <stdio.h>


int main(int argc, char *argv[])
{
    int num;
    printf("\t.:FAIXA DE VALORES:.\n");
    printf("Digite um número inteiro qualquer: ");
    scanf("%i",&num);

    if(num >= 1 && num <= 9)
    {
        printf("O valor está na faixa permitida!");
    }    
    else
    {
        printf("O valor informado nao e permitido pois nao esta na faixa de 1 a 9");
    }
    return 0;
}
