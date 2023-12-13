#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct heap{
    int* arr;
    int last;
};

typedef struct heap heap;

void swap(int*l, int i, int j){
    int temp = l[i];
    l[i] = l[j];
    l[j] = temp;
}


void percolateDown(heap* heap,int i){

    //already a heap
    if(heap->arr[i]>heap->arr[2*i+1] && heap->arr[i]>heap->arr[2*i+2]) return;

    switch (heap->arr[2*i+1]>heap->arr[2*i+2])
    {
    case true:
        swap(heap->arr,i,2*i+1);
        percolateDown(heap,2*i+1);
        break;   
    default:
        swap(heap->arr,i,2*i+2);
        percolateDown(heap,2*i+2);
        break;
    }

    
}

void percolateUp(int* heap,int i){
    // in correct position
    int prevIndex = (i-1)/2;
    if(heap[i] < heap[prevIndex]) return;
    else{
        swap(heap,i,prevIndex);
        percolateUp(heap,prevIndex);
    }
}


void insert(int* heap,int val){
    int lastIndex = lastIndex(heap);
    
}

int lastIndex(int* heap){
    int j = 0;
    int size = sizeof(heap)/sizeof(int);
    for(int i = 0;i<size;i++){
        if(heap[i] != 0){
            j = i;
        }
    }
    return j;
}

int parentIndex(int i){
    return (i-1)/2;
}

int nextPos(int* heap){
    
}

