#include <stdio.h>
#include <stdlib.h>
#define SIZE 10


int adicionar(float *array,int t)
{
    int p;
    float v;
    printf("Posicao: ");
    scanf("%i",&p);
    if(p < 0 || p > 10) return 1;
    else{
        printf("Valor: ");
        scanf("%f",&v);
        array[p] = v;
        return 0;
    }
}

int ler(float *array,int p)
{
    if(p < 0 || p > 10) printf("Posicao invalida!");
    else printf("%.2f",array[p]);
    return 0;
}

float somar(float *array,int t)
{
    float sum = 0;
    for(int c = 0; c < t; c++)
    {
        sum += array[c];
    }
    return sum;
}
int contar(float *array,int t,int opc)
{
    short int i = 0,iv = 0;
    for(int c = 0; c < t; c++)
    {
        if(array[c] > 0) i++;
        else iv++;
    }
    if(opc == 4) return i;
    else return iv;
}
int main(int argc, char *argv[])
{
    float *altura = (float*) malloc(sizeof(int) * SIZE);
    if(altura == NULL)
    {
        exit(EXIT_FAILURE);
    }
    int opc,p;
    
    do{
        printf("\n\t.:ALTURAS:.\n");
        printf("\n1 - Adicionar");
        printf("\n2 - Ler");
        printf("\n3 - Somar");
        printf("\n4 - Contar");
        printf("\n5 - Contar(posicoes vazias)");
        printf("\n9 - Sair\n");
        printf("Opcao: ");
        scanf("%i",&opc);

        switch (opc)
        {
            case 1 :
                if(adicionar(altura,SIZE) == 0) printf("Adicionado\n");
                else printf("Posicao invalida!");
                break;
            case 2 :
                printf("Posicao: ");
                scanf("%i",&p);
                ler(altura,p); 
                break;
            case 3 :
                printf("%.2f",somar(altura,SIZE));
                break;
            case 4 :
                printf("%i",contar(altura,SIZE,opc));
                break;
            case 5 :
                printf("%i",contar(altura,SIZE,opc));
                break;
            case 9:
                break;
            default :
                printf ("Opcao invalida!\n");
        }
    }while(opc != 9);
    free(altura);
    return 0;
}
