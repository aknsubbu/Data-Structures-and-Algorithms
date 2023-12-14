#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Node structure for the adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

// Graph structure containing an array of adjacency lists
struct Graph {
    int numVertices;
    struct Node* adjacencyList[MAX_VERTICES];
    int inDegree[MAX_VERTICES];
};

// Function to initialize the graph
struct Graph* initializeGraph(int numVertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;

    // Initialize the adjacency list for each vertex
    for (int i = 0; i < numVertices; ++i) {
        graph->adjacencyList[i] = NULL;
        graph->inDegree[i] = 0;
    }

    return graph;
}

// Function to add a directed edge to the graph
void addDirectedEdge(struct Graph* graph, int startVertex, int endVertex) {
    // Create a new node for the end vertex
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = endVertex;
    newNode->next = graph->adjacencyList[startVertex];

    // Update the adjacency list for the start vertex
    graph->adjacencyList[startVertex] = newNode;

    // Increment in-degree for the end vertex
    graph->inDegree[endVertex]++;
}

// Function to perform topological sorting using a queue
void topologicalSort(struct Graph* graph) {
    int queue[MAX_VERTICES];
    int front = 0, rear = -1;

    // Enqueue vertices with in-degree 0
    for (int i = 0; i < graph->numVertices; ++i) {
        if (graph->inDegree[i] == 0) {
            queue[++rear] = i;
        }
    }

    // Perform topological sorting
    while (front <= rear) {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        // Decrease in-degree of adjacent vertices and enqueue if in-degree becomes 0
        struct Node* temp = graph->adjacencyList[currentVertex];
        while (temp != NULL) {
            int adjacentVertex = temp->vertex;
            graph->inDegree[adjacentVertex]--;
            if (graph->inDegree[adjacentVertex] == 0) {
                queue[++rear] = adjacentVertex;
            }
            temp = temp->next;
        }
    }
}

int main() {
    int numVertices = 6;
    struct Graph* graph = initializeGraph(numVertices);

    // Add directed edges to the graph
    addDirectedEdge(graph, 5, 2);
    addDirectedEdge(graph, 5, 0);
    addDirectedEdge(graph, 4, 0);
    addDirectedEdge(graph, 4, 1);
    addDirectedEdge(graph, 2, 3);
    addDirectedEdge(graph, 3, 1);

    printf("Topological Sorting: ");
    topologicalSort(graph);

    free(graph); // Free the memory allocated for the graph

    return 0;
}
