#include <stdio.h>
#include <stdlib.h>

void swap(int*l, int i, int j){
    int temp = l[i];
    l[i] = l[j];
    l[j] = temp;
}

void bsort(int* l,int n){
    printf("\n");
    //printf("size is %d",size);
    for(int i = 0;i<n;i++){
        for(int j = i;j<n;j++){
            if(l[j] > l[j+1]){
                swap(l,j,j+1);
            }
        }
    }
}


int main(){
    //defining the array
    int* l = (int*)malloc(10*sizeof(int));
    for(int i = 0;i<10;i++){
        l[i] = i+1;
        if(i % 2 == 0){
            l[i] = 10+i;
        }
    }

    printf("original list\n");
    for(int i = 0;i<10;i++){
        printf("%d ",l[i]);
    }
    
    bsort(l,10);

    printf("sorted list\n");
    for(int i = 0;i<10;i++){
        printf("%d ",l[i]);
    }
}

