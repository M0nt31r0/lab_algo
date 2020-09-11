#include <stdio.h>


int main(int argc, char *argv[])
{
    for(int c = 1;c <= 20;c++)
    {
        if(c % 2 != 0)printf("%i ",c);
    }    
    return 0;
}
