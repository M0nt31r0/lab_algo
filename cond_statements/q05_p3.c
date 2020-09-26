#include <stdio.h>

float media(float notas[]);

int main(int argc, char *argv[])
{
    float notas[3];
    
    for(int c = 0; c < 3; c++)
    {
        printf("%iº NOTA: ",c);
        scanf("%f",&notas[c]);
    }
    media(notas);    
    
    return 0;
}

float media(float notas[])
{
    float media = (notas[0] + notas[2]) * 0.3 + notas[1] * 0.4;
    printf("MEDIA: %.2f\n",media);

    if(media > 0.0 && media < 5.0){
        printf("REPROVADO");
    }else if(media >= 5.0 && media < 7.5){
        printf("APROVADO");
    }else{
        printf("PARABÉNS! VOCÊ FOI APROVADO COM EXCELÊNCIA");}
    return 0;
}
