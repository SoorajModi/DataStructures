#include "LinkedListAPI.h"

/*FUNCTION DECLARATIONS*/
int getEOF(FILE* fp);

/******************************
            MAIN
*******************************/
int main(int argc, char *argv[]) {
    //Read in the file
    FILE* fp = NULL;
    fp = fopen(argv[1], "r");
    if(fp == NULL){
        printf("Error: file name invalid or not entered\nProgram terminating\n");
        return 0;
    }

    //Find size of the file
    int eof = getEOF(fp);

    List* list = initializeList(&printString, &deleteString, &compareStrings);

    //Read in the file
    while(ftell(fp) != eof){
        char tempStr[100];
        fgets(tempStr, 100, fp);
        insertBack(list, (void *)tempStr);
    }

    return 0;
}

// Helper functions

int getEOF(FILE* fp) {
  fseek(fp, 0, SEEK_END);
  int fileEnd = ftell(fp);
  fseek(fp, 0, SEEK_SET);
}

// Utility functions for list

char* printString(void* toBePrinted) {
    return (char*)(((Node*)toBePrinted)->data);
}

void deleteString(void* toBeDeleted) {
	  char* delete = (char *)toBeDeleted;
    free(delete);
}

int compareStrings(const void* first, const void* second) {
    if((first == NULL) || (second == NULL)) return -1;

    char* f = (char *)first;
    char* s = (char *)second;

    return strcmp(f, s);
}
