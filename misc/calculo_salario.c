#include <stdio.h>
#include <stdlib.h>


int main()
{
    float s,a;
    scanf("%f",&s);
    scanf("%f",&a);
    
    s = s + a;
    printf("Salario bruto: %.2f\n",s);
    // desconto c.sindical
    s *= 0.98;
    
    // desconto INSS
    if(s <= 1000.00) s *= 0.97;
    else if(s > 1000.00 && s <= 2000.00) s *= 0.95;
    else s *= 0.93;

    printf("Salario liquido: %.2f",s);
     return 0;
}

