#include <stdio.h>


int main(int argc, char *argv[])
{
    int a,b;

    scanf("%i%i",&a,&b);
    
    if(b >= a)
    {
        if(b==a)
        {
            printf("Valores iguais não permitidos");
        }else
        {
            printf("O maior valor é: %i",b);
        }
    }else
    {
        printf("O maior valor é: %i",a);
    }
    return 0;
}
