#include <stdio.h>


int main(int argc, char *argv[])
{
    unsigned long int a,sum = 0;
    short int n = 20,i = 0;
    
    do {
        a = n;
        // condicao para n(impar)
        if(n % 2 != 0)
        {
            // calculo fatorial
            for(int c = a - 1;c > 0;c--)
            {
                a *= c;
            }
            printf("N: %i\t| Posicao %i: ",n,i+1);
            printf("\ta = %lu\n",a);
            sum += a;
            i++;
        }
        n--;
    }while(n > 0);

    printf("Soma: %lu\nQtd. de impares: %i",sum,i);
    return 0;
}
