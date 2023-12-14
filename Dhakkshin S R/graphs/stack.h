#include <stdio.h>
#include <stdlib.h>

#define RED "\x1B[31m"
#define GREEN "\x1B[32m"
#define YELLOW "\x1B[33m"
#define RESET "\x1B[0m"

struct Stack
{
    int top;
    int* arr;
    int max;
};

struct Stack creatStack(int size);
void push(struct Stack* a, int data);
int pop(struct Stack* a);
void peek(struct Stack* a);
void display(struct Stack* a);


// using arrays
void push(struct Stack* a, int data)
{
    if (a->top == a->max-1)
    {
        printf(RED "Overflow!!\n" RESET);
        return;
    }
    else
    {
        a->top = a->top + 1;
        a->arr[a->top] = data;
        return;
    }
}

int pop(struct Stack* a)
{
    if (a->top == -1)
    {
        printf(RED "Underflow!!\n" RESET);
        //return -1;
    }
    else
    {
        int z =  a->arr[a->top];
        a->top = a->top - 1;
        return z;
    }
}

void peek(struct Stack* a)
{
    if (a->top == -1)
    {
        printf(RED "Underflow!!\n" RESET); 
    }
    else
    {
        printf("The top element is: ");
        printf(GREEN "%d\n" RESET, a->arr[a->top]);
    }
}

void display(struct Stack* a)
{
    if (a->top == -1)
    {
        printf(RED "Underflow!!\n" RESET); 
        return;
    }
    else
    {
        for (int i = a->top; i >= 0; i--)
        {
            printf(GREEN "| %d |\n" RESET, a->arr[i]);
        }
        printf(GREEN "|___|\n" RESET);
        return;
    }
}
// create stack
struct Stack creatStack(int size)
{
    struct Stack a;
    a.arr = (int*)malloc(sizeof(int) * size);
    a.top = -1;
    a.max = size;
    return a;
}

