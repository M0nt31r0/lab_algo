#include <stdio.h>
#include <stdlib.h>

// tamanho do array
#define SIZE 10


// descobre se o número informado já existe
int exists(int *array, int size, int n){
    for (register int i = 0; i < size; i++){
        if(array[i] == n)
            return 1;
    }
    return 0;
}

// procura por posicao do elemento no array
int Search(int *array, int size, int toSearch)
{
    int c = 0, find = 0;
    while(c <= size && find == 0) {
        if(array[c] == toSearch)
            printf("Posicao: [%i] = %i\n",c,array[c]);
            find++;
        c++;
    }
    return find; 
}
// remove elemento de acordo com nº digitado
int Remove(int *array, int size, int toRemove)
{
    int *arrFim = (array + size - 1);
    int counter = 0;
    while(array <= arrFim)
    {
        if(*array == toRemove){
            *array = -1;
            counter++;
        }
        array++;
    }
    if(counter == 0) printf("RA não encontrado!");
    return 0;
}
void printArray(int *array, int size){
    for(int i = 0; i < size; i++) printf("[%i] = %i\n",i,array[i]);
}

int main(int argc, char *argv[])
{
    int *ra = (int *) malloc(sizeof(int) * SIZE);
    if(ra == NULL){
        exit(EXIT_FAILURE);
    }
    int opc,c,n,toRemove,toSearch;
    
    do{
        int v = 0;
        printf("\n\t.:RA's:.\n");
        printf("\n1 - Adicionar");
        printf("\n2 - Remover");
        printf("\n3 - Imprimir posicao");
        printf("\n4 - Imprimir todos");
        printf("\n5 - Contar");
        printf("\n9 - Sair\n");
        printf("\nOpcao: ");
        scanf("%i",&opc);

        switch(opc)
        {
            case 1: 
                for(c = 0; c < SIZE; c++){
                    printf("%iº RA: ",c);
                    scanf("%i",&n);
                    if(exists(ra, SIZE, n) == 0)ra[c] = n;                        else{ 
                        printf("Número já existe!\n");
                        c--;
                    }
                }
                break;
            case 2:
                printf("RA: ");
                scanf("%i",&toRemove);
                Remove(ra,SIZE,toRemove);
                break;
            case 3:
                printf("RA: ");
                scanf("%i",&toSearch);
                if(Search(ra,SIZE,opc) == 0) printf("Nao encontrado!\n");
                break;
            case 4:
                printArray(ra,SIZE);
                break;
            case 5:
                for(c = 0; c < SIZE; c++){
                    if(ra[c] > 0) v++;
                }
                printf("Contagem RA's: %i",v);
                break;
            case 9: 
                break;
            default:
                printf("Opcao invalida!\n");
        }
    }while(opc != 9);

    free(ra);

    return 0;
}
