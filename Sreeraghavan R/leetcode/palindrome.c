#include <math.h>
#include <stdlib.h>
#include <stdio.h>


int main(){
    int x = 1023408;
    int copy = x;
    int a = 0;
    int i = 0;
    int* arr = (int*)malloc(10*sizeof(int));
    
    do{
        int a += (copy%10)*();
        copy /= 10;
        
        i++;
    }while(copy != 0);

    int* ptrs = arr;
    int* ptre = arr+i-1;
    printf("%d %d\n",*ptrs,*ptre);


    for(int i = 0;i<7;i++){
        printf("%d ",arr[i]);
    }
}