#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../../../testCases.h"
#define NUMBER_OF_ELEMENTS 100000

int main(void)
{
    clock_t start, end;
    double cpu_time_used;

    // int a[SIZE] = {4, 1, -1, 3, 2}, 
    
    int * arr = getTestCase("..\\..\\sorting\\numberFiles\\nearly-sorted.txt");
    int search = 99999;

    start = clock();

    for (int i = 0; i < NUMBER_OF_ELEMENTS; i++)
    {
        if (arr[i] == search)
        {
            end = clock();
            printf("Found %d at index %d\n", search, i);           
            cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
            printf("\nExecution time: %f seconds\n", cpu_time_used);
            return 0;
        }
    }
    end = clock();
    printf("%d not found\n", search);
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Execution time: %f seconds\n", cpu_time_used);
}