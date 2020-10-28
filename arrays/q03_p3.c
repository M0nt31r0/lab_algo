#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define X 6
#define Y 5

int **allocate(int x, int y);
int **free_mat(int x, int y, int **mat);
void fill_mat(int **mat);
void print_mat(int **mat);
int sum_mat(int **mat, int opt);

int main()
{
    int opt, **mat;
    mat = allocate(X,Y);
    srand(time(NULL));
    do{
        printf("\n\t.:ROWS X COLUMNS:.\n");
        printf("\n1  - Load random");
        printf("\n2  - Print all");
        printf("\n3  - Sum each lines");
        printf("\n4  - Sum each column");
        printf("\n5  - Line with most sum value");
        printf("\n6  - Column with most sum value");
        printf("\n7  - Most sum value columns and lines");
        printf("\n9  - Exit");
        printf("\nopt: ");
        scanf("%i",&opt);

        switch (opt)
        {
            case 1:
                fill_mat(mat);
                break;
            case 2:
                print_mat(mat);
                break;
            case 3:
                sum_mat(mat,opt);
                break;
            case 4:
                sum_mat(mat,opt);
                break;
                case 5:
                printf("Bigger sum value: %i",sum_mat(mat,opt));
                break;
            case 6:
                printf("Bigger sum value: %i",sum_mat(mat,opt));
                break;
            case 7:
                sum_mat(mat,opt);
                break;
            case 9:
                break;
            default:
                printf ("Invalid Option!\n");
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
void fill_mat(int **mat)
{
    int i,j;
    for(i = 0; i < X; i++){
        for(j = 0; j < Y; j++){
            mat[i][j] = rand() % 50;
        }
    }
}
void print_mat(int **mat)
{
    int i,j;
    for(i = 0; i < X; i++){
        for(j = 0; j < Y; j++){
            printf("%4i",mat[i][j]);
        }
        printf("\n");
    }
}
int sum_mat(int **mat, int opc)
{
    int i,j,sum,tmp = 0;
    if(opc == 3 || opc == 5){
        for(i = 0; i < X; i++){
            sum = 0;
            for(j = 0; j < Y;j++){
                sum += mat[i][j];
                printf("%2i",mat[i][j]);
                if(j < Y - 1) printf(" + ");
                else printf(" = ");
            }
            if(sum > tmp) tmp = sum;
            printf("%i\n",sum);
        }
    }
    else if(opc == 4 || opc == 6){
         for(i = 0; i < X; i++){
             sum = 0;
             for(j = 0; j < Y; j++){
                sum += mat[j][i];
                printf("%2i",mat[j][i]);
                if(j < Y - 1) printf(" + ");
                else printf(" = ");
             }
             printf("%i\n",sum);
             if(sum > tmp) tmp = sum;
         }
    }
    else{
        int l,c,sum_line = 0,sum_col = 0;
        do{
            printf("Row: ");
            scanf("%i",&l);
            printf("Column: ");
            scanf("%i",&c);
        }while(c > Y || c < 0 || l < 0 || l > X);
        for(i = 0; i < X; i++){
            for(j = 0; j < Y; j++){
                if(l == i)sum_line += mat[i][j];
                if(c == j)sum_col += mat[j][i];
            }
        }
        if(sum_line < sum_col) printf("Bigger sum: column with %i",sum_col);
        else if(sum_line > sum_col) printf("Bigger sum: row with %i",sum_line);
        else printf("Equal sum!");
        return 0;
    }
    if(opc == 5 || opc == 6) return tmp;
    else return 0;
}
