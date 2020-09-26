#include <stdio.h>


int main(int argc, char *argv[])
{
    for(int c = 1;c <= 200;c++)
    {
        if(c%4==0) printf("%i ",c);
    }    
    return 0;
}
