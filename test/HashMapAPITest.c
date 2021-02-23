#include "unity.h"
#include "HashMapAPI.h"
#include "DataTypes.h"

void setUp(void) {
}

void tearDown(void) {
}

void should_initialize_hash_map(void) {
    HashMap* hashMap = initializeHashMap(10, hashString, &printString, &deleteString, &compareString);

    TEST_ASSERT_NOT_NULL(hashMap);
    TEST_ASSERT_NOT_NULL(hashMap->print);
    TEST_ASSERT_NOT_NULL(hashMap->delete);
    TEST_ASSERT_NOT_NULL(hashMap->compare);
    TEST_ASSERT_NOT_NULL(hashMap->map);
    TEST_ASSERT_EQUAL(0, hashMap->numElements);
    TEST_ASSERT_EQUAL(10, hashMap->capacity);
}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(should_initialize_hash_map);

    return UNITY_END();
}