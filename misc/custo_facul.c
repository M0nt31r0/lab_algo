#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    float vm;
    float va;
    float v;
    int d;
} Aluno;

Aluno pgto;

int main()
{
    printf("Valor mensalidade: ");
    scanf("%f", &pgto.vm);
    printf("Valor adicional: ");
    scanf("%f",&pgto.va);
    printf("Dia pagamento: ");
    scanf("%i",&pgto.d);
    pgto.v = 0;

    pgto.v = pgto.vm + pgto.va;
    printf("Custo bruto: %.2f\n",pgto.v);
    // desconto bolsa
    pgto.v *= 0.95;

    if(pgto.d <= 10) pgto.v *= 0.92;
    else if(pgto.d > 10 && pgto.d <= 20) pgto.v *= 0.95;
    else pgto.v *= 0.97;

    printf("Custo liquido: %.2f",pgto.v);
     return 0;
}

