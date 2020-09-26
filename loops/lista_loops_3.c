#include <stdio.h>
#include <ctype.h>

int questao_um(void);
int questao_dois(void);
int questao_tres(void);
int questao_quatro(void);
int questao_cinco(void);
int ordena(int t,int *sum);

int i = 0,j = 0;

int main(int argc, char *argv[])
{
    short int opc;
    printf("\t.:OPCOES:.");
    printf("\n1 - Imprimir nomes x vezes e repetir");
    printf("\n2 - Imprimir multiplos");
    printf("\n3 - Imprimir 3 contagens");
    printf("\n4 - Imprimir 3 contagens decrescente");
    printf("\n5 - Somar intervalos 3 valores\n");
    printf("\nEscolha sua opção: ");
    scanf("%hi",&opc);
    switch(opc)
    {
        case 1:
            questao_um();
            break;
        case 2:
            questao_dois();
            break;
        case 3:
            questao_tres();
            break;
        case 4:
            questao_quatro();
            break;
        case 5:
            questao_cinco();
            break;
        default:
            printf("Opção inválida!");
    }
    return 0;
}

// imprimir nome X vezes e repetir
int questao_um(void)
{
    short int a;
    int rep;
    char *nome;
   
    do
    {
        printf("Número repetições: ");
        scanf("%i",&rep);
        printf("Nome: ");
        scanf("%s",nome);

        for(i = 0; i < rep; i++)
        {
            printf("%i - %s\n",i+1,nome);
        }
        printf("Quer continuar? (0 = Não | 1 = Sim)");
        scanf("%hi",&a);

    }while(a == 1);
    
    return 0;
}

// imprimir multiplos
int questao_dois(void)
{
    int n,p;
    printf("Repetições: ");
    scanf("%i",&n);
    printf("Passos contagem: ");
    scanf("%i",&p);

    if(p == 0) p = 1;

    for(i = 0; i < n; i += p)
    {
        printf("%i\n",i);
    }
    return 0;
}

// imprimir contagens
int questao_tres(void)
{
    int c[3],i;

    for(i = 0; i < 3; i++){
        printf("%iº número: ",i+1);
        scanf("%i",&c[i]);
    }

    for(i = 0; i < 3; i++)
    {
        printf("Impressão contagem do valor %i\n",c[i]);
        for(j = 1; j <= c[i]; j++)
        {
            printf("%i\n",j);
        }
        printf("\n");
    }
    return 0;
}

// imprimir 3 contagens decrescentes
int questao_quatro(void)
{
    int c[3],i;

    for(i = 0; i < 3; i++){
        printf("%iº número: ",i+1);
        scanf("%i",&c[i]);
    }

    for(i = 0; i < 3; i++)
    {
        printf("Impressão contagem do valor %i\n",c[i]);
        for(j = c[i]; j > 0; j--)
        {
            printf("%i\n",j);
        }
        printf("\n");
    }
    return 0;
}

// somar intervalos 3 valores
int questao_cinco(void)
{
    int c[3],i,sum[3] = {0,0,0};
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
