#include <stdio.h>


int main(int argc, char *argv[])
{
    unsigned long int a,sum = 0,max = 0;
    short int n,i = 0,min = 0;

    printf("1º valor: ");
    scanf("%hi",&n);
    printf("2º valor: ");
    scanf("%lu",&a);
    
    // determinando max e min
    min = n;
    max = a;
    if(n > a){
        max = n;
        min = a;
    }
    
    // calculando fatorial entre intervalo max min
    // gambiarra
    if(max%2 == 0) printf("%lu * ",max);
    else i--;

    for(int c = max - 1;c >= min;c--)
    {
        if(c%2 == 0)
        {
            // fatorial
            max *= c;
            printf("%i",c);
            if(c > min) printf(" * ");
            // soma
            sum += max;
            // contagem
            i++;
        }
    }
    // exibindo resultado fatorial e soma e qtd de pares
    printf(" = %lu\n",max);
    printf("Soma: %lu\nQtd. de pares: %i\n",sum,i+1);
    return 0;
}
