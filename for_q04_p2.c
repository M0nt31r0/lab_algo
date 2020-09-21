#include <stdio.h>


int main(int argc, char *argv[])
{
    double a[5],sum = 0;

    printf(".:SOMA DE FATORIAIS:.\n");
    for(int i = 0; i < 5; i++)
    {
        // input usuario
        printf("%iº valor: ",i);

        // loop para caso valor de a[i] > 40
        do{
            scanf("%lf",&a[i]);
            if(a[i] > 40) printf("Valor inválido, digite novamente: ");
        }while(a[i] > 40);
        
        printf("Fatorial de %.0lf: ",a[i]);
        
        // calcula fatorial
        float k = a[i];
        for(int c = k - 1; c > 0; c--)
        {
            a[i] *= c;
        }
        printf("%.0lf\n",a[i]);
        sum += a[i];
    }
    printf("Soma dos fatoriais: %.0lf",sum);
    return 0;
}
