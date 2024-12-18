#ifndef LIST_H
#define LIST_H

#include <stdio.h>

typedef struct{
    char name[20];
    char surname[20];
    int age;
    char group[20];
}Student2;

void List(Student2 arrayOfStudents[], int *count);

#endif