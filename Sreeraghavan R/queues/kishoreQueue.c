#include <stdio.h>
#include <stdlib.h>

void enqueue(int *arr, int *front, int *rear, int data, int size)
{
    // empty check
    if (*front == -1 && *rear == -1)
    {
        arr[0] = data;
        *front = 0;
        *rear = 0;
        return;
    }
    // overflow
    if ((*front == 0 && *rear == size - 1) || (*front - *rear == 1))
    {
        printf("Overflow!\n");
        return;
    }
    // not overflow, but rear is at end
    if (*rear == size - 1)
    {
        *rear = 0;
        arr[*rear] = data;
        return;
    }
    // normal case
    arr[++(*rear)] = data;
    return;
}

int dequeue(int *arr, int *front, int *rear, int size)
{
    // empty check
    if (*front == -1 && *rear == -1)
    {
        printf("Empty queue\n");
        return -999999; // This is a dummy variable to differentiate a success vs a failure
    }
    // one element
    if (*front == *rear)
    {
        int data = arr[*front];
        *front = -1;
        *rear = -1;
        return data;
    }
    // front at end
    if (*front == size - 1)
    {
        int data = arr[*front];
        *front = 0;
        return data;
    }
    // normal case
    return arr[(*front)++];
}

void printArray(int *arr, int front, int rear)
{
    int size = sizeof(arr) / sizeof(int);
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

int main()
{
    int *queue = (int *)malloc(5 * sizeof(int));
    int front = -1, rear = -1;
    enqueue(queue, &front, &rear, 1, 5);
    printArray(queue, front, rear);
    enqueue(queue, &front, &rear, 2, 5);
    printArray(queue, front, rear);
    enqueue(queue, &front, &rear, 3, 5);
    printArray(queue, front, rear);
    enqueue(queue, &front, &rear, 4, 5);
    printArray(queue, front, rear);
    enqueue(queue, &front, &rear, 5, 5);
    printArray(queue, front, rear);
    enqueue(queue, &front, &rear, 6, 5);
    printArray(queue, front, rear);
    printf("dequeued: %d\n", dequeue(queue, &front, &rear, 5));
    printArray(queue, front, rear);
    printf("dequeued: %d\n", dequeue(queue, &front, &rear, 5));
    printArray(queue, front, rear);
    printf("dequeued: %d\n", dequeue(queue, &front, &rear, 5));
    printArray(queue, front, rear);
    printf("dequeued: %d\n", dequeue(queue, &front, &rear, 5));
    printArray(queue, front, rear);
    printf("dequeued: %d\n", dequeue(queue, &front, &rear, 5));
    printArray(queue, front, rear);
    printf("dequeued: %d\n", dequeue(queue, &front, &rear, 5));
    printArray(queue, front, rear);
    enqueue(queue, &front, &rear, 6, 5);
    printArray(queue, front, rear);
    enqueue(queue, &front, &rear, 7, 5);
    printArray(queue, front, rear);

    return 0;
}