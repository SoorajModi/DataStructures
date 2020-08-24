#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "LinkedListAPI.h"
#include "PriorityQueue.h"

/*FUNCTION DECLARATIONS*/
void newPatient(void);
void processSimulation(void);

/******************************
            MAIN
*******************************/
int main(int argc, char *argv[]){
    //Read in the file
    FILE* fp = NULL;
    fp = fopen(argv[1], "r");
    if(fp == NULL){
        printf("Error: file name invalid or not entered\nProgram terminating\n");
        return 0;
    }

    //Find size of the file
    fseek(fp, 0, SEEK_END);
    int fileEnd = ftell(fp);
    if(fileEnd == 0){
        printf("The file has no contents\nProgram terminating\n");
        return 0;
    }
    fseek(fp, 0, SEEK_SET);

   //Read in the file
    while(ftell(fp) != fileEnd){
        char tempStr[25];
        fgets(tempStr, 25, fp);
    }

    //After processing the file, provide the main menu
    int pass = 0;
    while(pass == 0){
        printf("Would you like to:\n1. Add a new patient\n");
        printf("2.Process the full simulatiom\n3. Exit program\n");
        printf("Enter here: ");
        char inputStr[10];
        fgets(inputStr, 10, stdin);
        int validNum = 0;
        for(int p = 0; p<strlen(inputStr)-1; p++){
            if(!(isdigit(inputStr[p]))){
                validNum = 1;
            }
        }

        if(validNum == 0){
            int inputInt = atoi(inputStr);
            if(inputInt == 1){
                 newPatient();
            } else if (inputInt == 2){
                 processSimulation();
            } else if (inputInt == 3){
                 printf("Program terminating\n");
                 return 0;
            } else {
                printf("Error: you have entered an invalid number, ");
                printf("please enter one of the following: 1, 2, or 3");
            }
        } else if(validNum == 1){
            printf("Error: please enter a valid integer: 1, 2, or 3\n");
        } else {
            printf("Error: validNum is an invalid value FIXME\n");
        }
    }



    return 0;
}

void newPatient(void){
    printf("Entered the newPatient function");
}

void processSimulation(void){
    printf("Entered the processSimulation function");
}
