/**
 * Sooraj Modi
 * Created September, 2020
 */
#include "BinaryTreeAPI.h"

/************************
        FUNCTIONS
************************/

BinaryTree *initializeTree(void (*printFunction)(void *toBePrinted), void (*deleteFunction)(void *toBeDeleted),
                           int (*compareFunction)(const void *first, const void *second)) {
    BinaryTree *tree = malloc(sizeof(BinaryTree));

    tree->root = NULL;
    tree->print = printFunction;
    tree->delete = deleteFunction;
    tree->compare = compareFunction;

    return tree;
}

Node *initializeNode(void *data) {
    Node *node = malloc(sizeof(Node));

    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

void insertData(BinaryTree *tree, void *toInsert) {
    insertNode(tree->root, toInsert, tree->compare);
}

void insertNode(Node *node, void *toInsert, int (*compare)(const void *first, const void *second)) {
    if (compare(node->data, toInsert) >= 0) {
        if (node->right) {
            insertNode(node->right, toInsert, compare);
        } else {
            node->right = initializeNode(toInsert);
        }
    } else {
        if (node->left) {
            insertNode(node->left, toInsert, compare);
        } else {
            node->left = initializeNode(toInsert);
        }
    }
}

void removeData(BinaryTree *tree, void *toBeRemoved) {
    removeNode(tree, tree->root, toBeRemoved);
}

void removeNode(BinaryTree *tree, Node *node, void *toBeRemoved) {
    int result = tree->compare(node->data, toBeRemoved);
    if (result == 0) {
        deleteSubtree(node, tree->delete);
    } else if (result > 0) {
        removeNode(tree, node->right, toBeRemoved);
    } else {
        removeNode(tree, node->left, toBeRemoved);
    }
}

void printPostorder(BinaryTree *tree) {
    printPostorderNode(tree->root, tree->print);
}

void printPreorder(BinaryTree *tree) {
    printPreorderNode(tree->root, tree->print);
}

void printInorder(BinaryTree *tree) {
    printInorderNode(tree->root, tree->print);
}

void printPostorderNode(Node *node, void (*print)(void *toBePrinted)) {
    if (node == NULL) return;
    printPostorderNode(node->left, print);
    printPostorderNode(node->right, print);
    printNode(node, print);
}

void printPreorderNode(Node *node, void (*print)(void *toBePrinted)) {
    if (node == NULL) return;
    printNode(node, print);
    printPreorderNode(node->left, print);
    printPreorderNode(node->right, print);
}

void printInorderNode(Node *node, void (*print)(void *toBePrinted)) {
    if (node == NULL) return;
    printInorderNode(node->left, print);
    printNode(node, print);
    printInorderNode(node->right, print);
}

int isEmpty(BinaryTree *tree) {
    if (getTreeSize(tree) > 0) {
        return 1;
    }
    return 0;
}

int getTreeSize(BinaryTree *tree) {
    return getNumSubTreeNodes(tree->root);
}

int getNumSubTreeNodes(Node *node) {
    if (node == NULL) return 0;

    int num = getNumSubTreeNodes(node->left);
    num += getNumSubTreeNodes(node->right);

    return num + 1;
}

void deleteSubtree(Node *node, void (*delete)(void *toBeDeleted)) {
    if (node == NULL) return;

    deleteSubtree(node->left, delete);
    deleteSubtree(node->right, delete);
    deleteNode(node, delete);
}

void deleteTree(BinaryTree *tree) {
    deleteSubtree(tree->root, tree->delete);
    free(tree);
}

/************************
    UTILITY FUNCTIONS
************************/

void printNode(Node *node, void (*print)(void *toBePrinted)) {
    print(node->data);
}

void deleteNode(Node *node, void (*delete)(void *toBeDeleted)) {
    delete(node->data);
    free(node);
}

int compareNode(Node *node, void *toCompare, int (*compare)(const void *first, const void *second)) {
    return compare(node->data, toCompare);
}
