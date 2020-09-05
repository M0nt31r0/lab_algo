#include <stdio.h>


int max_min(int a,int b,int c,int d,int e)
{
    // funcao para calcular o menor e o maior valor
    // sem uso de vetor, repetição, sort
    int max=0,min=0;
    max = a;
    if((b>=max) || (c>=max) || (d>=max) || (e>=max))
    {
        // faz verificação dos valores procurando pelo maior ou igual
        // entre b,c,d,e
        min=a;
        if((b>=c) && (b>=d) && (b>=e))
        {
            max = b;
        }
        else if ((c>=b) && (c>=d) && (c>=e))
        {
            max = c;
        }
        else if((d>=b) && (d>=c) && (d>=e))
        {
            max = d;
        }
        else
        {
            max = e;
        }
        // verifica valores para encontrar o menor ou igual
        // entre b,c,d,e se eles forem menor que a
        if((b<=min) || (c<=min) || (d<=min) || (e<=min))
        {
            if((b<=c) && (b<=d) && (b<=e))
            {
                min = b;
            }
            else if((c<=b) && (c<=d) && (c<=e))
            {
                min = c;
            }
            else if((d<=b) && (d<=c) && (d<=e))
            {
                min = d;
            }
            else
            {
                min = e;
            }
        }    
    }    
    printf("maior %i\nmenor %i",max,min);
    return 0;
}


int main(int argc, char *argv[])
{
    int a,b,c,d,e;
    
    printf("\t.:CALCULO MAIOR MENOR:.\n");
    printf("Digite 5 numeros inteiros: \n");
    scanf("%i%i%i%i%i",&a,&b,&c,&d,&e);    
    max_min(a,b,c,d,e);
    
    return 0; 
}
