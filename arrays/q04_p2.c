// limpar tela
#ifdef _WIN32
#include <conio.h>
#else
#include <stdio.h>
#define clrscr() printf("\e[1;1H\e[2J")
#endif
// fim limpar tela

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100

static int p,c;
static float x = 0,z = 0;

void adicionar(float *array,int t,short int opc);
void imprimir(float *array,int t,short int opc);
float somar(float *array,int t,short int opc);
int contar(float *array,int t,short int opc);
float maior_menor(float *array,int t,short int opc);
int remover(float *array,int t,short int opc);
int Search(float *array,int t,short int opc);
void desconto(float *array,int t,short int opc);


int main(int argc, char *argv[])
{
    // seed rand
    srand(time(NULL));

    float *salario = (float*) malloc(sizeof(float) * SIZE);
    if(salario == NULL)
    {
        exit(EXIT_FAILURE);
    }
    short int opc;
    
    do{
        printf("\n\t.:SALARIOS:.\n");
        printf("\n1  - Adicionar");
        printf("\n2  - Pesquisar salario (1º ocorrencia)");
        printf("\n3  - Pesquisar salario (contar ocorrencias)");
        printf("\n4  - Imprimir todos");
        printf("\n5  - Adicionar na posicao");
        printf("\n6  - Somar salarios");
        printf("\n7  - Somar salarios iguais");       
        printf("\n8  - Contar salarios");
        printf("\n9  - Contar salarios iguais"); 
        printf("\n10 - Contar salarios (> que x)");
        printf("\n11 - Maior salario");
        printf("\n12 - Menor salario"); 
        printf("\n13 - Media salarios"); 
        printf("\n14 - Remover salarios iguais a x"); 
        printf("\n15 - Remover todos salarios");
        printf("\n16 - Remover salarios na posicao x");
        printf("\n17 - Imprimir salario da posicao x");
        printf("\n18 - Imprimir salarios menores que x");
        printf("\n19 - Aplicar decrescimo de Z%%");      
        printf("\n20 - Aplicar desconto de Z%% em salarios > x");
        printf("\n99 - Sair");
        printf("\nOpcao: ");
        scanf("%hi",&opc);
        clrscr();
        switch (opc)
        {
            case 1 :
                adicionar(salario,SIZE,opc);
                break;
            case 2 :
                if(Search(salario,SIZE,opc) == 0) printf("NAO ENCONTRADO!\n");
                break;
            case 3 :
                printf("Qtd.: %i",Search(salario,SIZE,opc));
                break;
            case 4 :
                imprimir(salario,SIZE,opc);
                break;
            case 5 :
                adicionar(salario,SIZE,opc);
                break;
            case 6 :
                printf("Soma: R$%.2f\n",somar(salario,SIZE,opc));
                break;
            case 7 :
                printf("Soma: R$%.2f\n",somar(salario,SIZE,opc));
                break;
            case 8 :
                printf("Contagem: %i",contar(salario,SIZE,opc));
                break;
            case 9 :
                printf("Contagem: %i",contar(salario,SIZE,opc));
                break;
            case 10 :
                printf("Contagem: %i",contar(salario,SIZE,opc));
                break;
            case 11 :
                printf("Maior: %.2f",maior_menor(salario,SIZE,opc));
                break;
            case 12 :
                printf("Menor: %.2f",maior_menor(salario,SIZE,opc));
                break;
            case 13 :
                    printf("Media: %.2f",maior_menor(salario,SIZE,opc));
                break;
            case 14 :
                if(remover(salario,SIZE,opc) != 0) printf("Removido com sucesso!\n");
                else printf("Valor nao encontrado\n");
                break;
            case 15 :
                remover(salario,SIZE,opc);
                break;
            case 16 :
                remover(salario,SIZE,opc);
                break;
            case 17 :
                imprimir(salario,SIZE,opc);
                break;
            case 18 :
                imprimir(salario,SIZE,opc);
                break;
            case 19 :
                desconto(salario,SIZE,opc);
                break;
            case 20 :
                desconto(salario,SIZE,opc);
                break;
            case 99:
                break;
            default :
                printf ("Opcao invalida!\n");
        }
    }while(opc != 99);
    free(salario);
    return 0;
}
void adicionar(float *array,int t, short int opc)
{
    if(opc == 1){
        for(c = 0; c < t;c++){
            array[c] = rand() % 100 + 1;

        }
    }
    else if(opc == 5){
        printf("Posicao: ");
        scanf("%i",&p);
        if(p < 0 || p > t) printf("Posicao invalida!\n");
        else{
            printf("Valor: ");
            scanf("%f",&x);
            array[p] = x;
            printf("Valor adicionado!\n");
        }
    }
}
void imprimir(float *array, int t, short int opc)
{
    if(opc == 4)
    {
        for(c = 0; c < t; c++) printf("[%i] = \tR$%.2f\n",c,array[c]);
    }
    else if(opc == 17)
    {
        printf("Posicao: ");
        scanf("%i",&p);
        printf("[%i] = R$%.2f\n",p,array[p]);
    }
    else
    {
        printf("Valor: ");
        scanf("%f",&x);
        for(c = 0; c < t; c++){
            if(array[c] < x) printf("[%i] = \tR$%.2f\n",c,array[c]);
        }
    }
}

float somar(float *array,int t,short int opc)
{
    float sum = 0;
    if(opc == 6){
        for(c = 0; c < t; c++) sum += array[c];
        return sum;
    }
    else{
        printf("Salario: ");
        scanf("%f",&x);
        for(c = 0; c < t; c++) if(array[c] == x) sum += array[c];
        return sum;
    }
}
int contar(float *array,int t,short int opc)
{
    short int i = 0,iv = 0, p = 0;
    if(opc == 9 || opc == 10)
    {
        printf("Salario: ");
        scanf("%f",&x);
    }
    for(int c = 0; c < t; c++)
    {
        p++;
        if(array[c] == x) i++;
        else if(array[c] > x) iv++;
    }
    if(opc == 8) return p;
    else if(opc == 9) return i;
    else return iv;
}
int Search(float *array, int size, short int opc)
{
    int c = 0,find = 0;
    float toSearch;
    printf("Salario: ");
    scanf("%f",&toSearch);
    
    if(opc == 2){
        while(c <= size && find == 0){
            if(array[c] == toSearch){
                printf("[%i] = R$%.2f\n",c,array[c]);
                find++;
            }
            c++;
        }
        return find;
    }
    else{
        while(c <= size){
            if(array[c] == toSearch) find++;
            c++;
        }
        return find;
    }   
}

float maior_menor(float *array, int t,short int opc)
{
    float max = 0, min = 0;
    max = array[0];
    min = array[0];
    for(c = 0; c < t; c++){
        x += array[c];
        if(array[c] > max) max = array[c];
        if(array[c] < min) min = array[c];
    }
    if(opc == 11) return max;
    else if(opc == 12) return min;
    else return (x/t);
}
int remover(float *array, int t, short int opc)
{
    if(opc == 14){
        printf("Remover: ");
        scanf("%f",&x);
        for(c = 0; c < t; c++)
        {
            if(array[c] == x) array[c] = -1;
            p++;
        }
        return p;
    }
    else if(opc == 15)
    {
        for(c = 0; c < t; c++) array[c] = -1;
    }
    else
    {
        printf("Remover posicao: ");
        scanf("%i",&p);
        if(p < 0 || p > t) printf("Posicao invalida!\n");
        else array[p] = -1;
    }
    return 0;
}
void desconto(float *array, int t, short int opc)
{
    printf("Desconto: ");
    scanf("%f",&z);
    if(opc == 19)
    {
        for(c = 0; c < t; c++){
            array[c] *= (1 - z/100);        
        }
    }
    else
    {
        printf("Referencia: ");
        scanf("%f",&x);
        for(c = 0; c < t; c++){
            if(array[c] > x) array[c] *= (1.00 - z/100);
        }
    }
}

