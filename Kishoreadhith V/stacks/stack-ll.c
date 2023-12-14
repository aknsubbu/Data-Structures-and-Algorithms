#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Stack{
    struct Node *top;
    int size;
};

struct Stack* createStack(){
    struct Stack *stack = (struct Stack*) malloc (sizeof(struct Stack));
    stack->top = NULL;
    stack->size = 0;
    return stack;
}

void push(struct Stack *stack, int data){
    struct Node *node = (struct Node*) malloc (sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    if(stack->top == NULL){
        stack->top = node;
    }
    else{
        stack->top->next = node;
        node->prev = stack->top;
        stack->top = node;
    }
    stack->size++;
    return;
}

int pop(struct Stack *stack){
    if(stack->top == NULL){
        printf("Underflow!\n");
        return -1;
    }
    int data = stack->top->data;
    struct Node *temp = stack->top;
    stack->top = stack->top->prev;
    free(temp);
    stack->size--;
    return data;
}

void printStack(struct Stack *stack){
    struct Node *temp = stack->top;
    while (temp != NULL)
    {
        printf("|%d| \n", temp->data);
        temp = temp->prev;
    }
    printf("---\n");
    return;
}

int main(){
    struct Stack *stack = createStack();
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    printStack(stack);
    printf("%d\n", pop(stack));
    printf("%d\n", pop(stack));
    printf("%d\n", pop(stack));
    printf("%d\n", pop(stack));
    printStack(stack);
    return 0;
}