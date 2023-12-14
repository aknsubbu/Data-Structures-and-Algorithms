//avl tree

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left,*right;
};

struct node *stack[20];

int top=-1;

void push(struct node *temp)
{
    stack[++top]=temp;
}

struct node *pop()
{
    return(stack[top--]);
}

