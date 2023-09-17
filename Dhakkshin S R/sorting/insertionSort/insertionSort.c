#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../../testCases.h"
#define NUMBER_OF_ELEMENTS 100000
//#define SIZE 3

void shiftRight(int * a, int start, int end, int tmp, int arrLen);
void printArray(int * a, int arrLen);


int main(void)
{
    //unsorted array
    // int a[NUMBER_OF_ELEMENTS] = {4, 1, -1};
    // int arrLen = SIZE;

    clock_t start, end;
    double cpu_time_used;

    int * a = getTestCase("..\\numberFiles\\nearly-sorted.txt");

    start = clock();
    for (int i = 1; i < NUMBER_OF_ELEMENTS; i++)
    {
        int tmp = *(a + i);
        for (int j = i - 1; j >= 0; j--)
        {
            if (tmp >= *(a + j))
            {
                shiftRight(a, j + 1, i, tmp, NUMBER_OF_ELEMENTS);
                break;
            }
            else if (j == 0)
            {
                shiftRight(a, 0, i, tmp, NUMBER_OF_ELEMENTS);
            }
        }
    }
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Execution time: %f seconds\n", cpu_time_used);
    printf("\n");
    //printArray(a, NUMBER_OF_ELEMENTS);

}

void shiftRight(int * a, int start, int end, int tmp, int arrLen)
{
    for (int i = end; i > start; i--)
    {
        *(a + i) = *(a + i - 1);
    }
    *(a + start) = tmp;
    //printArray(a, arrLen);
}

void printArray(int * a, int arrLen)
{
    for (int i = 0; i < arrLen; i++)
    {
        printf("%d ", *(a + i));
    }
    printf("\n");
}