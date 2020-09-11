#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{
    const short d = 3;
    for(int c = 0;c <= 15;c++)
    {
        int k = pow(d,c);
        printf("%hi^%i = %i\n",d,c,k);
    }
    return 0;
}
