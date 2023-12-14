#include <stdio.h>
#include <stdlib.h>

struct Graph{
    int **adj;
    int size;
};

struct Graph* createGraph(int size){
    size++;
    struct Graph *graph = (struct Graph*) malloc (sizeof(struct Graph));
    graph->adj = (int **) calloc (size, sizeof(int *));
    for (int i = 0; i < size; i++)
    {
        graph->adj[i] = (int *) calloc (size, sizeof(int));
    }
    graph->size = size;
    return graph;
}

void addEdge(struct Graph *graph, int src, int dest){
    graph->adj[src][dest] = 1;
    graph->adj[dest][src] = 1;
}

void addDirectedEdge(struct Graph *graph, int src, int dest){
    graph->adj[src][dest] = 1;
}

void printGraph(struct Graph *graph){
    printf("  ");
    for (int i = 1; i < graph->size; i++)
    {
        printf("%d ", i);
    }
    printf("\n");
    for (int i = 1; i < graph->size; i++)
    {
        printf("%d ", i);
        for (int j = 1; j < graph->size; j++)
        {
            printf("%d ", graph->adj[i][j]);
        }
        printf("\n");
    }
}

void buildGraph(struct Graph *graph){
    int src, dest;
    printf("Enter the source and destination vertices (-1 -1 to exit): ");
    while (1)
    {
        scanf("%d %d", &src, &dest);
        if (src == -1 && dest == -1)
        {
            break;
        }
        addDirectedEdge(graph, src, dest);
    }
}

void dfs(struct Graph *graph, int src){
    int *stack = (int *) malloc (graph->size * sizeof(int));
    int top = -1;
    int *visited = (int *) calloc (graph->size, sizeof(int));
    stack[++top] = src;
    visited[src] = 1;
    while (top != -1)
    {
        int curr = stack[top--];
        printf("%d ", curr);
        visited[curr] = 2;
        for (int i = 1; i < graph->size; i++)
        {
            if (graph->adj[curr][i] == 1 && visited[i] == 0)
            {
                stack[++top] = i;
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

void bfs(struct Graph *graph, int src){
    int *queue = (int *) malloc (graph->size * sizeof(int));
    int front = -1, rear = -1;
    int *visited = (int *) calloc (graph->size, sizeof(int));
    queue[++rear] = src;
    front++;
    visited[src] = 1;
    while (front != rear)
    {
        int curr = queue[++front];
        printf("%d ", curr);
        visited[curr] = 2;
        for (int i = 1; i < graph->size; i++)
        {
            if (graph->adj[curr][i] == 1 && visited[i] == 0)
            {
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

int main(){
    int size;
    printf("Enter the number of vertices: ");
    scanf("%d", &size);
    struct Graph *graph = createGraph(size);
    buildGraph(graph);
    printGraph(graph);
    printf("DFS: ");
    dfs(graph, 1);
    printf("BFS: ");
    bfs(graph, 1);
}