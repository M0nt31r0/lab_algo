#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

float soma(float *m);
void desconto(float *m);

int c = 0;

int main(int argc, char *argv[])
{
    short int opc;
    float *m = (float *) malloc(sizeof(float) * SIZE);
    if(m == NULL) exit(EXIT_FAILURE);
    
    do{
        printf("\n\t.:GESTAO MENSALIDADES:.\n");
        printf("\n1 - Carregar");
        printf("\n2 - Imprimir");
        printf("\n3 - Somar");
        printf("\n4 - Media");
        printf("\n5 - Aplicar desconto");
        printf("\n9 - Sair");
        printf("\nOpcao: ");
        scanf("%hi",&opc);

        switch (opc)
        {
            case 1 :
                for(c = 0; c < SIZE; c++){
                    printf("%iª mensalidade: ",c+1);
                    scanf("%f",&m[c]);
                } 
                break;
            case 2 :
                for(c = 0; c < SIZE; c++) printf("[%i] = %.2f\n",c,m[c]);
                break;
            case 3 :
                printf("Soma = R$%.2f",soma(m));
                break;
            case 4 :
                printf("Soma = R$%.2f",soma(m)/SIZE); 
                break;
            case 5 :
                desconto(m);
                break;
            case 9:
                break;
            default :
                printf ("Opcao invalida!\n");
        }
    }while(opc != 9);

    free(m);
    return 0;
}

float soma(float *m)
{
    float sum = 0.0;
    for(c = 0; c < SIZE; c++) sum += m[c];
    return sum;
}
void desconto(float *m)
{
    float d;
    printf("Desconto(%%): ");
    scanf("%f",&d);
    for(c = 0; c < SIZE; c++) m[c] *= (1 - d/100);
}
