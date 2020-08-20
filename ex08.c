#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
    // vp = valor prestação
    // tx = valor taxa
    // t = tempo
    float vp,tx,valor;
    int t;

    printf("\t.:PARCELA EM ATRASO:.\n");
    printf("Valor da prestacao:\tR$ ");
    scanf("%f",&vp);
    printf("Valor da taxa:\t\tR$ ");
    scanf("%f",&tx);
    printf("Tempo de atraso:\t ");
    scanf("%i",&t);

    valor = vp + (vp * (tx/100) * t);
    printf("Valor total:\tR$ %0.2f\n",valor);
    return 0;
}
