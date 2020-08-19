#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
    float atv[2],ead[2],av[2],pluri;
    
    // coletando dados e armazenando em um array.
    // desconsiderei o uso de um único array.
    printf("\t.:MEDIA FINAL LP:.\n");
    for(int i = 0;i<2;i++)
    {
        printf("Nota atividade(%iºsem):\t ",i+1);
        scanf("%f",&atv[i]);
        printf("Nota EAD(%iºsem):\t ",i+1);
        scanf("%f",&ead[i]);
        printf("Nota avaliação(%iºsem):\t ",i+1);
        scanf("%f",&av[i]);
        
    }    
    printf("Nota pluridisciplinar:\t ");
    scanf("%f",&pluri);
    
    //Cálculo np1,np2 e média final. 
    float np1 = (atv[0] + ead[0])* 0.2 + av[0] * 0.6;
    float np2 =(atv[1] + ead[1] + pluri)*0.2 + av[1]*0.4;
    float media = np1 * 0.4 + np2 * 0.6;
    
    printf("NP1: %0.1f\nNP2: %0.1f\nMF: %0.1f",np1,np2,media);
    return 0;
}
