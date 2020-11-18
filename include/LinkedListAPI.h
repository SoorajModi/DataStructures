#ifndef _LINKED_LIST_API_
#define _LINKED_LIST_API_

/************************
     CORE LIBARIES
************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/************************
       CORE OBJECTS
************************/

/**
 * Node for the Linked List
 * Contains a pointer to data, and pointers to the next and previous node.
 **/
typedef struct node {
    void* data;
    struct node* next;
    struct node* prev;
} Node;

/**
 * Struct for a Linked List.
 * Contains a pointer to the front and end of the list and to helper functions.
 **/
typedef struct list {
    Node* head;
    Node* tail;
    int length;
    void (*delete)(void* toBeDeleted);
    int (*compare)(const void* first, const void* second);
    void (*print)(void* toBePrinted);
} List;

/************************
      CORE FUNCTIONS
************************/

/**Function to initialize the List Struct. Allocates memory to the Struct.
 * @param printFunction function pointer to print the data associated with a single node in the list.
 * @param deleteFunction function pointer to delete the data associated with a single node in the list
 * @param compareFunction function pointer to compare the data associated with two nodes of the list in order to test for equality.
 * @return pointer to the List Struct.
 **/
List* initializeList(void (*printFunction)(void* toBePrinted),void (*deleteFunction)(void* toBeDeleted),int (*compareFunction)(const void* first, const void* second));

/**Function for initializing a node for a linked list. This node contains generic data and may be connected to
 * other nodes in a list.
 * @pre data should be of same size of void pointer on the users machine to avoid size conflicts. data must be valid.
 * data must be cast to void pointer before being added.
 * @post data is valid to be added to a linked list
 * @param data - is a generic pointer to any data type.
 * @return On success returns a node that can be added to a linked list. On failure, returns NULL.
 **/
Node* initializeNode(void* data);

/**Inserts a Node to the front of a linked list. The list then updates accordingly.
 * @pre 'List' type must exist and be used in order to keep track of the linked list.
 * @param list pointer to the List Struct.
 * @param toBeAdded a pointer to data that is to be added to the linked list.
 * @post Node is inserted into the List, set to List head.
 **/
void insertFront(List* list, void* toBeAdded);

/**Inserts a Node to the back of a linked list. The list then updates accordingly.
 * @pre 'List' type must exist and be used in order to keep track of the linked list.
 * @param list pointer to the List struct.
 * @param toBeAdded a pointer to data that is to be added to the linked list.
 * @post Node is inserted into the List, set to List tail.
 **/
void insertBack(List* list, void* toBeAdded);

/**Uses the comparison function in the List struct to place the element in the appropriate position in the list.
 * @pre List exists and has memory allocated to it. Data to be added is valid.
 * @post The node to be added will be placed immediately before or after the first occurrence of a related node
 * @param list a pointer to the dummy head of the list containing function pointers for delete and compare, as well
 * as a pointer to the first and last element of the list.
 * @param toBeAdded a pointer to data that is to be added to the linked list
 **/
void insertSorted(List* list, void* toBeAdded);

/**Function to return the data at the front of the list.
 * @pre The list exists and has memory allocated to it.
 * @param list pointer to the List.
 * @return pointer to the node located at the head of the list
 **/
void* getDataFromFront(List* list);

/**Function to return the data at the back of the list.
 * @pre The list exists and has memory allocated to it
 * @param list pointer to the dummy head of the list containing the tail of the list
 * @return pointer to the node located at the tail of the list
 **/
void* getDataFromBack(List* list);

/**Function to print list from head to tail. This will utilize the list's printNode function pointer to print.
 * @pre List must exist, but does not have to have elements.
 * @param list pointer to linked list.
 **/
void printForward(List* list);

/**Function to print list from tail to head. This will utilize the list's printNode function pointer to print.
 * @pre List must exist, but does not have to have elements.
 * @param list pointer to linked list.
 **/
void printBackwards(List* list);

/**Function to get the length of the list.
 * @pre List must exist, does not have to have elements.
 * @param list pointer to linked list.
 * @return the number of nodes in the list.
 **/
int getLength(List* list);

/**Deletes the entire linked list head to tail, starting with the nodes, followed by the list itself.
 * @pre List type must exist and be used in order to keep track of the linked list.
 * @param list pointer to the list struct.
 **/
void deleteList(List* list);

/**Deletes all nodes in a linked list, but not the list itself.
 * @pre List type must exist and be used.
 * @param list pointer to the List.
 */
void clearList(List* list);

/**Function to remove a node from the list and alter the pointers accordingly to not disrupt the order of the
 * data structure.
 * @pre List must exist and have memory allocated to it
 * @post toBeDeleted will have its memory freed if it exists in the list.
 * @param list pointer to the dummy head of the list containing deleteFunction function pointer
 * @param toBeDeleted pointer to data that is to be removed from the list
 **/
void deleteDataFromList(List* list, void* toBeDeleted);

/**Function to determine if the list is empty.
 * @pre List must exist, does not have to have elements.
 * @param list pointer to linked list.
 * @return 1 if the list is empty.
 * @return 0 if the list is not empty.
 **/
int isEmpty(List* list);

/**Deletes the head of the linked list, including the data associated with the head.
 * @pre List type must exist and be used in order to keep track of the linked list.
 * @param list pointer to the list struct.
 * @post head node is deleted, the next element of the list is set to head.
 **/
void deleteFromFront(List* list);

/**Deletes the tail of the linked list, including the data associated with the tail.
 * @pre List type must exist and be used in order to keep track of the linked list.
 * @param list pointer to the list struct.
 * @post tail node is deleted, the previous element of the list is set to tail.
 **/
void deleteFromBack(List* list);

/**Deletes the node with data matching toBeDeleted in the linked list.
 * @pre List type must exist and be used in order to keep track of the linked list.
 * @param list pointer to the list struct.
 * @param void pointer to the data to be deleted.
 * @post node associated with toBeDeleted is removed, list is maintained.
 **/
void deleteDataFromList(List* list, void* toBeDeleted);

/************************
    UTILITY FUNCTIONS
************************/

// Utility function for insertSorted
void insertInorder(List* list, void* toBeAdded);

// Utility function for deleteDataFromList
void deleteNodeFromList(List* list, Node* node);

// Utility function for deleteNodeFromList
void deleteNodeFromMiddle(List* list, Node* node) ;

/**Function to return the node that matches a specified.
 * @pre The list exists and has memory allocated to it.
 * @param list pointer to a linked list.
 * @param data to be found.
 * @return pointer to the node with data toFind.
 **/
Node* getNode(List* list, void* toFind);

/**Function to return the head of the list.
 * @pre The list exists and has memory allocated to it.
 * @param list pointer to a linked list.
 * @return pointer to the head of list.
 **/
Node* getHead(List* list);

/**Function to return the tail of the list.
 * @pre The list exists and has memory allocated to it.
 * @param list pointer to a linked list.
 * @return pointer to the tail of list.
 **/
Node* getTail(List* list);

/**Function to return the next element of the list.
 * @pre The node exists and has memory allocated to it.
 * @param Node pointer to a node.
 * @return pointer to the next node.
 **/
Node* getNext(Node* node);

/**Function to return the previous element of the list.
 * @pre The node exists and has memory allocated to it.
 * @param Node pointer to a node.
 * @return pointer to the next node.
 **/
Node* getPrev(Node* node);

/**Function to print the data associated with a given node.
 * @pre Node must exist, and must be populated.
 * @pre print must be able to print the data stored in the given node.
 * @param Node pointer to the node to be printed
 * @param Pointer to print function
 * @post the data associated with the node will be printed to console.
 **/
void printNode(Node* node, void (*print)(void* toBePrinted));

/**Function to delete a single node.
 * @pre Node must exist and have memory allocated to it
 * @post toDelete will have its associate data freed using delete, it will then free the Node
 * @param Node pointer to the node to be deleted
 * @param delete function pointer to function that will delete data associated with the node
 **/
void deleteNode(Node* toDelete, void (*delete)(void* toBeDeleted));

/**Compare a node with data.
 * @pre Node, data, and compare function must exist and have memory allocated to it
 * @param Node pointer to the node to be compared.
 * @param Pointer to data to be compared.
 * @param delete function pointer to function that will delete data associated with the node.
 * @return > 0 if first->data > second.
 * @return == 0 if first->data == second.
 * @return < 0 if first->data < second.
 **/
int compareNode(Node* first, void* second, int (*compare)(const void* first, const void* second));

#endif
