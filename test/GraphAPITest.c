#include "GraphAPI.h"

int main(void) {
  Graph* graph = createGraph();

  for (int i = 1; i < 6; i++) {
    addVertex(graph, i);
  }

  addEdge(graph, 1, 2);
  addEdge(graph, 2, 3);
  addEdge(graph, 2, 4);
  addEdge(graph, 3, 4);
  addEdge(graph, 4, 1);
  addEdge(graph, 4, 5);

  printGraph(graph);

  printf("Checking for Vertex 5: %d\n", checkForVertex(graph, 5));
  printf("Checking for Vertex 6: %d\n", checkForVertex(graph, 6));

  printf("Number of vertices: %d\n", getNumVertices(graph));
  printf("Number of edges: %d\n", getNumEdges(graph));

  freeGraph(graph);

  return 0;
}
