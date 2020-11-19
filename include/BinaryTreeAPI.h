#ifndef _BINARY_TREE_API_
#define _BINARY_TREE_API_

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
 * Node for the Binary Tree.
 * Contains a pointer to data, and pointers to the left and right children nodes.
 **/
typedef struct node {
  void* data;
  struct node* left;
  struct node* right;
} Node;

/**
 * Struct for a Binary Tree.
 * Contains a pointer to the root, and pointers to helper functions.
 **/
typedef struct binaryTree {
    Node* root;
    void (*delete)(void* toBeDeleted);
    int (*compare)(const void* first, const void* second);
    void (*print)(void* toBePrinted);
} BinaryTree;

/************************
      CORE FUNCTIONS
************************/

/**Function to initialize the Binary Tree Struct. Allocates memory to the Struct.
 * @param printFunction function pointer to print the data associated with a single node in the Binary Tree.
 * @param deleteFunction function pointer to delete the data associated with a single node in the Binary Tree
 * @param compareFunction function pointer to compare the data associated with two nodes of the Binary Tree in order to test for equality.
 * @return pointer to the Binary Tree Struct.
 **/
BinaryTree* initializeTree(void (*printFunction)(void *toBePrinted), void (*deleteFucntion)(void *toBeDeleted), int (*compareFunction)(const void *first, const void *second));

/**Function for initializing a node for a Binary Tree. This node contains generic data and may be connected to
 * child nodes in a Binary Tree.
 * @pre data should be of same size of void pointer on the users machine to avoid size conflicts. data must be valid.
 * data must be cast to void pointer before being added.
 * @post data is valid to be added to a Binary Tree.
 * @param data - is a generic pointer to any data type.
 * @return On success returns a node that can be added to a Binary Tree. On failure, returns NULL.
 **/
Node* initializeNode(void* data);

void insertData(BinaryTree* tree, void* toInsert);
void insertNode(Node* node, void* toInsert, int (*compare)(const void *first, const void *second));

void removeData(BinaryTree* tree, void* toBeRemoved);
void removeNode(BinaryTree* tree, Node* node, void* toBeRemoved);

void printPostorder(BinaryTree* tree);
void printPreorder(BinaryTree* tree);
void printInorder(BinaryTree* tree);
void printPostorderNode(Node* node, void (*print)(void *toBePrinted));
void printPreorderNode(Node* node, void (*print)(void *toBePrinted));
void printInorderNode(Node* node, void (*print)(void *toBePrinted));

int isEmpty(BinaryTree* tree);
int getTreeSize(BinaryTree* tree);
itn getNumSubTreeNodes(Node* node);

void freeRoot(Node* root, void (*delete)(void *toBeDeleted));
void freeTree(BinaryTree* tree);

/************************
    UTILITY FUNCTIONS
************************/

void printNode(Node* node, void (*print)(void *toBePrinted));

void deleteNode(Node* node, void (*delete)(void *toBeDeleted));

int compareNode(Node* node, void* toCompare, int (*compare)(const void *first, const void *second));

#endif
