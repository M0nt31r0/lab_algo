#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
    float hAula = 25.00,bruto,liquido;    
    int qtdAula;
    
    printf("\t.:INFORMACOES SALARIAIS:.\n");
    printf("Nº aulas semanais: ");
    scanf("%i",&qtdAula);
   
    // acrescimo de 10% (vales + plano sáude)
    float acresc = (qtdAula * hAula * 4) * 0.1;
    bruto = acresc + (qtdAula * hAula * 4);
    // decrescimo 5% + 7% (IR e INSS)
    float decresc = bruto * 0.12; 
    liquido = bruto - decresc;
    
    printf("Salario bruto:\t\tR$ %0.2f\nDescontos(IR/INSS):\tR$ %0.2f\nSalario liquido:\tR$ %0.2f\n",bruto,decresc,liquido);
    
    return 0;
}
