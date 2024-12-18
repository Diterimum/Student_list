#include <stdio.h>
#include "add.h"

void Add(char *name, char *surname, int *age, char *group, int *count){
    printf("Write student name surname age group:\n");
    if(scanf("%19s %19s %d %19s", name, surname, age, group)==4){
        printf("Student added successfully!\n");
        (*count)++;
    }else{
        printf("Invalid input.\n");
    }
}