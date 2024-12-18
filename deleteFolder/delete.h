#ifndef DELETE_H
#define DELETE_H

#include <stdio.h>

typedef struct{
    char name[20];
    char surname[20];
    int age;
    char group[20];
}Student1;

void Delete(Student1 arrayOfStudents[], int *count);

#endif