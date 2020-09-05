#include <stdio.h>


int main(int argc, char *argv[])
{
    int num[4],c;
    for(c = 0; c < 4; c++){
        printf("%iº número: ",c);
        scanf("%i",&num[c]);
    }
    printf("Valores divisíveis por 2 e 3: ");
    for(int c = 0; c < 4; c++){
        if(num[c]%2 == 0 && num[c]%3 == 0)printf("%i ",num[c]);
    }

    return 0;
}
