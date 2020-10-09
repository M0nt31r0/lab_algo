#include <stdio.h>
#include <stdlib.h>



int main(int argc, char *argv[])
{
    float C;
    
    printf(".:CONVERSOR TEMPERATURA:.\n");
    printf("Temperatura(°C): ");    
    scanf("%f",&C);
    
    float F = C * 1.8 + 32;
    
    printf("Temperatura(°F): %0.2f°F",F);
    return 0;
}
