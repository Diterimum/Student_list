#include <stdio.h>
#include "delete.h"

Student1 buffer;

Student1 deleteStudent[2]={
    {"","",-1,""},
    {"","",-1,""},
};

void Delete(Student1 arrayOfStudents[], int *count){
    int found=1;
    int elem=0;
    int i=0;
    int j=0;
    printf("Write student name surname group\n");
    scanf("%s %s %s", deleteStudent[0].name, deleteStudent[0].surname, deleteStudent[0].group);
    for(;i<*count;i++){
        elem=0;
        if(deleteStudent[0].name[0]!='\0' && deleteStudent[0].surname[0]!='\0' && deleteStudent[0].group[0]!='\0'){
            found=1;
            while(deleteStudent[0].name[elem]!='\0' && arrayOfStudents[i].name[elem]!='\0'){
                if(deleteStudent[0].name[elem]!=arrayOfStudents[i].name[elem]){
                    found=0;
                    break;
                    printf("N\n");
                }
                elem++;
            }
            elem=0;
            while(deleteStudent[0].surname[elem]!='\0' && arrayOfStudents[i].surname[elem]!='\0'){
                if(deleteStudent[0].surname[elem]!=arrayOfStudents[i].surname[elem]){
                    found=0;
                    break;
                    printf("S\n");
                }
                elem++;
            }
            elem=0;
            while(deleteStudent[0].group[elem]!='\0' && arrayOfStudents[i].group[elem]!='\0'){
                if(deleteStudent[0].group[elem]!=arrayOfStudents[i].group[elem]){
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
        arrayOfStudents[i]=deleteStudent[1];
        for(;i<*count;i++){
            for(j=i+1;j<*count;j++){
                if(arrayOfStudents[i].age<arrayOfStudents[j].age){
                    buffer=arrayOfStudents[j];
                    arrayOfStudents[j]=arrayOfStudents[i];
                    arrayOfStudents[i]=buffer;
                }
            }
        }
        (*count)--;
        printf("Deleted\n");
    }else{
        printf("No such a student\n");
    }
}