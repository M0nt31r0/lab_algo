#include <stdio.h>


int main(int argc, char *argv[])
{
    float a = 0,sum = 0.0;
    short int c = 0;
    do
    {
        sum += a;
        printf("Valor: ");
        scanf("%f",&a);
        if(a > 0) c++;
    }while(a > 0);

    printf("\nSoma %.2f\nMedia: %.2f",sum,sum/c);
    
    return 0;
}
