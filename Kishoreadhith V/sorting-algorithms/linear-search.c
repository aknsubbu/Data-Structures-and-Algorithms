#include <stdio.h>
#include "../swap.h"
#include <time.h>
#include <stdlib.h>
#define N 100000


int linearSearch(int * arr, int len, int target){
    for (int i = 0; i < len; i++)
    {
        if (arr[i] == target)
        {
            return i;
        }   
    }
    return -1;
}

void readArrayFromFile(int * array, int len, char * fileName){
    FILE * file = fopen(fileName, "r");
    for (int i = 0; i < len; i++)
    {
        fscanf(file, "%d", array + i);
    }
    fclose(file);
}

int main() {
    int* nums = (int *) malloc (N * sizeof(int));
    readArrayFromFile(nums, N, "100k-random.txt");
    // Measure the time before sorting
    clock_t start_time = clock();

    linearSearch(nums, 100000, 0);

    // Measure the time after sorting
    clock_t end_time = clock();

    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    // printf("Sorted array: ");
    // printArray(a, 5);
    printf("Time taken: %f seconds\n", time_taken);

    return 0;
}