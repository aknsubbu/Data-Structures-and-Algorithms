#include <stdio.h>

int peak(int * arr, int n){
    int i;
    for(i = 1; i < n-1; i++){
        if(arr[i] > arr[i-1] && arr[i] > arr[i+1]){
            return arr[i];
        }
    }
    return -1;
}

int main(){
    int arr[] = {1, 2, 3, 4, 5, 4, 3, 2, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("%d\n", peak(arr, n));
    return 0;
}