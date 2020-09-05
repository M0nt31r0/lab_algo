#include <stdio.h>


int main(int argc, char *argv[])
{
    int valor[5];
    short int par = 0,impar = 0;
    
    printf("Digite 5 valores inteiros\n");
    for(int c = 0; c < 5; c++)
    {
        printf("%iº valor: ",c);
        scanf("%i",&valor[c]);
        if(valor[c]%2 == 0){
            par++;
        }else{
            impar++;
        }
    }
    printf("PARES: %i\nIMPARES: %i\nMAIOR QUANTIDADE: ",par,impar);
    if(par > impar)printf("PAR");
    else printf("IMPAR");

    return 0;
}
