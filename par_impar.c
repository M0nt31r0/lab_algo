#include <stdio.h>

int main(int argc, char *argv[])
{
    short int n[3];
    
    for(int i = 0;i < 3;i++)
    {
        printf("%iº Valor: ",i+1);
        scanf("%hi",&n[i]);
        if(n[i]%2==0)
        {
            printf("O valor informado é par.\n");
        }else
        {
            printf("O valor informado é impar.\n");
        }
    }    
    
    
    return 0;
}
