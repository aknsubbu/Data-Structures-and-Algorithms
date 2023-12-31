#include <stdio.h>

struct Heap{
    int *arr;
    int size;
};

struct Heap createHeap(int size){
    struct Heap *heap=(struct Heap *)malloc(sizeof(struct Heap));
    heap->size = 0;
    heap->arr = (int *)malloc(size * sizeof(int));
    return *heap;
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(struct Heap *heap, int i){
    //i is the index of the node to be heapified
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;

    if(left < heap->size && heap->arr[left] > heap->arr[largest] )
        largest = left;

    if(right < heap->size && heap->arr[right] > heap->arr[largest])
        largest = right;

    if(largest != i){
        swap(&heap->arr[i], &heap->arr[largest]);
        heapify(heap, largest);
    }
}

void insert(struct Heap *heap,int x){
    heap->arr[heap->size] = x;
    heap->size++;
    int i = heap->size-1;
    while(i != 0 && heap->arr[(i-1)/2] < heap->arr[i]){
        swap(&heap->arr[i], &heap->arr[(i-1)/2]);
        i = (i-1)/2;
    }

}

int extractMax(struct Heap *heap){
    // this function extracts the maximum element from the heap by deleting it
    if(heap->size <= 0){
        printf("Heap is empty. Cannot extract minimum.\n");
        return -1;
    }
    int root = heap->arr[0];
    heap->arr[0] = heap->arr[heap->size-1];
    heap->size--;
    heapify(heap, 0);
    return root;
}

void printHeap(struct Heap *heap){
    for(int i=0; i<heap->size; i++)
        printf("%d ", heap->arr[i]);
    printf("\n");
}

int main(){
    int size;
    printf("Enter the size of the heap: ");
    scanf("%d", &size);
    struct Heap heap = createHeap(size);
    printf("Enter the elements of the heap: ");
    for(int i=0; i<size; i++)
        scanf("%d", &heap.arr[i]);
    heap.size = size;
    for(int i=size/2-1; i>=0; i--)
        heapify(&heap, i);
    printf("The heap is: ");
    printHeap(&heap);
    printf("Enter the element to be inserted: ");
    int x;
    scanf("%d", &x);
    insert(&heap, x);
    printf("The heap after insertion is: ");
    printHeap(&heap);
    printf("The maximum element is: %d\n", extractMax(&heap));
    printf("The heap after deletion is: ");
    printHeap(&heap);
    return 0;
}