#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Stack{
    struct Node *top;
    int size;
};

struct Stack* createStack(){
    struct Stack *stack = (struct Stack*) malloc (sizeof(struct Stack));
    stack->top = NULL;
    stack->size = 0;
    return stack;
}

struct Queue{
    struct Stack *stack1;
    struct Stack *stack2;
    int size;
};

struct Queue* createQueue(){
    struct Queue *queue = (struct Queue*) malloc (sizeof(struct Queue));
    queue->stack1 = createStack();
    queue->stack2 = createStack();
    queue->size = 0;
    return queue;
}

struct Node* getNode(int data){
    struct Node *node = (struct Node*) malloc (sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

void push(struct Stack *stack, int data){
    struct Node *node = getNode(data);
    if(stack->top == NULL){
        stack->top = node;
    }
    else{
        stack->top->next = node;
        node->prev = stack->top;
        stack->top = node;
    }
    stack->size++;
    return;
}

int pop(struct Stack *stack){
    if(stack->top == NULL){
        printf("Underflow!\n");
        return -1;
    }
    int data = stack->top->data;
    struct Node *temp = stack->top;
    stack->top = stack->top->prev;
    free(temp);
    stack->size--;
    return data;
}

void enqueue(struct Queue *queue, int data){
    push(queue->stack1, data);
    queue->size++;
    return;
}

int dequeue(struct Queue *queue){
    if(queue->stack1-> size == 0){
        printf("Underflow!\n");
        return -1;
    }
    while (queue->stack1->size != 1)
    {
        push(queue->stack2, pop(queue->stack1));
    }
    int data = pop(queue->stack1);
    while (queue->stack2->size != 0)
    {
        push(queue->stack1, pop(queue->stack2));
    }
    queue->size--;
    return data;
}

void printQueue(struct Queue *queue){
    if(queue->stack1->size == 0){
        printf("Queue is empty!\n");
        return;
    }
    while (queue->stack1->size != 0)
    {
        push(queue->stack2, pop(queue->stack1));
    }
    while (queue->stack2->size != 0)
    {
        int data = pop(queue->stack2);
        printf("|%d| \n", data);
        push(queue->stack1, data);
    }
    printf("---\n");
    return;
}

int main(){
    struct Queue *queue = createQueue();
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    printQueue(queue);
    dequeue(queue);
    printQueue(queue);
    dequeue(queue);
    printQueue(queue);
    dequeue(queue);
    printQueue(queue);
    dequeue(queue);
    printQueue(queue);
    return 0;
}