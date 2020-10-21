#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int opc,c, m[60] = {0};
    size_t t = sizeof(m) / sizeof(m[0]);

    do{
        int i = 0,sum = 0,n = 0;
        printf("\n\t.:SORTEIO:.\n");
        printf("\n1 - Atribuir(-1)");
        printf("\n2 - Carregar array");
        printf("\n3 - Imprimir");
        printf("\n4 - Somar");
        printf("\n5 - Contagem e soma impares");
        printf("\n6 - Percorrer array por valor solicitado");
        printf("\n7 - Valores repetidos");
        printf("\n8 - Sair\n");
        scanf("%i",&opc);

        switch (opc)
        {
            case 1 :
                for(c = 0; c < t; c++){
                    m[c] = -1;
                }
                break;
                
            case 2 :
                for(c = 0; c < t; c++){
                    m[c] = rand() % 60 + 1 ;
                }
                break;
                
            case 3 :
                for(c = 0;c < t; c++){
                    printf("[%i] = %i\n",c,m[c]);
                }
                break;
                
            case 4 :
                for(c = 0;c < t; c++){
                    sum += m[c];
                }
                printf("Soma: %i",sum);
                break;
                
            case 5 :
                for(c = 0;c < t; c++){
                    if(m[c]%2 != 0){
                        i++;
                        sum += m[c];
                    }
                }
                printf("Soma: %i\nQtd.: %i",sum,i);
                break;
                
            case 6 :
                printf("Informe um valor(1 - 60): ");
                scanf("%i",&n);
                for(c = n; c < t; c++)
                {
                    printf("[%i] = %i\n",c,m[c]);
                }
                break;
                
            case 7 :
                printf("Informe um valor(1 - 60):");
                scanf("%i",&n);
                for(c = 0; c < t; c++)
                {
                    if(m[c] == n){
                        printf("pos[%i] -> %i\n",c,n);
                        i++;
                    }
                }
                printf("Qtd. valores repetidos: %i\n",i);
                break;
            case 8 :
                break;
            default :
                printf ("Valor invalido!\n");
        }
    }while(opc != 8);
    return 0;
}
