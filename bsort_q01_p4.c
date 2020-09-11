#include <stdio.h>

float area_quad_ret(float a,float b);
float area_triang(float a, float b);
float area_circ(float a);
void insert_sort(int m[], int n);

const float pi = 3.14;
float m[4];

int main(int argc, char *argv[])
{
    float a,b;

    for(int i = 0; i < 4; i++)
    {
        if(i < 3)
        {   
            if(i == 0)printf("\n.:AREA DO RETANGULO:.");
            else if(i == 1)printf("\n.:AREA DO QUADRADO:.");
            else printf("\n.:AREA DO TRIANGULO:.");
            printf("\nLado a: ");
            scanf("%f",&a);
            printf("Lado b: ");
            scanf("%f",&b);
            m[i] = area_quad_ret(a,b);
            if(i==3) m[i] = area_triang(a,b);
        }
        else
        { 
            printf("\n.:AREA DO CIRCULO:.\n");
            printf("Raio: ");
            scanf("%f",&a);
            m[i] = area_circ(a);
        }
    }
    printf("\nÁrea retângulo: %.2f\nÁrea quadrado: %.2f\nÁrea triângulo: %.2f\nÁrea circulo: %.2f\n",m[0],m[1],m[2],m[3]); 
    
    // Retorna vetor ordenado
    int t = 4,i;
    float temp = 0.0f;
    for(i = 0; i < t; i++)
    {
        for(int j = 0;j<t-i-1;j++)
        {
            if(m[j] > m[j+1])
            {
                temp = m[j];
                m[j] = m[j+1];
                m[j+1] = temp;
            }
        }
    }
    printf("\n.:AREA EM ORDEM CRESCENTE:.\n");
    for(i = 0; i<t; i++)
    {
        printf("%.2f ",m[i]);
    }
    printf("\n\nMENOR AREA: %.2f",m[0]);
    printf("\nMAIOR AREA: %.2f",m[3]);

    return 0;
}
float area_quad_ret(float a,float b)
{
    a = a * b;
    return a;
}
float area_triang(float a,float b)
{
    a = (a * b)/2;
    return a;
}
float area_circ(float a)
{
    a = pi * (a*a);
    return a;
}
