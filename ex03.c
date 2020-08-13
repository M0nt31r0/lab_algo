#include <stdio.h>
#include <stdlib.h>



int main(int argc, char *argv[])
{
    float mensalidade,transp,alim;
    float mensal,anual;

    printf("\t.:CALCULO GASTO TOTAL FACULDADE:.\n");
    printf("Mensalidade: \tR$ ");
    scanf("%f",&mensalidade);    
    printf("Transporte: \tR$ ");
    scanf("%f",&transp);
    printf("Alimentacao:\t R$ ");
    scanf("%f",&alim);
    
    mensal = mensalidade + transp + alim;
    anual = mensal * 12;
    printf("Custo mensal: \tR$ %0.2f\nCusto anual:\tR$ %0.2f",mensal,anual);

    return 0;
}
