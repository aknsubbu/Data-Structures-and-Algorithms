#include <stdio.h>
#include <stdlib.h>

#define MAX_HEAP_SIZE 100

// min-heap
struct MinHeap {
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
void minHeapify(struct MinHeap *heap, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < heap->size && heap->arr[left] < heap->arr[smallest])
        smallest = left;

    if (right < heap->size && heap->arr[right] < heap->arr[smallest])
        smallest = right;

    if (smallest != index) {
        swap(&heap->arr[index], &heap->arr[smallest]);
        minHeapify(heap, smallest);
    }
}


void insert(struct MinHeap *heap, int key) {
    if (heap->size == MAX_HEAP_SIZE) {
        printf("Heap is full. Cannot insert.\n");
        return;
    }

    int i = heap->size++;
    heap->arr[i] = key;


    while (i != 0 && heap->arr[(i - 1) / 2] > heap->arr[i]) {
        swap(&heap->arr[i], &heap->arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

//extractMin
int extractMin(struct MinHeap *heap) {
    if (heap->size <= 0) {
        printf("Heap is empty. Cannot extract minimum.\n");
        return -1;
    }


    int min = heap->arr[0];


    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;


    minHeapify(heap, 0);

    return min;
}

// Function to delete a key at a given index from the heap
void deleteKey(struct MinHeap *heap, int index) {
    if (index >= heap->size) {
        printf("Index out of range. Cannot delete key.\n");
        return;
    }


    while (index != 0 && heap->arr[(index - 1) / 2] > heap->arr[index]) {
        swap(&heap->arr[index], &heap->arr[(index - 1) / 2]);
        index = (index - 1) / 2;
    }

    extractMin(heap);
}

// show heap
void printHeap(struct MinHeap *heap) {
    printf("Heap: ");
    for (int i = 0; i < heap->size; i++)
        printf("%d ", heap->arr[i]);
    printf("\n");
}

int main() {
    struct MinHeap heap;
    heap.size = 0;

    // Insert  keys into the heap
    insert(&heap, 3);
    insert(&heap, 2);
    insert(&heap, 15);
    insert(&heap, 5);
    insert(&heap, 4);
    insert(&heap, 45);

    printHeap(&heap);

    printf("Extracted Min: %d\n", extractMin(&heap));

    printHeap(&heap);

    deleteKey(&heap, 2);

    printHeap(&heap);

    return 0;
}
