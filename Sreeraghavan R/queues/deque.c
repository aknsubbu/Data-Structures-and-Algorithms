#include <stdio.h>
#include <stdlib.h>

void enqueue(int* q, int *front, int *rear, int size, int val,int end){

    if(end == 1){
        if(*front == -1){
        *front = 0;
        q[++(*rear)] = val;
        return;
    }
    if((*rear == size-1 && *front == 0)|| *rear == *front-1){
        printf("OVERFLOW\n");
        return;
    }
    if(*rear == size-1){
      *rear = 0;
      q[0] = val;
      return;
    }
    q[++(*rear)] = val;
    }
}

int dequeue(int* q, int *front, int *rear, int size,int end){
   if(end == 1){
    if(*front == -1){
      printf("UNDERFLOW");
   }
   if(*front == *rear){
      *front = *rear = -1;
   }
   return q[(*front)++];
   }
}

void display(int *arr,int *front , int *rear,int size){
   
   printf("Size is %d\n",size);
   if(*front ==-1 && *rear ==-1){
      printf("the list is empty ....! ");
      return ;
   }
   if(*rear<*front){
      for(int i=*front;i<size;i++){
         printf("%d ",arr[i]);
      }
      for(int i=0;i<=*rear;i++){
         printf("%d ",arr[i]);
      }
      printf("\n");
      return;
   } 
   else{
      for(int i=*front;i<=*rear;i++){
         printf("%d ",arr[i]);
      }
      return;
   }
}