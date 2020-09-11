#include <stdio.h>


int main(int argc, char *argv[])
{
    long a;
    printf("Digite um valor inteiro qualquer: ");
    scanf("%li",&a);

    printf("%li x",a);
    for(int c = a-1; c > 0;c--)
    {
        printf(" %i",c);
        if(c > 1) printf(" x");
        else printf(" = ");
        a *= c; 
    }   
    printf("%li",a); 
    return 0;
}
