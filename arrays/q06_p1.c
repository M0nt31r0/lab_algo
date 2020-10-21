#include <stdio.h>
#include <stdlib.h>


int main()
{
    int a[] = {5,12,60,3,12,3,1},k = 0;
    size_t t = sizeof(a)/sizeof(a[0]);
    
    for(int i = 0;i < t;i++){
        k = 0;
        for(int j = 0;j < t;j++){
            if(a[i] == a[j]) k++;
        }
        if(k > 1) printf("%i = %i\n",a[i],k);
    }
     return 0;
}

