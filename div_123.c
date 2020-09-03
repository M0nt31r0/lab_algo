#include <stdio.h>


int main(int argc, char *argv[])
{
    int n[3];
    printf("\t.:DIVISIVEL 1,2,3:.\n");
    for(int i = 0;i<3;i++)
    {
        printf("Digite um numero inteiro qualquer: \n");
        scanf("%i",&n[i]);
        if(n[i]%1 == 0)
        {
            if(n[i]%2 == 0)
            {
                if(n[i]%3 == 0)
                {
                    printf("O número %i É divisível por 1,2 e 3\n",n[i]);
                }else
                {
                    printf("O número %i NAO é divisível por 1,2 e 3\n",n[i]);
                }
            }else
            {
                printf("O número %i NAO é divisível por 1,2 e 3\n",n[i]);
            }
        }else
        {
            printf("O número %i NAO é divisível por 1,2 e 3\n",n[i]);
        }
    }
    return 0;
}
