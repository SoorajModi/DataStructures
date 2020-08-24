#include "LinkedListAPI.h"

/**
 *
 */
void create(void (*printFunction)(void *toBePrinted), void (*deleteFucntion)(void *toBeDeleted), int (*compareFunction)(const void *first, const void *second));

/**
 *
 */
void destroy(List *list);

/**
 * @param list
 * @param dataToBeAdded
 */
void insert(List *list, void * dataToBeAdded);

/**
 *
 */
void pop(List *list);

/**
 *
 */
void peek(List *list);

/**
 *
 */
void removeNode(List *list, void *toBeDeleted);

/**
 *
 */
void isEmpty(List *list);
