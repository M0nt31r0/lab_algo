#include <stdio.h>
#include <stdlib.h>
#define X 6
#define Y 5

int **allocate(int x, int y);
int **free_mat(int x, int y, int **mat);
void fill_mat(int **mat,int opt);
void print_mat(int **mat,int opt);
int sum_mat(int **mat,int opt);

int main()
{
    int opt, **mat;
    mat = allocate(X,Y);
    
    do{
        printf("\n\t.:LINHAS X COLUNAS:.\n");
        printf("\n1  - Load");
        printf("\n2  - Load random");
        printf("\n3  - Print address and value");
        printf("\n4  - Print line");
        printf("\n5  - Sum line");
        printf("\n6  - Print column");
        printf("\n7  - Sum line with column");
        printf("\n9  - Exit");
        printf("\nopt: ");
        scanf("%i",&opt);

        switch (opt)
        {
            case 1:
                fill_mat(mat,opt);
                break;
            case 2:
                fill_mat(mat,opt);
                break;
            case 3:
                print_mat(mat,opt);
                break;
            case 4:
                print_mat(mat,opt);
                break;
            case 5:
                printf("Sum: %i\n",sum_mat(mat,opt));
                break;
            case 6:
                print_mat(mat,opt);
                break;
            case 7:
                printf("Sum: %i\n",sum_mat(mat,opt));
                break;
            case 9:
                break;
            default:
                printf ("Opcao invalida!\n");
        }
        }while(opt != 9); 
    mat = free_mat(X,Y,mat);
    return 0;
}

int **allocate(int m, int n)
{
    int i;
    // chk parameters
    if(m < 1 || n < 1){
        printf("Invalid Parameters\n");
        return (NULL);
    }
    // allocate lines
    int **arr = (int **) calloc(m,sizeof(int*));
    if(arr == NULL){
        printf("Out of memory\n");
        exit(0);
    }
    // allocate columns
    for(i = 0; i < m; i++){
        arr[i] = (int *) calloc(n,sizeof(int));
        if(arr[i] == NULL){
            printf("Out of memory\n");
            exit(0);
        }
    }
    return (arr);
}
int **free_mat(int m,int n,int **mat)
{
    int i;
    if(m < 1 || n < 1){
        printf("Invalid Parameters\n");
        return (NULL);
    }
    if(mat == NULL) return (NULL);
    for(i = 0; i < m; i++) free(mat[i]); // free rows
    free(mat); // free matrix
    return (NULL);
}
void fill_mat(int **mat, int opt)
{
    int i,j;
    if(opt == 1){
        for(i = 0; i < X; i++){
            for(j = 0; j < Y; j++){
                scanf("%i",&mat[i][j]);
             }
         }
    }else{
        for(i = 0; i < X; i++){
            for(j = 0; j < Y; j++){
                mat[i][j] = rand() % 50;
            }
        }
    }
}
void print_mat(int **mat, int opt)
{
    int i,j;
    if(opt == 3){
        for(i = 0; i < X; i++){
            for(j = 0; j < Y; j++){
                printf("[%i][%i] = %i\n",i,j,mat[i][j]);
            }
        }
    }
    else if(opt == 4){
        int l;
        printf("Line to print: ");
        scanf("%i",&l);
        if(l > X || l < 0) printf("Inexistent\n");
        else{
            for(i = l; i <= l; i++){
                for(j = 0; j < Y; j++){
                    printf("%i ",mat[i][j]);
                }
            }
        }
    }
    else{
        int l;
        printf("Column to print: ");
        scanf("%i",&l);
        if(l > Y || l < 0) printf("Inexistent\n");
        else{
            for(i = 0; i < X; i++){
                for(j = l; j <= l;j++)
                    printf("%i ",mat[i][j]);
            }
        }
    }
}
int sum_mat(int **mat, int opc)
{
    int i,j,sum = 0;
    if(opc == 5){
        int v;
        printf("Sum line: ");
        scanf("%i",&v);
        if(v > X || v < 0) printf("Inexistent\n");
        else{
            for(i = v; i <= v; i++){
                for(j = 0; j < Y;j++)
                    sum += mat[i][j];    
            }
        }
    }else{
        int v,w;
        printf("Line: ");
        scanf("%i",&v);
        printf("Column: ");
        scanf("%i",&w);
        if(v < 0 || w < 0 || v > X || w > Y) printf("Inexistent\n");
        else{
            for(i = 0; i < X; i++){
                for(j = 0; j < Y; j++)
                    if(i == v || j == w) sum += mat[i][j];    
            }
        }
    }
    return sum;
}
