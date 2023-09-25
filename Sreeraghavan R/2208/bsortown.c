#include <stdio.h>
#include "utilities.h"
#include <stdlib.h>
#define len 10





int main(){
    int* l = readrandom(len);
    
    
    for(int i = len-1;i>=1;i--){
        for(int j = 0;j<i;j++){
            if(l[j] > l[j+1]){
                swap(l,j,j+1);
            }
        }
    }
    

    printf("Sorted\n");
    for(int i = 0; i <len;i++){
        printf("%d ",l[i]);
    }

}