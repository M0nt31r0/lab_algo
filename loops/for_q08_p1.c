#include <stdio.h>
#include <math.h>


int main(int argc, char *argv[])
{
    int a,b;
    long c;

    printf("Base: ");
    scanf("%i",&a);
    printf("Expoente: "); 
    scanf("%i",&b);
    
    for(int i = 0;i <= b;i++)
    {
        c = pow(a,i);
        printf("%i^%i = %li\n",a,i,c);
    }
    return 0;
}
