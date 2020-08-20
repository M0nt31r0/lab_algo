#include <stdio.h>
#include <stdlib.h>



int main(int argc, char *argv[])
{
    float r,d,e;
    
    printf("\t.:CONVERSAO MONETARIA:.\n");    
    printf("Digite um valor(R$): ");
    scanf("%f",&r);
    printf("Cotacao(Real para Dolar): $ ");
    scanf("%f",&d);
    printf("Cotacao(Real para Euro): € "); 
    scanf("%f",&e);

    d = r * d;
    e = r * e;
    
    printf("Valor em dolar:\t$ %0.2f\nValor em Euro:\t€ %0.2f",d,e);
    return 0;
}
