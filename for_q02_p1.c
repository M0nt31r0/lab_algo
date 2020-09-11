#include <stdio.h>


int main(int argc, char *argv[])
{
    int num;
    printf("Digite um número inteiro qualquer: ");
    scanf("%i",&num);
    
    for(int c = 1;c < 11;c++)
    {
        printf("%i x %i = %i\n",num,c,num*c);
    }    
    return 0;
}
