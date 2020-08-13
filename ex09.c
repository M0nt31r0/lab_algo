#include <stdio.h>
#include <stdlib.h>



int main(int argc, char *argv[])
{
    float r,d,e;
    
    printf("\t.:CONVERSÃO MONETÁRIA:.\n");    
    printf("Digite um valor(R$): ");
    scanf("%f",&r);
    printf("Cotação(Real para Dólar): $ ");
    scanf("%f",&d);
    printf("Cotação(Real para Euro): € "); 
    scanf("%f",&e);

    d = r * d;
    e = r * e;
    
    printf("Valor em dólar:\t$ %0.2f\nValor em Euro:\t€ %0.2f",d,e);
    return 0;
}
