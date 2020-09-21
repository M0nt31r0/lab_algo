#include <stdio.h>



int main(int argc, char *argv[])
{
    double a = 1;
    
    for(int c = 0;c < 64;c++)
    {
        a = a * 2;
        if(c == 63)
        {
            printf("%.0lf",a);
        }
    }
    return 0;
}
