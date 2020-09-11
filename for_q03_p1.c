#include <stdio.h>


int main(int argc, char *argv[])
{
    int i = 0;
    for(int c = 1;c < 101;c++)
    {
        i += c;
    }
    printf("Soma: %i",i);
    
    return 0;
}
