#include <stdio.h>
#include <stdlib.h>

void enqueue(int *queue, int *front, int *rear, int size, int data){
    if(*rear == size - 1){
        printf("Queue is full!\n");
        return;
    }
    if(*front == -1){
        *front = 0;
    }
    *rear = *rear + 1;
    queue[*rear] = data;
    return;
}

int dequeue(int *queue, int *front, int *rear){
    if(*front == -1){
        printf("Queue is empty!\n");
        return -1;
    }
    int data = queue[*front];
    if(*front == *rear){
        *front = -1;
        *rear = -1;
    }
    else{
        *front = *front + 1;
    }
    return data;
}

void push(int *stack, int *top, int size, int data){
    if(*top == size - 1){
        printf("Stack is full!\n");
        return;
    }
    *top = *top + 1;
    stack[*top] = data;
    return;
}

int pop(int *stack, int *top){
    if(*top == -1){
        printf("Stack is empty!\n");
        return -1;
    }
    int data = stack[*top];
    *top = *top - 1;
    return data;
}

int countStudents(int* students, int studentsSize, int* sandwiches, int sandwichesSize) {
    int front = 0;
    int rear = studentsSize - 1;
    int top = -1;
    int *stack = (int *)malloc(sizeof(int) * sandwichesSize);
    for(int i = sandwichesSize - 1; i >= 0; i--){
        push(stack, &top, sandwichesSize, sandwiches[i]);
    }
    int count = 0;
    while (count < studentsSize)
    {
        if(students[front] == stack[top]){
            pop(stack, &top);
            dequeue(students, &front, &rear);
            studentsSize--;
        }
        else{
            enqueue(students, &front, &rear, studentsSize, dequeue(students, &front, &rear));
        }
        count++;
    }
    return studentsSize;
}

int firstUniqChar(char* s) {
    int len = strlen(s);
    int *arr = (int *)calloc(sizeof(int) * 26);
    int *queue = (int *)malloc(sizeof(int) * len);
    int front = -1;
    int rear = -1;
    for(int i = 0; i < len; i++){
        if(arr[s[i] - 'a'] == 1){
            enqueue(queue, &front, &rear, len, s[i] - 'a');
        }
    }

}