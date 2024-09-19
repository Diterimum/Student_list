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

int main(){
    char answer;
    int count=0;
    int i=0;
    int j=0;
    for(;;){
        i=0;
        printf("\nDo you want to add student?\nWrite 'Y' if yes, write 'N' if no.\n");
        scanf(" %c", &answer);
        if(answer=='Y')
        {
            printf("Write student name\n");
            scanf("%s", arrayOfStudents[count].name);
            printf("Write student surname\n");
            scanf("%s", arrayOfStudents[count].surname);
            printf("Write student age\n");
            scanf("%d", &arrayOfStudents[count].age);
            printf("In what group is he/she/it/they/we/I study?\n");
            scanf("%s", arrayOfStudents[count].group);
            count=count+1;
        }
        else if(answer=='N')
        {
            printf("Maybe you want to delete someone?\n");
            scanf(" %c", &answer);
            if(answer=='Y'){
                
            }if(answer=='N'){
                printf("Maybe you want to see them all?\n");
                scanf(" %c", &answer);
                if(answer=='Y'){
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
                    }   
                    printf("\nSorted Students\n");
    
                    i=0;
                    for(;i<count;i++){
                        printf("Name: %s\n", arrayOfStudents[i].name);
                        printf("Surname: %s\n", arrayOfStudents[i].surname);
                        printf("Age: %d\n", arrayOfStudents[i].age);
                        printf("Group: %s\n\n", arrayOfStudents[i].group);
                    }
                    if(answer=='N'){

                    }
                    if(answer=='S'){

                    }
                    if(answer=='G'){

                    }
                }else if(answer=='N'){
                    printf("Ok, goodbye!\n");
                    break;
                }
            }
        }
    }
    return 0;
}