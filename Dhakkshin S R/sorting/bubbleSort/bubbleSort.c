#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../../swap.h"
#include "../../testCases.h"
#define NUMBER_OF_ELEMENTS 100000

void bubbleSort(int * arr, int n);

int main(void)
{
    // int numberOfElements;
    // printf("Enter the number of elements: ");
    // scanf("%d", &numberOfElements);
    // int * arr = malloc(numberOfElements * sizeof(int));
    // for (int i = 0; i < numberOfElements; i++)
    // {
    //     printf("Enter element %d: ", i + 1);
    //     scanf("%d", &arr[i]);
    // }

    clock_t start, end;
    double cpu_time_used;

    int * arr = getTestCase("..\\numberFiles\\nearly-sorted.txt");

    //calling the sort function
    start = clock();
    bubbleSort(arr, NUMBER_OF_ELEMENTS);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Execution time: %f seconds\n", cpu_time_used);

    // printing the sorted array
    // printf("After sorting:\n");
    // for (int i = 0; i < NUMBER_OF_ELEMENTS; i++)
    // {
    //     printf("%i ", arr[i]);
    // }
    // printf("\n");

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
            //comparisons++;
            if (a[j] > a[j + 1])
            {
                swap(a, j);
                //swaps++;
                flag = 0;
            }
        }
        if (flag) break;
    }
    //printf("\nComparisons: %i\nSwaps: %i\n", comparisons, swaps);
}