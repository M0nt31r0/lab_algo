#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Database {
    unsigned long long cpf;
    char name[20];
    short int age;
    char sex[1];
    float salary;

};
struct Parameters {
    unsigned long long pCpf;
    char pName[20];
    short int pAge;
    char pSex[1];
    float pSalary;
};


void inicialize(struct Database *clients, int Size){
    for(int i = 0; i < Size; i++){
        clients[i].cpf = 0;
        strcpy(clients[i].name, "NULL");
        clients[i].sex[0] = 'c';
        clients[i].age= 0;
        clients[i].salary = 0.0;
    }
}

void printAll(struct Database *clients, int Size){
    for(int i = 0; i < Size; i++){
        if(clients[i].cpf > 0){
            printf("%lli | %s | %i | %c | R$ %.2f\n",clients[i].cpf,clients[i].name,clients[i].age,clients[i].sex[0],clients[i].salary);
        }   
    }
}

int getPosition(struct Database *clients, int Size){
    int i,j = -1;
    for(i = 0; i < Size; i++){
        if(clients[i].cpf == 0){
            j = i;
            break;
        }
    }
    return j;
}

int toSearch(struct Database *clients, int Size, unsigned long long code){
    int find = -1;
    for(int i = 0; i < Size; i++){
        if(clients[i].cpf == code){
            find = i;
            break;
        }
    }
    // return position of element 
    return find;
}


void insert(struct Database *clients, int Size, struct Parameters p){
    int pos = getPosition(clients,Size);
    if(pos == -1){
        printf("Database full!");
    }else{
        clients[pos].cpf = p.pCpf;
        strcpy(clients[pos].name,p.pName);
        clients[pos].age = p.pAge;
        clients[pos].sex[0] = p.pSex[0];
        clients[pos].salary = p.pSalary;
    }
}
void toChange(struct Database *clients, int Size, struct Parameters p){
    int code = p.pCpf;
    int find = toSearch(clients, Size, code);
    strcpy(clients[find].name,p.pName);
    clients[find].age = p.pAge;
    clients[find].sex[0] = p.pSex[0];
    clients[find].salary = p.pSalary;
    printf("Data changed!");
}

void toRemove(struct Database *clients, int Size, unsigned long long code){
    int find = toSearch(clients,Size,code);
    if(find >= 0){
        strcpy(clients[find].name,"NULL");
        clients[find].cpf = 0;
        clients[find].age = 0;
        clients[find].sex[0] = ' ';
        clients[find].salary = 0.0;
        printf("Data removed!");
    }else{
        printf("Register not found!");
    }
}
void getInfo(struct Parameters *p){
    printf("Name: ");
    scanf(" %[^\n]s", p->pName);
    printf("Age:  ");
    scanf("%hi", &p->pAge);
    do{
        printf("Sex:  ");
        scanf("%s", p->pSex);
    }while(p->pSex[0] != 'M' && p->pSex[0] != 'F' && p->pSex[0] != 'f' && p->pSex[0] != 'm');
    printf("Salary: ");
    scanf("%f",&p->pSalary);

}
void printSuperiorToX(struct Database *clients,int Size,float x){
    for(int i = 0; i < Size; i++){
        if(clients[i].salary > x){
            printf("%lli | %s | %i | %c | R$ %.2f\n",clients[i].cpf,clients[i].name,clients[i].age,clients[i].sex[0],clients[i].salary);
        }
    }
}
void UpdateSal(struct Database *clients, int Size, float x){
    for(int i = 0; i < Size; i++){
        clients[i].salary *= (1 + x/100);
    }
    printf("Salary updated!");
}

float averageSal(struct Database *clients, int Size){
    float average = 0.0;
    int k = 0;
    for(int i = 0; i < Size; i++){
        if(clients[i].salary > 0){
            average += clients[i].salary;
            k++;
        }
    }
    printf("%i",k);
    return (average/k);
}

int RegisteredNum(struct Database *clients, int Size){
    int k = 0;
    for(int i = 0; i < Size; i++){
        if(clients[i].cpf > 0) k++;
    }
    return k;
}

void ClassifyByAge(struct Database *clients, int Size){
    int child = 0,adult = 0,teen = 0;
    for(int i = 0; i < Size; i++){
        if(clients[i].age <= 12) child++;
        else if(clients[i].age >= 18) adult++;
        else teen++;
    }
    printf("Childs: %i\nAdults: %i\nTeenager: %i\n",child,adult,teen);
}

int main()
{
    short int opt,k;
    struct Database clients[50];
    struct Parameters p;
    size_t Size = sizeof(clients)/sizeof(*clients);
    inicialize(clients, Size);
    do{
        printf("\n\t.:DATABASE CLIENTS:.\n");
        printf("\n1  - Insert");
        printf("\n2  - Change");
        printf("\n3  - Remove");
        printf("\n4  - Search by CPF");
        printf("\n5  - Print all");
        printf("\n6  - Print Salary bigger than x");
        printf("\n7  - Update salary by x%%");
        printf("\n8  - Calculate average Salary");
        printf("\n9  - Show number of clients registered");
        printf("\n10 - Show number clients by age");
        printf("\n11 - Quit");
        printf("\nOPT: ");
        scanf("%hi",&opt);

        switch (opt)
        {
            case 1:
                printf("CPF.: ");
                scanf("%lli",&p.pCpf);
                if(toSearch(clients,Size,p.pCpf) == -1){
                    getInfo(&p);
                    insert(clients, Size, p);
                }else printf("CPF already registered!");
                break;
            case 2:
                printf("CPF to change: ");
                scanf("%lli",&p.pCpf);
                if(toSearch(clients,Size,p.pCpf) >= 0){
                    getInfo(&p);
                    toChange(clients, Size, p);
                }else printf("CPF not found!");
                break;
            case 3:
                printf("CPF to remove: ");
                scanf("%llu",&p.pCpf);
                toRemove(clients, Size, p.pCpf); 
                break;
            case 4:
                printf("CPF to search: ");
                scanf("%llu",&p.pCpf);
                k = toSearch(clients,Size,p.pCpf);
                if(k != -1) printf("Found at position: %i", k);   
                else printf("Not found!");
                break;
            case 5:
                printAll(clients, Size); 
                break;
            case 6:
                printf("x: ");
                scanf("%f",&p.pSalary);
                printSuperiorToX(clients, Size, p.pSalary);
                break;
            case 7:
                do{
                    printf("x: ");
                    scanf("%f",&p.pSalary);
                }while(p.pSalary <= 0);
                UpdateSal(clients, Size, p.pSalary);
                break;
            case 8:
                printf("Average: %.2f",averageSal(clients, Size));
                break;
            case 9:
                printf("Number of clients: %i",RegisteredNum(clients, Size));
                break;
            case 10:
                ClassifyByAge(clients, Size);
                break;
            case 11:
                break;
            default:
                printf ("Invalid Option!\n");
        }
        }while(opt != 11);
    
    return 0;
}
