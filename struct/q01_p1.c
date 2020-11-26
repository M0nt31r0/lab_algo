#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct City {
    int cod;
    char name[20];
    int habitants;
};

struct Parameters{
    int code1;
    char name1[20];
    int h;
};

void inicialize(struct City *info, int Size){
    for(int i = 0; i < Size; i++){
        info[i].cod = 0;
        strcpy(info[i].name, "NULL");
        info[i].habitants = 0;
    }
}

void printAll(struct City *info, int Size){
    for(int i = 0; i < Size; i++){
        printf("%i; %s; %i\n",info[i].cod,info[i].name,info[i].habitants);
    }
}

int getPosition(struct City *info, int Size){
    int i,j = -1;
    for(i = 0; i < Size; i++){
        if(info[i].cod == 0){
            j = i;
            break;
        }
    }
    return j;
}

int toSearch(struct City *info, int Size, int code){
    int find = -1;
    for(int i = 0; i < Size; i++){
        if(info[i].cod == code){
            find = i;
            break;
        }
    }
    // return position of element 
    return find;
}


void insert(struct City *info, int Size, struct Parameters p){
    int pos = getPosition(info,Size);
    int find = toSearch(info, Size, p.code1);
    if(pos == -1){
        printf("Database full!");
    }
    if(find >= 0){
        printf("Cod. already registered");
    }else{
        info[pos].cod = p.code1;
        strcpy(info[pos].name,p.name1);
        info[pos].habitants = p.h;
    }
}

void toChange(struct City *info, int Size, struct Parameters p){
    int code = p.code1;
    int find = toSearch(info,Size,code);
    if(find >= 0){
        strcpy(info[find].name,p.name1);
        info[find].habitants = p.h;
        printf("Data changed!");
    }else{
        printf("Data not found!");
    }
}

void toRemove(struct City *info, int Size, int code){
    int find = toSearch(info,Size,code);
    if(find >= 0){
        strcpy(info[find].name,"NULL");
        info[find].cod = 0;
        info[find].habitants = 0;
        printf("Data removed!");
    }else{
        printf("Data not found!");
    }
}

int main()
{
    short int opt;
    int code;
    struct City info[10];
    struct Parameters p;
    size_t Size = sizeof(info)/sizeof(*info);
    inicialize(info, Size);
    do{
        printf("\n\t.:Cities:.\n");
        printf("\n1  - Insert");
        printf("\n2  - Change");
        printf("\n3  - Remove");
        printf("\n4  - Search");
        printf("\n5  - Print all");
        printf("\n9  - Quit");
        printf("\nOPT: ");
        scanf("%hi",&opt);

        switch (opt)
        {
            case 1:
                printf("Cod.: ");
                scanf("%i",&p.code1);
                printf("Name: ");
                scanf(" %[^\n]s", p.name1);
                printf("Number of Habitants: ");
                scanf("%i", &p.h);
                insert(info, Size, p);
                break;
            case 2:
                printf("Cod. to change: ");
                scanf("%i",&p.code1);
                printf("Name: ");
                scanf(" %[^\n]s", p.name1);
                printf("Number of habitants: ");
                scanf("%i", &p.h);
                toChange(info, Size, p);      
                break;
            case 3:
                printf("Cod. to remove: ");
                scanf("%i",&code);
                toRemove(info, Size, code); 
                break;
            case 4:
                printf("Cod. to search: ");
                scanf("%i",&code);
                printf("Found at position: %i",toSearch(info,Size,code));   
                break;
            case 5:
                printAll(info, Size); 
                break;
            case 9:
                break;
            default:
                printf ("Invalid Option!\n");
        }
        }while(opt != 9);
    
    return 0;
}
