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


int main(void)
{
    printf("Enter the size of the stack: ");
    int size;
    scanf("%d", &size);
    struct Stack stack = creatStack(size);
    struct Stack* stackPTR = &stack;

    // while loop with switch case for menu until user exits
    int choice;
    while(1)
    {
        printf("\nEnter 1 to push, 2 to pop, 3 to peek, 4 display, 5 to to exit: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the element to push: ");
            int data;
            scanf("%d", &data);
            push(stackPTR, data);
            break;
        case 2:
            printf("The popped element is: ");
            printf(GREEN "%d\n" RESET, pop(stackPTR));
            break;
        case 3:
            peek(stackPTR);
            break;
        case 4:
            display(stackPTR);
            break;
        case 5:
            printf("Exiting...\n");
            return 0;
            break;
        default:    
            printf(YELLOW "Invalid choice!!\n" RESET);
            break;
        }
    }

}

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
    a.arr = malloc(sizeof(int) * size);
    a.top = -1;
    a.max = size;
    return a;
}

