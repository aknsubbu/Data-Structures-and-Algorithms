#include <stdio.h>
#include <stdlib.h>
#include "../swap.h"

void bubbleSort(int * arr, int n);

int main(void)
{
    int numberOfElements;
    printf("Enter the number of elements: ");
    scanf("%d", &numberOfElements);
    int * arr = malloc(numberOfElements * sizeof(int));
    for (int i = 0; i < numberOfElements; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    //calling the sort function
    bubbleSort(arr, numberOfElements);

    // printing the sorted array
    printf("After sorting:\n");
    for (int i = 0; i < numberOfElements; i++)
    {
        printf("%i ", arr[i]);
    }
    printf("\n");

    free(arr); 
}

void bubbleSort(int * a, int n)
{
    int comparisons = 0, swaps = 0, flag;
    for (int i = 0; i < n - 1; i++)
    {
        flag = 1;
        for (int j = 0; j < n - i - 1; j++)
        {
            comparisons++;
            if (a[j] > a[j + 1])
            {
                swap(a, j);
                swaps++;
                flag = 0;
            }
        }
        if (flag) break;
    }
    printf("\nComparisons: %i\nSwaps: %i\n", comparisons, swaps);
}