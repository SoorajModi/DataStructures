#include "StackAPI.h"
#include "DataTypes.h"

/*FUNCTION DECLARATIONS*/
int getEOF(FILE* fp);

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

  Stack* stack = initializeStack(&printString, &deleteString, &compareString);

  //Read in the file
  while(ftell(fp) != eof) {
      char tempStr[100];
      fgets(tempStr, 100, fp);
      char* str = malloc(sizeof(char)*strlen(tempStr)+1);
      strncpy(str, tempStr, strlen(tempStr) + 1);
      str[strlen(str) - 1] = '\0';
      push(stack, (void *)str);
  }

  printStack(stack);

  deleteStack(stack);

  fclose(fp);

  return 0;
}

int getEOF(FILE* fp) {
  fseek(fp, 0, SEEK_END);
  int fileEnd = ftell(fp);
  fseek(fp, 0, SEEK_SET);
  return fileEnd;
}
