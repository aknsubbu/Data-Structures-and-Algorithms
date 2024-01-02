// #include <stdio.h>

// void swap(int *a, int *b)
// {
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }

// void minHeapify(int arr[], int n, int i)
// {
//     int smallest = i;
//     int left = 2 * i + 1;
//     int right = 2 * i + 2;

//     if (left < n && arr[left] < arr[smallest])

//         smallest = left;

//     if (right < n && arr[right] < arr[smallest])
//         smallest = right;

//     if (smallest != i)
//     {
//         swap(&arr[i], &arr[smallest]);
//         minHeapify(arr, n, smallest);
//     }
// }

// void buildMinHeap(int arr[], int n)
// {
//     int startIdx = (n / 2) - 1;

//     for (int i = startIdx; i >= 0; i--)
//         minHeapify(arr, n, i);
// }

// void maxHeapify(int arr[], int n, int i)
// {
//     int largest = i;
//     int left = 2 * i + 1;
//     int right = 2 * i + 2;

//     if (left < n && arr[left] > arr[largest])
//         largest = left;

//     if (right < n && arr[right] > arr[largest])
//         largest = right;

//     if (largest != i)
//     {
//         swap(&arr[i], &arr[largest]);
//         maxHeapify(arr, n, largest);
//     }
// }

// void buildMaxHeap(int arr[], int n)
// {
//     int startIdx = (n / 2) - 1;

//     for (int i = startIdx; i >= 0; i--)
//         maxHeapify(arr, n, i);
// }

// int main()
// {
//     int arr[] = {4, 10, 3, 5, 1};
//     int n = sizeof(arr) / sizeof(arr[0]);

//     buildMinHeap(arr, n);
//     for (int i = 0; i < n; i++)
//         printf("%d ", arr[i]);

//     buildMaxHeap(arr, n);
//     for (int i = 0; i < n; i++)
//         printf("%d ", arr[i]);

//     return 0;
// }

#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void percolateUp(int arr[], int i)
{
    while (i > 0 && arr[i] < arr[(i - 1) / 2])
    {
        swap(&arr[i], &arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void percolateDown(int arr[], int n, int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i)
    {
        swap(&arr[i], &arr[smallest]);
        percolateDown(arr, n, smallest);
    }
}

int main()
{
    int arr[] = {4, 10, 3, 5, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Percolate up
    for (int i = 0; i < n; i++)
    {
        percolateUp(arr, i);
    }

    printf("Heap after percolate up: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    // Percolate down
    for (int i = n - 1; i >= 0; i--)
    {
        percolateDown(arr, n, i);
    }

    printf("\nHeap after percolate down: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
