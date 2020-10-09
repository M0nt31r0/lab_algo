#include <stdio.h>

int ordena(int t,int *sum);

int i = 0,j = 0;
int main()
{
    int c[3],sum[3] = {0,0,0};
    // tamanho do array
    int t = sizeof(sum)/sizeof(sum[0]);

    for(i = 0; i < 3; i++){
        printf("%iº número: ",i+1);
        scanf("%i",&c[i]);
    }
    for(i = 0; i < 3; i++)
    {
        printf("\nImpressão contagem do valor %i\n",c[i]);
        for(j = c[i]; j > 0; j--)
        {
            sum[i] += j;
            printf("%i ",j);
            // exemplo: imprime 3 como sendo 1 + 2 + 3 = 6
            if(j == 1)printf("=");
            else printf("+ ");
        }
        printf(" %i",sum[i]);
        printf("\n");
    }
    // chama funcao ordena array e imprime na tela
    ordena(t,sum);
    return 0;
}

int ordena(int t,int *sum)
{
    int aux = 0;
    for(i = 0; i < t;i++)
    {
        for(j = 0; j < t-i-1;j++)
        {
            if(sum[j] > sum[j+1])
            {
                aux = sum[j];
                sum[j] = sum[j+1];
                sum[j+1] = aux; 
            }
        }    
    }
    printf("\nOrdenado: ");
    for(i = 0; i < t; i++)
    {
        printf("%i ",sum[i]);
    }
    printf("\nMenor soma: %i\nMaior soma: %i",sum[0],sum[2]);
    
    return 0;
}
