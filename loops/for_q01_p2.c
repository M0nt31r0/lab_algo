#include <stdio.h>


int main(int argc, char *argv[])
{
    int ant = 0,prox = 0;
    
    for(int i = 0;i < 15;i++)
    {
        prox = ant + prox;
        ant = prox - ant;
        if(prox == 0){prox = prox + 1;}
        printf("%i ",prox);
    }
    return 0;
}
