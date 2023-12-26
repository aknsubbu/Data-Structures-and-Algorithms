#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    node * next;
};

typedef struct node node;

struct Queue{
    node * front;
    node * rear;
};

typedef struct Queue Queue;

Queue * createQueue(){
    Queue * q = (Queue *)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

void enqueue_front(Queue * queue, int data){
    node * newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    // empty
    if (queue->front == NULL && queue->rear == NULL)
    {
        queue->front = newNode;
        queue->rear = newNode;
        return;
    }
    newNode->next = queue->front;
    queue->front = newNode;
}

void enqueue_rear(Queue * queue, int data){
    node * newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    // empty
    if (queue->front == NULL && queue->rear == NULL)
    {
        queue->front = newNode;
        queue->rear = newNode;
        return;
    }
    queue->rear->next = newNode;
    queue->rear = newNode;    
}

int dequeue_front(Queue * queue){
    // last element
    if (queue->front == queue->rear)
    {
        int data = queue->front->data;
        queue->front = NULL;
        queue->rear = NULL;
        return data;
    }
    // empty queue
    if (queue->front == NULL && queue->rear == NULL)
    {
        printf("Underflow!\n");
        return -999999;
    }
    int data = queue->front->data;
    queue->front = queue->front->next;
    return data;
}

int dequeue_rear(Queue * queue){
    // last element
    if (queue->front == queue->rear)
    {
        int data = queue->front->data;
        queue->front = NULL;
        queue->rear = NULL;
        return data;
    }
    // empty queue
    if (queue->front == NULL && queue->rear == NULL)
    {
        printf("Underflow!\n");
        return -999999;
    }
    int data = queue->rear->data;
    node * temp = queue->front;
    while (temp->next != queue->rear)
    {
        temp = temp->next;
    }
    temp->next = NULL;
    queue->rear = temp;
    return data;
}

void printQueue(Queue * queue){
    if(queue->front == NULL && queue->rear == NULL){
        printf("Empty queue\n");
        return;
    }
    node * temp = queue->front;
    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    Queue * queue = createQueue();
    enqueue_front(queue, 1);
    enqueue_front(queue, 2);
    enqueue_front(queue, 3);
    enqueue_front(queue, 4);
    enqueue_front(queue, 5);
    enqueue_rear(queue, 6);
    enqueue_rear(queue, 7);
    enqueue_rear(queue, 8);
    enqueue_rear(queue, 9);
    enqueue_rear(queue, 10);
    printQueue(queue);
    printf("%d\n", dequeue_front(queue));
    printf("%d\n", dequeue_front(queue));
    printf("%d\n", dequeue_front(queue));
    printf("%d\n", dequeue_front(queue));
    printf("%d\n", dequeue_front(queue));
    printf("%d\n", dequeue_rear(queue));
    printf("%d\n", dequeue_rear(queue));
    printf("%d\n", dequeue_rear(queue));
    printf("%d\n", dequeue_rear(queue));
    printf("%d\n", dequeue_rear(queue));
    printQueue(queue);
    return 0;
}