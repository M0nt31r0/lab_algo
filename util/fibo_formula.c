#include <stdio.h>
#include <math.h>

int fib(int n){
    double phi = (1 + sqrt(5)) / 2;
    return round(pow(phi,n) / sqrt(5));
}
int main(int argc, char *argv[])
{
    // exibe 8ª posicao(0-8) fibonacci
    int n = 8;
    printf("%d",fib(n));
    return 0;
}
