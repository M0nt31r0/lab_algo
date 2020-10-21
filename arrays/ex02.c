#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
    int opc, idades[20] = {0},c;
    size_t t = sizeof(idades)/sizeof(*idades);
    srand(time(NULL));

    do{
        int sum = 0, age[3] = {0};

        printf("\n\t.:SISTEMA DE IDADES:.\n");
        printf("\n1 - Carregar(aleatorio)");
        printf("\n2 - Imprimir");
        printf("\n3 - Somar");
        printf("\n4 - Exibir crianças (0 a 10 anos)");
        printf("\n5 - Relatório idades");
        printf("\n9 - Sair\n");
        printf("Opc: ");

        scanf("%i",&opc);
        switch (opc)
        {
            case 1 :
                for(c = 0; c < t; c++){
                    // criancas entre 1 e 100
                    idades[c] = rand() % 100 + 1;
                }
                break;
            case 2 :
                for(c = 0; c < t; c++) printf("[%i] = %i\n",c,idades[c]);
                break;
            case 3 :
                for(c = 0; c < t; c++) sum += idades[c];
                printf("Soma idades: %i\n", sum);
                break;
            case 4 :
                for(c = 0; c < t; c++){
                    if(idades[c] > 0 && idades[c] <= 10) printf("[%i] = %i\n",c,idades[c]);
                }
                break;
            case 5 :
                for(c = 0; c < t; c++){
                    if(idades[c] > 0 && idades[c] <= 17)age[0]++;
                    else if(idades[c] > 17 && idades[c] <= 60) age[1]++;
                    else age[2]++;
                }
                printf("Menores (0 a 17): %i\nAdultos (18 a 60): %i\nIdosos: %i\n",age[0],age[1],age[2]);
                break;
            case 9 :
                break;
            default :
                printf ("Opcao invalida!\n");
        }
    }while(opc != 9);
    return 0;
}
