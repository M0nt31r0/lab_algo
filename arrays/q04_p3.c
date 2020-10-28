#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define X 50 // number of rows
#define Y 20 // number of columns
      
int maxmin(int **mat, int opt);
int **allocate(int x, int y);
int **free_mat(int x, int y, int **mat);
void fill_mat(int **mat);
void print_mat(int **mat);
void numrep(int **mat, int v);
void report(int **mat);
void printeven(int **mat);

int main()
{
    int opt, **mat, v;
    srand(time(NULL)); // seed random
    mat = allocate(X,Y);
    
    do{
        printf("\n\t.:PROCESS:.\n");
        printf("\n1  - Load");
        printf("\n2  - Print");
        printf("\n3  - Bigger element");
        printf("\n4  - Smaller element");
        printf("\n5  - Number of elements equal to x");
        printf("\n6  - Print only even elements");
        printf("\n7  - Report even x odd");
        printf("\n9  - Quit");
        printf("\nOPT: ");
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
                maxmin(mat,opt);
                break;
            case 4:
                maxmin(mat,opt);
                break;
            case 5:
                printf("Value: ");
                scanf("%i",&v);
                numrep(mat,v); 
                break;
            case 6:
                printeven(mat); 
                break;
            case 7:
                report(mat);
                break;
            case 9:
                break;
            default:
                printf ("Invalid\n");
        }
    }while(opt != 9);

    mat = free_mat(X,Y,mat);
    
    return 0;
}
//allocate memory for matrix
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
// free memory
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
// fill matrix with numbers between 0 and 5000
void fill_mat(int **mat)
{
    int i,j;
    for(i = 0; i < X; i++){
        for(j = 0; j < Y; j++){
            mat[i][j] = rand() % 5000;
        }
    }
}
// print matrix
void print_mat(int **mat)
{
    int i,j;
    for(i = 0; i < X; i++){
        for(j = 0; j < Y; j++){
            printf("%4i ",mat[i][j]);
        }
        printf("\n");
    }
}
// find de bigger and smaller value 
int maxmin(int **mat, int opt)
{
    int i,j,index[4] = {0};
    int max = mat[0][0],min = mat[0][0];
    for(i = 0; i < X;i++){
        for(j = 0; j < Y; j++){
            if(max < mat[i][j]){
                max = mat[i][j];
                index[0] = i;
                index[1] = j;
            }
            if(min > mat[i][j]){ 
                min = mat[i][j];
                index[2] = i;
                index[3] = j;
            }
        }
    }
    if(opt == 3) printf("Bigger element: [%i][%i] = %i",index[0],index[1],max);
    else printf("Smaller element: [%i][%i] = %i",index[2],index[3],min);
    return 0;
}
// counts number of reps and print position of elements and result of count
void numrep(int **mat, int v)
{
    int i,j,index[2] = {0},c = 0;
    for(i = 0; i < X; i++){
        for(j = 0; j < Y; j++){
            if(v == mat[i][j]){
                index[0] = i;
                index[1] = j;
                c++;
                printf("INDEX [%i][%i] = %i\n",index[0],index[1],mat[i][j]);
            } 
        }
    }
    printf("Number of reps: %i",c);
}
// print only even elements in matrix
void printeven(int **mat)
{
    int i,j;
    for(i = 0; i < X; i++){
        for(j = 0; j < Y;j++){
            if(mat[i][j]%2==0) printf("[%i][%i] = %i\n",i,j,mat[i][j]);
        }
    }
}
// number of even/odd
// Sum of even/odd
// max and min even/odd
// average even/odd
// bigger sum between even/odd
// bigger count between even/odd
void report(int **mat)
{
    unsigned long int even = 0, odd = 0;
    int i,j,e = 0, o = 0;
    int maxmin[4] = {0};
    maxmin[1] = mat[0][0];
    maxmin[3] = mat[0][0];
    for(i = 0; i < X; i++){
        for(j = 0; j < Y; j++){
            if((mat[i][j]%2) == 0){
                if(e == 0) maxmin[1] = mat[i][j]; // get first even
                even += mat[i][j];
                e++;
                if(maxmin[0] < mat[i][j]) maxmin[0] = mat[i][j];
                if(maxmin[1] > mat[i][j]) maxmin[1] = mat[i][j];
            }else{
                if(o == 0) maxmin[3] = mat[i][j]; // get first odd
                odd += mat[i][j];
                o++;
                if(maxmin[2] < mat[i][j]) maxmin[2] = mat[i][j];
                if(maxmin[3] > mat[i][j]) maxmin[3] = mat[i][j];
            }
        }
    }
    printf("\tQTD\n\nEven: %i\nOdd:  %i\n\tSUM\n\nSum Even: %li\nSum Odd:  %li\n\n",e,o,even,odd);
    printf("\tMAX ELEMENT\n\nEven Max: %i   Even Min: %i\nOdd Max:  %i   Odd Min:  %i\n\n"
            ,maxmin[0],maxmin[1],maxmin[2],maxmin[3]);
    printf("\tAVERAGE\n\nEVEN: %li   ODD: %li\n\n",even/e,odd/o);
    printf("\tBIGGER SUM | QTY\n\n");
    if(even > odd) printf("Sum of EVEN > Sum of ODD\n");
    else printf("Sum of ODD > Sum of EVEN\n");
    if(e > o) printf("Qty. of EVEN > Qty. of ODD\n");
    else printf("Qty. of ODD > Qty. of EVEN\n");
}
