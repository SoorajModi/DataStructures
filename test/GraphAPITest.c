#include "unity.h"
#include "GraphAPI.h"

void setUp(void) {
}

void tearDown(void) {
}

void should_initialize_graph(void) {
    Graph* graph = createGraph();

    TEST_ASSERT_NOT_NULL(graph);
    TEST_ASSERT_NULL(graph->vertexList);
    TEST_ASSERT_EQUAL(0, graph->numVertices);
    TEST_ASSERT_EQUAL(0, graph->numEdges);

    freeGraph(graph);
}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(should_initialize_graph);

    return UNITY_END();
}