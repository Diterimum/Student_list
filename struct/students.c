#include <stdio.h>

char answer;
static int count=7;
int i=0;
int j=0;

struct nsog{
    char name[20];
    char surname[20];
    int age;
    char group[20];
};

struct nsog arrayOfStudents[]={
    {"Ivan", "Ivanov", 20, "GroupA"},
    {"Petr", "Petrov", 21, "GroupB"},
    {"Svetlana", "Svetlova", 19, "GroupA"},
    {"Anna", "Ananova", 22, "GroupC"},
    {"Dmitry", "Dmitriev", 23, "GroupB"},
    {"Mikhail", "Mikhailov", 20, "GroupA"},
    {"Ekaterina", "Ekaterinina", 18, "GroupC"},
    {"","",-1,""},
};

struct nsog buffer;

struct nsog delete[2]={
    {"","",-1,""},
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
    int found=1;
    int elem=0;
    i=0;
    printf("Write student data\n");
    printf("Write student name\n");
    scanf("%s", delete[0].name);
    printf("Write student surname\n");
    scanf("%s", delete[0].surname);
    printf("Write student group\n");
    scanf("%s", delete[0].group);
    for(;i<count;i++){
        elem=0;
        if(delete[0].name[0]!='\0' && delete[0].surname[0]!='\0' && delete[0].group[0]!='\0'){
            found=1;
            while(delete[0].name[elem]!='\0' && arrayOfStudents[i].name[elem]!='\0'){
                if(delete[0].name[elem]!=arrayOfStudents[i].name[elem]){
                    found=0;
                    break;
                    printf("N\n");
                }
                elem++;
            }
            elem=0;
            while(delete[0].surname[elem]!='\0' && arrayOfStudents[i].surname[elem]!='\0'){
                if(delete[0].surname[elem]!=arrayOfStudents[i].surname[elem]){
                    found=0;
                    break;
                    printf("S\n");
                }
                elem++;
            }
            elem=0;
            while(delete[0].group[elem]!='\0' && arrayOfStudents[i].group[elem]!='\0'){
                if(delete[0].group[elem]!=arrayOfStudents[i].group[elem]){
                    found=0;
                    break;
                    printf("G\n");
                }
                elem++;
            }
        }else{
            printf("Else\n");
            found=0;
            break;
        }
        if(found==1){
            break;
        }
    }

    if(found==1){
        arrayOfStudents[i]=delete[1];
        for(;i<count;i++){
            for(j=i+1;j<count;j++){
                if(arrayOfStudents[i].age<arrayOfStudents[j].age){
                    buffer=arrayOfStudents[j];
                    arrayOfStudents[j]=arrayOfStudents[i];
                    arrayOfStudents[i]=buffer;
                }
            }
        }
        count--;
        printf("Deleted\n");
    }else{
        printf("No such a student\n");
    }
}

void List(){
    i=0;
    char group_type[20] = "";

    printf("In what type do you want to see?\n Write 'A' to see all students, write 'G' to only 1 group of all\n");
    scanf(" %c", &answer);
    if(answer=='G'){
        printf("Write group\n");
        scanf("%s", group_type);
    }
    printf("In what type do you want to see them all?\n Write 'A' for sort in ages, write 'N' for sort in names, write 'S' for sort in surnames\n");
    scanf(" %c", &answer);
    if(answer=='A'){
        for(;i<count;i++){
            for(j=i+1;j<count;j++){
                if(arrayOfStudents[i].age<arrayOfStudents[j].age){
                    buffer=arrayOfStudents[j];
                    arrayOfStudents[j]=arrayOfStudents[i];
                    arrayOfStudents[i]=buffer;
                }
            }
        }
    }
    if(answer=='N'){
        for(;i<count;i++){
            for(j=i+1;j<count;j++){
                if((int)arrayOfStudents[i].name[0]>(int)arrayOfStudents[j].name[0]){
                    buffer=arrayOfStudents[j];
                    arrayOfStudents[j]=arrayOfStudents[i];
                    arrayOfStudents[i]=buffer;
                }
            }
        }   
    }
    if(answer=='S'){
        for(;i<count;i++){
            for(j=i+1;j<count;j++){
                if((int)arrayOfStudents[i].surname[0]>(int)arrayOfStudents[j].surname[0]){
                    buffer=arrayOfStudents[j];
                    arrayOfStudents[j]=arrayOfStudents[i];
                    arrayOfStudents[i]=buffer;
                }
            }
        }   
    }
    printf("\nSorted Students\n\n");

    i=0;
    int elem=0;
    int flag=1;
    for(;i<count;i++){
        elem=0;
        if(group_type[0]!='\0'){
            flag=1;
            while(group_type[elem]!='\0' && arrayOfStudents[i].group[elem]!='\0'){
                if(group_type[elem]!=arrayOfStudents[i].group[elem]){
                    flag=0;
                    break;
                }
                elem++;
            }
            if(flag==1){
                printf("Name: %s\n", arrayOfStudents[i].name);
                printf("Surname: %s\n", arrayOfStudents[i].surname);
                printf("Age: %d\n", arrayOfStudents[i].age);
                printf("Group: %s\n\n", arrayOfStudents[i].group);
            }
        }else{
            printf("Name: %s\n", arrayOfStudents[i].name);
            printf("Surname: %s\n", arrayOfStudents[i].surname);
            printf("Age: %d\n", arrayOfStudents[i].age);
            printf("Group: %s\n\n", arrayOfStudents[i].group);
        }
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
    }
    return 0;
}