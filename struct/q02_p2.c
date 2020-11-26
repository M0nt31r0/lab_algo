#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define noClients 100

struct Database{
    long long cpf;
    long rg;
    char name[30];
    char gender;
    short int age;
    float salary;
};
struct Parameters{
    long long pcpf;
    long prg;
    char pname[30];
    char pgender;
    short int page;
    float psalary;
};

void inicializer(struct Database *a){
    for(int i = 0; i < noClients; i++){
        a[i].cpf = 0;
        a[i].rg = 0;
        a[i].age = 0;
        a[i].salary = 0.0;
        strcpy(a[i].name,"NULL");
        a[i].gender = ' ';
    }
}

void inicializertmp(struct Parameters *tmp){
    tmp->pcpf = 0;
    tmp->prg = 0;
    tmp->page = 0;
    tmp->psalary = 0.0;
    strcpy(tmp->pname, "NULL");
    tmp->pgender = ' ';
}

void ShowAll(struct Database *client){
    for(int i = 0; i < noClients; i++){
        if(client[i].cpf != 0){
            printf("CPF: %lli RG: %li Name: %s Gender: %c Age: %i Salary: %.2f\n",client[i].cpf, client[i].rg, client[i].name, client[i].gender, client[i].age, client[i].salary);
        }
    }
}

int getPosition(struct Database *client){
    int i, j = -1;
    for(i = 0; i < noClients; i++){
        if(client[i].cpf == 0){
            j = i;
            break;
        }
    }
    return j;
}

int check(struct Database *client, long long cod){
    int i, j = -1;
    for(i = 0; i < noClients; i++){
        if(client[i].cpf == cod){
            j = i;
            break;
        }
    }
    return j;
}

void Search(struct Database *x, long long cpf){
    short int find = 0;
    for(int i = 0; i < noClients; i++){
        if(x[i].cpf == cpf){
            printf("CPF: %lli RG: %li Name: %s Gender: %c Age: %i Salary: %.2f\n",x[i].cpf, x[i].rg, x[i].name, x[i].gender, x[i].age, x[i].salary);
            find++;
        }
    }
    if(find == 0) printf("Not found!");
}

void getInfo(struct Parameters *tmp){
    printf("RG: ");
    scanf("%li", &tmp->prg);
    printf("Name: ");
    scanf(" %[^\n]s", tmp->pname);
    printf("Age: ");
    scanf("%hi", &tmp->page);
    printf("Gender: ");
    scanf(" %c", &tmp->pgender);
    printf("Salary: ");
    scanf("%f", &tmp->psalary);
}

void insert(struct Database *x, struct Parameters tmp){
    int pos = getPosition(x);
    if(pos == -1) printf("Database full!");
    else{
        if(check(x,tmp.pcpf) == -1){
            getInfo(&tmp);
            x[pos].cpf = tmp.pcpf;
            x[pos].rg = tmp.prg;
            x[pos].age = tmp.page;
            x[pos].gender = tmp.pgender;
            x[pos].salary = tmp.psalary;
            strcpy(x[pos].name, tmp.pname);
        }else printf("Already in use!");
    }
}

void change(struct Database *x, struct Parameters tmp){
    int pos = check(x, tmp.pcpf);
    if(pos >= 0){
        getInfo(&tmp);
        x[pos].cpf = tmp.pcpf;
        x[pos].rg = tmp.prg;
        x[pos].age = tmp.page;
        x[pos].gender = tmp.pgender;
        x[pos].salary = tmp.psalary;
        strcpy(x[pos].name, tmp.pname);
    }else printf("Not found!");
}

void Remove(struct Database *x, long long cpf){
    int pos = check(x, cpf);
    if(pos >= 0){
        x[pos].cpf = 0;
        x[pos].rg = 0;
        x[pos].age = 0;
        x[pos].salary = 0.0;
        strcpy(x[pos].name, "NULL");
        x[pos].gender = ' ';
        printf("Removed!");
    }else printf("Not found!");
}

// find pattern in string (case sensitive)
int match(char *txt, char *pattern){
    int pos = -1,i;
    int x = strlen(txt);
    int y = strlen(pattern);
    
    for(i = 0; i <= x - y; i++){
        int j;
        for(j = 0; j < y; j++){
            if(txt[i+j] != pattern[j]) break;
        }
        if(j == y){
            pos = i; // pattern found at index i
            break;
        }
    }
    return pos; 
}
void SearchName(struct Database *x, char* pattern){
    short int find = 0;
    int pos = -1;
    for(int i = 0; i < noClients; i++){
        pos = match(x[i].name, pattern);
        if(pos >= 0) {
            printf("CPF: %lli RG: %li Name: %s Gender: %c Age: %i Salary: %.2f\n",x[i].cpf, x[i].rg, x[i].name, x[i].gender, x[i].age, x[i].salary);
            find++;
        }
    }
}

void Report(struct Database *x){
    int m[2] = {0,0}, f[2] = {0,0};
    float sum[2] = {0}; 
    for(int i = 0; i < noClients; i++){
        if(x[i].gender == 'M' || x[i].gender == 'm'){
            m[0]++;
            m[1] += x[i].age;
            sum[0] += x[i].salary;
        }else if(x[i].gender == 'F' || x[i].gender == 'f'){
            f[0]++;
            f[1] += x[i].age;
            sum[1] += x[i].salary;
        }
    }
    // prevents division by 0
    if(m[0] != 0){
        printf("Mens:\nNo. of men: %i\nAverage Age: %i\nAvg. Salary:%.2f\n",m[0],(m[1]/m[0]), (sum[0]/m[0]));
    }else printf("No. of men = 0\n");
    printf("---------------\n");
    if(f[0] != 0){
        printf("Woman:\nNo. of woman: %i\nAverage Age: %i\nAvg. Salary:%.2f",f[0],(f[1]/f[0]), (sum[1]/f[0]));    
    }else printf("No. of woman = 0");
}

void ReportSalary(struct Database *x){
    float max = x[0].salary,min = x[0].salary,sum = 0;
    short int c = 0, pmin = 0, pmax = 0, minSalary = 0;
    for(int i = 0; i < noClients; i++){
        if(x[i].salary > 0){
            sum += x[i].salary;
            if(max < x[i].salary) {
                max = x[i].salary;
                pmax = i;
            }
            if(min > x[i].salary) {
                min = x[i].salary;
                pmin = i;    
            }
            if(x[i].salary < 1045) minSalary++;
            c++;
        }
    }
    printf("Bigger salary: %.2f; - %s\n",x[pmax].salary, x[pmax].name);
    printf("Smaller salary: %.2f; - %s\n", x[pmin].salary, x[pmin].name);
    printf("Average of all: %.2f\nSum of salaries: %.2f\nNum of clients with less than minimum wage: %i", sum/c, sum, minSalary);
}
int main()
{
    struct Database *client;
    client = (struct Database*) malloc(sizeof(struct Database) * noClients);
    struct Parameters tmp;
    inicializer(client);
    short int opt;
    
    do{
        inicializertmp(&tmp);
        printf("\n\t.:Clients:.\n");
        printf("\n1  - Insert");
        printf("\n2  - Change");
        printf("\n3  - Remove");
        printf("\n4  - Search CPF");
        printf("\n5  - Search Name");
        printf("\n6  - Show All");
        printf("\n7  - Report");
        printf("\n8  - Report salary");
        printf("\n9  - Quit");
        printf("\nOPT: ");
        scanf("%hi",&opt);

        switch (opt)
        {
            case 1:
                printf("CPF: ");
                scanf("%lli", &tmp.pcpf);
                insert(client, tmp);
                break;
            case 2:
                printf("CPF: ");
                scanf("%lli", &tmp.pcpf);
                change(client, tmp);
                break;
            case 3:
                printf("CPF: ");
                scanf("%lli", &tmp.pcpf);
                Remove(client, tmp.pcpf);
                break;
            case 4:
                printf("CPF: ");
                scanf("%lli", &tmp.pcpf);
                Search(client, tmp.pcpf);
                break;
            case 5:
                printf("Name or pattern: ");
                scanf("%s", tmp.pname);
                SearchName(client, tmp.pname);
                break;
            case 6:
                ShowAll(client); 
                break;
            case 7:
                Report(client);
                break;
            case 8:
                ReportSalary(client);
                break;
            case 9:
                break;
            default:
                printf ("Invalid Option!\n");
        }
    }while(opt != 9);
    free(client);
    return 0;
}
