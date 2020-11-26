#include <stdio.h>
#include <stdlib.h>


int main()
{
     float peso,altura,imc = 0, imc2 = 0;
     printf("Peso: ");	
     scanf("%f",&peso);
     printf("Altura: ");
     scanf("%f",&altura);

     imc = peso / altura * altura;
     imc2 = peso / altura / altura;
     
     printf("IMC: %.2f\n", imc);
     printf("IMC2: %.2f", imc2);
     return 0;
}

