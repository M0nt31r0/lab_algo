#include <stdio.h>


int main(int argc, char *argv[])
{
    int v[4],max = 0,min = 0,max2 = 0,min2 = 0;
    int i, c[4] = {0,0,0,0};

    for(i = 0;i < 4; i++)
    {
        if(i == 0) printf("Primeiro intervalo\n");
        else if(i == 2) printf("Segundo intervalo\n");
        printf("%iº valor: ",i+1);
        scanf("%i",&v[i]);
    }
    max = v[0];
    min = v[1];
    max2 = v[2];
    min2 = v[3];
    if(v[1] > v[0]){ 
        max = v[1];
        min = v[0];
    }
    if(v[3] > v[2]) {
        max2 = v[3];
        min2 = v[2];
    }
    for(i = min; i <= max; i++)
    {
        if(i%3==0 && i%5==0)
        {
            c[0] += 1;
            c[1] += i;
        }
    }
    for(i = min2; i <= max2; i++)
    {
        if(i%4==0 && i%3==0 && i%6==0)
        {
            c[2] += 1;
            c[3] += i;
        }
    }
    printf("Soma intervalo 1: %i\nSoma intervalo 2: %i\n",c[1],c[3]);
    printf("Contagem 1: %i\nContagem 2: %i\n",c[0],c[2]);

    // intervalo com maior soma
    if(c[1] > c[3]){
        printf("Intervalo 1 tem a maior soma (%i)\n",c[1]);
    }else if(c[1] < c[3]){
        printf("Intervalo 2 tem a maior soma (%i)\n",c[3]);
    }else{
        printf("Ambos os intervalos tem a mesma soma\n");
    }
    // intervalo com maior quantidade de valores
    if(c[0] > c[2]){
        printf("Intervalo 1 tem a maior quantidade de valores(%i)\n",c[0]);
    }else if(c[0] < c[2]){
        printf("Intervalo 2 tem a maior quantidade de valores(%i)\n",c[2]);
    }else{
        printf("Ambos os intervalos tem a mesma quantidade de valores\n");
    }
    return 0;
}
