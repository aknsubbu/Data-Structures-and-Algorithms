#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

int linearsearch(int *arr, int size, int val) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == val)
            return 1;
    }
    return 0;
}

int main() {
    int n, i, v;
    printf("Enter the value to be searched:\n");
    scanf("%d", &v);

    FILE *file = fopen("array.txt", "r");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return 1;
    }

    fscanf(file, "%d", &n);
    int *a = (int *)malloc(n * sizeof(int));

    printf("Array read from the file:\n");
    for (i = 0; i < n; i++) {
        fscanf(file, "%d", &a[i]);
        printf("%d ", a[i]);
    }
    printf("\n");

    fclose(file);

    clock_t start_time = clock();

    if (linearsearch(a, n, v))
        printf("Value %d is in the array.\n", v);
    else
        printf("Value %d is not in the array.\n", v);

    clock_t end_time = clock();
    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("Execution Time: %f seconds\n", time_taken);

    free(a);
    return 0;
}