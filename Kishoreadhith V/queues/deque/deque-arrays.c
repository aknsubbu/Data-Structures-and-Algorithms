#include <stdio.h>
#include <stdlib.h>

void enqueue_front(int *queue, int *front, int *rear, int data, int size){
    // empty check
    if (*front == -1 && *rear == -1)
    {
        queue[0] = data;
        *front = 0;
        *rear = 0;
        return;
    }
    //overflow
    if((*front == 0 && *rear == size - 1) || (*front - *rear == 1)){
        printf("Overflow!\n");
        return;
    }
    // not overflow, but front is at start
    if(*front == 0){
        *front = size - 1;
        queue[*front] = data;
        return;
    }
    // normal case
    queue[--(*front)] = data;
}

void enqueue_rear(int *queue, int *front, int *rear, int data, int size){
    // empty check
    if (*front == -1 && *rear == -1)
    {
        queue[0] = data;
        *front = 0;
        *rear = 0;
        return;
    }
    //overflow
    if((*front == 0 && *rear == size - 1) || (*front - *rear == 1)){
        printf("Overflow!\n");
        return;
    }
    // not overflow, but rear is at end
    if(*rear == size - 1){
        *rear = 0;
        queue[*rear] = data;
        return;
    }
    // normal case
    queue[++(*rear)] = data;
}

int dequeue_front(int *queue, int *front, int *rear, int size){
    // empty check
    if (*front == -1 && *rear == -1)
    {
        printf("Empty queue\n");
        return -999999;
    }
    // one element
    if (*front == *rear)
    {
        int data = queue[*front];
        *front = -1;
        *rear = -1;
        return data;
    }
    // front at end
    if (*front == size - 1)
    {
        int data = queue[*front];
        *front = 0;
        return data;
    }
    //normal case
    return queue[(*front)++];
}

int dequeue_rear(int *queue, int *front, int *rear, int size){
    // empty check
    if (*front == -1 && *rear == -1)
    {
        printf("Empty queue\n");
        return -999999;
    }
    // one element
    if (*front == *rear)
    {
        int data = queue[*front];
        *front = -1;
        *rear = -1;
        return data;
    }
    // rear at start
    if (*rear == 0)
    {
        int data = queue[*rear];
        *rear = size - 1;
        return data;
    }
    //normal case
    return queue[(*rear)--];
}

void printArray(int * arr, int front, int rear, int size){
    if (front == -1 && rear == -1)
    {
        printf("Empty queue\n");
        return;
    }
    if (rear < front)
    {
        for (int i = front; i < size; i++)
        {
            printf("%d\t", arr[i]);
        }
        for (int i = 0; i <= rear; i++)
        {
            printf("%d\t", arr[i]);
        }
        printf("\n");
        return;
    }
    for (int i = front; i <= rear; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

int main(){
    // menu driven
    int size;
    printf("Enter size of queue: ");
    scanf("%d", &size);
    int * queue = (int *) malloc (size * sizeof(int));
    int front = -1, rear = -1;
    int choice = 0;
    while (choice != 5)
    {
        printf("1. Enqueue front\n2. Enqueue rear\n3. Dequeue front\n4. Dequeue rear\n5. Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter data: ");
            int data;
            scanf("%d", &data);
            enqueue_front(queue, &front, &rear, data, size);
            break;
        case 2:
            printf("Enter data: ");
            scanf("%d", &data);
            enqueue_rear(queue, &front, &rear, data, size);
            break;
        case 3:
            printf("Dequeued %d\n", dequeue_front(queue, &front, &rear, size));
            break;
        case 4:
            printf("Dequeued %d\n", dequeue_rear(queue, &front, &rear, size));
            break;
        case 5:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
        printArray(queue, front, rear, size);
    }
    return 0;
}