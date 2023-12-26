#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#define left(i) (2*i+1)
#define right(i) (2*i+2)


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

    if(heap->arr[i]<heap->arr[left(i)] && heap->arr[i]<heap->arr[right(i)]) return;

    switch (heap->arr[left(i)]>heap->arr[right(i)])
    {
    case true:
        swap(heap->arr,i,left(i));
        percolateDown(heap,left(i));
        break;   
    default:
        swap(heap->arr,i,right(i));
        percolateDown(heap,right(i));
        break;
    }

    
}

void heapSort(int* arr, int size) {
    for (int i = size - 1; i > 0; i--) {
        swap(arr, 0, i);
        percolateDown(arr,i);
    }
}

void percolateUp(heap* heap,int i){
    // in correct position
    int prevIndex = (i-1)/2;
    if(prevIndex < 0 ) return;
    if(heap->last <= 0) return;
    if(heap->arr[i] < heap->arr[prevIndex]) return;
    printf("Hello World!\n");

    swap(heap->arr,i,prevIndex);
    i = prevIndex;
    percolateUp(heap,prevIndex);
    
}

void insert(heap* heap,int val){
    heap->arr[heap->last] = val;
    percolateUp(heap,heap->last);
    heap->last++;
}

heap* createHeap(int size){
    heap* new = (heap*)malloc(sizeof(heap));
    new->arr = (int*) calloc(size,sizeof(int));
    new->last = 0;
    return new;
}

void inorder(heap* heap,int i){
    printf("%d %d\n",left(i),right(i));
    if(heap->arr[left(i)] != 0) inorder(heap,left(i));
    printf("%d ",heap->arr[i]);
    if(heap->arr[right(i)] != 0) inorder(heap,right(i));
}

void inordernl(heap* heap){
    inorder(heap,0);
    printf("\n");
}


int extractMin(heap* heap){
    return heap->arr[0];
}

int main(){
    heap* heap1 = createHeap(15);
    insert(heap1,8);
    insert(heap1,1);
    insert(heap1,2);
    insert(heap1,7);
    insert(heap1,3);
    insert(heap1,4);
    insert(heap1,6);
    insert(heap1,5);
    for(int i = 0;i<15;i++) printf("%d ",heap1->arr[i]);
    // inordernl(heap1);
}