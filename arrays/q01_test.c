#include <stdio.h>
#include <stdlib.h>

#define SIZE 15

short int c = 0;
void nota(float *notas, short int opc);

int main(int argc, char *argv[])
{
    short int opc;
    float *notas = (float *) malloc(sizeof(float) * SIZE);
    
    if(notas == NULL)
    {
        exit(EXIT_FAILURE);
    }
    
    do{
        printf("\n\t.:MEDIA NOTAS ALUNOS:.\n");
        printf("\n1 - Carregar");
        printf("\n2 - Imprimir");
        printf("\n3 - Media");
        printf("\n4 - Aprovados");
        printf("\n5 - Contar Reprovados");
        printf("\n9 - Sair\n");
        printf("Opcao: ");
        scanf("%hi",&opc);
        switch (opc)
        {
            case 1 :
                for(c = 0; c < SIZE; c++)
                {
                    printf("%iº nota: ",c+1);
                    scanf("%f",&notas[c]);
                }
                break;
            case 2 :
                for(c = 0; c < SIZE; c++) printf("[%i] = %.2f\n",c,notas[c]);
                break;
            case 3 :
                nota(notas,opc);
                break;
            case 4 :
                nota(notas,opc);
                break;
            case 5 :
                nota(notas,opc);
                break;
            case 9: 
                break;
            default :
                printf ("Opcao invalida!\n");
        }
    }while(opc != 9);
    
    free(notas);
    return 0;
}

void nota(float *notas, short int opc)
{
    float sum = 0;
    int i = 0; 
    for(c = 0; c < SIZE; c++){
        if(notas[c] >= 5.00 && opc == 4){ 
            printf("[%i] = %.2f\n",c,notas[c]);
        }else if(notas[c] < 5) i++;
        // soma notas
        sum += notas[c];
    }
    if(opc == 5) printf("QTD. Reprovados: %i\n",i);
    else if(opc == 3) printf("Soma = %.2f\n",sum/SIZE);
}
