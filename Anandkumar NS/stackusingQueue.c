#include <stdio.h>
#include <stdlib.h>

// Structure representing a queue node
struct QueueNode {
    int data;
    struct QueueNode* next;
};

// Structure representing a queue
struct Queue {
    struct QueueNode* front;
    struct QueueNode* rear;
};

// Initialize a new queue
struct Queue* initializeQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

// Enqueue an element to the rear of the queue
void enqueue(struct Queue* queue, int data) {
    struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    newNode->data = data;
    newNode->next = NULL;

    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
        return;
    }

    queue->rear->next = newNode;
    queue->rear = newNode;
}

// Dequeue an element from the front of the queue
int dequeue(struct Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty\n");
        return -1; // Assuming -1 as an invalid value for demonstration
    }

    struct QueueNode* temp = queue->front;
    int data = temp->data;

    queue->front = temp->next;

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(temp);
    return data;
}

// Structure representing a stack using two queues
struct Stack {
    struct Queue* queue1;
    struct Queue* queue2;
};

// Initialize a new stack
struct Stack* initializeStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->queue1 = initializeQueue();
    stack->queue2 = initializeQueue();
    return stack;
}

// Push an element onto the stack
void push(struct Stack* stack, int data) {
    // Enqueue the element to queue1
    enqueue(stack->queue1, data);
}

// Pop the top element from the stack
int pop(struct Stack* stack) {
    if (stack->queue1->front == NULL) {
        printf("Stack is empty\n");
        return -1; // Assuming -1 as an invalid value for demonstration
    }

    // Move all elements from queue1 to queue2, except the last one
    while (stack->queue1->front->next != NULL) {
        enqueue(stack->queue2, dequeue(stack->queue1));
    }

    // The last element in queue1 is the top element in the stack
    int poppedElement = dequeue(stack->queue1);

    // Swap the names of queue1 and queue2
    struct Queue* temp = stack->queue1;
    stack->queue1 = stack->queue2;
    stack->queue2 = temp;

    return poppedElement;
}

// Display the top element of the stack
int top(struct Stack* stack) {
    if (stack->queue1->front == NULL) {
        printf("Stack is empty\n");
        return -1; // Assuming -1 as an invalid value for demonstration
    }

    // Move all elements from queue1 to queue2
    while (stack->queue1->front != NULL) {
        enqueue(stack->queue2, dequeue(stack->queue1));
    }

    // The last element in queue2 is the top element in the stack
    int topElement = stack->queue2->rear->data;

    // Swap the names of queue1 and queue2
    struct Queue* temp = stack->queue1;
    stack->queue1 = stack->queue2;
    stack->queue2 = temp;

    return topElement;
}

// Check if the stack is empty
int isEmpty(struct Stack* stack) {
    return (stack->queue1->front == NULL);
}

int main() {
    struct Stack* stack = initializeStack();

    push(stack, 1);
    push(stack, 2);
    push(stack, 3);

    printf("Top element: %d\n", top(stack));

    printf("Pop: %d\n", pop(stack));
    printf("Pop: %d\n", pop(stack));

    printf("Top element: %d\n", top(stack));

    push(stack, 4);

    printf("Top element: %d\n", top(stack));

    return 0;
}
