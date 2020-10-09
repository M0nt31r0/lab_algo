#include <stdio.h>
#include <stdlib.h>



int main(int argc, char *argv[])
{
    float r,pi = 3.14;
    
    printf("\t.:AREA DA CIRCUNFERENCIA:.");
    printf("\nRaio: ");
    scanf("%f",&r);
    
    float area = 2 * pi * r;
    printf("Area = %0.2f",area);
    
    return 0;
}
