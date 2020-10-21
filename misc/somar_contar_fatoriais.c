#include <stdio.h>
#include <stdlib.h>
#define Max(i,k) (i>k?i:k)
#define Min(i,k) (i<k?i:k)

int main()
{
    int i,k,sum = 0,v = 0;
    scanf("%i",&i);
    scanf("%i",&k);
    for(int c = Min(i,k); c < Max(i,k); c++)
    {
        int f = 1;
        if(c%2 == 0)
        {
            for(int i = 1; i <= c; i++){
                f *= i;
            }
            printf("\n");
            sum += f;
            v++;
        }
    }
    printf("Soma: %i\nQtd: %i\n",sum,v);
     return 0;
}

