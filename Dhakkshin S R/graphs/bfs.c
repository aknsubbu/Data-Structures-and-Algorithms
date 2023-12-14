#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50

struct Node {
    int vertex;
    struct Node* next;
};

struct Graph {
    int numVertices;
    struct Node* adjacencyList[MAX_VERTICES];
};

struct Graph* initializeGraph(int numVertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;

    // Initialize the adjacency list for each vertex
    for (int i = 0; i < numVertices; ++i) {
        graph->adjacencyList[i] = NULL;
    }

    return graph;
}

void addEdge(struct Graph* graph, int startVertex, int endVertex) {
    // Create a new node for the end vertex
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = endVertex;
    newNode->next = graph->adjacencyList[startVertex];

    // Update the adjacency list for the start vertex
    graph->adjacencyList[startVertex] = newNode;
}

void printGraph(struct Graph* graph) {
    printf("Adjacency List:\n");
    for (int i = 0; i < graph->numVertices; ++i) {
        struct Node* current = graph->adjacencyList[i];
        printf("Vertex %d: ", i);
        while (current != NULL) {
            printf("%d -> ", current->vertex);
            current = current->next;
        }
        printf("NULL\n");
    }
}

struct Queue {
    int items[MAX_VERTICES];
    int front;
    int rear;
};

struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

int isEmpty(struct Queue* queue) {
    if (queue->rear == -1)
        return 1;
    else
        return 0;
}

void enqueue(struct Queue* queue, int value) {
    if (queue->rear == MAX_VERTICES - 1)
        printf("\nQueue is Full!!");
    else {
        if (queue->front == -1)
            queue->front = 0;
        queue->rear++;
        queue->items[queue->rear] = value;
    }
}

int dequeue(struct Queue* queue) {
    int item;
    if (isEmpty(queue)) {
        printf("Queue is empty");
        item = -1;
    } else {
        item = queue->items[queue->front];
        queue->front++;
        if (queue->front > queue->rear) {
            queue->front = queue->rear = -1;
        }
    }
    return item;
}

void deleteQueue(struct Queue* queue) {
    if (queue) {
        if (queue->items)
            free(queue->items);
        free(queue);
    }
}

void bfs(struct Graph* graph, int startVertex) {
    struct Queue* queue = createQueue();

    int* visited = malloc(graph->numVertices * sizeof(int));
    for (int i = 0; i < graph->numVertices; i++)
        visited[i] = 0;

    visited[startVertex] = 1; // just to keep track of visited nodea
    enqueue(queue, startVertex);
    
    printf("BFS: ");
    while (!isEmpty(queue)) {
        // Print the visited node
        int currentVertex = dequeue(queue);
        printf("%d", currentVertex);

        // Find the adjacent vertices and add them to the queue
        struct Node* temp = graph->adjacencyList[currentVertex];

        while (temp) {
            int adjVertex = temp->vertex;

            if (visited[adjVertex] == 0) {
                visited[adjVertex] = 1;
                enqueue(queue, adjVertex);
            }
            temp = temp->next;
        }
    }
}

int main() {
    struct Graph* graph = initializeGraph(6);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 4);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);

    printGraph(graph);

    bfs(graph, 0);

    return 0;
}