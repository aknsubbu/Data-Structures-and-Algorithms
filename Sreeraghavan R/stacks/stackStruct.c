#include <stdio.h>
#include <stdlib.h>

struct stknode{
    int data;
    struct stknode* below;
};

typedef struct stknode stknode;

int isEmpty(stknode* s){
    return !s;
}

stknode* getNode(int val){
    stknode* newNode = (stknode *)malloc(sizeof(stknode));
    newNode->data = val;
    newNode->below = NULL;
    return newNode;
}

stknode* push(stknode* s,int val){
    stknode* new = getNode(val);
    new->below = s;
    return new;
}

void print(stknode* s){
    stknode* iter = s;
    while(iter){
        printf("%d ",iter->data);
        iter = iter->below;
    }
}


int pop(stknode* s){
    if(isEmpty(s)){
        printf("UNDERFLOW\n");
        return -999999;
    }
    int tbReturned = s->data;
    s = s->below;
    return tbReturned;
}





