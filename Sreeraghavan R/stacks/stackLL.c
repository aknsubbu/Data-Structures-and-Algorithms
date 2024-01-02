#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct node{
    int data;
    struct node* below;
};

typedef struct node node;

int isEmpty(node* s){
    return !s;
}

node* getNode(int val){
    node* newNode = (node *)malloc(sizeof(node));
    newNode->data = val;
    newNode->below = NULL;
    return newNode;
}

node* push(node* s,int val){
    node* new = getNode(val);
    new->below = s;
    return new;
}

void print(node* s){
    node* iter = s;
    while(iter){
        printf("%d ",iter->data);
        iter = iter->below;
    }
}


int pop(node* s){
    if(isEmpty(s)){
        printf("UNDERFLOW\n");
        return -999999;
    }
    int tbReturned = s->data;
    s = s->below;
    return tbReturned;
}

int main(){
    node* s = getNode(0);
    s = push(s,1);
    s = push(s,2);
    s = push(s,3);
    printf("%d\n",pop(s));
    s = push(s,4);
    print(s);
}