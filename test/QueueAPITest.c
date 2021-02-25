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

void should_add_to_end_of_queue(void) {
    Queue* queue = initializeQueue(&printString, &deleteString, &compareString);

    char *string = malloc(sizeof(char) * 6);
    char *string2 = malloc(sizeof(char) * 7);
    strncpy(string, "string", 6);
    strncpy(string2, "string2", 7);

    enqueue(queue, (void *)string);
    TEST_ASSERT_EQUAL(1, getQueueLength(queue));
    TEST_ASSERT_EQUAL(string, queue->tail->data);

    enqueue(queue, (void *)string2);
    TEST_ASSERT_EQUAL(2, getQueueLength(queue));
    TEST_ASSERT_EQUAL(string2, queue->tail->data);

    deleteQueue(queue);
}

void should_get_from_front_of_list(void) {
    Queue* queue = initializeQueue(&printString, &deleteString, &compareString);

    char *string = malloc(sizeof(char) * 6);
    char *string2 = malloc(sizeof(char) * 7);
    strncpy(string, "string", 6);
    strncpy(string2, "string2", 7);

    enqueue(queue, (void *)string);
    TEST_ASSERT_EQUAL(1, getQueueLength(queue));
    TEST_ASSERT_EQUAL(string, front(queue));

    enqueue(queue, (void *)string2);
    TEST_ASSERT_EQUAL(2, getQueueLength(queue));
    TEST_ASSERT_EQUAL(string, front(queue));

    deleteQueue(queue);
}

void should_remove_from_front_of_queue(void) {
    Queue* queue = initializeQueue(&printString, &deleteString, &compareString);

    char *string = malloc(sizeof(char) * 6);
    char *string2 = malloc(sizeof(char) * 7);
    strncpy(string, "string", 6);
    strncpy(string2, "string2", 7);

    enqueue(queue, (void *)string);
    enqueue(queue, (void *)string2);

    dequeue(queue);
    TEST_ASSERT_EQUAL(1, getQueueLength(queue));
    TEST_ASSERT_EQUAL(string2, front(queue));

    deleteQueue(queue);
}

void should_determine_if_queue_is_empty(void) {
    Queue* queue = initializeQueue(&printString, &deleteString, &compareString);
    TEST_ASSERT_TRUE(isQueueEmpty(queue));

    char *string = malloc(sizeof(char) * 6);
    strncpy(string, "string", 6);

    enqueue(queue, (void *)string);
    TEST_ASSERT_FALSE(isQueueEmpty(queue));

    deleteQueue(queue);
}

void should_clear_queue(void) {
    Queue* queue = initializeQueue(&printString, &deleteString, &compareString);

    char *string = malloc(sizeof(char) * 6);
    char *string2 = malloc(sizeof(char) * 7);
    strncpy(string, "string", 6);
    strncpy(string2, "string2", 7);

    enqueue(queue, (void *)string);
    enqueue(queue, (void *)string2);

    emptyQueue(queue);
    TEST_ASSERT_TRUE(isQueueEmpty(queue));


    deleteQueue(queue);
}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(should_initialize_queue);
    RUN_TEST(should_add_to_end_of_queue);
    RUN_TEST(should_get_from_front_of_list);
    RUN_TEST(should_remove_from_front_of_queue);
    RUN_TEST(should_determine_if_queue_is_empty);
    RUN_TEST(should_clear_queue);

    return UNITY_END();
}