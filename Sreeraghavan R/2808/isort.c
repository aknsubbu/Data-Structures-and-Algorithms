#include <stdio.h>
#include <stdlib.h>
#define LEN 100000

int* isort(int* arr,int len){
    for(int i = 1;i<len;i++){
        int temp = arr[i];
        for(int j = i-1;j>=0;j--){    


            //printing for debug
            // for(int i = 0;i<6;i++){
            //     printf("%d ",arr[i]);
            // }
            // printf("\n");
            // printf("i = %d j = %d temp = %d\n",i,j,temp);  


            if(temp < arr[j]){
                //printf("duplicated\n");
                arr[j+1] = arr[j];
                continue;
            }
            arr[j+1] = temp;
            break;
        }
    }
    return arr;
}


int main(){
    
    int* p = (int*)malloc(LEN*sizeof(int));


    FILE* fr = fopen("random.txt","r");
    int* lr = (int*)malloc(LEN*sizeof(int));
    for(int i = 0;i<LEN;i++){
        fscanf(fr,"%d ",lr+i);
    }


    p = isort(lr,LEN);
    for(int i = 0;i<20;i++){
        printf("%d ",lr[i]);
    }


}