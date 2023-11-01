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

void writeArrayToFile(int * array, int len, char * fileName){
    FILE * file = fopen(fileName, "a");
    for (int i = 0; i < len; i++)
    {
        fprintf(file, "%d ", *(array + i));
    }
    fprintf(file, "\n");
    fclose(file);
}



void printArray(int * array, int len){
    for (int i = 0; i < len; i++)
    {
        printf("%d\t", *(array + i));
    }
    printf("\n");
}

void bubbleSort(int * arr, int len){
    int swapsMadeInCurrentIteration, totalSwaps = 0, comparisons = 0;
    for (int i = 0; i < len - 1; i++)
    {
        swapsMadeInCurrentIteration = 0;
        for (int j = 0; j < len - i - 1; j++)
        {   
            comparisons++;
            if (*(arr + j) > *(arr + j + 1))
            {
                swap(j, j+1, arr);
                swapsMadeInCurrentIteration++;
                totalSwaps++;
                // writeArrayToFile(arr, len, fileName);
            }
            
        }
        if (!swapsMadeInCurrentIteration)
        {
            break;
        }
        
    }
    // FILE * file = fopen(fileName, "a");
    // fprintf(file, "Number of swaps: %d\nSwaps: %d", totalSwaps);
    // fclose(file);
    
}


void bubbleSortIterDemo (int * arr, int len, char * fileName){
    int swapsMadeInCurrentIteration, totalSwaps = 0, comparisons = 0;
    for (int i = 0; i < len - 1; i++)
    {
        swapsMadeInCurrentIteration = 0;
        for (int j = 0; j < len - i - 1; j++)
        {   
            comparisons++;
            if (*(arr + j) > *(arr + j + 1))
            {
                swap(j, j+1, arr);
                swapsMadeInCurrentIteration++;
                totalSwaps++;
                writeArrayToFile(arr, len, fileName);
            }
            
        }
        if (!swapsMadeInCurrentIteration)
        {
            break;
        }
        
    }
    FILE * file = fopen(fileName, "a");
    fprintf(file, "Number of swaps: %d\nComparisons: %d", totalSwaps);
    fclose(file);
    
}


void reverseBubbleSort (int * arr, int len, char * fileName){
    int swapsMadeInCurrentIteration, totalSwaps = 0, comparisons = 0;
    for (int i = len - 1; i > 0; i--)
    {
        swapsMadeInCurrentIteration = 0;
        for (int j = len - 1; j > i; j--)
        {   
            comparisons++;
            if (*(arr + j) < *(arr + j - 1))
            {
                swap(j, j-1, arr);
                swapsMadeInCurrentIteration++;
                totalSwaps++;
                writeArrayToFile(arr, len, fileName);
            }
            
        }
        if (!swapsMadeInCurrentIteration)
        {
            break;
        }
        
    }
    FILE * file = fopen(fileName, "a");
    fprintf(file, "Number of swaps: %d\nComparisons: %d", totalSwaps);
    fclose(file);
    
}



int main() {
    int* nums = (int *) malloc (N * sizeof(int));
    readArrayFromFile(nums, N, "100k-random.txt");
    // Measure the time before sorting
    clock_t start_time = clock();

    bubbleSort(nums, 100000);

    // Measure the time after sorting
    clock_t end_time = clock();

    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    // printf("Sorted array: ");
    // printArray(a, 5);
    printf("Time taken: %f seconds\n", time_taken);

    return 0;
}