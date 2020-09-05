#include <stdio.h>


int main(int argc, char *argv[])
{
    float nota[5];
    printf(".:CALCULO MEDIA NOTAS:.");

    for(int i = 0; i < 4; i++)
    {
        printf("%iº Nota: ",i);
        scanf("%f",&nota[i]);
        nota[5] += nota[i];
    }    
    float media = nota[5]/4;
    if(media >= 5)
    {
        printf("Media: %.1f\naprovado",media);
    }
    else
    {
        printf("Media: %.1f\nreprovado",media);
    }
    return 0;
}
