#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int *arr, int n){
    int r=0;
    for (int c = 0; c < n - 1; ++c) {
        for (int x = 0; x < n - 1 - c; ++x) {
            if (arr[x] > arr[x + 1]) {
                swap(&arr[x], &arr[x + 1]);
                r++;
                printf(" Number of Iterations: %d\n",r);
            }
            else{
                continue;
            }
        }
        break;
    }
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    char filename[] = "./number files/random.txt"; 
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    int n;
    fscanf(fp, "%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        perror("Memory allocation error");
        return 1;
    }

    for (int i = 0; i < n; ++i) {
        fscanf(fp, "%d", &arr[i]);
    }

    fclose(fp);

    bubbleSort(arr, n);

    printf("Sorted array:\n");
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    
    return 0;
}