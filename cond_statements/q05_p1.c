#include <stdio.h>
#include <math.h>


int main(int argc, char *argv[])
{
    float a,b,c;
    scanf("%f%f%f",&a,&b,&c);
    
    float delta = b*b - 4*a*c;

    if(delta < 0 || a == 0){
        printf("IMPOSSIVEL CALCULAR");
    }else{
        float x[2];
        x[0] = (-b + sqrt(delta)) / (2*a);
        x[1] = (-b - sqrt(delta)) / (2*a);

        printf("r1: %.3f\nr2: %.3f\n",x[0],x[1]);
    }
    return 0;
}
