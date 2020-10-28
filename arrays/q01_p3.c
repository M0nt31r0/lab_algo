#include <stdio.h>
#include <stdlib.h>
#define T 3
int main()
{
    int array[T][T] = {{0}};
    int opc,j = 0,c = 0, sum = 0;
    
    do{
        printf("\n\t.:BASICO:.\n");
        printf("\n1  - Carregar");
        printf("\n2  - Imprimir");
        printf("\n3  - Somar");
        printf("\n4  - Zerar");
        printf("\n9 - Sair");
        printf("\nOPCAO: ");
        scanf("%i",&opc);

        switch (opc)
        {
            case 1:
                for(c = 0; c < T; c++){
                    for(j = 0; j < T; j++){
                        scanf("%i",&array[c][j]);
                    }
                }
                break;
            case 2:
                for(c = 0; c < T; c++){
                    for(j = 0; j < T; j++){
                        printf("%4i",array[c][j]);
                    }
                    printf("\n");
                }
                break;
            case 3:
                for(c = 0; c < T; c++){
                    for(j = 0; j < T; j++){
                        sum += array[c][j];
                    }
                }
                printf("%i",sum);
                break;
            case 4:
                for(c = 0; c < T; c++){
                    for(j = 0; j < T; j++){
                        array[c][j] = 0;
                    }
                }
                break;
            case 9:
                break;
            default:
                printf ("Opcao invalida!\n");
        }
    }while(opc != 9);
    return 0;
}
