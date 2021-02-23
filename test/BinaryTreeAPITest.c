#include "unity.h"
#include "BinaryTreeAPI.h"
#include "DataTypes.h"

void setUp(void) {
}

void tearDown(void) {
}

void should_initialize_hash_map(void) {
    BinaryTree* tree = initializeTree(&printString, &deleteString, &compareString);

    TEST_ASSERT_NOT_NULL(tree);
    TEST_ASSERT_NOT_NULL(tree->print);
    TEST_ASSERT_NOT_NULL(tree->delete);
    TEST_ASSERT_NOT_NULL(tree->compare);
    TEST_ASSERT_NULL(tree->root);

    deleteTree(tree);
}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(should_initialize_hash_map);

    return UNITY_END();
}