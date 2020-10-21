// limpar tela
#ifdef _WIN32
#include <conio.h>
#else
#include <stdio.h>
#define clrscr() printf("\e[1;1H\e[2J")
#endif
// fim limpar tela

#include <stdlib.h>
#include <math.h>
#define S 10

void add(int *array);
void rm(int *array);
void print(int *array);
int sum(int *array);
int count(int *array);
void transfer(int *array, int *array2, int opc);
int max_min(int *array, int opc);

int main(int argc, char *argv[])
{
    short int opc; 
    int *a = (int *) calloc(sizeof(int),S);
    int *b = (int *) calloc(sizeof(int),S);
    if(a == NULL || b == NULL){
        printf("Error!\n");
        exit(0);
    }

    do{
        printf("\n\t.:VETORES A e B:.\n");
        printf("\n1  - Adicionar vetor A");
        printf("\n2  - Adicionar vetor B");
        printf("\n3  - Remover do vetor A valor da posicao x");
        printf("\n4  - Remover do vetor B valor da posicao x");
        printf("\n5  - Imprimir vetor A");
        printf("\n6  - Imprimir vetor B");
        printf("\n7  - Contar valores vetor A");
        printf("\n8  - Contar valores vetor B");
        printf("\n9  - Somar valores de cada vetor e apresentar");
        printf("\n10 - Qual vetor te maior quantidade de valores?");
        printf("\n11 - Qual vetor tem a maior soma de valores?");
        printf("\n12 - Transferir valores pares de A para B");
        printf("\n13 - Transferir valores impares de B para A");
        printf("\n14 - Media de valores de cada vetor");
        printf("\n15 - Qual vetor tem a maior media?");
        printf("\n16 - Maior valor de cada vetor");
        printf("\n17 - Menor valor de cada vetor");
        printf("\n18 - Qual vetor apresenta o maior valor");
        printf("\n99 - Sair");
        printf("\nOPCAO: ");
        scanf("%hi",&opc);
        // limpa tela
        clrscr();

        int va = 0, vb = 0;
        char compare = 'A';
        switch (opc)
        {
            case 1 :
                add(a);                
                break;
            case 2 :
                add(b);
                break;
            case 3 :
                rm(a);
                break;
            case 4 :
                rm(b);
                break;
            case 5 :
                print(a); 
                break;
            case 6 :
                print(b);              
                break;
            case 7 :
                printf("Count A: %i",count(a));
                break;
            case 8 :
                printf("Count B: %i",count(b));
                break;
            case 9 :
                printf("Soma A: %i\n",sum(a));
                printf("Soma B: %i",sum(b));
                break;
            case 10 :
                if(count(a) == count(b)) {
                    printf("A e B tem a mesma qtd");
                    break;
                }
                else if(count(b) > count(a)) compare = 'B'; 
                printf("> qtd. entre A e B: %c",compare);
                break;
            case 11 :
                va = sum(a);
                vb = sum(b);
                if(va == vb) {
                    printf("Sum(A) = Sum(B)");
                    break;
                }
                else if(vb > va) compare = 'B';
                else printf("> Soma entre A e B.: %c",compare);
                break;
            case 12 :
                transfer(a,b,opc);
                break;
            case 13 :
                transfer(a,b,opc);
                break;
            case 14 :
                printf("Media A: %i\n",sum(a)/S);
                printf("Media B: %i",sum(b)/S);
                break;
            case 15 :
                va = sum(a)/S;
                vb = sum(b)/S;
                if(va == vb){
                    printf("Med(A) = Med(B)");
                    break;
                }
                else if(vb > va) compare = 'B';
                printf("Maior media entre A e B: %c",compare);
                break;
            case 16 :
                printf("Maior A: %i\n",max_min(a,opc));
                printf("Maior B: %i", max_min(b,opc));
                break;
            case 17 :
                printf("Menor A: %i\n",max_min(a,opc));
                printf("Menor B: %i",max_min(b,opc));
                break;
            case 18 :
                va = max_min(a,opc);
                vb = max_min(b,opc);
                if(va == vb) {
                    printf("Maior valor(A) = Maior valor(B)");
                    break;
                }
                else if(va < vb) compare = 'B';
                printf("Vetor com maior valor: %c",compare);
                break;
            case 99:
                break;
            default :
                printf ("Opcao invalida!\n");
        }
    }while(opc != 99);
    free(a);
    free(b);
    return 0;
}

void add(int *array){
    for(int c = 0; c < S; c++){
        scanf("%i", array + c);
    }
}

void rm(int *array){
    int x = 0;
    printf("Remover da posicao: ");
    scanf("%i",&x);
    if(x < 0 || x > S) printf("Posicao inexistente\n");
    else{
        *(array + x) = -1;
        printf("Elemento removido da posicao\n");
    }
}

void print(int *array){
    for(int c = 0; c < S;c++) printf("[%i] = %i\n", c,*(array+c));
}

int count(int *array){
    int count = 0;
    for(int c = 0; c < S;c++){
        if(*(array+c) > 0) count++; 
    }
    return count;
}

int sum(int *array){
    int sum = 0;
    for(int c = 0; c < S; c++) sum += *(array + c); 
    return sum;
}

void transfer(int *array, int *array2, int opc){
    for(int c = 0; c < S;c++){
        if(*(array + c)%2 == 0 && opc == 12) *(array2 + c) = *(array + c);
        if(*(array2 + c)%2 != 0 && opc == 13) *(array + c) = *(array2 + c);
    }
}

int max_min(int *array, int opc){
    int tmp = 1;
    tmp = *(array);
    if(opc == 16 || opc == 18){
        for(int c = 0; c < S;c++){
            if(tmp < *(array + c)) tmp = *(array + c); 
        }
    }
    if(opc == 17){
        for(int c = 0; c < S;c++){
            if(tmp > *(array + c)) tmp = *(array + c);
        }
    }
    return tmp;
}
