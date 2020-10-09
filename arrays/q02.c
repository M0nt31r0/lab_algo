#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    float m[10] = {0},sum = 0.0;
    int opc,c = 0;
    
    do{
        printf(".:MENSALIDADES:.\n");
        printf("1 - Zerar\n");
        printf("2 - Carregar\n");
        printf("3 - Imprimir\n");
        printf("4 - Somar\n");
        printf("5 - Sair\n");
        
        scanf("%i",&opc);
        system("clear");
        switch(opc)
        {
            case 1:
                for(c = 0; c < 10; c++)
                {
                    m[c] = 0.0;
                }
                break;
            case 2:
                for(c = 0; c < 10; c++)
                {
                    scanf("%f",&m[c]);
                }
                break;
            case 3:
                for(c = 0; c < 10; c++)
                {
                    printf("[%i] = %.2f\n",c,m[c]);
                }
                break;
            case 4:
                for(c = 0;c < 10; c++)
                {
                    sum += m[c];
                }
                printf("Sum: %.2f\n",sum);
                break;
            case 5:
                break;
            default:
                printf("Opcao invalida!");
        } 
    }while(opc != 5);
    return 0;
}
