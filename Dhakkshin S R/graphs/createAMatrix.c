#include <stdio.h>
#include <stdlib.h>

int** initializeGraph(int numVertices) {
    int** graph = malloc(sizeof(int*) * numVertices);
    for (int i = 0; i < numVertices; i++) {
        graph[i] = malloc(sizeof(int) * numVertices);
        for (int j = 0; j < numVertices; j++) {
            graph[i][j] = 0;
        }
    }

    return graph;
}

void addEdge(int** graph, int startVertex, int endVertex, int weight) {
    graph[startVertex][endVertex] = weight;
}

void printGraph(int** graph, int numVertices) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            printf("%d\t", graph[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int numVertices = 5;

    int** graph = initializeGraph(numVertices);

    addEdge(graph, 0, 1, 1); // Edge from vertex 0 to vertex 1 with weight 1
    addEdge(graph, 0, 2, 1); // Edge from vertex 0 to vertex 2 with weight 1
    addEdge(graph, 1, 3, 1); // Edge from vertex 1 to vertex 3 with weight 1
    addEdge(graph, 2, 4, 1); // Edge from vertex 2 to vertex 4 with weight 1
    addEdge(graph, 3, 4, 1); // Edge from vertex 3 to vertex 4 with weight 1

    printGraph(graph, numVertices);

    return 0;
}
