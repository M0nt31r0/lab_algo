#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    float d,e,le;
    
    typedef struct
    {
        char nome[20];
        float reais;
    
    } Pessoa;

    Pessoa Pessoas[5];
    
    // Solicita valores do usúario
    printf("\t.:INFORME COTACAO DAS MOEDAS:.\n");
    printf("Cotação dólar: ");
    scanf("%f",&d);
    printf("Cotação Euro: ");
    scanf("%f",&e);
    printf("Cotação Libra Esterlina: ");
    scanf("%f",&le);

    float a[4],soma = 0,aux = 0.0;
    
    for(int c = 0; c < 4; c++)
    {
        strcpy(Pessoas[c].nome, "NULL");
        
        printf("Nome: ");
        scanf("%s%*c",&Pessoas[c].nome);
        printf("Informe quantidade a ser levada: ");
        scanf("%f%*c",&Pessoas[c].reais);
        
        soma += Pessoas[c].reais;    
    }
    
    int c,j;
    
    for(c = 0; c < 4 ; c++)
    {
        // Atribui valores da struct para o vetor a
        a[c] = Pessoas[c].reais;
    }

    // Ordena o vetor
    for(c = 0; c < 4; c++)
    {
        for(j = 0;j < 4-c-1;j++)
        {
            if(a[j] >= a[j+1])
            {
                aux = a[j];
                a[j] = a[j+1];
                a[j+1] = aux;
            }
        }
    }

    // print array ordenado
    printf("\n\t.:VALORES ORDENADOS:.\n");
    for(c = 0; c < 4; c++)
    {
        printf("%.2f",a[c]);
    }

    // converte reais para dolar,euro,libras e exibe valores na tela
    for(c = 0; c < 4; c++)
    {
        printf("\n%s tem R$ %.2f\n", Pessoas[c].nome, Pessoas[c].reais);
        float dol = Pessoas[c].reais / d;
        float eu = Pessoas[c].reais / e;
        float libr = Pessoas[c].reais / le;
        printf("CONVERTENDO...");
        printf("\n%.2f dólares | %.2f euros | %.2f libras\n", dol,eu,libr);
    }
    printf("\nTOTAL DE R$: %.2f\n",soma);
    
    // Definindo o maior e menor valor da struct 
    printf("\n\t.:DEFININDO MAIOR E MENOR:.\n");
    for(c = 0; c < 4; c++)
    {
        // definindo pessoa com menor e maior valor em dinheiro
        // exibindo nome e quantidade em dinheiro da pessoa
        if(Pessoas[c].reais == a[3])printf("Nome: %s Maior:R$ %.2f\n", Pessoas[c].nome,a[3]);
        if(Pessoas[c].reais == a[0])printf("Nome: %s Menor:R$ %.2f", Pessoas[c].nome,a[0]);
    }
    return 0;
}
