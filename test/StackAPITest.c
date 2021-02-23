#include "unity.h"
#include "StackAPI.h"
#include "DataTypes.h"

void setUp(void) {
}

void tearDown(void) {
}

void should_initialize_hash_map(void) {
    Stack* stack = initializeStack(&printString, &deleteString, &compareString);

    TEST_ASSERT_NOT_NULL(stack);
    TEST_ASSERT_NOT_NULL(stack->print);
    TEST_ASSERT_NOT_NULL(stack->delete);
    TEST_ASSERT_NOT_NULL(stack->compare);
    TEST_ASSERT_NULL(stack->head);
    TEST_ASSERT_NULL(stack->tail);
    TEST_ASSERT_EQUAL(0, stack->length);

    deleteList(stack);
}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(should_initialize_hash_map);

    return UNITY_END();
}