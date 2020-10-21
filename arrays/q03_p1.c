#include <stdio.h>
#include <stdlib.h>

int c = 0;

int main(int argc, char *argv[])
{
    short int m[8] = {0};
    size_t t = sizeof(m) / sizeof(m[0]);
    int opc,c = 0;
    
    do{
        int i = 0, sum = 0;
        
        printf("\n.:IDADES:.\n");
        printf("1 - Zerar\n");
        printf("2 - Carregar\n");
        printf("3 - Imprimir\n");
        printf("4 - Somar\n");
        printf("5 - Exibir Pares\n");
        printf("6 - Contar pares\n");
        printf("7 - Somar pares\n");
        printf("8 - Menores de idade\n");
        printf("9 - Contar maiores de idade\n");
        printf("10 - Somar maiores de idade\n");
        printf("11 - Sair\n");
        
        scanf("%i",&opc);
        system("clear");
        
        switch(opc)
        {
            case 1:
                for(c = 0; c < t; c++)
                {
                    m[c] = 0.0;
                }
                break;
            case 2:
                for(c = 0; c < t; c++)
                {
                    scanf("%hi",&m[c]);
                }
                break;
            case 3:
                for(c = 0; c < t; c++)
                {
                    printf("[%i] = %hi\n",c,m[c]);
                }
                break;
            case 4:
                for(c = 0;c < t; c++)
                {
                    sum += m[c];
                }
                printf("Sum: %i\n",sum);
                break;
            case 5:
                for(c = 0; c < t; c++)
                {
                    if(m[c]%2==0) printf("[%i] = %hi\n",c,m[c]);
                }
                break;
            case 6:
                for(c = 0; c < t; c++)
                {
                    if(m[c]%2 == 0) i++;
                }
                printf("Pares: %i",i);
                break;
            case 7:
                for(c = 0; c < t; c++)
                {
                    if(m[c]%2 == 0) sum += m[c];
                }
                printf("Sum: %i",sum);
                break;
            case 8:
                printf("Menor que 18: ");
                for(c = 0; c < t; c++)
                {
                    if(m[c] < 18) printf("%i",m[c]);
                }
               break;
            case 9:
                 for(c = 0; c < t; c++)
                {
                    if(m[c] >= 18) i++;
                }
                printf("Qtd. Maiores de 18: %i",i);
               break;
            case 10:
                for(c = 0; c < t; c++)
                {
                    if(m[c] >= 18) sum += m[c];
                }
                printf("Sum: %i",sum);
               break;
            case 11:
                break;
            default:
                printf("Opcao invalida!");
        }
    }while(opc != 11);   
    return 0;
}

