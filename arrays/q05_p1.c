#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define Max(n,i) (n>i?n:i)
#define Min(n,i) (n<i?n:i)

int main(int argc, char *argv[])
{
    int opc, m[60] = {0}, n = 0, c = 0, i = 0;
    size_t t = sizeof(m) / sizeof(m[0]);
    
    // seed rand
    srand(time(NULL));
    do{
        printf("\n\t.:SORTEIO2:.\n");
        printf("\n1 - Atribuir(-1)");
        printf("\n2 - Carregar array");
        printf("\n3 - Imprimir");
        printf("\n4 - Intervalo array");
        printf("\n5 - Sair \n");
        scanf("%i",&opc);

        switch (opc)
        {
            case 1 :
                for(c = 0; c < t; c++){
                    m[c] = -1;
                }
                break;
            case 2 :
                for(c = 0; c < t; c++){
                    m[c] = rand() % 60 + 1;
                }
                break;    
            case 3 :
                for(c = 0; c < t; c++){
                    printf("[%i] = %i\n",c,m[c]);
                }
                break;
            case 4 :
                scanf("%i%i",&n,&i);
                for(c = Min(n,i); c < Max(n,i);c++){
                    printf("[%i] = %i\n",c,m[c]);
                } 
                break;
            case 5 :
                break; 
            default :
                printf ("Opcao invalida!\n");
        }
    }while(opc != 5);
    return 0;
}
