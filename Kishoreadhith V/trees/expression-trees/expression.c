#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node * getNode(int data){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}



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
