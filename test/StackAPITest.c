#include "unity.h"
#include "StackAPI.h"
#include "DataTypes.h"

void setUp(void) {
}

void tearDown(void) {
}

void should_initialize_stack(void) {
    Stack* stack = initializeStack(&printString, &deleteString, &compareString);

    TEST_ASSERT_NOT_NULL(stack);
    TEST_ASSERT_NOT_NULL(stack->print);
    TEST_ASSERT_NOT_NULL(stack->delete);
    TEST_ASSERT_NOT_NULL(stack->compare);
    TEST_ASSERT_NULL(stack->head);
    TEST_ASSERT_NULL(stack->tail);
    TEST_ASSERT_EQUAL(0, stack->length);

    deleteStack(stack);
}

void should_push_data_onto_stack(void) {
    Stack* stack = initializeStack(&printString, &deleteString, &compareString);

    char *string = malloc(sizeof(char) * 6);
    strncpy(string, "string", 6);
    push(stack, string);

    TEST_ASSERT_EQUAL(1, getSize(stack));
    TEST_ASSERT_EQUAL(string, stack->head->data);

    deleteStack(stack);
}

void should_get_data_from_top_of_stack(void) {
    Stack* stack = initializeStack(&printString, &deleteString, &compareString);

    char *string = malloc(sizeof(char) * 6);
    strncpy(string, "string", 6);
    push(stack, string);

    TEST_ASSERT_EQUAL(string, top(stack));

    deleteStack(stack);
}

void should_pop_data_from_top_of_stack(void) {
    Stack* stack = initializeStack(&printString, &deleteString, &compareString);

    char *string = malloc(sizeof(char) * 6);
    strncpy(string, "string", 6);
    push(stack, string);

    TEST_ASSERT_EQUAL(string, top(stack));
    TEST_ASSERT_EQUAL(1, getSize(stack));
    TEST_ASSERT_FALSE(isStackEmpty(stack));

    pop(stack);

    TEST_ASSERT_EQUAL(0, getSize(stack));
    TEST_ASSERT_TRUE(isStackEmpty(stack));

    deleteStack(stack);
}

void should_clear_all_data_from__stack(void) {
    Stack* stack = initializeStack(&printString, &deleteString, &compareString);

    char *string = malloc(sizeof(char) * 6);
    char *string2 = malloc(sizeof(char) * 7);
    strncpy(string, "string", 6);
    strncpy(string2, "string2", 7);

    push(stack, string);
    push(stack, string2);

    TEST_ASSERT_EQUAL(2, getSize(stack));
    TEST_ASSERT_FALSE(isStackEmpty(stack));

    clearStack(stack);

    TEST_ASSERT_EQUAL(0, getSize(stack));
    TEST_ASSERT_TRUE(isStackEmpty(stack));

    deleteStack(stack);
}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(should_initialize_stack);
    RUN_TEST(should_push_data_onto_stack);
    RUN_TEST(should_get_data_from_top_of_stack);
    RUN_TEST(should_pop_data_from_top_of_stack);
    RUN_TEST(should_clear_all_data_from__stack);

    return UNITY_END();
}