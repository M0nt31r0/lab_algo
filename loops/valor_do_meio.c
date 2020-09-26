#include <stdio.h>


int main(int argc, char *argv[])
{
    float n[4],aux,sum = 0.0;
    int j;
    
    // input usuario
    for(j = 0; j < 3;j++)
    {
        printf("%iº valor: ",j);
        scanf("%f",&n[j]);
        sum += n[j];
    }
   
    // bubble sort
    for(j = 0;j < 3;j++)
    {
        for(int c = 0; c < 3-j-1;c++)
        {
            if(n[c] > n[c+1])
            {
                aux = n[c];
                n[c] = n[c+1];
                n[c+1] = aux;
            }
        }
    }
    printf("Soma: %.2f\nMedia: %.2f\nValor do meio: %.2f",sum,sum/3,n[1]);
    

    return 0;
}
