#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    int priority;
    struct Node* next;
};

struct PriorityQueue {
    struct Node* front;
};

struct Node* createNode(int data, int priority) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;
    return newNode;
}

void initializeQueue(struct PriorityQueue* q) {
    q->front = NULL;
}

int isEmpty(struct PriorityQueue* q) {
    return (q->front == NULL);
}

void enqueue(struct PriorityQueue* q, int data, int priority) {
    struct Node* newNode = createNode(data, priority);

    if (isEmpty(q) || priority < q->front->priority) {
        newNode->next = q->front;
        q->front = newNode;
    } else {
        struct Node* current = q->front;
        while (current->next != NULL && current->next->priority <= priority) {
            current = current->next;
        }

        newNode->next = current->next;
        current->next = newNode;
    }
}

int dequeue(struct PriorityQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1; // Assuming -1 is not a valid element in the queue
    }

    struct Node* temp = q->front;
    int data = temp->data;
    q->front = q->front->next;
    free(temp);

    return data;
}

int main() {
    struct PriorityQueue myQueue;
    initializeQueue(&myQueue);

    enqueue(&myQueue, 3, 2);
    enqueue(&myQueue, 1, 1);
    enqueue(&myQueue, 4, 4);
    enqueue(&myQueue, 2, 3);

    printf("Dequeued item: %d\n", dequeue(&myQueue));
    printf("Dequeued item: %d\n", dequeue(&myQueue));

    return 0;
}
