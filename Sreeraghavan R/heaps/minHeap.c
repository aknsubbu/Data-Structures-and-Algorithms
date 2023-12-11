#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>



enum typeChild = {LEFT, RIGHT};
enum typeNode = {BOTH,LEFT,RIGHT,NONE};

void swap(int*l, int i, int j){
    int temp = l[i];
    l[i] = l[j];
    l[j] = temp;
}

int childType(int i){
    if(i%2 == 1) return LEFT;
    return RIGHT;
}

void percolateDown(int* heap,int i){

    //already a heap
    if(heap[i]>heap[2*i+1] && heap[i]>heap[2*i+2]) return;

    switch (heap[2*i+1]>heap[2*i+2])
    {
    case true:
        swap(heap,i,2*i+1);
        percolateDown(heap,2*i+1);
        break;   
    default:
        swap(heap,i,2*i+2);
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
        i = prevIndex;
        percolateUp(heap,prevIndex);
    }
}

void insert(int* heap,int val){
    heap[heap->last] = val;
    percolateUp(heap,heap->last);
    heap->last = 2*(heap->last)+1;
}

int* createHeap(){
    int* newheap = (int*) malloc(sizeof(heap));
    return newheap;
}

void inorder(int* heap,int i){
    if(heap[2*i+1] != 0) inorder(heap,2*i+1);
    printf("%d ",heap[i]);
    if(heap[2*i+2] != 0) inorder(heap,2*i+2);
}

void inordernl(int* heap){
    inorder(heap,0);
    printf("\n");
}

void deleteMin(int* heap) {
    if (heap->last == 0) {
        printf("Heap is empty. Nothing to delete.\n");
        return;
    }

    swap(heap, 0, heap->last);
    heap->last--;

    percolateDown(heap, 0);

    free(&heap[heap->last + 1]);
}

int extractMin(int* heap){
    return heap[0];
}

int main(){
    int* heap1 = createHeap();
    insert(heap1,1);
    insert(heap1,2);
    insert(heap1,3);
    insert(heap1,4);
    insert(heap1,5);
    insert(heap1,6);
    insert(heap1,7);
    insert(heap1,8);
    inordernl(heap1);
    for(int i = 0;i<8;i++) printf("%d ",heap1->arr[i]);
}
