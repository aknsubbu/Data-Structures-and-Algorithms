#include <stdio.h>

void heapify(int arr[], int n, int i, int isMaxHeap) {
    int largestOrSmallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (isMaxHeap) {
        // For max-heap, compare with left and right children
        if (left < n && arr[left] > arr[largestOrSmallest])
            largestOrSmallest = left;

        if (right < n && arr[right] > arr[largestOrSmallest])
            largestOrSmallest = right;
    } else {
        // For min-heap, compare with left and right children
        if (left < n && arr[left] < arr[largestOrSmallest])
            largestOrSmallest = left;

        if (right < n && arr[right] < arr[largestOrSmallest])
            largestOrSmallest = right;
    }

    // If the largest/smallest is not the root, swap them and recursively heapify the affected sub-tree
    if (largestOrSmallest != i) {
        int temp = arr[i];
        arr[i] = arr[largestOrSmallest];
        arr[largestOrSmallest] = temp;

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largestOrSmallest, isMaxHeap);
    }
}

void heapSort(int arr[], int n, int isMaxHeap) {
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i, isMaxHeap);

    // One by one extract an element from the heap
    for (int i = n - 1; i >= 0; i--) {
        // Move current root to end
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // Call heapify on the reduced heap
        heapify(arr, i, 0, isMaxHeap);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: \n");
    printArray(arr, n);

    // Sort as Max Heap (Ascending Order)
    heapSort(arr, n, 1);
    printf("Sorted array (Max Heap): \n");
    printArray(arr, n);

    // Sort as Min Heap (Descending Order)
    heapSort(arr, n, 0);
    printf("Sorted array (Min Heap): \n");
    printArray(arr, n);

    return 0;
}
