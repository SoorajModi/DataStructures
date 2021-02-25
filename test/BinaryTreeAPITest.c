#include "unity.h"
#include "BinaryTreeAPI.h"
#include "DataTypes.h"

void setUp(void) {
}

void tearDown(void) {
}

void should_initialize_binary_tree(void) {
    BinaryTree *tree = initializeTree(&printString, &deleteString, &compareString);

    TEST_ASSERT_NOT_NULL(tree);
    TEST_ASSERT_NOT_NULL(tree->print);
    TEST_ASSERT_NOT_NULL(tree->delete);
    TEST_ASSERT_NOT_NULL(tree->compare);
    TEST_ASSERT_NULL(tree->root);

    deleteTree(tree);
}

void should_initialize_node(void) {
    char* string = (char *)malloc(sizeof(char)*6);
    strncpy(string, "string", 6);

    Node* node = initializeNode((void*)string);

    TEST_ASSERT_NULL(node->left);
    TEST_ASSERT_NULL(node->right);
    TEST_ASSERT_EQUAL(string, (char *) node->data);

    deleteNode(node, &deleteString);
}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(should_initialize_binary_tree);
    RUN_TEST(should_initialize_node);

    return UNITY_END();
}