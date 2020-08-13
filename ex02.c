#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
    int anoNasc,anoAtual;
    
    printf("Informe seu ano de Nascimento: ");
    scanf("%i",&anoNasc);
    printf("Informe o ano atual: ");
    scanf("%i",&anoAtual);
    
    int idade = anoAtual - anoNasc;
    
    printf("Você viveu %i dias",idade*365);
    
    return 0;
}
