#include "unity.h"
#include "QueueAPI.h"
#include "DataTypes.h"

void setUp(void) {
}

void tearDown(void) {
}

void should_initialize_queue(void) {
    Queue* queue = initializeQueue(&printString, &deleteString, &compareString);

    TEST_ASSERT_NOT_NULL(queue);
    TEST_ASSERT_NOT_NULL(queue->print);
    TEST_ASSERT_NOT_NULL(queue->delete);
    TEST_ASSERT_NOT_NULL(queue->compare);
    TEST_ASSERT_NULL(queue->head);
    TEST_ASSERT_NULL(queue->tail);
    TEST_ASSERT_EQUAL(0, queue->length);

    deleteQueue(queue);
}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(should_initialize_queue);

    return UNITY_END();
}