#include <stdio.h>


int main(int argc, char *argv[])
{
    // Carregar e imprimir valores
    int idade[10] = {0};
    for(int c = 0; c < 10; c++)
    {
        scanf("%i",&idade[c]);
    }
    for(int c = 0;c < 10; c++)
    {
        printf("idade [%i]: %i\n",c,idade[c]);
    }
    return 0;
}
