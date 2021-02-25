#include "unity.h"
#include "unity_memory.h"
#include "GraphAPI.h"

void setUp(void) {
    UnityMalloc_StartTest();
}

void tearDown(void) {
    UnityMalloc_EndTest();
}

void should_initialize_graph(void) {
    Graph *graph = createGraph();

    TEST_ASSERT_NOT_NULL(graph);
    TEST_ASSERT_NULL(graph->vertexList);
    TEST_ASSERT_EQUAL(0, graph->numVertices);
    TEST_ASSERT_EQUAL(0, graph->numEdges);

    freeGraph(graph);
}

void should_add_vertex_to_graph(void) {
    Graph *graph = createGraph();
    TEST_ASSERT_EQUAL(0, graph->numVertices);
    TEST_ASSERT_EQUAL(0, getNumVertices(graph));

    addVertex(graph, 1);
    TEST_ASSERT_EQUAL(1, graph->numVertices);
    TEST_ASSERT_EQUAL(1, graph->vertexList->value);
    TEST_ASSERT_NULL(graph->vertexList->adjList);
    TEST_ASSERT_NULL(graph->vertexList->next);

    addVertex(graph, 2);
    TEST_ASSERT_EQUAL(2, graph->numVertices);
    TEST_ASSERT_EQUAL(2, getNumVertices(graph));
    TEST_ASSERT_EQUAL(1, graph->vertexList->value);
    TEST_ASSERT_EQUAL(2, graph->vertexList->next->value);

    freeGraph(graph);
}

void should_add_edge_to_graph(void) {
    Graph *graph = createGraph();
    TEST_ASSERT_EQUAL(0, graph->numEdges);
    TEST_ASSERT_EQUAL(0, getNumEdges(graph));

    addVertex(graph, 1);
    addVertex(graph, 2);
    addVertex(graph, 3);

    addEdge(graph, 1, 2);
    addEdge(graph, 3, 1);

    TEST_ASSERT_EQUAL(2, graph->numEdges);
    TEST_ASSERT_EQUAL(2, getNumEdges(graph));
    TEST_ASSERT_EQUAL(2, graph->vertexList->adjList->value);
    TEST_ASSERT_EQUAL(3, graph->vertexList->adjList->next->value);

    freeGraph(graph);
}

void should_check_if_vertex_is_present_in_graph(void) {
    Graph *graph = createGraph();

    addVertex(graph, 1);

    TEST_ASSERT_TRUE(checkForVertex(graph, 1));
    TEST_ASSERT_FALSE(checkForVertex(graph, 2));

    freeGraph(graph);
}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(should_initialize_graph);
    RUN_TEST(should_add_vertex_to_graph);
    RUN_TEST(should_add_edge_to_graph);
    RUN_TEST(should_check_if_vertex_is_present_in_graph);

    return UNITY_END();
}