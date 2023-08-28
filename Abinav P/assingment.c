// #include<stdio.h>
// #include "swap.h"
// void main(){
//     int temp,swaps=0;
//     int array[]={5,3,1,4,2};
//    for(int i=5-1;i>1;i++){
//         for(int j = 0; j < i; j++){
//             if(array[j] > array[j + 1]){
//                 swap(&array[j],&array[j+1]);
//                 swaps++;
//             }
//         }
//     }
//     for(int i=0;i<5;i++){
//         printf("%d ",array[i]);
//     }
//     printf("the number of swaps done is %d",swaps);
// }



//insertion sort
#include<stdio.h>
void main(){
    int array[]={5,3,1,4,2};
    int i,j,key;
    for(i=1;i<5;i++){
        key=array[i];
        j=i-1;
        while(j>=0 && array[j]>key){
            array[j+1]=array[j];
            j=j-1;
        }
        array[j+1]=key;
    }
    for(int i=0;i<5;i++){
        printf("%d ",array[i]);
    }
}

