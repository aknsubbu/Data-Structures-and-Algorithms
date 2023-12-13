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

void enqueue(struct Queue * queue, int data){
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

int dequeue(struct Queue * queue){
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

void printQueue(struct Queue * queue){
    if(queue->front == NULL && queue->rear == NULL){
        printf("Empty queue\n");
        return;
    }
    struct Node * temp = queue->front;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    struct Queue * queue = createQueue();
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    printQueue(queue);
    printf("dequeued: %d\n", dequeue(queue));
    printQueue(queue);
    printf("dequeued: %d\n", dequeue(queue));
    printQueue(queue);
    printf("dequeued: %d\n", dequeue(queue));
    printQueue(queue);
    printf("dequeued: %d\n", dequeue(queue));
    printQueue(queue);
    return 0;
}