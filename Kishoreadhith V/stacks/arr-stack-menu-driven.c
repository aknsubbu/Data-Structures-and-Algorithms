#include <stdio.h>
#include <stdlib.h>

void push(int * arr, int * top, int data, int size){
    if(*top >= size - 1){
        printf("Overflow!\n");
        return;
    }
    arr[++(*top)] = data;
    return;
}

int pop(int * arr, int * top){
    if(*top == -1){
        printf("Underflow!\n");
        return -99999999;
    }
    return arr[(*top)--];
}

void printArray(int * arr, int top){
    if(top == -1){
        printf("Stack is empty\n");
        return;
    }
    for(int i = 0; i <= top; i++){
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

int main() {
    int stack_size = 50;
    int * stack = (int *) malloc (stack_size * sizeof(int));
    int top = -1;
    int choice;
    printf("---\n");
    printf("1 - push and print\n");
    printf("2 - pop and print\n");
    printf("3 - exit\n");
    printf("---\n");
    do{
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("---\n");
        switch(choice){
            case 1:
                printf("Enter number to push: ");
                int val;
                scanf("%d", &val);
                push(stack, &top, val, stack_size);
                printArray(stack, top);
                break;
            case 2:
                printf("Popped element: %d\n", pop(stack, &top));
                printArray(stack, top);
                break;
            case 3:
                printf("exit\n");
                break;
        }
        
    } while (choice != 3);
}