#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
    printf("\t.:CALCULO MEDIA SIMPLES:.\n");
    float num, sum = 0.0;
    for (int i = 0; i < 3 ; i++)
    {
        printf("Nota %i:\n",i);
        scanf("%f",&num);
        if (num > 10.0 || num < 0.0)
        {
            printf("ERRO! Digite um valor valido.");
            return 0;
        }
        sum += num;
    }    
    printf("Media: %0.2f",sum/3);
    
    return 0;
}
