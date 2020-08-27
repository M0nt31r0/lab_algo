#include <stdio.h>


int main(int argc, char *argv[])
{
    int a,b,c;
    scanf("%i\n%i\n%i",&a,&b,&c);
    if(a>b)
    {
        if(b>c)
        {
            printf("%i %i %i\n",c,b,a);
        }
        else
        {
            if(a>c)
            {
                printf("%i %i %i\n",b,c,a);
            }
            else
            {
                printf("%i %i %i\n",b,a,c);
            }
        }
    }
    else
    {
        if(b>c)
        {
            if(a>c)
            {
                printf("%i %i %i\n",c,a,b);
            }else{
                printf("%i %i %i\n",a,c,b);
            }
        }
        else
        {
            printf("%i %i %i\n",a,b,c);
        }
    }
    
    
    return 0;
}
