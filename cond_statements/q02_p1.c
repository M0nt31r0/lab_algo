#include <stdio.h>


int main(int argc, char *argv[])
{
    int num;
    printf("\t.:NÚMERO PAR OU IMPAR:.\n");
    printf("Digite um número inteiro qualquer: ");
    scanf("%i",&num);
    if (num%2 == 0)
    {
        printf("O valor digitado é par.");
    }    
    else
    {
        printf("O valor digitado é impar.");
    }
    return 0;
}
