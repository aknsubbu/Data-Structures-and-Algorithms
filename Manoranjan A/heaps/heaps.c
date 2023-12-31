//min and max heap using arrays

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int heap[MAX_SIZE];

int size = 0;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}

void insert(int element)
{
    int i = size;
    heap[i] = element;
    size++;
    while (i > 0 && heap[i] < heap[(i - 1) / 2])
    {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void minHeapify(int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < size && heap[left] < heap[smallest])
    {
        smallest = left;
    }
    if (right < size && heap[right] < heap[smallest])
    {
        smallest = right;
    }
    if (smallest != i)
    {
        swap(&heap[i], &heap[smallest]);
        minHeapify(smallest);
    }
}

void maxHeapify(int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < size && heap[left] > heap[largest])
    {
        largest = left;
    }
    if (right < size && heap[right] > heap[largest])
    {
        largest = right;
    }
    if (largest != i)
    {
        swap(&heap[i], &heap[largest]);
        maxHeapify(largest);
    }
}

void delete(int element)
{
    int i;
    for (i = 0; i < size; i++)
    {
        if (heap[i] == element)
        {
            break;
        }
    }
    if (i == size)
    {
        printf("Element not found\n");
        return;
    }
    heap[i] = heap[size - 1];
    size--;
    minHeapify(i);
}

void display()
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", heap[i]);
    }
    printf("\n");
}

