//stacks using queues

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int queue[MAX_SIZE];

int front = -1, rear = -1;

void enqueue(int x)
{
    if (rear == MAX_SIZE - 1)
    {
        printf("queue is full\n");
        return;
    }
    if (front == -1 && rear == -1)
    {
        front = rear = 0;
    }
    else
    {
        rear++;
    }
    queue[rear] = x;
}

void dequeue()
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
    else
    {
        front++;
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
    for (i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

void push(int x)
{
    enqueue(x);
}

void pop()
{
    int i, x;
    if (front == -1 && rear == -1)
    {
        printf("stack is empty\n");
        return;
    }
    for (i = front; i < rear; i++)
    {
        enqueue(queue[i]);
    }
    x = queue[rear];
    dequeue();
    for (i = front; i < rear; i++)
    {
        enqueue(queue[i]);
    }
}

void display_stack()
{
    int i;
    if (front == -1 && rear == -1)
    {
        printf("stack is empty\n");
        return;
    }
    for (i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main()
{
    int ch, x;
    while (1)
    {
        printf("1.push\n");
        printf("2.pop\n");
        printf("3.display\n");
        printf("4.exit\n");
        printf("enter your choice\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("enter the element to be pushed\n");
            scanf("%d", &x);
            push(x);
            break;
        case 2:
            pop();
            break;
        case 3:
            display_stack();
            break;
        case 4:
            exit(0);
        default:
            printf("invalid choice\n");
        }
    }
    return 0;
}
