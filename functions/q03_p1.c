#include <stdio.h>
#include <stdlib.h>

void req(int opt, float *a,float *b,float *c,float atv[],float *pluri);

float average1(float a,float b){
    return (a+b)/2;
}
float average2(float a,float b,float c){
    return (a+b+c)/3;
}
float average3(float a,float b,float c){
    return (a*0.40+b*0.40+c*0.20);
}
float average4(float a,float b,float c,float pluri){
    return (a*0.30+b*0.30+c*0.20+pluri*0.20);
}
float average5(float a,float b, float atv[], float pluri){
    atv[0] += atv[1] + atv[2];
    atv[0] /= 3;
    return (a*0.30+b*0.30+atv[0]*0.20+pluri*0.20);
}
void check(float m){
    if(m >= 5) printf("Approved!\n");
    else printf("Disapproved!\n");
}
float average6(float a,float b,float c, float atv[],float pluri){
    a = c*0.30 + a*0.70;
    printf("%f\n",a);
    b = b*0.60 + pluri*0.20 + ((atv[0] + atv[1])/2) * 0.20;
    printf("%f\n",b);
    return (a+b)/2;
}
int main()
{
    int opt;
    float a,b,c,pluri,atv[3],m = 0.0;
    do{
        printf("\n\t.:AVERAGE:.\n");
        printf("\n1  - Average 1 (A,B)");
        printf("\n2  - Average 2 (A,B,C)");
        printf("\n3  - Average 3 (A[40%%],B[40%%],C[20%%])");
        printf("\n4  - Average 4 (A[30%%],B[30%%],C[20%%],Pluri[20%%])");
        printf("\n5  - Average 5 (A[30%%],B[30%%],3C[20%%],Pluri[20%%])");
        printf("\n6  - Average 6 ((NP1+NP2)/2)");
        printf("\n9 - Quit");
        printf("\nOPT: ");
        scanf("%i",&opt);

        switch (opt)
        {
            case 1:
                req(opt,&a,&b,0,0,0);
                m = average1(a,b);
                printf("Average: %.1f\n",m);
                check(m);
                break;
            case 2:
                req(opt,&a,&b,&c,0,0);
                m = average2(a,b,c);
                printf("Average: %.1f\n",m);
                check(m);
                break;
            case 3:
                req(opt,&a,&b,&c,0,0);
                m = average3(a,b,c);
                printf("Average: %.1f\n",m);
                check(m);
                break;
            case 4:
                req(opt,&a,&b,&c,0,&pluri);
                m = average4(a,b,c,pluri);
                printf("Average: %.1f\n",m);
                check(m);
                break;
            case 5:
                req(opt,&a,&b,0,atv,&pluri);
                m = average5(a,b,atv,pluri);
                printf("Average: %.1f\n",m);
                check(m);
                break;
            case 6:
                req(opt,&a,&b,&c,atv,&pluri);
                m = average6(a,b,c,atv,pluri);
                printf("Average: %.1f\n",m);
                check(m);
                break;
            case 9:
                break;
            default:
                printf ("Invalid Option!\n");
        }
        }while(opt != 9);
    
    return 0;
}
void req(int opt, float *a,float *b,float *c,float atv[],float *pluri){

    if(opt == 1){
        printf("A: ");
        scanf("%f",a);
        printf("B: ");
        scanf("%f",b);
    }
    else if(opt == 2 || opt == 3) {
        printf("A: ");
        scanf("%f",a);
        printf("B: ");
        scanf("%f",b);
        printf("C: ");
        scanf("%f",c);
    }
    else if(opt == 4){
        printf("A: ");
        scanf("%f",a);
        printf("B: ");
        scanf("%f",b);
        printf("C: ");
        scanf("%f",c);
        printf("Pluri: ");
        scanf("%f",pluri);
    }
    else if(opt == 5){
        printf("A: ");
        scanf("%f",a);
        printf("B: ");
        scanf("%f",b);
        for(int i = 0; i < 3; i++){
            printf("atv[%i]:\t",i);
            scanf("%f",&atv[i]);
        }
        printf("Pluri:\t");
        scanf("%f",pluri);
    }
    else{
        printf("NP1: \n");
        printf("atv:\t");
        scanf("%f",c);
        printf("A:\t");
        scanf("%f",a);
        printf("NP2: \n");
        printf("atv[1]:\t");
        scanf("%f",&atv[0]);
        printf("atv[2]:\t");
        scanf("%f",&atv[1]);
        printf("Pluri:\t");
        scanf("%f",pluri);
        printf("B:\t");
        scanf("%f",b);
    }
}
