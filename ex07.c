#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(int argc, char *argv[])
{
    float R,h,pi = 3.14,v;
    
    printf(".:VOLUME LATA DE ÓLEO:.\n");
    printf("Raio: ");
    scanf("%f",&R);    
    printf("Altura: ");
    scanf("%f",&h);
    
    v = pi * h * pow(R,2);
    printf("VOLUME = %0.2f",v);
    
    return 0;
}
