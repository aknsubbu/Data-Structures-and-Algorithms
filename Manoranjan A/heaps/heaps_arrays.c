#include <stdio.h>
#include <stdlib.h>



void insert(int heap[], int *size, int element) {
    int i = *size;
    heap[i] = element;
    (*size)++;
    while (i > 0 && heap[i] < heap[(i - 1) / 2]) {
        int temp = heap[i];
        heap[i] = heap[(i - 1) / 2];
        heap[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

void minHeapify(int heap[], int size, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < size && heap[left] < heap[smallest]) {
        smallest = left;
    }
    if (right < size && heap[right] < heap[smallest]) {
        smallest = right;
    }
    if (smallest != i) {
        int temp = heap[i];
        heap[i] = heap[smallest];
        heap[smallest] = temp;
        minHeapify(heap, size, smallest);
    }
}

int main() {
    int heap[100];
    int size = 0;
    insert(heap, &size, 10);
    insert(heap, &size, 20);
    insert(heap, &size, 30);
    insert(heap, &size, 40);
    insert(heap, &size, 50);
    insert(heap, &size, 60);
    insert(heap, &size, 70);
    insert(heap, &size, 80);
    insert(heap, &size, 90);
    insert(heap, &size, 100);
    for (int i = 0; i < size; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");
    minHeapify(heap, size, 0);
    for (int i = 0; i < size; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");
    return 0;
}

