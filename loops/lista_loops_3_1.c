#include <stdio.h>
#include <ctype.h>

int questao_seis(void);
int questao_sete(void);
int questao_oito(void);
int ordena(int t,long int *prod);

int i = 0,j = 0;

int main(int argc, char *argv[])
{
    short int opc;
    printf("\t.:OPCOES:.");
    printf("\n1 - Produto intervalo 3 valores");
    printf("\n2 - Somar salários");
    printf("\n3 - Menu interativo");
    printf("\nEscolha sua opcao: ");
    scanf("%hi",&opc);
    switch(opc)
    {
        case 1:
            questao_seis();
            break;
        case 2: 
            questao_sete();
            break;
        case 3:
            questao_oito();
            break;
        default:
            printf("Opção inválida!");
    }
    return 0;
}

// multiplicar intervalos 3 valores
int questao_seis(void)
{
    int c[3],i;
    long int prod[3] = {1,1,1};
    // tamanho do array
    int t = sizeof(prod)/sizeof(prod[0]);

    for(i = 0; i < 3; i++){
        printf("%iº número: ",i+1);
        scanf("%i",&c[i]);
    }
    for(i = 0; i < 3; i++)
    {
        printf("\nImpressão contagem do valor %i\n",c[i]);
        for(j = c[i]; j > 0; j--)
        {
            prod[i] *= j;
            printf("%i ",j);
            // exemplo: imprime 3 como sendo 1 * 2 * 3 = 6
            if(j == 1)printf("=");
            else printf("* ");
        }
        printf(" %li",prod[i]);
        printf("\n");
    }
    // chama funcao ordena array e imprime na tela
    ordena(t,prod);
    return 0;
}

// somar salarios
int questao_sete(void)
{
    float s[5] = {0,0,0,0,0},sum = 0.0;
    j = 0, i = 0;
    do
    {
        printf("Informe salário: ");
        scanf("%f",&s[i]);
        sum += s[i];
        printf("Deseja informar outro salário (0 = Nao, 1 = Sim)?");
        scanf("%i",&j);
        i++;
    }while(j != 0 && i <= 5);
    if(i > 5)
    {
        printf("Você atingiu o limite de salários a serem informados(5)\n");
    }
    printf("Soma salários:R$ %.2f",sum);
    
    return 0;
}

// funcao questao_oito
int operacoes(int n,short int opc)
{
    if(opc == 1 || opc == 2) j = 0;
    else j = 1; 
    for(i = 1; i <= n; i++)
    {
        // contar pares
        if(opc == 1)
        {
            if(i%2 == 0) j++;
        }
        // contar impares
        else if(opc == 2)
        {
            if(i%2!= 0) j++;
        }
        // produto pares
        else if(opc == 3)
        {
            if(i%2==0) j *= i;
            printf("%i ",j);
        }
        // produto impares
        else if(opc == 4)
        {
            if(i%2!=0) j *= i;
            printf("%i ",j);
        }
    }
    printf("Resultado: %i\n",j);
    return 0;
}

// menu interativo 6 opcoes
int questao_oito(void)
{
    short int opc = 0;
    int n;
    do{
        printf(".:OPCOES:.");
        printf("\n1 - Contar pares");
        printf("\n2 - Contar impares");
        printf("\n3 - Produto pares");
        printf("\n4 - Produto impares");
        printf("\n9 - Sair");
        printf("\nEscolha sua opcao: ");
        scanf("%hi",&opc);
        
        if(opc > 0 && opc <= 4)
        {
            printf("Informe um número: ");
            scanf("%i",&n);
            operacoes(n,opc);
        }else if(opc > 4 && opc < 0 && opc != 9){
            printf("Opcao inválida!");
        }
    }while(opc != 9);
    return 0;
}
int ordena(int t,long int *a)
{
    int aux = 0;
    for(i = 0; i < t;i++)
    {
        for(j = 0; j < t-i-1;j++)
        {
            if(a[j] > a[j+1])
            {
                aux = a[j];
                a[j] = a[j+1];
                a[j+1] = aux; 
            }
        }    
    }
    printf("\nOrdenado: ");
    for(i = 0; i < t; i++)
    {
        printf("%li ",a[i]);
    }
    return 0;
}

