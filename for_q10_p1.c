#include <stdio.h>


int main(int argc, char *argv[])
{
    long fat[5];
    int a[5], c = 0;
    
    printf("Digite 5 valores inteiros quaisquer: \n");

    for(c = 0;c < 5;c++){
        printf("%iº valor: ",c);
        scanf("%i",&a[c]);
        fat[c] = a[c];
    }
    for(int c = 0;c < 5;c++)
    {
        printf("%i x ",a[c]);
        for(int j = a[c]-1;j > 0;j--)
        {
            printf("%i",j);
            if(j != 1) printf(" x ");
            else printf(" = ");
            fat[c] *= j; 
        }
        printf("%li\n",fat[c]);
    }   
    return 0;
}
