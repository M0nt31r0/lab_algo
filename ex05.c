#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
    float hAula = 25.00,bruto,liquido;    
    int qtdAula;
    
    printf("\t.:INFORMAÇÕES SALARIAIS:.\n");
    printf("Nº aulas semanais: ");
    scanf("%i",&qtdAula);
   
    // acrescimo de 10% (vales + plano sáude)
    float acresc = (qtdAula * hAula * 4) * 10/100;
    bruto = acresc + (qtdAula * hAula * 4);
    // decrescimo 5% + 7% (IR e INSS)
    float decresc = bruto * 12/100; 
    liquido = bruto - decresc;
    
    printf("Salário bruto:\t\tR$ %0.2f\nDescontos(IR/INSS):\tR$ %0.2f\nSalário líquido:\tR$ %0.2f",bruto,decresc,liquido);
    
    return 0;
}
