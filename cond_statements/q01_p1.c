#include <stdio.h>

int main(int argc, char *argv[])
{
    printf("\t.:CALCULO MAIOR MENOR:.\n");
    printf("Digite 5 numeros inteiros: \n");
    
    int n[5],max = 0,min = 0;
    
    for(int c = 0;c < 5;c++)
    {
        printf("%iº número: ",c);
        scanf("%i",&n[c]);
    }
    max = n[0];
    min = n[0];
    for(int i = 0;i < 5;i++)
    {
        if(max < n[i])
        {
            max = n[i];
        }
        if(min > n[i])
        {
            min = n[i];
        }
    }
    printf("\nmax: %i min: %i",max,min);
    return 0; 
}
