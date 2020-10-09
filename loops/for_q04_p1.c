#include <stdio.h>


int main(int argc, char *argv[])
{
    int p = 0,i = 0;
    
    for(int c = 1;c <= 500;c++)
    {
        if(c%2==0){
            p += c;
        }
        else {
            i += c;
        }
    }
    printf("Soma impar: %i\n",i);
    printf("Soma par: %i",p);
    return 0;
}
