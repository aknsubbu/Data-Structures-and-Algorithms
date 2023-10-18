#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void fillTree(int arr[],int length,int levels){
    printf("Enter -1 if you want to enter a NULL node\n");
    for(int i=0;i<length;i++){
        int x;
        
        if(i==0){
            printf("x----Root Node----x\n");
        }
        else if(i%2==0){
            printf("x----Right Child----x\n");
        }
        else{
            printf("x----Left Child----x\n");
        }
        printf("Enter the value of node %d: ",i);
        scanf("%d",&x);
        if(x==-1){
            arr[i] = -1;
        }
        else{
            arr[i] = x;
        }
    }

}

void displayTree(int arr[],int length,int levels){
    
    for(int i=0;i<levels;i++){
        for(int j=0;j<pow(2,i);j++){
            printf("%d ",arr[j]);
        }
        printf("\n");
    }
}

int main(){
    int length,levels;
    printf("Enter the number of levels of the binary tree: ");
    scanf("%d",&levels);
    length = (pow(2,levels))-1;
    int *arr=(int *)malloc(length*sizeof(int));
    fillTree(arr,length,levels);
    displayTree(arr,length,levels);
    return 0;
}
