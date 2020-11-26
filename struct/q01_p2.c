#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define noStudents 30 

struct student{
    long int RA;
    char course[5];
    short int period;
    char name[30];
};
struct Parameters{
    long int pRA;
    char pcourse[5];
    short int pperiod;
    char pname[30];
};

void inicialize(struct student *astudent){
    for(int i = 0; i < noStudents; i++){
        astudent[i].RA = 0;
        strcpy(astudent[i].course, "NULL");
        strcpy(astudent[i].name, "NULL");
        astudent[i].period = 0;
    }
}

void inicializetmp(struct Parameters *tmp){
        tmp->pRA = 0;
        strcpy(tmp->pcourse, "NULL");
        strcpy(tmp->pname, "NULL");
        tmp->pperiod = 0;

}
int getPosition(struct student *astudent){
    int i, j = -1;
    for(i = 0; i < noStudents; i++){
        if(astudent[i].RA == 0){
            j = i;
            break;
        }
    }
    return j;
}

int check(struct student *astudent, int code){
    int pos = -1;
    for(int i = 0; i < noStudents; i++){
        if(astudent[i].RA == code){
            pos = i;
            break;
        }
    }
    return pos;
}

void ShowAll(struct student *astudent){
    for(int i = 0; i < noStudents; i++){
        printf("%li %s %s %hi\n",astudent[i].RA,astudent[i].name,astudent[i].course,astudent[i].period);
    }
}

void getinfo(struct Parameters *tmp){
    printf("Name: ");
    scanf("%s", tmp->pname);
    printf("Course: ");
    scanf("%s", tmp->pcourse);
    printf("Period: ");
    scanf("%hi", &tmp->pperiod);
}

void insert(struct student *astudent, struct Parameters tmp){
    int pos = getPosition(astudent);
    if(pos == -1) printf("Database full!\n");
    else{
        if(check(astudent, tmp.pRA) == -1){
            getinfo(&tmp);
            astudent[pos].RA = tmp.pRA;
            strcpy(astudent[pos].name, tmp.pname);
            strcpy(astudent[pos].course, tmp.pcourse);
            astudent[pos].period = tmp.pperiod;
        }else printf("RA already in use!");
    }
}

void change(struct student *astudent, struct Parameters tmp){
    int pos = check(astudent, tmp.pRA);
    if(pos >= 0){
        getinfo(&tmp);
        strcpy(astudent[pos].name, tmp.pname);
        strcpy(astudent[pos].course, tmp.pcourse);
        astudent[pos].period = tmp.pperiod;
    }else printf("RA not found!");
}

void Remove(struct student *astudent, long int ra){
    int pos = check(astudent,ra);
    if(pos >= 0){
        astudent[pos].RA = 0;
        astudent[pos].period = 0;
        strcpy(astudent[pos].name,"NULL");
        strcpy(astudent[pos].course,"NULL");
        printf("Removed!");
    }printf("CPF not found!");
}

void Search(struct student *astudent, long int ra){
    short int find = 0;
    for(int i = 0; i < noStudents; i++){
        if(astudent[i].RA == ra){
            printf("Position: %i \n%li %s %s %hi",i,astudent[i].RA, astudent[i].name, astudent[i].course, astudent[i].period);
            find++;
        }
    }
    if(find == 0) printf("RA not found!");
}

int Count(struct student *astudent){
    int c = 0;
    for(int i = 0; i < noStudents; i++){
        if(astudent[i].RA > 0) c++;
    }
    return c;
}

int Raffle(struct student *astudent){
    int i, k = 0, c = 0, winner = -1;
    do{
        c = rand() % noStudents;
        for(i = 0; i < noStudents; i++){
            if((c == i) && (astudent[i].RA > 0)){
                winner = i;
            }
        }
        k++; // prevents infinite loop 
    }while(winner == -1 && k < 1000);
    return winner;
}
int main()
{
    srand(time(NULL)); // seed rand
    short int opt,pos = 0;
    struct Parameters tmp; // hold input
    struct student *astudent = (struct student*)malloc(sizeof(struct student) * noStudents);
    if(astudent == NULL) return 1;
    inicialize(astudent);
    do{
        inicializetmp(&tmp);
        printf("\n\t.:Raffle:.\n");
        printf("\n1  - Insert");
        printf("\n2  - Change");
        printf("\n3  - Remove");
        printf("\n4  - Search");
        printf("\n5  - Print all");
        printf("\n6  - Number of registered");
        printf("\n7  - Raffle");
        printf("\n9  - Quit");
        printf("\nOPT: ");
        scanf("%hi",&opt);
        switch (opt)
        {
            case 1:
                printf("RA: ");
                scanf("%li", &tmp.pRA);
                insert(astudent,tmp);
                break;
            case 2:
                printf("RA: ");
                scanf("%li", &tmp.pRA);
                change(astudent,tmp); 
                break;
            case 3:
                printf("RA: ");
                scanf("%li", &tmp.pRA);
                Remove(astudent, tmp.pRA);
                break;
            case 4:
                printf("RA: ");
                scanf("%li", &tmp.pRA);
                Search(astudent, tmp.pRA);            
                break;
            case 5:
                ShowAll(astudent);
                break;
            case 6:
                printf("Number of registered students: %i",Count(astudent)); 
                break;
            case 7:
                pos = Raffle(astudent);
                printf("WINNER:\nRA: %li\nName: %s\nCourse: %s\nPeriod: %hi",astudent[pos].RA, astudent[pos].name,astudent[pos].course,astudent[pos].period);
            case 9:
                
                break;
            default:
                printf ("Invalid Option!\n");
        }
    }while(opt != 9);
    free(astudent);
    return 0;
}
