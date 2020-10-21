#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int opc,c;
    float notas[10] = {0};
    size_t t = sizeof(notas)/sizeof(notas[0]);
    
    do{
        float med = 0;
        int k = 0;
        printf("\n\t.:SISTEMA DE NOTAS:.\n");
        printf("\n1 - Carregar");
        printf("\n2 - Imprimir");
        printf("\n3 - Media geral");
        printf("\n4 - Aprovados e contagem");
        printf("\n5 - Media aprovados");
        printf("\n9 - Sair");
        printf("\nOpcao: ");
        scanf("%i",&opc);

        switch (opc)
        {
            case 1:
                for(c = 0; c < t; c++){
                    do{
                        printf("%iª nota: ",c+1);
                        scanf("%f",&notas[c]);
                        if(notas[c] < 0 || notas[c] > 10)
                            printf("Nota invalida! Digite novamente\n");
                        
                    }while(notas[c] < 0 || notas[c] > 10);
                }
                break;
            case 2 :
                for(c = 0; c < t; c++){
                    printf("[%i] = %.1f\n",c,notas[c]);
                }
                break;
            case 3 :
                for(c = 0; c < t; c++){
                    med += notas[c]; 
                }
                printf("Media geral: %.1f",med/t);
                break;
            case 4 :
                for(c = 0; c < t; c++){
                    if(notas[c] > 6.0) {
                        printf("[%i] = %.1f\n",c,notas[c]);
                        k++;
                    }
                }
                printf("Qtd. aprovados: %i\n",k);
                break;
            case 5 :
                for(c = 0; c < t;c++){
                    if(notas[c] > 6.0) {
                        med += notas[c];
                        k++;
                    }
                }
                printf("Media aprovados: %.1f\n",med/k);
                break;
            case 9 :
                break;
            default :
                printf ("Opcao invalida!\n");
        }
    }while(opc != 9);
    return 0;
}
