#include <stdio.h>
#include <stdlib.h>
#define RED "\x1B[31m"
#define GREEN "\x1B[32m"
#define YELLOW "\x1B[33m"
#define RESET "\x1B[0m"

struct queue
{
    int* arr;
    int front;
    int rear;
    int max;
};


void enqueue(struct queue* a, int data)
{
    a->rear = (a->rear + 1) % a->max;

    if (a->rear != a->front)
    {
        a->arr[a->rear] = data;
    }
    else
    {
        printf(RED "OverFlow\n" RESET);
    }
}

void display(struct queue* a)
{
    if (a->front == -1)
    {
        printf(RED "Underflow!!\n" RESET); 
        return;
    }
    else
    {
        int front = a->front, rear = a->rear;

        for (front; front != rear; front = (front + 1 % a->max))
        {
            printf(GREEN "| %d |\n" RESET, a->arr[front]);
        }
        printf(GREEN "|___|\n" RESET);
        return;
    }
}

struct queue createQueue(int size)
{
    struct queue a;
    a.arr = malloc(sizeof(int) * size);
    a.front = -1;
    a.rear = -1;
    a.max = size;
    return a;
}

int main(void)
{

}