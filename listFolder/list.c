#include <stdio.h>
#include "list.h"

Student2 buffer;

void List(Student2 arrayOfStudents[], int *count){
    int i=0; int j=0;
    char group_type[20] = "";
    char answer;
    printf("In what type do you want to see?\n Write 'A' to see all students, write 'G' to only 1 group of all\n");
    scanf(" %c", &answer);
    if(answer=='G'){
        printf("Write group\n");
        scanf("%s", group_type);
    }
    printf("In what type do you want to see them all?\n Write 'A' for sort in ages, write 'N' for sort in names, write 'S' for sort in surnames\n");
    scanf(" %c", &answer);
    if(answer=='A'){
        for(;i<*count;i++){
            for(j=i+1;j<*count;j++){
                if(arrayOfStudents[i].age<arrayOfStudents[j].age){
                    buffer=arrayOfStudents[j];
                    arrayOfStudents[j]=arrayOfStudents[i];
                    arrayOfStudents[i]=buffer;
                }
            }
        }
    }
    if(answer=='N'){
        for(;i<*count;i++){
            for(j=i+1;j<*count;j++){
                if((int)arrayOfStudents[i].name[0]>(int)arrayOfStudents[j].name[0]){
                    buffer=arrayOfStudents[j];
                    arrayOfStudents[j]=arrayOfStudents[i];
                    arrayOfStudents[i]=buffer;
                }
            }
        }   
    }
    if(answer=='S'){
        for(;i<*count;i++){
            for(j=i+1;j<*count;j++){
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
    for(;i<*count;i++){
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