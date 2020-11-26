#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void req(float *a,float *b);
float square(float a,float b);
float triangle(float a,float b);
float losang(float a,float b);
float cone(float a,float b);
float parallel(float a,float b,float c);
float circle(float a);
float trapez(float a,float b,float c);

const float pi = 3.14159;
int main()
{
    int opt;
    float a,b,c;
    
    do{
        float v = 0.0;
        printf("\n\t.:AREA GEOMETRIC FIGURES:.\n");
        printf("\n1  - Rectangle");
        printf("\n2  - Triangle");
        printf("\n3  - Square");
        printf("\n4  - Circle");
        printf("\n5  - Parallelepiped");
        printf("\n6  - Losangle");
        printf("\n7  - Cone");
        printf("\n8  - Trapezium");
        printf("\n9  - Quit");
        printf("\nOPT: ");
        scanf("%i",&opt);

        switch (opt)
        {
            case 1:
                req(&a,&b);
                v = square(a,b);
                printf("%.2f",v);
                break;
            case 2:
                req(&a,&b);
                v = triangle(a,b);
                printf("%.2f",v);
                break;
            case 3:
                req(&a,&b);
                v = square(a,b); 
                printf("%.2f",v);
                break;
            case 4:
                scanf("%f",&a);
                v = circle(a);
                printf("%.2f",v);
                break;
            case 5:
                scanf("%f",&a);
                scanf("%f",&b);
                scanf("%f",&c);
                v = parallel(a,b,c);
                printf("%.2f",v);
                break;
            case 6:
                req(&a,&b);
                v = triangle(a,b);
                printf("%.2f",v);
                break;
            case 7:
                req(&a,&b);
                v = cone(a,b);
                printf("%.2f",v);           
                break;
            case 8:
                scanf("%f",&a);
                scanf("%f",&b);
                scanf("%f",&c);
                v = trapez(a,b,c);
                printf("%.2f",v);
                break;
            case 9:
                break;
            default:
                printf ("Invalid Option!\n");
        }
        }while(opt != 9);
    
    return 0;
}
void req(float *a,float *b){
    scanf("%f",a);
    scanf("%f",b);
}
float square(float a,float b){
    return a*b;
}
float triangle(float a,float b){
    return (a*b)/2;
}
float circle(float a){
    return pi*(a*a);
}
float parallel(float a,float b,float c){
    return 2*(a*b + a*c + b*c);
}
float cone(float a,float b){
    return (pi*a*(a + sqrt(a*a + b*b))); // total surface area
}
float trapez(float a,float b,float c){
    return ((a+b)*c)/2;
}
