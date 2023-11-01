#include <stdio.h>

int main(){
    // sorted array
    // int n = 100000;
    // FILE *file = fopen("sorted.txt", "w");
    // for (int i = 0; i < n; i++)
    // {
    //     fprintf(file, "%d ", i);
    // }
    // fprintf(file, "\n");
    // fclose(file);

    // reverse sorted
    int n = 100000;
    FILE *file = fopen("reverse.txt", "w");
    for (int i = n; i > 0; i--)
    {
        fprintf(file, "%d ", i);
    }
    fprintf(file, "\n");
    fclose(file);
}