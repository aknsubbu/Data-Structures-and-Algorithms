#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    int priority;
    struct Node * next;
};

struct Queue{
    struct Node * front;
    struct Node * rear;
};

struct Queue ** createPriorityQueue(int size){
    struct Queue **pq = (struct Queue **)malloc(sizeof(struct Queue *) * size);
    for (int i = 0; i < size; i++)
    {
        pq[i] = (struct Queue *)malloc(sizeof(struct Queue));
        pq[i]->front = NULL;
        pq[i]->rear = NULL;
    }
    return pq;
}

void enqueue(struct Queue **pq, int data, int priority){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    // empty check
    if (pq[priority]->front == NULL && pq[priority]->rear == NULL)
    {
        newNode->next = NULL;
        pq[priority]->front = newNode;
        pq[priority]->rear = newNode;
        return;
    }
    // non-empty
    pq[priority]->rear->next = newNode;
    pq[priority]->rear = newNode;
    return;
}

int dequeue(struct Queue **pq, int size){
    for(int i = 0; i < size; i++){
        if(pq[i]->front != NULL){
            struct Node *temp = pq[i]->front;
            int data = temp->data;
            pq[i]->front = pq[i]->front->next;
            free(temp);
            return data;
        }
    }
    printf("Queue is empty!\n");
    return -1;
}

void printQueue(struct Queue **pq, int size){
    for(int i = 0; i < size; i++){
        if(pq[i]->front == NULL){
            printf("Queue %d is empty\n", i);
            continue;
        }
        struct Node *temp = pq[i]->front;
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
    struct Queue **pq = createPriorityQueue(size);
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