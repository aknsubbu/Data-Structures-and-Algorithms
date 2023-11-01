#include <stdio.h>
#include "../swap.h"
#include <time.h>
#include <stdlib.h>
#define N 100000

void readArrayFromFile(int * array, int len, char * fileName){
    FILE * file = fopen(fileName, "r");
    for (int i = 0; i < len; i++)
    {
        fscanf(file, "%d", array + i);
    }
    fclose(file);
}

void printArray(int * array, int len){
    for (int i = 0; i < len; i++)
    {
        printf("%d\t", *(array + i));
    }
    printf("\n");
}
void insertionSortUnoptimised(int * arr, int len){
    for (int i = 1; i < len; i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (arr[j] < arr[j-1])
            {
                swap(j, j-1, arr);
                // printArray(arr, len);
            } else {
                break;
            }     
        }        
    }    
}

int main() {
    int* nums = (int *) malloc (N * sizeof(int));
    readArrayFromFile(nums, N, "100k-random.txt");
    // Measure the time before sorting
    clock_t start_time = clock();

    insertionSortUnoptimised(nums, 100000);

    // Measure the time after sorting
    clock_t end_time = clock();

    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    // printf("Sorted array: ");
    // printArray(a, 5);
    printf("Time taken: %f seconds\n", time_taken);

    return 0;
}






