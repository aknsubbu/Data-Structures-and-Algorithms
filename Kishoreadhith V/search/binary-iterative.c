#include <stdio.h>

int binarySearchIterative(int * arr, int len, int target){
    int start = 0;
    int end = len - 1;

    while (start <= end)
    {
        int mid = (start + end)/2;
        if (*(arr + mid) == target)
        {
            return mid;
        }
        else if (*(arr + mid) > target)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return -1;    
}

int binarySearchRecursive(int * arr, int start, int end, int target){
    if (start > end)
    {
        return -1;
    }
    else
    {
        int mid = (start + end)/2;
        if (*(arr + mid) == target)
        {
            return mid;
        }
        else if (*(arr + mid) > target)
        {
            return binarySearchRecursive(arr, start, mid - 1, target);
        }
        else
        {
            return binarySearchRecursive(arr, mid + 1, end, target);
        }
    }
}

int main(){
    int arr[] = {10,20,30,40,50,60,70,80,90,100};
    int target = 50;
    int result = binarySearchIterative(arr, 10, target);
    int result2 = binarySearchRecursive(arr, 0, 9, target);
    printf("%d \n %d", result, result2);
}