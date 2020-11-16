#ifndef _DATA_TYPES_
#define _DATA_TYPES_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct person {
  char* firstName;
  char* lastName;
  int age;
} Person;

void printPerson(void* toBePrinted);
int comparePerson(const void* first, const void* second);
void deletePerson(void* toBeDeleted);

void printString(void* toBePrinted);
int compareString(const void* first, const void* second);
void deleteString(void* toBeDeleted);

void printInt(void* toBePrinted);
int compareInt(const void* first, const void* second);
void deleteInt(void* toBeDeleted);

#endif
