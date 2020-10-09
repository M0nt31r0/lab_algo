#include <stdio.h>

float area = 0.0;

float area_quad_ret(float a,float b)
{
    area = a * b;
    return area;
}
float area_triang(float a,float b)
{
    area = (a * b)/2;
    return area;
}
float area_circ(float a)
{
    area = 3.14 * (a*a);
    return area;
}
int main()
{
    float a,b;
    int opc;
    do{
        printf("\n\t.:CALCULO DE AREAS\n");
        printf("1 - Quadrado\n2 - Retangulo\n3 - Triangulo\n4 - Circulo\n5 - Sair");
        printf("\nEscolha uma opção: ");
        scanf("%i",&opc);

        if (opc == 1 || opc == 2)
        {
            printf("Lado a: ");
            scanf("%f",&a);
            printf("Lado b: ");
            scanf("%f",&b);
        }
        
        switch(opc)
        {
            case 1:
                area_quad_ret(a,b);
                break;
            case 2:
                area_quad_ret(a,b);
                break;
            case 3: 
                printf("Base: ");
                scanf("%f",&a);
                printf("Altura: ");
                scanf("%f",&b);
                area_triang(a,b);
                break;
            case 4: 
                printf("Raio: ");
                scanf("%f",&a);
                area_circ(a);
                break;
            case 5:
                printf("Volte sempre!");
                break;
            default:
                printf("Opcao invalida!");
        }
        if(opc == 1 || opc == 2 || opc == 3 || opc == 4){
            printf("AREA: %.2f",area);
        }
    }while(opc != 5);
    return 0;
}

