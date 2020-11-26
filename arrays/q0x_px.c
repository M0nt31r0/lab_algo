#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define X 50
#define Y 100


int **allocate(int x, int y);
int **free_mat(int x, int y, int **mat);
void fill_mat(int **mat);
void print_mat(int **mat);
void print_line(int **mat);
void print_column(int **mat);
int print_sum(int **mat);
int menor_sumCol(int **mat);
long sumRowCol(int **mat);
void maxminMat(int **mat);

int main()
{
    int opc, **mat;
    srand(time(NULL)); // seed
    mat = allocate(X,Y);
    // carrega com valores aleatorios 1-30
    fill_mat(mat);
    
    do{
        printf("\n\t.:MATRIZ:.\n");
        printf("\n1  - Carregar");
        printf("\n2  - Imprimir todos");
        printf("\n3  - Imprimir linha x");
        printf("\n4  - Imprimir coluna Y");
        printf("\n5  - Imprimir soma das linhas");
        printf("\n6  - Linha com maior soma");
        printf("\n7  - Coluna com menor soma");
        printf("\n8  - Somar linha x com coluna y");        
        printf("\n9  - Menor e maior valor");
        printf("\n99  - Sair");
        printf("\nOPCAO: ");
        scanf("%i",&opc);

        switch (opc)
        {
            case 1:
                fill_mat(mat);
                break;
            case 2:
                print_mat(mat);
                break;
            case 3:
                print_line(mat);
                break;
            case 4:
                print_column(mat);
                break;
            case 5:
                print_sum(mat);
                break;
            case 6:
                printf("Linha com maior soma: [%i]\n",print_sum(mat));
                break;
            case 7:
                printf("Coluna com menor soma: [%i]\n",menor_sumCol(mat));
                break;
            case 8:
                printf("%li",sumRowCol(mat));
                break;
            case 9:
                maxminMat(mat);
                break;
            case 99: 
                break;
            default:
                printf ("Opcao invalida!\n");
        }
    }while(opc != 99);
    mat = free_mat(X,Y,mat); 
    
    return 0;
}
int **allocate(int m, int n)
{
    int i;
    // checa parametros
    if(m < 1 || n < 1){
        printf("Parametros invalidos\n");
        return (NULL);
    }
    // aloca linhas 
    int **arr = (int **) calloc(m,sizeof(int*));
    if(arr == NULL){
        printf("Sem memoria\n");
        exit(0);
    }
    // aloca colunas
    for(i = 0; i < m; i++){
        arr[i] = (int *) calloc(n,sizeof(int));
        if(arr[i] == NULL){
            printf("Sem memoria\n");
            exit(0);
        }
    }
    return (arr);
}
// free matriz
int **free_mat(int m,int n,int **mat)
{
    int i;
    if(m < 1 || n < 1){
        printf("Parametros invalidos\n");
        return (NULL);
    }
    if(mat == NULL) return (NULL);
    for(i = 0; i < m; i++) free(mat[i]); // libera linhas
    free(mat); 
    return (NULL);
} 
// preenche matriz com valores entre 0 e 1000
void fill_mat(int **mat)
{
    int i,j;
    for(i = 0; i < X; i++){
        for(j = 0; j < Y; j++){
            mat[i][j] = rand() % 1000;
        }
    }
}
// print matrix
void print_mat(int **mat)
{
    int i,j;
    for(i = 0; i < X; i++){
        for(j = 0; j < Y; j++){
            printf("%3i ",mat[i][j]);
        }
        printf("\n");
    }
}

void print_line(int **mat)
{
    short int x,i,j;
    do{
        printf("x: ");
        scanf("%hi",&x);
    }while(x < 0 || x > (X-1));
    for(i = x; i <= x; i++){
        for(j = 0; j < Y; j++){
            printf("%i ",mat[i][j]);
        }
        printf("\n");
    }
}
void print_column(int **mat)
{
    short int x,i,j;
    do{
        printf("x: ");
        scanf("%hi",&x);
    }while(x < 0 || x > (Y-1));
    for(i = x; i <= x; i++){
        for(j = 0; j < X; j++){
            printf("%i ",mat[j][i]);
        }
        printf("\n");
    }
}
int print_sum(int **mat)
{
    short int i,j,k = 0;
    long sum = 0,tmp = 0;
    for(i = 0; i < X; i++){
        sum = 0;
        for(j = 0; j < Y; j++){
            sum += mat[i][j];
        }
        if(sum > tmp){
            tmp = sum; // linha com > soma
            k = i; // posicao linha
        }
        printf("[%i] = %li\n",i,sum);
    }
    return k;
}
int menor_sumCol(int **mat)
{
    short int i,j,k = 0;
    long sum = 0,tmp = 0;
    for(i = 0; i < Y; i++){
        sum = 0;
        for(j = 0; j < X; j++){
            sum += mat[j][i];
        }
        if(sum < tmp){
            tmp = sum; // menor soma coluna
            k = i; // posicao
        }
        printf("[%i] = %li\n",i,sum); // facilitar visualizacao
    }
    return k;
}
long sumRowCol(int **mat)
{
    short int i,j,x,y;
    int sum = 0,sumc = 0, suml = 0;
    do{
        printf("linha: ");
        scanf("%hi",&x);
    }while(x < 0 || x > (X-1));
    do{
        printf("coluna: ");
        scanf("%hi",&y);
    }while(x < 0 || x > (Y-1));
    for(i = x; i <= x; i++){
        for(j = 0; j < Y; j++){
            suml += mat[i][j]; // soma linha 
        }
    }
    for(i = y; i <= y; i++){
        for(j = 0; j < X; j++){
            sumc += mat[j][i]; // soma coluna
        }
    }
    sum = sumc + suml;
    return sum;
}
void maxminMat(int **mat)
{
    short int i,j,min = 0,max = 0;
    int colMax = 0, linMax = 0, colMin = 0, linMin = 0;
    min = mat[0][0];
    max = mat[0][0];
    for(i = 0; i < X; i++){
        for(j = 0; j < Y; j++){
            if(min > mat[i][j]) {  // menor valor
                min = mat[i][j];
                linMin = i;
                colMin = j;
            }
            if(max < mat[i][j]) {  // maior valor
                max = mat[i][j];
                linMax = i;
                colMax = j;
            }
        }
    }
    printf("Maior valor matriz: [%i][%i] = %i\n",linMax, colMax,max);
    printf("Menor valor matriz: [%i][%i] = %i\n",linMin, colMin,min);
}
