#include <stdio.h>
#include <stdlib.h>

struct Heap {
    int* arr;
    int size;
};

void propagateUp(struct Heap* mHeap, int i) {
    if (i == 0)
        return;

    int tmp = 0;
    int* heap = mHeap->arr;

    while ((*(heap + (i - 1) / 2) < *(heap + i)) && (i != 0)) {
        tmp = *(heap + (i - 1) / 2);
        *(heap + (i - 1) / 2) = *(heap + i);
        *(heap + i) = tmp;

        i = (i - 1) / 2;
    }
    return;
}

struct Heap* createHeap() {
    struct Heap* heap = malloc(sizeof(struct Heap));
    printf("Enter the number of elements:");
    scanf("%d", &(heap->size));
    heap->arr = malloc(heap->size * sizeof(int));

    int val;
    for (int i = 0; i < heap->size; i++) {
        printf("Enter a number:");
        scanf("%d", &val);
        heap->arr[i] = val;
        propagateUp(heap, i);
    }
    return heap;
}

int extractMax(struct Heap* h) {
    return h->arr[0];
}

void heapify(struct Heap* h, int i) {
    // curr is out of bounds
    if (i >= h->size)
        return;

    // children are out of bounds
    if (((2 * i + 1) >= h->size) || ((2 * i + 2) >= h->size))
        return;

    // both children are smaller than curr
    if ((*(h->arr + 2 * i + 1) < *(h->arr + i)) && (*(h->arr + 2 * i + 2) < *(h->arr + i)))
        return;

    // parent is smaller than both children
    if ((*(h->arr + 2 * i + 1) > *(h->arr + i)) && (*(h->arr + 2 * i + 2) > *(h->arr + i))) {

        // swapping curr with the larger child
        if (*(h->arr + 2 * i + 1) > *(h->arr + 2 * i + 2)) {
            int tmp = *(h->arr + 2 * i + 1);
            *(h->arr + 2 * i + 1) = *(h->arr + i);
            *(h->arr + i) = tmp;
            i = 2 * i + 1;
        } else {
            int tmp = *(h->arr + 2 * i + 2);
            *(h->arr + 2 * i + 2) = *(h->arr + i);
            *(h->arr + i) = tmp;
            i = 2 * i + 2;
        }
        heapify(h, i);
        return;
    }

    // left child is larger, right is smaller
    if (*(h->arr + 2 * i + 1) > *(h->arr + i)) {
        int tmp = *(h->arr + 2 * i + 1);
        *(h->arr + 2 * i + 1) = *(h->arr + i);
        *(h->arr + i) = tmp;
        i = 2 * i + 1;
        heapify(h, i);
        return;
    }

    // left child is smaller, right is larger
    if (*(h->arr + 2 * i + 2) > *(h->arr + i)) {
        int tmp = *(h->arr + 2 * i + 2);
        *(h->arr + 2 * i + 2) = *(h->arr + i);
        *(h->arr + i) = tmp;
        i = 2 * i + 2;
        heapify(h, i);
        return;
    }
}

void deleteMax(struct Heap* h) {
    h->arr[0] = h->arr[--h->size];
    for (int i = 0; i < h->size; i++)
        printf("%d, ", h->arr[i]);
    printf("\n");
    heapify(h, 0);
    return;
}

int main(void) {
    struct Heap* maxHeap = createHeap();
    for (int i = 0; i < maxHeap->size; i++)
        printf("%d, ", maxHeap->arr[i]);
    printf("\nRoot: %d\n", extractMax(maxHeap));
    deleteMax(maxHeap);
    for (int i = 0; i < maxHeap->size; i++)
        printf("%d, ", maxHeap->arr[i]);
    return 0;
}
