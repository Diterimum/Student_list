#include <stdio.h>

struct nsog{
    char name[20];
    char surname[20];
    int age;
    char group[20];
};
struct nsog arrayOfStudents[]={
    {"","",-1,""},
    {"","",-1,""},
    {"","",-1,""},
    {"","",-1,""},
};

struct nsog buffer[]={
    {"","",-1,""},
};

int main() {
    char answer;
    int count=0;
    for(;;){
        printf("Do you want add student?\nWrite "Y" if yes, write "N" if no.");
        scanf("%c", answer);
        if(answer=='Y'){
            printf("Write student name");
            scanf("%s", arrayOfStudents[count].name);
            printf("Write student surname");
            scanf("%s", arrayOfStudents[count].surname);
            printf("Write student age");
            scanf("%d", arrayOfStudents[count].age);
            printf("In what group is he/she/it/they/we/I study?");
            scanf("%s", arrayOfStudents[count].group);
            count=count+1;
        }elif(answer=='N'){
            printf("Maybe you want to delete someone?\nWrite "Y" if yes, write "N" if no.");
            scanf("%c", answer);
            if(aswer=='Y'){
            
            }elif(aswer=='N'){
                printf("Ok, goodbye!");
                break;
            }
        }
    }
    return 0;
}