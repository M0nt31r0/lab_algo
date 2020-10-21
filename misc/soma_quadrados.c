#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n[4] = {0};
    for(int c = 0; c < 3; c++){
        scanf("%i",&n[c]);
        n[3] += n[c] * n[c];
    }
    
    printf("Soma: %i",n[3]);
     return 0;
}

