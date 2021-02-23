#include "unity.h"
#include "LinkedListAPI.h"
#include "DataTypes.h"

void setUp(void) {
}

void tearDown(void) {
}

void should_initialize_hash_map(void) {
    List* list = initializeList(&printString, &deleteString, &compareString);

    TEST_ASSERT_NOT_NULL(list);
    TEST_ASSERT_NOT_NULL(list->print);
    TEST_ASSERT_NOT_NULL(list->delete);
    TEST_ASSERT_NOT_NULL(list->compare);
    TEST_ASSERT_NULL(list->head);
    TEST_ASSERT_NULL(list->tail);
    TEST_ASSERT_EQUAL(0, list->length);

    deleteList(list);
}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(should_initialize_hash_map);

    return UNITY_END();
}