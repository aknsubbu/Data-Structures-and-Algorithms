#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node * next;
};

struct Queue{
    struct Node * front;
    struct Node * rear;
};

struct Queue * createQueue(){
    struct Queue * q = (struct Queue *)malloc(sizeof(struct Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

void enqueue_front(struct Queue * queue, int data){
    struct Node * newNode = (struct Node *)malloc(sizeof(struct Node));
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

void enqueue_rear(struct Queue * queue, int data){
    struct Node * newNode = (struct Node *)malloc(sizeof(struct Node));
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

int dequeue_front(struct Queue * queue){
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

int dequeue_rear(struct Queue * queue){
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
    struct Node * temp = queue->front;
    while (temp->next != queue->rear)
    {
        temp = temp->next;
    }
    temp->next = NULL;
    queue->rear = temp;
    return data;
}

void printQueue(struct Queue * queue){
    if(queue->front == NULL && queue->rear == NULL){
        printf("Empty queue\n");
        return;
    }
    struct Node * temp = queue->front;
    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    struct Queue * queue = createQueue();
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