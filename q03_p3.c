#include <stdio.h>


int main(int argc, char *argv[])
{
    short int i;
    printf("Idade: ");
    scanf("%hi",&i);
    
    if(i > 0 && i <= 10)
    {
        printf("Olá criança");
    }  
    else if(i > 10 && i <= 14)
    {
        printf("Olá, você é um(a) pré-adolescente");
    }  
    else if(i > 14 && i <= 18)
    {
        printf("Parabéns, você já pode ser eleitor");
    }
    else if(i > 18 && i <= 21)
    {
        printf("Hummm, você já é um adulto");
    }
    else
    {
        printf("Bem, agora já está na hora de sair de casa e seguir sua vida :)");
    }
    return 0;
}
