#include <stdio.h>
#include <stdlib.h>

#define MAX_HEAP_SIZE 100

// max-heap
struct MaxHeap {
    int arr[MAX_HEAP_SIZE];
    int size;
};

// swap to repeahify
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

//heapify at index 
void maxHeapify(struct MaxHeap *heap, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < heap->size && heap->arr[left] > heap->arr[smallest])
        smallest = left;

    if (right < heap->size && heap->arr[right] > heap->arr[smallest])
        smallest = right;

    if (smallest != index) {
        swap(&heap->arr[index], &heap->arr[smallest]);
        maxHeapify(heap, smallest);
    }
}


void insert(struct MaxHeap *heap, int key) {
    if (heap->size == MAX_HEAP_SIZE) {
        printf("Heap is full. Cannot insert.\n");
        return;
    }

    int i = heap->size++;
    heap->arr[i] = key;


    while (i != 0 && heap->arr[(i - 1) / 2] < heap->arr[i]) {
        swap(&heap->arr[i], &heap->arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

//extractMin
int extractMin(struct MaxHeap *heap) {
    if (heap->size <= 0) {
        printf("Heap is empty. Cannot extract minimum.\n");
        return -1;
    }


    int max = heap->arr[0];


    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;


    maxHeapify(heap, 0);

    return max;
}


// show heap
void printHeap(struct MaxHeap *heap) {
    printf("Heap: ");
    for (int i = 0; i < heap->size; i++)
        printf("%d ", heap->arr[i]);
    printf("\n");
}

//duplicate values
void duplicates(struct MaxHeap *heap){
    for(int i=0;i<heap->size;i++){
        int ele=heap->arr[i];
        for(int j=0;j<heap->size;j++){
            if(i==j){
                continue;
            }
            else if(heap->arr[j]==ele){
                printf("Duplicate found at position %d \n" ,j);
            }
        }
    }
}


int main() {
    struct MaxHeap heap;
    heap.size = 0;

    // // Insert  keys into the heap
    // insert(&heap, 3);
    // insert(&heap, 2);
    // insert(&heap, 15);
    // insert(&heap, 5);
    // insert(&heap, 4);
    // insert(&heap, 45);
    // insert(&heap, 15);
    // insert(&heap, 5);

    int ips;
    printf("Enter the number of inputs: ");
    scanf("%d",&ips);
    for(int i=0;i<ips;i++){
        int vals;
        printf("Enter the value: ");
        scanf("%d",&vals);
        insert(&heap,vals);
    }

    printf("\n\nOriginal Heap: \n");
    printHeap(&heap);
    // printf("\n\nExample Extract Min: \n");
    // printf("Extracted Min: %d\n", extractMin(&heap));
    // printHeap(&heap);
    printf("\n\n Duplicates: \n");
    duplicates(&heap);


    return 0;
}
