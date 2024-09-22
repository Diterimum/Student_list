#include <stdio.h>

char answer;
static int count=0;
int i=0;
int j=0;

struct nsog{
    char name[20];
    char surname[20];
    int age;
    char group[20];
};
struct nsog arrayOfStudents[]={
    {"","",-1,""},
};

struct nsog buffer[]={
    {"","",-1,""},
};

struct nsog delete[]={
    {"","",-1,""},
};

void Add(){
    printf("Write student name\n");
    scanf("%s", arrayOfStudents[count].name);
    printf("Write student surname\n");
    scanf("%s", arrayOfStudents[count].surname);
    printf("Write student age\n");
    scanf("%d", &arrayOfStudents[count].age);
    printf("In what group is he/she/it study?\n");
    scanf("%s", arrayOfStudents[count].group);
    count=count+1;
}

void Delete(){
    printf("Write student data\n");
    scanf(" %s", delete.name);
    scanf(" %s", delete.surname);
    scanf(" %s", delete.age);
    scanf(" %s", delete.group);
    for(;i<count;i++){
        if(delete==arrayOfStudents[i]){
            arrayOfStudents[i]={"","",-1,""};
        }
    }
    if(i==count){
        printf("We dont have that student\n")
    }
}

void List(){
    printf("In what type do you want to see them all?\n Write 'A' for sort in ages, write 'N' for sort in names, write 'S' for sort in surnames, write 'G' for sort in groups\n");
    scanf(" %c", &answer);
    if(answer=='A'){
        for(;i<count;i++){
            for(j=i+1;j<count;j++){
                if(arrayOfStudents[i].age<arrayOfStudents[j].age){
                    buffer[0]=arrayOfStudents[j];
                    arrayOfStudents[j]=arrayOfStudents[i];
                    arrayOfStudents[i]=buffer[0];
                }
            }
        }   
        printf("\nSorted Students\n");
    
        i=0;
        for(;i<count;i++){
            printf("Name: %s\n", arrayOfStudents[i].name);
            printf("Surname: %s\n", arrayOfStudents[i].surname);
            printf("Age: %d\n", arrayOfStudents[i].age);
            printf("Group: %s\n\n", arrayOfStudents[i].group);
        }
    }
    if(answer=='N'){
        for(;i<count;i++){
            for(j=i+1;j<count;j++){
                if((int)arrayOfStudents[i].name[0]<(int)arrayOfStudents[j].name[0]){
                    buffer[0]=arrayOfStudents[j];
                    arrayOfStudents[j]=arrayOfStudents[i];
                    arrayOfStudents[i]=buffer[0];
                }
            }
        }   
        printf("\nSorted Students\n");

        i=0;
        for(;i<count;i++){
            printf("Name: %s\n", arrayOfStudents[i].name);
            printf("Surname: %s\n", arrayOfStudents[i].surname);
            printf("Age: %d\n", arrayOfStudents[i].age);
            printf("Group: %s\n\n", arrayOfStudents[i].group);
        }
    }
    if(answer=='S'){
        for(;i<count;i++){
            for(j=i+1;j<count;j++){
                if((int)arrayOfStudents[i].surname[0]<(int)arrayOfStudents[j].surname[0]){
                    buffer[0]=arrayOfStudents[j];
                    arrayOfStudents[j]=arrayOfStudents[i];
                    arrayOfStudents[i]=buffer[0];
                }
            }
        }   
        printf("\nSorted Students\n");
                        
        i=0;
        for(;i<count;i++){
            printf("Name: %s\n", arrayOfStudents[i].name);
            printf("Surname: %s\n", arrayOfStudents[i].surname);
            printf("Age: %d\n", arrayOfStudents[i].age);
            printf("Group: %s\n\n", arrayOfStudents[i].group);
        }
    }
    if(answer=='G'){
        printf("What group do you want to see?");
        // ...
    }
}

int main(){
    for(;;){
        i=0;
        printf("\nWhat do you want to do?\nWrite 'A' for student add,\nwrite 'D' for student delete,\nwrite 'L' for student list.\nWrite 'X' for shut down\n");
        scanf(" %c", &answer);
        if(answer=='A'){
            Add();
        }else if(answer=='D'){
            Delete();
        }else if(answer=='L'){
            List();
        }else if(answer=='X'){
            break;
        }else{
            printf("Invalid input, please try again\n");
        }
    return 0;
}