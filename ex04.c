#include <stdio.h>
#include <stdlib.h>



int main(int argc, char *argv[])
{
    float r,pi = 3.14;
    
    printf("\t.:ÁREA DA CIRCUNFERÊNCIA:.");
    printf("\nRaio: ");
    scanf("%f",&r);
    
    float area = 2 * pi * r;
    printf("Área = %0.2f",area);
    
    return 0;
}
