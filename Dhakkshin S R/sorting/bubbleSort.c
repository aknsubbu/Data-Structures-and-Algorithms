#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int * arr, int n);
void swap(int * a, int i);

int main(void)
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int * arr = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    //calling the sort function
    bubbleSort(arr, n);

    // printing the sorted array
    printf("After sorting:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%i ", *(arr + i));
    }
    printf("\n");
}

void bubbleSort(int * a, int n)
{
    int tmp;
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < (n - i -1); j++)
        {
            if (*(a+j) > *(a+j+1))
            {
                swap(a, j);
            }
        }
    }
}

void swap(int * a, int i)
{
    int tmp;
    tmp = *(a + i);
    *(a + i) = *(a + i + 1);
    *(a + i + 1) = tmp;
    return;
}