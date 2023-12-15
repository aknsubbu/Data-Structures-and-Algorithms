#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Heap {
    int arr[MAX_SIZE];
    int size;
};

void initHeap(struct Heap* heap) {
    heap->size = 0;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(struct Heap* heap, int index) {
    while (index > 0) {
        int parentIndex = (index - 1) / 2;
        if (heap->arr[index] > heap->arr[parentIndex]) {
            swap(&heap->arr[index], &heap->arr[parentIndex]);
            index = parentIndex;
        } else {
            break;
        }
    }
}

void heapifyDown(struct Heap* heap, int index) {
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;
    int largest = index;

    if (leftChild < heap->size && heap->arr[leftChild] > heap->arr[largest]) {
        largest = leftChild;
    }

    if (rightChild < heap->size && heap->arr[rightChild] > heap->arr[largest]) {
        largest = rightChild;
    }

    if (largest != index) {
        swap(&heap->arr[index], &heap->arr[largest]);
        heapifyDown(heap, largest);
    }
}

void insert(struct Heap* heap, int value) {
    if (heap->size < MAX_SIZE) {
        heap->arr[heap->size] = value;
        heapifyUp(heap, heap->size);
        heap->size++;
    } else {
        printf("Heap is full. Cannot insert.\n");
    }
}

int extractMax(struct Heap* heap) {
    if (heap->size > 0) {
        int maxValue = heap->arr[0];
        heap->arr[0] = heap->arr[heap->size - 1];
        heap->size--;
        heapifyDown(heap, 0);
        return maxValue;
    } else {
        printf("Heap is empty. Cannot extract max.\n");
        return -1;
    }
}

int extractMin(struct Heap* heap) {
    if (heap->size > 0) {
        int minValue = heap->arr[heap->size - 1];
        heap->size--;
        heapifyDown(heap, 0);
        return minValue;
    } else {
        printf("Heap is empty. Cannot extract min.\n");
        return -1;
    }
}

void deleteElement(struct Heap* heap, int value) {
    int i;
    for (i = 0; i < heap->size; i++) {
        if (heap->arr[i] == value) {
            break;
        }
    }

    if (i == heap->size) {
        printf("Element not found in the heap.\n");
        return;
    }

    heap->arr[i] = heap->arr[heap->size - 1];
    heap->size--;

    heapifyDown(heap, i);
    heapifyUp(heap, i);
}

void heapSort(int arr[], int n) {
    struct Heap heap;
    initHeap(&heap);

    for (int i = 0; i < n; i++) {
        insert(&heap, arr[i]);
    }

    for (int i = n - 1; i >= 0; i--) {
        arr[i] = extractMax(&heap);
    }
}

void printHeap(struct Heap* heap) {
    printf("Heap: ");
    for (int i = 0; i < heap->size; i++) {
        printf("%d ", heap->arr[i]);
    }
    printf("\n");
}

int main() {
    struct Heap maxHeap;
    initHeap(&maxHeap);

    insert(&maxHeap, 3);
    insert(&maxHeap, 1);
    insert(&maxHeap, 4);
    insert(&maxHeap, 2);

    printf("Max Heap:\n");
    printHeap(&maxHeap);

    printf("Max value extracted: %d\n", extractMax(&maxHeap));

    printf("Max Heap after extraction:\n");
    printHeap(&maxHeap);

    deleteElement(&maxHeap, 1);

    printf("Max Heap after deleting element 1:\n");
    printHeap(&maxHeap);

    struct Heap minHeap;
    initHeap(&minHeap);

    insert(&minHeap, 1); 
    insert(&minHeap, 2);
    insert(&minHeap, 3);
    insert(&minHeap, 4);

    printf("Min Heap:\n");
    printHeap(&minHeap);

    printf("Min value extracted: %d\n", extractMin(&minHeap));
    printf("Min Heap after extraction:\n");
    printHeap(&minHeap);

    deleteElement(&minHeap, 1);

    printf("Min Heap after deleting element 1:\n");
    printHeap(&minHeap);

    int arr[] = {5, 2, 9, 1, 5, 6};
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    printf("\nOriginal Array: ");
    for (int i = 0; i < arrSize; i++) {
        printf("%d ", arr[i]);
    }

    heapSort(arr, arrSize);

    printf("\nSorted Array: ");
    for (int i = 0; i < arrSize; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}