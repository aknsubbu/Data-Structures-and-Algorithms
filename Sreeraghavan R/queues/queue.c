#include <stdio.h>
#include <stdlib.h>

void enqueue(int* q, int *front, int *rear, int size, int val){
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

int dequeue(int* q, int *front, int *rear, int size){
   if(*front == -1){
      printf("UNDERFLOW");
   }
   if(*front == *rear){
      *front = *rear = -1;
   }
   return q[(*front)++];
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

int main(){
    int front,rear,size = 5;
    int arr[size];
    front = rear = -1;
    size = 5;
    enqueue(arr,&front,&rear,size,1);
    enqueue(arr,&front,&rear,size,2);
    enqueue(arr,&front,&rear,size,3);
    enqueue(arr,&front,&rear,size,4);
    enqueue(arr,&front,&rear,size,5);
    printf("%d\n",dequeue(arr,&front,&rear,size));
    enqueue(arr,&front,&rear,size,6);
    printf("\n%d %d\n",front,rear);
    dequeue(arr,&front,&rear,size);
    dequeue(arr,&front,&rear,size);
    enqueue(arr,&front,&rear,size,7);
    enqueue(arr,&front,&rear,size,8);
    enqueue(arr,&front,&rear,size,9);

    display(arr,&front,&rear,size);
}