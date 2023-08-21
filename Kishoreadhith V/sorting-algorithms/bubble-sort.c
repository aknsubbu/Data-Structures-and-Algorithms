#include <stdio.h>
#include <stdlib.h>

void swap(int a, int b, int * array){
    int temp = *(array + a);
    *(array + a) = *(array + b);
    *(array + b) = temp;
}

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

void bubbleSort(int * arr, int len, char * fileName){
    int swapsMadeInCurrentIteration, totalSwaps = 0;
    for (int i = 0; i < len - 1; i++)
    {
        swapsMadeInCurrentIteration = 0;
        for (int j = 0; j < len - i - 1; j++)
        {
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
            break;;
        }
        
    }
    FILE * file = fopen(fileName, "a");
    fprintf(file, "Number of swaps: %d\n", totalSwaps);
    fclose(file);
    
}



int main(){
    int * nums = (int *) malloc(6 * sizeof(int));
    readArrayFromFile(nums, 6, "input.txt");
    printArray(nums, 6);
    bubbleSort(nums, 6, "input.txt");
    printArray(nums, 6);
}