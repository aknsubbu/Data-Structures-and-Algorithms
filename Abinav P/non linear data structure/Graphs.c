// #include <stdio.h>
// #include <stdlib.h>

// #define MAX_VERTICES 100

// typedef struct
// {
//     int vertices[MAX_VERTICES];
//     int adjMatrix[MAX_VERTICES][MAX_VERTICES];
//     int numVertices;
// } Graph;

// void initGraph(Graph *graph, int numVertices)
// {
//     graph->numVertices = numVertices;
//     for (int i = 0; i < numVertices; i++)
//     {
//         graph->vertices[i] = 0;
//         for (int j = 0; j < numVertices; j++)
//         {
//             graph->adjMatrix[i][j] = 0;
//         }
//     }
// }

// void addEdge(Graph *graph, int src, int dest)
// {
//     graph->adjMatrix[src][dest] = 1;
//     graph->adjMatrix[dest][src] = 1;
// }

// void bfs(Graph *graph, int startVertex)
// {
//     int visited[MAX_VERTICES] = {0};
//     int queue[MAX_VERTICES];
//     int front = 0, rear = 0;

//     visited[startVertex] = 1;
//     queue[rear++] = startVertex;

//     while (front < rear)
//     { // Change the condition from `front <= rear` to `front < rear`
//         int currentVertex = queue[front++];
//         printf("%d ", currentVertex);

//         for (int i = 0; i < graph->numVertices; i++)
//         {
//             if (graph->adjMatrix[currentVertex][i] == 1 && !visited[i])
//             {
//                 visited[i] = 1;
//                 queue[rear++] = i;
//             }
//         }
//     }
//     printf("\n");
// }

// void dfsRecursive(Graph *graph, int startVertex, int visited[])
// {
//     visited[startVertex] = 1;
//     printf("%d ", startVertex);

//     for (int i = 0; i < graph->numVertices; i++)
//     {
//         if (graph->adjMatrix[startVertex][i] == 1 && !visited[i])
//         {1
//             dfsRecursive(graph, i, visited);
//         }
//     }
// }

// void dfs(Graph *graph, int startVertex)
// {
//     int visited[MAX_VERTICES] = {0};

//     dfsRecursive(graph, startVertex, visited);
//     printf("\n");
// }

// int main()
// {
//     Graph graph;
//     int numVertices, src, dest;

//     printf("Enter the number of vertices: ");
//     scanf("%d", &numVertices);

//     initGraph(&graph, numVertices);

//     printf("Enter the edges (src dest) [Enter -1 -1 to stop]:\n");
//     while (1)
//     {
//         scanf("%d %d", &src, &dest);
//         if (src == -1 && dest == -1)
//         {
//             break;
//         }
//         addEdge(&graph, src, dest);
//     }

//     int startVertex;
//     printf("Enter the starting vertex for BFS and DFS: ");
//     scanf("%d", &startVertex);

//     printf("BFS traversal: ");
//     bfs(&graph, startVertex);
//     printf("DFS traversal: ");
//     dfs(&graph, startVertex);

//     return 0;
// }
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct Graph
{
    int numVertices;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

void initGraph(Graph *graph, int numVertices)
{
    graph->numVertices = numVertices;
    for (int i = 0; i < numVertices; i++)
    {
        for (int j = 0; j < numVertices; j++)
        {
            graph->adjMatrix[i][j] = 0;
        }
    }
}

void addEdge(Graph *graph, int src, int dest)
{
    graph->adjMatrix[src][dest] = 1;
}

void topologicalSortUtil(Graph *graph, int vertex, int visited[], int stack[])
{
    visited[vertex] = 1;

    for (int i = 0; i < graph->numVertices; i++)
    {
        if (graph->adjMatrix[vertex][i] == 1 && !visited[i])
        {
            topologicalSortUtil(graph, i, visited, stack);
        }
    }

    stack[--stack[0]] = vertex;
}

void topologicalSort(Graph *graph)
{
    int visited[MAX_VERTICES] = {0};
    int stack[MAX_VERTICES + 1];
    stack[0] = graph->numVertices;

    for (int i = 0; i < graph->numVertices; i++)
    {
        if (!visited[i])
        {
            topologicalSortUtil(graph, i, visited, stack);
        }
    }

    printf("Topological Sort: ");
    for (int i = 1; i <= graph->numVertices; i++)
    {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main()
{
    Graph graph;
    int numVertices, src, dest;

    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    initGraph(&graph, numVertices);

    printf("Enter the edges (src dest) [Enter -1 -1 to stop]:\n");
    while (1)
    {
        scanf("%d %d", &src, &dest);
        if (src == -1 && dest == -1)
        {
            break;
        }
        addEdge(&graph, src, dest);
    }

    topologicalSort(&graph);

    return 0;
}
