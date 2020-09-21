#include <stdio.h>


int main(int argc, char *argv[])
{
    int n,sum = 0;

    for(int i = 0; i < 6; i++)
    {
        printf("%iº número: ",i + 1);
        scanf("%i",&n);
        sum += n;
    }

    printf("Soma: %i\nMédia: %i",sum,sum/6);
    return 0;
}
