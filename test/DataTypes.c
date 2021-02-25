#include "DataTypes.h"

// Person Functions

void printPerson(void *toBePrinted) {
    Person *toPrint = (Person *) toBePrinted;
    printf("{firstName: %s,lastName: %s,age: %d}\n", toPrint->firstName, toPrint->lastName, toPrint->age);
}

int comparePerson(const void *first, const void *second) {
    return (((Person *) first)->age - ((Person *) second)->age);
}

void deletePerson(void *toBeDeleted) {
    Person *toDelete = (Person *) toBeDeleted;
    free(toDelete->firstName);
    free(toDelete->lastName);
    free(toDelete);
}

// String Functions

void printString(void *toBePrinted) {
    printf("%s\n", (char *) toBePrinted);
}

int compareString(const void *first, const void *second) {
    return strcmp((char *) first, (char *) second);
}

void deleteString(void *toBeDeleted) {
    free(toBeDeleted);
    toBeDeleted = NULL;
}

int hashString(void *toHash) {
    unsigned char *str = (unsigned char*)toHash;

    unsigned long hash = 5381;
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash;
}

// Integer Functions

void printInt(void *toBePrinted) {
    printf("%ls\n", (int *) toBePrinted);
}

int compareInt(const void *first, const void *second) {
    return (int *) first - (int *) second;
}

void deleteInt(void *toBeDeleted) {
    free((int *) toBeDeleted);
}