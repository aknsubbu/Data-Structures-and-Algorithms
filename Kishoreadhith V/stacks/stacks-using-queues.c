#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Queue{
    struct Node *front;
    struct Node *rear;
    int size;
};

struct Queue* createQueue(){
    struct Queue *queue = (struct Queue*) malloc (sizeof(struct Queue));
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
    return queue;
}

struct Stack{
    struct Queue *queue1;
    struct Queue *queue2;
    int size;
};

struct Stack* createStack(){
    struct Stack *stack = (struct Stack*) malloc (sizeof(struct Stack));
    stack->queue1 = createQueue();
    stack->queue2 = createQueue();
    stack->size = 0;
    return stack;
}

struct Node* getNode(int data){
    struct Node *node = (struct Node*) malloc (sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

void enqueue(struct Queue *queue, int data){
    struct Node *node = getNode(data);
    if(queue->front == NULL){
        queue->front = node;
        queue->rear = node;
    }
    else{
        queue->rear->next = node;
        node->prev = queue->rear;
        queue->rear = node;
    }
    queue->size++;
    return;
}

int dequeue(struct Queue *queue){
    if(queue->front == NULL){
        printf("Underflow!\n");
        return -1;
    }
    int data = queue->front->data;
    struct Node *temp = queue->front;
    queue->front = queue->front->next;
    if(queue->front == NULL){
        queue->rear = NULL;
    }
    else{
        queue->front->prev = NULL;
    }
    free(temp);
    queue->size--;
    return data;
}

void push(struct Stack *stack, int data){
    enqueue(stack->queue1, data);
    stack->size++;
    return;
}

int pop(struct Stack *stack){
    if(stack->queue1->front == NULL){
        printf("Underflow!\n");
        return -1;
    }
    while (stack->queue1->size > 1)
    {
        enqueue(stack->queue2, dequeue(stack->queue1));
    }
    int data = dequeue(stack->queue1);
    struct Queue *temp = stack->queue1;
    stack->queue1 = stack->queue2;
    stack->queue2 = temp;
    stack->size--;
    return data;
}

void printStack(struct Stack *stack){
    struct Node *temp = stack->queue1->rear;
    while (temp != NULL)
    {
        printf("|%d| \n", temp->data);
        temp = temp->prev;
    }
    printf("---\n");
    return;
}

int main(){
    struct Stack *stack = createStack();
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    printStack(stack);
    printf("%d\n", pop(stack));
    printf("%d\n", pop(stack));
    printf("%d\n", pop(stack));
    printf("%d\n", pop(stack));
    printStack(stack);
    return 0;
}