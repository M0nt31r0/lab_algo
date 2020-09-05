#include <stdio.h>
#include <stdlib.h>

// funcao recebe dois numeros do array e os compara
// se (a - b) > 0 entao a > b e resultado > 0
// se *(int*)b - *(int*)a o array passa a ser decrescente
int compare (const void * a, const void * b)
{
    return (*(int*)a - *(int*)b);
}

int main(int argc, char *argv[])
{
    int num[3], c;
    
    // pede input do usuário
    for(c = 0;c < 3;c++)
    {
        printf("%iº valor: ",c);
        scanf("%i", &num[c]);    
    }

    // ordena array
    // void qsort(void *base, size_t nitems,size_t size, int(*compare)(const void *,const void *))
    // base é um ponteiro para primeiro elemento do array
    // nitems é o número de elementos do array
    // size é o tamanho em bytes de cada elemento
    // e compare é a função de comparação 
    qsort(num, 3, sizeof(int),compare);
    
    //mostra valores ordenados
    printf("Número ordenados: \n");
    for(c = 0; c < 3; c++)
    {
        printf("%d ",num[c]);
    }
    return 0;
}
