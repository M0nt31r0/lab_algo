#include <stdio.h>


int main(int argc, char *argv[])
{
    float v;
  
    printf("Informe o valor do produto: R$ ");
    scanf("%f",&v);

    if (v <= 3000.00)
    {
        printf("BARATO");
    }
    else if (v > 3000.00 && v <= 5000.00)
    {
        printf("CARO");
    }
    else
    {
        printf("ABSURDO");
    }
    return 0;
}
