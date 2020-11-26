#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void req(float *a,float *b);
float sum(float a,float b);
float sub(float a,float b);
float divide(float a,float b);
float multiply(float a,float b);

int main()
{
    int opt;
    float a,b;
    // pass adress on function
    do{
        printf("\n\t.:SIMPLE CALCULATOR:.\n");
        printf("\n1  - Sum");
        printf("\n2  - Subtraction");
        printf("\n3  - Multiply");
        printf("\n4  - Divide");
        printf("\n5  - Potency");
        printf("\n6  - Square Root");
        printf("\n9  - Quit");
        printf("\nOPT: ");
        scanf("%i",&opt);
        
        switch (opt)
        {
            case 1:
                req(&a,&b);
                printf("%.2f",sum(a,b)); 
                break;
            case 2:
                req(&a,&b);
                printf("%.2f",sub(a,b));
                break;
            case 3:
                req(&a,&b);
                printf("%.2f",multiply(a,b));
                break;
            case 4:
                req(&a,&b);
                printf("%.2f",divide(a,b));
                break;
            case 5:
                req(&a,&b);
                printf("%.2f",pow(a,b));
                break;
            case 6:
                scanf("%f",&a);
                printf("%.2f",sqrt(a));
                break;
            case 9:
                break;
            default:
                printf ("Invalid Option!\n");
        }
        }while(opt != 9);
    
    return 0;
}
// GO TO 
void req(float *a,float *b){
    scanf("%f",a);
    scanf("%f",b);
}
float sum(float a,float b){
    return a+b;
}
float sub(float a,float b){
    return a-b;
}
float multiply(float a,float b){
    return a*b;
}
float divide(float a,float b){
    return a/b;
}

