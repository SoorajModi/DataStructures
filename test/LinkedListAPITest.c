#include "unity.h"
//#include "unity_memory.h"
#include "LinkedListAPI.h"
#include "DataTypes.h"

void setUp(void) {
//    UnityMalloc_StartTest();
}

void tearDown(void) {
//    UnityMalloc_EndTest();
}

void should_initialize_linked_list(void) {
    List *list = initializeList(&printString, &deleteString, &compareString);

    TEST_ASSERT_NOT_NULL(list);
    TEST_ASSERT_NOT_NULL(list->print);
    TEST_ASSERT_NOT_NULL(list->delete);
    TEST_ASSERT_NOT_NULL(list->compare);
    TEST_ASSERT_NULL(list->head);
    TEST_ASSERT_NULL(list->tail);
    TEST_ASSERT_EQUAL(0, list->length);

    deleteList(list);
}

void should_initialize_node(void) {
    char *string = malloc(sizeof(char) * 6);
    strncpy(string, "string", 6);
    Node *node = initializeNode((void *) string);

    TEST_ASSERT_NULL(node->next);
    TEST_ASSERT_NULL(node->prev);
    TEST_ASSERT_EQUAL(string, (char *) node->data);

    deleteNode(node, &deleteString);
}

void should_insert_data_to_front_of_list(void) {
    List *list = initializeList(&printString, &deleteString, &compareString);

    char *string = malloc(sizeof(char) * 6);
    char *string2 = malloc(sizeof(char) * 7);
    strncpy(string, "string", 6);
    strncpy(string2, "string2", 7);

    insertFront(list, (void *) string);
    insertFront(list, (void *) string2);

    TEST_ASSERT_EQUAL(string2, (char *) list->head->data);

    deleteList(list);
}

void should_get_data_from_front_of_list(void) {
    List *list = initializeList(&printString, &deleteString, &compareString);

    char *string = malloc(sizeof(char) * 6);
    strncpy(string, "string", 6);

    insertFront(list, (void *) string);

    TEST_ASSERT_EQUAL(string, (char *) getDataFromFront(list));

    deleteList(list);
}

void should_insert_data_to_back_of_list(void) {
    List *list = initializeList(&printString, &deleteString, &compareString);

    char *string = malloc(sizeof(char) * 6);
    char *string2 = malloc(sizeof(char) * 7);
    strncpy(string, "string", 6);
    strncpy(string2, "string2", 7);

    insertBack(list, (void *) string);
    insertBack(list, (void *) string2);

    TEST_ASSERT_EQUAL(string2, (char *) list->tail->data);

    deleteList(list);
}

void should_get_data_from_back_of_list(void) {
    List *list = initializeList(&printString, &deleteString, &compareString);

    char *string = malloc(sizeof(char) * 6);
    char *string2 = malloc(sizeof(char) * 7);
    strncpy(string, "string", 6);
    strncpy(string2, "string2", 7);

    insertBack(list, (void *) string);
    insertBack(list, (void *) string2);

    TEST_ASSERT_EQUAL(string2, (char *) getDataFromBack(list));

    deleteList(list);
}

void should_return_1_if_list_is_empty(void) {
    List *list = initializeList(&printString, &deleteString, &compareString);

    TEST_ASSERT_EQUAL(1, isEmpty(list));

    deleteList(list);
}

void should_return_0_if_list_is_empty(void) {
    List *list = initializeList(&printString, &deleteString, &compareString);

    char *string = malloc(sizeof(char) * 6);
    strncpy(string, "string", 6);
    insertFront(list, (void *) string);

    TEST_ASSERT_EQUAL(0, isEmpty(list));

    deleteList(list);
}

void should_return_length_of_list(void) {
    List *list = initializeList(&printString, &deleteString, &compareString);
    TEST_ASSERT_EQUAL(0, getLength(list));

    char *string = malloc(sizeof(char) * 6);
    strncpy(string, "string", 6);
    insertFront(list, (void *) string);
    TEST_ASSERT_EQUAL(1, getLength(list));

    deleteList(list);
}

void should_delete_node_from_front(void) {
    List *list = initializeList(&printString, &deleteString, &compareString);

    char *string = malloc(sizeof(char) * 6);
    char *string2 = malloc(sizeof(char) * 7);
    strncpy(string, "string", 6);
    strncpy(string2, "string2", 7);

    insertBack(list, (void *) string);
    insertBack(list, (void *) string2);

    TEST_ASSERT_EQUAL(string, (char *) list->head->data);

    deleteFromFront(list);

    TEST_ASSERT_EQUAL(string2, (char *) list->head->data);

    deleteList(list);
}

void should_delete_node_from_back(void) {
    List *list = initializeList(&printString, &deleteString, &compareString);

    char *string = malloc(sizeof(char) * 6);
    char *string2 = malloc(sizeof(char) * 7);
    strncpy(string, "string", 6);
    strncpy(string2, "string2", 7);

    insertBack(list, (void *) string);
    insertBack(list, (void *) string2);

    TEST_ASSERT_EQUAL(string2, (char *) list->tail->data);

    deleteFromBack(list);

    TEST_ASSERT_EQUAL(string, (char *) list->tail->data);

    deleteList(list);
}

void should_clear_all_content_of_list(void) {
    List *list = initializeList(&printString, &deleteString, &compareString);

    char *string = malloc(sizeof(char) * 6);
    strncpy(string, "string", 6);
    insertFront(list, (void *) string);

    TEST_ASSERT_EQUAL(1, getLength(list));
    clearList(list);
    TEST_ASSERT_EQUAL(0, getLength(list));

    deleteList(list);
}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(should_initialize_linked_list);
    RUN_TEST(should_initialize_node);
    RUN_TEST(should_insert_data_to_front_of_list);
    RUN_TEST(should_get_data_from_front_of_list);
    RUN_TEST(should_insert_data_to_back_of_list);
    RUN_TEST(should_get_data_from_back_of_list);
    RUN_TEST(should_return_1_if_list_is_empty);
    RUN_TEST(should_return_0_if_list_is_empty);
    RUN_TEST(should_return_length_of_list);
    RUN_TEST(should_delete_node_from_front);
    RUN_TEST(should_delete_node_from_back);
    RUN_TEST(should_clear_all_content_of_list);

    return UNITY_END();
}