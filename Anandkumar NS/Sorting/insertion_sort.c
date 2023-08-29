#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int sampleLengthVar, int* sampleArrayPtr) {
    for (int i = 1; i < sampleLengthVar; i++) {
        int key = sampleArrayPtr[i];
        int j = i - 1;
        
        while (j >= 0 && sampleArrayPtr[j] > key) {
            sampleArrayPtr[j + 1] = sampleArrayPtr[j];
            j = j - 1;
        }
        
        sampleArrayPtr[j + 1] = key;
    }
}

int* readFile(char filename[], int* sampleLengthVar) {
    FILE* fp;
    fp = fopen(filename, "r");
    
    if (fp == NULL) {
        printf("Error opening file.\n");
        return NULL;
    }
    
    fscanf(fp, "%d", sampleLengthVar);
    printf("Scanning a sample of length: %d\n", *sampleLengthVar);

    int* sampleArrayPtr = (int*)malloc(*sampleLengthVar * sizeof(int));
    if (sampleArrayPtr == NULL) {
        printf("Memory allocation failed.\n");
        fclose(fp);
        return NULL;
    }

    for (int i = 0; i < *sampleLengthVar; i++) {
        fscanf(fp, "%d", &sampleArrayPtr[i]);
    }
    
    fclose(fp);
    return sampleArrayPtr;
}

int main() {
    char filename[] = "./number files/descending.txt";
    int sampleLengthVar;
    int* sampleArrayPtr = readFile(filename, &sampleLengthVar);

    if (sampleArrayPtr != NULL) {
        clock_t start_time = clock();

        insertionSort(sampleLengthVar, sampleArrayPtr);

        clock_t end_time = clock();
        double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;
        
        printf("Sorted Array:\n");
        for (int i = 0; i < sampleLengthVar; i++) {
            printf("%d ", sampleArrayPtr[i]);
        }
        printf("\n");
printf("Execution Time: %f seconds\n", time_taken);
        free(sampleArrayPtr); 
    }

    return 0;
}