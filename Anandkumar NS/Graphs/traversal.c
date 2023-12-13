// bfs and dfs traversal for graphs 

#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *createNode(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void addEdge(struct node **adjList, int u, int v)
{
    struct node *newNode = createNode(v);
    newNode->next = adjList[u];
    adjList[u] = newNode;
    newNode = createNode(u);
    newNode->next = adjList[v];
    adjList[v] = newNode;
}
void printGraph(struct node **adjList, int V)
{
    for (int i = 0; i < V; i++)
    {
        struct node *temp = adjList[i];
        printf("Adjacency list of vertex %d\n", i);
        while (temp)
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

void bfs(struct node **adjList, int V, int start)
{
    int *visited = (int *)calloc(V, sizeof(int));
    int *queue = (int *)malloc(V * sizeof(int));
    int front = -1, rear = -1;
    queue[++rear] = start;
    visited[start] = 1;
    while (front != rear)
    {
        int u = queue[++front];
        printf("%d ", u);
        struct node *temp = adjList[u];
        while (temp)
        {
            if (!visited[temp->data])
            {
                queue[++rear] = temp->data;
                visited[temp->data] = 1;
            }
            temp = temp->next;
        }
    }
}

void dfs(struct node **adjList, int V, int start)
{
    int *visited = (int *)calloc(V, sizeof(int));
    int *stack = (int *)malloc(V * sizeof(int));
    int top = -1;
    stack[++top] = start;
    visited[start] = 1;
    while (top != -1)
    {
        int u = stack[top--];
        printf("%d ", u);
        struct node *temp = adjList[u];
        while (temp)
        {
            if (!visited[temp->data])
            {
                stack[++top] = temp->data;
                visited[temp->data] = 1;
            }
            temp = temp->next;
        }
    }
}

int main()
{
    int V = 5;
    struct node **adjList = (struct node **)malloc(V * sizeof(struct node *));
    for (int i = 0; i < V; i++)
        adjList[i] = NULL;
    addEdge(adjList, 0, 1);
    addEdge(adjList, 0, 4);
    addEdge(adjList, 1, 2);
    addEdge(adjList, 1, 3);
    addEdge(adjList, 1, 4);
    addEdge(adjList, 2, 3);
    addEdge(adjList, 3, 4);
    printGraph(adjList, V);
    return 0;
}

