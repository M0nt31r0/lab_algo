#include <stdio.h>
#include <stdlib.h>

void swap(int *a,int *b)
{
    int x = *a;
    *a = *b;
    *b = x;
}

int main(int argc, char *argv[])
{
    int n[3];

    for(int i = 0;i < 3;i++)
    {
        printf("%iº valor: ",i+1);
        scanf("%i",&n[i]);
    }
    if (n[0]>n[1] || n[1] > n[2])
    {
        if(n[1] < n[2])
        {
            swap(&n[0],&n[1]);
        }
        else
        {
            swap(&n[0],&n[2]);
        }
    }
    if (n[1]>n[2])
    {
        swap(&n[1],&n[2]);
    }
    printf("Valores ordenados: %i %i %i",n[0],n[1],n[2]);
    return 0;
}
