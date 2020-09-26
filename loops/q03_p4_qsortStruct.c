#include <stdio.h>
#include <stdlib.h>

int comparator(const void *a, const void *b);

typedef struct
{
    int RA;
    float nota1;
    float nota2;
    float pluri;
    float media;
} Nota;

int main(int argc, char *argv[])
{
    Nota notas[3] = {0.0};
    float total = 0.0;
    int c = 0,aprov = 0,reprov=0;
    
    printf("\t.:INFORME OS VALORES ABAIXO:.\n");
    for(c = 0;c < 3;c++)
    {
        printf("RA: ");
        scanf("%i",&notas[c].RA);
        printf("Nota 1: ");
        scanf("%f",&notas[c].nota1);
        printf("Nota 2: ");
        scanf("%f",&notas[c].nota2);
        printf("Pluri: ");
        scanf("%f",&notas[c].pluri);

        // calcula media
        notas[c].media += (notas[c].nota1*0.30 + notas[c].nota2*0.40 + notas[c].pluri*0.30);
        printf("\n");
    }
    for(c = 0;c < 3;c++)
    {
        // exibe RA e MEDIA e uma mensagem de aprovado ou reprovado
        printf("RA: %i | MEDIA: %.2f", notas[c].RA,notas[c].media);
        
        total += notas[c].media;
        if (notas[c].media >= 7.0) {aprov += 1; printf(" | APROVADO\n");}
        else {reprov += 1; printf(" | REPROVADO\n");}
    }
    printf("\nTOTAL APROVADOS: %i",aprov);
    printf(" | TOTAL REPROVADOS: %i\n",reprov);
    printf("MEDIA TOTAL = %.2f\n",total/3);

    printf("\n.:NOTAS ORDENADAS:.\n");

    // sort struct, passando como parametro o array, tamanho do array, tamanho da struct, e a função de comparação
    qsort(notas,3,sizeof(Nota),comparator);

    // exibe struct ordenada
    for(c = 0;c < 3;c++)
    {
        printf("RA: %i MEDIA: %.2f\n",notas[c].RA,notas[c].media);
    }
    return 0;
}
int comparator(const void *a, const void *b)
{
    const Nota *nota_1 = (Nota *)a;
    const Nota *nota_2 = (Nota *)b;
    return (nota_1 -> media - nota_2 -> media ); 
}
