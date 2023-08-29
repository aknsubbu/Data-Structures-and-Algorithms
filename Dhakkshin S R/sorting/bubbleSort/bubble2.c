#include <stdio.h>
#include "../swap.h"

// sink sort
int main(void)
{
    int n = 10, comparisons = 0, swaps = 0;
    int arr[10] = {1, 3, 3, 4, 5, 6, 9, 8, 1, 0};

    for (int pass = 0; pass < n - 1; pass++)
    {
        printf("pass:%d  ", pass);
        for (int i = n - 1; i > pass; i--)
        {
            comparisons++;
            if (arr[i - 1] < arr[i])
            {
                swap(arr, i - 1);
                swaps++;
            }
            printf("i = %d ", i);
        }
        printf("\n");
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\nComparisons: %d\nSwaps: %d\n", comparisons, swaps);
}