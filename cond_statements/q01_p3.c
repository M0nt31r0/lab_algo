#include <stdio.h>
#include <stdlib.h>

// funcao comparar
int compare (const void * a, const void * b)
{
    return (*(int*)a - *(int*)b);
}

int main(int argc, char *argv[])
{
    int num[3], c;
    
    // input do usuário
    for(c = 0;c < 3;c++)
    {
        printf("%iº valor: ",c);
        scanf("%i", &num[c]);    
    }
    
    // funcao qsort
    qsort(num, 3, sizeof(int),compare);
    
    // mostra valores ordenados
    printf("Número ordenados: \n");
    for(c = 0; c < 3; c++)
    {
        printf("%d ",num[c]);
    }
    return 0;
}
