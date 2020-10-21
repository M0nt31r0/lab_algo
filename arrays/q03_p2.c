#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100

int adicionar(short int *array, int t, short int opc);
void imprimir(short int *array, int t, short int opc);
int remover(short int *array, int t, short int opc);
int contar_somar(short int *array, int t, short int opc);

static int c = 0;
short int pos = 0;

int main(int argc, char *argv[])
{
    // seed rand
    srand(time(NULL));

    short int opc;
    short int *idade = (short int*) malloc(sizeof(short int) * SIZE);
    if(idade == NULL)
    {
        exit(EXIT_FAILURE);
    }
    
    do{
        printf("\n\t.:IDADES:.\n");
        printf("\n1 - Adicionar aleatoriamente");
        printf("\n2 - Adicionar na posicao");
        printf("\n3 - Imprimir a posicao");
        printf("\n4 - Imprimir todas");
        printf("\n5 - Remover da posicao");
        printf("\n6 - Remover todas");
        printf("\n7 - Contar idades");
        printf("\n8 - Somar idades");
        printf("\n9 - Somar idades impares");
        printf("\n10 - Imprimir idades pares");
        printf("\n99 - Sair\n");
        printf("Opcao: ");
        scanf("%hi",&opc);

        switch (opc)
        {
            case 1 :
                adicionar(idade,SIZE,opc); 
                break;
            case 2 :
                if(adicionar(idade,SIZE,opc) == 1) printf("Posicao invalida\n");
                else printf("Valor adicionado\n");
                break;
            case 3 :
                imprimir(idade,SIZE,opc);
                break;
            case 4 :
                imprimir(idade,SIZE,opc);
                break;
            case 5 :
                if(remover(idade,SIZE,opc) == 1) printf("Posicao invalida!\n");
                break;
            case 6 :
                remover(idade,SIZE,opc);
                break;
            case 7 :
                printf("%i\n",contar_somar(idade,SIZE,opc)); 
                break;
            case 8 :
                printf("%i\n",contar_somar(idade,SIZE,opc));
                break;
            case 9 :
                printf("%i\n",contar_somar(idade,SIZE,opc));
                break;
            case 10 :
                imprimir(idade,SIZE,opc);
                break;
            case 99:
                break;
            default :
                printf ("Opcao invalida!\n");
        }
    }while(opc != 99);
    
    free(idade);
    
    return 0;
}
int adicionar(short int *array, int t, short int opc)
{
    short int v;
    if(opc == 1)
    {
        for(c = 0; c < t; c++)
        {
            // valores aleatorios 1 - 100
            array[c] = rand() % 100 + 1;
        }
    }
    else if(opc == 2)
    {
        printf("Posicao: ");
        scanf("%hi",&pos);
        if(pos > t || pos < 0) return 1;
        else{
            printf("Valor: ");
            scanf("%hi",&v);
            array[pos] = v;
        }
    }
    return 0;
}

void imprimir(short int *array, int t, short int opc)
{
    if(opc == 3)
    {
        printf("Posicao: ");
        scanf("%hi",&pos);
        if(pos < 0 || pos > t) printf("Posicao invalida");
        else printf("%hi",array[pos]);
    }
    else if(opc == 4)
    {
        for(c = 0; c < t; c++) printf("[%i] = %hi\n",c,array[c]);
    }
    else
    {
        for(c = 0; c < t; c++){
            if(array[c]%2==0) printf("[%i] = %hi\n",c,array[c]);
        }
    }
}
int remover(short int *array, int t, short int opc)
{
   if(opc == 5)
   {
        printf("Posicao: ");
        scanf("%hi",&pos);
        if(pos < 0 || pos > t) return 1;
        else{
            array[pos] = -1;
        }
   }
   else
   {
       for(c = 0; c < t; c++){
           array[c] = -1;
       }
       printf("Idades removidas!\n");
   }
   return 0;
}
int contar_somar(short int *array, int t, short int opc)
{
    int sum = 0, i = 0, sum_impar = 0;

    for(c = 0; c < t; c++)
    {
        if(array[c] > 0){
            i++;             // conta idades
            sum += array[c]; // soma idades
            if(array[c]%2 != 0) sum_impar += array[c]; // soma idades impares
        }
    }
    if(opc == 7) return i;
    else if(opc == 8) return sum;
    else return sum_impar;
}
