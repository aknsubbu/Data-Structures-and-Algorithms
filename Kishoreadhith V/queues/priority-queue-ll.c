#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node * next;
};

typedef struct node node;

struct Queue{
    node * front;
    node * rear;
};

typedef struct Queue Queue;


Queue ** createPriorityQueue(int size){
    Queue **pq = (Queue **)malloc(sizeof(Queue *) * size);
    for (int i = 0; i < size; i++)
    {
        pq[i] = (Queue *)malloc(sizeof(Queue));
        pq[i]->front = NULL;
        pq[i]->rear = NULL;
    }
    return pq;
}

void enqueue(Queue **pq, int data, int priority){
    node *new = (node *)malloc(sizeof(node));
    new->data = data;
    if (pq[priority]->front == NULL && pq[priority]->rear == NULL)
    {
        new->next = NULL;
        pq[priority]->front = new;
        pq[priority]->rear = new;
        return;
    }
    pq[priority]->rear->next = new;
    pq[priority]->rear = new;
    return;
}

int dequeue(Queue **pq, int size){
    for(int i = 0; i < size; i++){
        if(pq[i]->front != NULL){
            node *temp = pq[i]->front;
            int data = temp->data;
            pq[i]->front = pq[i]->front->next;
            free(temp);
            return data;
        }
    }
    printf("EMPTY QUEUE\n");
    return -999999;
}

void printQueue(Queue **pq, int size){
    for(int i = 0; i < size; i++){
        if(pq[i]->front == NULL){
            printf("Queue %d is empty\n", i);
            continue;
        }
        node *temp = pq[i]->front;
        while(temp != NULL){
            printf("%d\t", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main(){
    int size, data, priority, choice;
    printf("Enter the number of queues: ");
    scanf("%d", &size);
    Queue **pq = createPriorityQueue(size);
    while (1)
    {
        printf("1. Enqueue\n2. Dequeue\n3. Print\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter data and priority: ");
            scanf("%d %d", &data, &priority);
            enqueue(pq, data, priority);
            break;
        case 2:
            printf("Dequeued %d\n", dequeue(pq, size));
            break;
        case 3:
            printQueue(pq, size);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice!\n");
            break;
        }
    }
    return 0;
}