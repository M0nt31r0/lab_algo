#include <stdio.h>


int main(int argc, char *argv[])
{
    float nota[5];
    printf(".:CALCULO MEDIA NOTAS:.\n");

    for(int i = 0; i < 4; i++)
    {
        printf("%iº Nota: ",i);
        scanf("%f",&nota[i]);
        nota[5] += nota[i];
    }   

    float media = nota[5]/4;
    
    if(media >= 7)
    {
        printf("Media: %.1f\naprovado",media);
    }
    else
    {
        printf("Media: %.1f\n",media);
        printf("Aluno exame\n");
        printf("Digite media do exame: \n");
        scanf("%f",&nota[0]);
        media = (media + nota[0])/2;

        if(media >= 5)
        {
            printf("Media exame: %.1f\n",media);
            printf("Aprovado em exame\n");
        }
        else
        {
            printf("Media exame: %.1f\n",media);
            printf("Reprovado\n");
        }
    }
    return 0;
}
