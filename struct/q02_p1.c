#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct
{
    long int RA;
    char name[20];
    short int age;
    float tuition;
}student;
typedef struct
{
    long int pRA;
    char pname[20];
    short int page;
    float ptuition;
}parameters;

void inicialize(student *info, int size);
void inicializeParam(parameters p);
int getPosition(student *info, int size);
int check(student *info, int size, long int RA);
void getInfo(parameters *p);
void insert(student *info, int size, parameters p);
void PrintAll(student *info, int size);
void toChange(student *info, int size, parameters p);
void toRemove(student *info, int size,long int RA);
void toSearch(student *info, int size, long int RA);
float AverageTuition(student *info, int size, short int opt);
float maxminTuit(student *info, int size, short int opt);
void biggerThanX(student *info, int size, float t);

int main()
{
    short int opt,k = 0;
    float c = 0;
    student info[2];
    parameters p;
    size_t size = sizeof(info)/sizeof(*info);
    inicialize(info,size);

    do{
        inicializeParam(p);
        printf("\n\t.:STUDENTS:.\n");
        printf("\n1  - Insert");
        printf("\n2  - Change");
        printf("\n3  - Remove");
        printf("\n4  - Search(RA)");
        printf("\n5  - Print All");
        printf("\n6  - Sum tuition");
        printf("\n7  - Number registered students");
        printf("\n8  - Average value tuition");
        printf("\n9  - Maximum value tuition");
        printf("\n10 - Minimum value tuition");
        printf("\n11 - Print tuition bigger than x");
        printf("\n20 - Quit");
        printf("\nOPT: ");
        scanf("%hi",&opt);

        switch (opt)
        {
            case 1:
                getInfo(&p);
                insert(info, size, p);
                break;
            case 2:
                getInfo(&p);
                toChange(info, size, p);
                break;
            case 3:
                printf("RA: ");
                scanf("%li",&p.pRA);
                toRemove(info, size, p.pRA);
                break;
            case 4:
                printf("RA: ");
                scanf("%li",&p.pRA);
                toSearch(info, size, p.pRA);               
                break;
            case 5:
                PrintAll(info,size);
                break;
            case 6:
                c = AverageTuition(info, size, opt);
                printf("Sum: %.2f",c);
                break;
            case 7:
                k = AverageTuition(info, size, opt);
                printf("Registered students: %hi",k);
                break;
            case 8:
                c = AverageTuition(info, size, opt);
                printf("Average: %.2f",c);
                break;
            case 9:
                c = maxminTuit(info, size, opt);
                printf("Max: %.2f",c);
                break;
            case 10:
                c = maxminTuit(info, size, opt);
                printf("Min: %.2f",c);
                break;
            case 11: 
                printf("X: ");
                scanf("%f",&p.ptuition);
                biggerThanX(info, size, p.ptuition);
                break;
            case 20:
                break;
            default:
                printf ("Invalid Option!\n");
        }
        }while(opt != 20);
    
    return 0;
}
void inicialize(student *info,int  size)
{
    for(int i = 0; i < size; i++){
        info[i].age = 0;
        info[i].tuition = 0.0;
        info[i].RA = 0;
        strcpy(info[i].name,"NULL");
    }
}

void inicializeParam(parameters p)
{
    p.page = 0;
    p.ptuition = 0.0;
    p.pRA = 0;
    strcpy(p.pname,"NULL");
}

void getInfo(parameters *p)
{
    printf("RA: ");
    scanf("%li", &p->pRA);
    printf("Name: ");
    scanf(" %[^\n]s", p->pname);
    printf("Age: ");
    scanf("%hi",&p->page);
    printf("Tuition: ");
    scanf("%f",&p->ptuition);
}

int getPosition(student *info, int size)
{
    int i,j = -1;
    for(i = 0; i < size; i++){
        if(info[i].RA == 0){
            j = i;
            return j;
        }
    }
    return j;
}

int check(student *info, int size, long int RA)
{
    int i,j = -1;
    for(i = 0; i < size; i++){
        if(info[i].RA == RA){
            j = i;
            return j;
        }
    }
    return j;
}

void insert(student *info, int size, parameters p)
{
    short int pos = getPosition(info, size);
    short int findElement = check(info, size, p.pRA);
    if(pos == -1) printf("Database full\n");
    else if(findElement >= 0) printf("RA already registered\n");
    else{
        info[pos].RA = p.pRA;
        info[pos].age = p.page;
        info[pos].tuition = p.ptuition;
        strcpy(info[pos].name, p.pname);
    }
}

void PrintAll(student *info, int size)
{
    for(int i = 0; i < size; i++){
        printf("%li; %s; %hi; %.2f\n", info[i].RA, info[i].name, info[i].age, info[i].tuition);
    }
}

void toChange(student *info, int size, parameters p){
    int pos = check(info, size, p.pRA);
    if(pos >= 0){
        strcpy(info[pos].name,p.pname);
        info[pos].age = p.page;
        info[pos].tuition = p.ptuition;
        printf("Data changed!\n");
    }else{
        printf("Register not found!\n");
    }
}

void toRemove(student *info, int size,long int RA)
{
    int pos = check(info, size, RA);
    if(pos >= 0){
        info[pos].age = 0;
        info[pos].RA = 0;
        info[pos].tuition = 0.0;
        strcpy(info[pos].name, "NULL");
        printf("Removed!\n");
    }else printf("RA not found!\n");
}

void toSearch(student *info, int size, long int RA){
    short int k = 0;
    for(int i = 0; i < size; i++){
        if(info[i].RA == RA){
            printf("%li; %s; %hi; %f", RA, info[i].name, info[i].age, info[i].tuition);
            k++;
        }
    }
    if(k == 0) printf("RA not found!\n");
}
float AverageTuition(student *info, int size, short int opt){
    float sum = 0;
    short int k = 0;
    for(int i = 0; i < size; i++){
        if(info[i].tuition > 0){
            sum += info[i].tuition;
            k++;
        }
    }
    if(opt == 6) return sum;
    else if(opt == 7) return k;
    else return (sum/k);
}
float maxminTuit(student *info, int size, short int opt)
{
    float min, max;
    min = info[0].tuition;
    max = info[0].tuition;
    for(int i = 0; i < size; i++){
        if(max < info[i].tuition) max = info[i].tuition;
        if(min > info[i].tuition) min = info[i].tuition;
    }
    if(opt == 9) return max;
    else return min;
}
void biggerThanX(student *info, int size, float t){
    for(int i = 0; i < size; i++){
        if(info[i].tuition > t && info[i].tuition != 0){
           printf("%li; %s; %i; %2f\n",info[i].RA,info[i].name,info[i].age,info[i].tuition);
        }
    }
}
