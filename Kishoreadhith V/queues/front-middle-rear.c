#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};

typedef struct {
    struct Node *front;
    struct Node *middle;
    struct Node *back;
    int size;
} FrontMiddleBackQueue;

struct Node* getNode(int data){
    struct Node *node = (struct Node*) malloc (sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

FrontMiddleBackQueue* frontMiddleBackQueueCreate() {
    FrontMiddleBackQueue *queue = (FrontMiddleBackQueue*) malloc (sizeof(FrontMiddleBackQueue));
    queue->front = NULL;
    queue->middle = NULL;
    queue->back = NULL;
    queue->size = 0;
    return queue;
}

void setMiddle(FrontMiddleBackQueue *queue){
    int mid = queue->size / 2;
    struct Node *temp = queue->front;
    for(int i = 1; i < mid; i++){
        temp = temp->next;
    }
    queue->middle = temp;
    return;
}

void frontMiddleBackQueuePushFront(FrontMiddleBackQueue* obj, int val) {
    struct Node *node = getNode(val);
    if(obj->front == NULL){
        obj->front = node;
        obj->middle = node;
        obj->back = node;
    }
    else{
        obj->front->prev = node;
        node->next = obj->front;
        obj->front = node;
    }
    obj->size++;
    setMiddle(obj);
}

void frontMiddleBackQueuePushMiddle(FrontMiddleBackQueue* obj, int val) {
    struct Node *node = getNode(val);
    if(obj->front == NULL){
        obj->front = node;
        obj->middle = node;
        obj->back = node;
    } else if(obj->size < 3){
        obj->front->next = node;
        node->prev = obj->front;
        obj->back = node;
    } else {
        if(obj->middle != NULL) {
            obj->middle->prev->next = node;
            node->prev = obj->middle->prev;
            node->next = obj->middle;
            obj->middle->prev = node;
        }
    }
    obj->size++;
    setMiddle(obj);
}

void frontMiddleBackQueuePushBack(FrontMiddleBackQueue* obj, int val) {
    struct Node *node = getNode(val);
    if(obj->front == NULL){
        obj->front = node;
        obj->middle = node;
        obj->back = node;
    }
    else{
        obj->back->next = node;
        node->prev = obj->back;
        obj->back = node;
    }
    obj->size++;
    setMiddle(obj);
}

int frontMiddleBackQueuePopFront(FrontMiddleBackQueue* obj) {
    if(obj->front == NULL){
        printf("Underflow!\n");
        return -1;
    }
    int data = obj->front->data;
    struct Node *temp = obj->front;
    obj->front = obj->front->next;
    if(obj->front == NULL){
        obj->middle = NULL;
        obj->back = NULL;
    }
    else{
        obj->front->prev = NULL;
    }
    free(temp);
    obj->size--;
    setMiddle(obj);
    return data;
}

int frontMiddleBackQueuePopMiddle(FrontMiddleBackQueue* obj) {
    if(obj->front == NULL){
        printf("Underflow!\n");
        return -1;
    }
    int data = obj->middle->data;
    struct Node *temp = obj->middle;
    obj->middle->prev->next = obj->middle->next;
    obj->middle->next->prev = obj->middle->prev;
    free(temp);
    obj->size--;
    setMiddle(obj);
    return data;
}

int frontMiddleBackQueuePopBack(FrontMiddleBackQueue* obj) {
    if(obj->front == NULL){
        printf("Underflow!\n");
        return -1;
    }
    int data = obj->back->data;
    struct Node *temp = obj->back;
    obj->back = obj->back->prev;
    if(obj->back == NULL){
        obj->front = NULL;
        obj->middle = NULL;
    }
    else{
        obj->back->next = NULL;
    }
    free(temp);
    obj->size--;
    setMiddle(obj);
    return data;
}

void frontMiddleBackQueueFree(FrontMiddleBackQueue* obj) {
    free(obj);
}

/**
 * Your FrontMiddleBackQueue struct will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = frontMiddleBackQueueCreate();
 * frontMiddleBackQueuePushFront(obj, val);
 
 * frontMiddleBackQueuePushMiddle(obj, val);
 
 * frontMiddleBackQueuePushBack(obj, val);
 
 * int param_4 = frontMiddleBackQueuePopFront(obj);
 
 * int param_5 = frontMiddleBackQueuePopMiddle(obj);
 
 * int param_6 = frontMiddleBackQueuePopBack(obj);
 
 * frontMiddleBackQueueFree(obj);
*/