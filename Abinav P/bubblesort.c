// bubble sort in single forloop and double forloop

#include<Stdio.h>
#include<stdlib.h>
int *bsort(int *array,int number){
    int i,j,temp;
    for(i=0;i<number;i++){
        for(j=0;j<number-i-1;j++){
            if(array[j]>array[j+1]){
                temp=array[j];
                array[j]=array[j+1];
                array[j+1]=temp;
            }
        }
    }
    return array;
}
int *bsort(int array[],int number){
    for(int i=0;i<number;i++){
        if(array[i]>array[i+1]){
            int temp=array[i];
            array[i]=array[i+1];
            array[i+1]=temp;
        }
    }
}

void main(){
    int number;
    printf("Enter the number of elements: ");
    scanf("%d",&number);
    int *array=(int *)malloc(number*sizeof(int));   
    for(int i=0;i<number;i++){
        scanf("%d",&array[i]);
    }
    array=bsort(array,number);
    for(int i=0;i<number;i++){
        printf("%d ",array[i]);
    }
}


bubble sort in ascending order and descending order
#include<stdio.h>
#include "customfunctions.h"
void main(){
   int number;
   printf("Enter the number of elements: ");
   scanf("%d",&number);
   int *array=(int *)malloc(number*sizeof(int));
    for(int i=0;i<number;i++){
         scanf("%d",&array[i]);
    }
    int sorted=bubblesort(array,number);
    for(int i=0;i<number;i++){
        printf("%d ",array[i]);
    }

    int descending=bubblesortdescending(array,number);
    printf("\n");
    for(int i=0;i<number;i++){
        printf("%d ",array[i]);
    }
}

//randomize elements in an array
#include<stdio.h>
#include "customfunctions.h"
void main(){
    int array[]={1,2,3,4,5};
    int number=sizeof(array)/sizeof(array[0]);
    int *randomized=randomize(array,number);
    for(int i=0;i<number;i++){
        printf("%d ",randomized[i]);
    }
}
