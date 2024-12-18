#include <stdio.h>
#include "addFolder/add.h"
#include "deleteFolder/delete.h"
#include "listFolder/list.h"

static FILE *fp;
char ch;
char line[60];

char answer;
static int count=0;
int i=0;
int j=0;
int k=0;
int b=0;

struct nsog{
    char name[20];
    char surname[20];
    int age;
    char group[20];
};

struct nsog arrayOfStudents[]={
    {"", "", -1, ""},
    {"", "", -1, ""},
    {"", "", -1, ""},
    {"", "", -1, ""},
    {"", "", -1, ""},
    {"", "", -1, ""},
    {"", "", -1, ""},
    {"", "", -1, ""},
    {"", "", -1, ""},
    {"", "", -1, ""},
    {"", "", -1, ""},
    {"", "", -1, ""},
    {"", "", -1, ""},
    {"", "", -1, ""},
    {"", "", -1, ""},
    {"", "", -1, ""},
};

struct nsog buffer;

struct nsog delete[2]={
    {"","",-1,""},
    {"","",-1,""},
};

void textToStruct(){
    int inWord=0;
    fp=fopen("students_list.txt", "r");
    i=0; count=0;
    while(fgets(line,50,fp)!=NULL){
        for(;i<=count;i++){
            j=0;k=0;b=0;
            for(;(k<4);j++){
                if(((int)line[j]>64 && (int)line[j]<91) || ((int)line[j]>96 && (int)line[j]<123) || ((int)line[j]>47 && (int)line[j]<58)){
                    inWord=1;
                }else{
                    k=k+1;
                    b=0;
                    inWord=0;
                }
                if(inWord==1){
                    if(k==0){
                        arrayOfStudents[i].name[b]=line[j];
                    }
                    else if(k==1){
                        arrayOfStudents[i].surname[b]=line[j];
                    }
                    else if(k==2){
                        if(arrayOfStudents[i].age==-1){
                            arrayOfStudents[i].age=arrayOfStudents[i].age*0+(line[j]-'0');
                        }else{
                            arrayOfStudents[i].age=arrayOfStudents[i].age*10+(line[j]-'0');
                        }
                    }
                    else if(k==3){
                        arrayOfStudents[i].group[b]=line[j];
                    }
                    b=b+1;
                }
            }
        }
        count=count+1;
    }
}

void structToZero(){
    for(i=0;i<count;i++){
        arrayOfStudents[i]=delete[1];
    }
}

void structToText(){
    fp=fopen("students_list.txt", "w");
    for(i=0;i<count;i++){
        fprintf(fp, "%s %s %d %s", arrayOfStudents[i].name, arrayOfStudents[i].surname, arrayOfStudents[i].age, arrayOfStudents[i].group);
        if(i!=count-1){
            fprintf(fp, "\n");
        }
    }
    structToZero();
}

int main(){
    for(;;){
        textToStruct();
        printf("\nWhat do you want to do?\nWrite 'A' for student add,\nwrite 'D' for student delete,\nwrite 'L' for student list.\nWrite 'X' for shut down\n");
        scanf(" %c", &answer);
        if(answer=='A'){
            Add(arrayOfStudents[count].name, arrayOfStudents[count].surname, &arrayOfStudents[count].age, arrayOfStudents[count].group, &count);
        }else if(answer=='D'){
            Delete(arrayOfStudents, &count);
        }else if(answer=='L'){
            List(arrayOfStudents, &count);
        }else if(answer=='X'){
            break;
        }else{
            printf("Invalid input, please try again\n");
        }
        structToText();
        fclose(fp);
    }
    return 0;
}