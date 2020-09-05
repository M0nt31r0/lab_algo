#include <stdio.h>

float calc_imc(float h, float p)
{
    h = p / (h*h);
    
    printf("IMC: %.1f\n",h);
    
    if(h <= 18.5)printf("MAGREZA");
    else if(h > 18.5 && h <= 24.9)printf("NORMAL");
    else if(h > 25 && h <= 29.9)printf("SOBREPESO(GRAU I)");
    else if(h > 30 && h < 39.9)printf("OBESIDADE(GRAU II)");
    else printf("OBESIDADE GRAVE(GRAU III)");
    
    return 0;
}

int main(int argc, char *argv[])
{
    float h,p;
    
    printf("Digite seu peso: ");
    scanf("%f",&p);
    printf("Digite sua altura: ");
    scanf("%f",&h);
    
    calc_imc(h,p);
    
    return 0;
}
