#include <stdio.h>
#include <stdlib.h>


int main()
{
    float v = 1,d[3];
    for(int c = 0; c < 3; c++){
        if(c == 0) printf("Comprimento: ");
        else if(c == 1) printf("Largura: ");
        else printf("Altura: ");
        scanf("%f",&d[c]);
        v *= d[c];
    }
    printf("Volume = %.2f\n",v);
     return 0;
}

