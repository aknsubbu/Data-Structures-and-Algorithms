#include <stdio.h>
#include <stdlib.h>
 
#define MAX_VERTICES 100
 
typedef struct {
    int vertices[MAX_VERTICES];
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
    int numVertices;
} Graph;
 
void initGraph(Graph* graph, int numVertices) {
    graph->numVertices = numVertices;
    for (int i = 0; i < numVertices; i++) {
        graph->vertices[i] = 0;
        for (int j = 0; j < numVertices; j++) {
            graph->adjMatrix[i][j] = 0;
        }
    }
}
 
void addEdge(Graph* graph, int src, int dest) {
    graph->adjMatrix[src][dest] = 1;
    graph->adjMatrix[dest][src] = 1;
}
 
void bfs(Graph* graph, int startVertex) {
    int visited[MAX_VERTICES] = {0};
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;
 
    visited[startVertex] = 1;
    queue[rear++] = startVertex;
 
    while (front < rear) {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);
 
        for (int i = 0; i < graph->numVertices; i++) {
            if (graph->adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
    printf("\n");
}
 
void dfsRecursive(Graph* graph, int startVertex, int visited[]) {
    visited[startVertex] = 1;
    printf("%d ", startVertex);
 
    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->adjMatrix[startVertex][i] == 1 && !visited[i]) {
            dfsRecursive(graph, i, visited);
        }
    }
}
 
void dfs(Graph* graph, int startVertex) {
    int visited[MAX_VERTICES] = {0};
 
    dfsRecursive(graph, startVertex, visited);
    printf("\n");
}
 
int main() {
    Graph graph;
    int numVertices, src, dest;
 
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);
 
    initGraph(&graph, numVertices);
 
    printf("Enter the edges (src dest) [Enter -1 -1 to stop]:\n");
    while (1) {
        scanf("%d %d", &src, &dest);
        if (src == -1 && dest == -1) {
            break;
        }
        addEdge(&graph, src, dest);
    }
 
    int startVertex;
    printf("Enter the starting vertex for BFS and DFS: ");
    scanf("%d", &startVertex);
 
    printf("BFS traversal: ");
    bfs(&graph, startVertex);
    printf("DFS traversal: ");
    dfs(&graph, startVertex);
 
    return 0;
}