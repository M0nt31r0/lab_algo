#include <stdio.h>

int fat(int n)
{
    if(n==1){ 
        printf("%i = ",n);
        return 1;
    }
    else{
        printf("%i ", n);
        printf("x ");
        return n * fat(n-1);
    }
}
int main(int argc, char *argv[])
{  
    printf("%i\n",fat(5));
    return 0;
}
