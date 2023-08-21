#include <stdio.h>
#include <stdlib.h> 

int main(){
    int n;
    printf("Enter the number of elements to be sorted: ");
    scanf("%d", &n);
    int *arr = (int*)malloc(n * sizeof(int));

    // Input
    for(int i = 0; i < n; ++i){
        printf("Enter element number %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    bubbleSort(arr, n);

    // Printing
    printf("Sorted elements:\n");
    for(int i = 0; i < n; ++i){
        printf("%d ", arr[i]);
    }

    free(arr);

    return 0;
}

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
