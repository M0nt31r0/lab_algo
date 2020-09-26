#include <stdio.h>
#include <stdlib.h>

// funcao que compara os valores
int compare (const void * a, const void * b)
{
    return (*(int*)a - *(int*)b);
}

int main(int argc, char *argv[])
{
    int num[3];
    int c;

    for(c = 0;c < 3;c++)
    {
        printf("%iº valor: ",c);
        scanf("%i",&num[c]);
        
        // checa se o valor digitado é igual ao anterior
        // pede input do usuário novamente
        if(num[c] == num[c-1]){
            while(num[c] == num[c-1]){
                printf("Valor repetido, digite novamente!\n");
                printf("%iº valor: ",c);
                scanf("%i", &num[c]);
            }
        }    
    }
    // quicksort
    qsort(num, 3, sizeof(int),compare);
    
    //mostra valores ordenados
    printf("Número ordenados: \n");
    for(c = 0; c < 3; c++)
    {
        printf("%d ",num[c]);
    }
    return 0;
}
