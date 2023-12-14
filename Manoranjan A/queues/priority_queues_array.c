#include <stdio.h>

#define MAX_SIZE 100

struct PriorityQueue {
    int arr[MAX_SIZE];
    int front;
    int rear;
};

void initializeQueue(struct PriorityQueue* q) {
    q->front = -1;
    q->rear = -1;
}

int isEmpty(struct PriorityQueue* q) {
    return (q->front == -1);
}

int isFull(struct PriorityQueue* q) {
    return (q->rear == MAX_SIZE - 1);
}

void enqueue(struct PriorityQueue* q, int item) {
    if (isFull(q)) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }

    if (isEmpty(q)) {
        q->front = q->rear = 0;
        q->arr[q->rear] = item;
    } else {
        int i;
        for (i = q->rear; i >= q->front && item < q->arr[i]; i--) {
            q->arr[i + 1] = q->arr[i];
        }

        q->arr[i + 1] = item;
        q->rear++;
    }
}

int dequeue(struct PriorityQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }

    int item = q->arr[q->front];

    if (q->front == q->rear) {
        initializeQueue(q);
    } else {
        q->front++;
    }

    return item;
}

int main() {
    struct PriorityQueue myQueue;
    initializeQueue(&myQueue);

    enqueue(&myQueue, 3);
    enqueue(&myQueue, 1);
    enqueue(&myQueue, 4);
    enqueue(&myQueue, 2);

    printf("Dequeued item: %d\n", dequeue(&myQueue));
    printf("Dequeued item: %d\n", dequeue(&myQueue));

    return 0;
}
