//deque using array

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int deque[MAX_SIZE];

int front = -1, rear = -1;

void enqueue_front(int x)
{
    if ((front == 0 && rear == MAX_SIZE - 1) || (front == rear + 1))
    {
        printf("queue is full\n");
        return;
    }
    if (front == -1 && rear == -1)
    {
        front = rear = 0;
    }
    else if (front == 0)
    {
        front = MAX_SIZE - 1;
    }
    else
    {
        front--;
    }
    deque[front] = x;
}

void enqueue_rear(int x)
{
    if ((front == 0 && rear == MAX_SIZE - 1) || (front == rear + 1))
    {
        printf("queue is full\n");
        return;
    }
    if (front == -1 && rear == -1)
    {
        front = rear = 0;
    }
    else if (rear == MAX_SIZE - 1)
    {
        rear = 0;
    }
    else
    {
        rear++;
    }
    deque[rear] = x;
}

void dequeue_front()
{
    if (front == -1 && rear == -1)
    {
        printf("queue is empty\n");
        return;
    }
    if (front == rear)
    {
        front = rear = -1;
    }
    else if (front == MAX_SIZE - 1)
    {
        front = 0;
    }
    else
    {
        front++;
    }
}

void dequeue_rear()
{
    if (front == -1 && rear == -1)
    {
        printf("queue is empty\n");
        return;
    }
    if (front == rear)
    {
        front = rear = -1;
    }
    else if (rear == 0)
    {
        rear = MAX_SIZE - 1;
    }
    else
    {
        rear--;
    }
}

void display()
{
    int i;
    if (front == -1 && rear == -1)
    {
        printf("queue is empty\n");
        return;
    }
    if (front <= rear)
    {
        for (i = front; i <= rear; i++)
        {
            printf("%d ", deque[i]);
        }
    }
    else
    {
        for (i = front; i < MAX_SIZE; i++)
        {
            printf("%d ", deque[i]);
        }
        for (i = 0; i <= rear; i++)
        {
            printf("%d ", deque[i]);
        }
    }
    printf("\n");
}

int main()
{
    int ch, x;
    while (1)
    {
        printf("1.enqueue_front\n");
        printf("2.enqueue_rear\n");
        printf("3.dequeue_front\n");
        printf("4.dequeue_rear\n");
        printf("5.display\n");
        printf("6.exit\n");
        printf("enter your choice\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("enter the element to be inserted\n");
            scanf("%d", &x);
            enqueue_front(x);
            break;
        case 2:
            printf("enter the element to be inserted\n");
            scanf("%d", &x);
            enqueue_rear(x);
            break;
        case 3:
            dequeue_front();
            break;
        case 4:
            dequeue_rear();
            break;
        case 5:
            display();
            break;
        case 6:
            exit(0);
        default:
            printf("invalid choice\n");
        }
    }
    return 0;
}