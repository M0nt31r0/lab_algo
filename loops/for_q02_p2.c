#include <stdio.h>


int main(int argc, char *argv[])
{
    for(int i = 10;i <= 100;i++)
    {
        if(i%10==0)
        {
            printf("Celsius: %i°C\n",i);
            printf("Fahrenheit: %.1f°F\n",(float)(i*1.8+32));
        }
    }
    return 0;
}
