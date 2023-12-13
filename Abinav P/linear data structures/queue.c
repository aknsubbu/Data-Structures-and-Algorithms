// #include<stdio.h>
// #include<stdlib.h>

// void enqueue(int *arr,int *front,int *rear,int data,int size){
//     if(*rear==-1 && *front ==-1){
//       arr[0]=data;
//       *front=0;
//       *rear=0;
//       return;
//     }
//     if((*front==0 && *rear==size-1)||(*front-*rear==1)){
//       printf("the queue is overflow...!");
//       return;
//     }
//     if(*rear == size-1){
//       *rear=0;
//       arr[*rear]=data;
//       return;
//     }
//     arr[++(*rear)]=data;
//     return;
// }


// int dequeue(int *arr, int *front, int *rear, int size) {
//     if (*front == -1 && *rear == -1) {
//         printf("The queue is empty...!\n");
//         return -99;
//     }
//     int data = arr[*front];
//     if (*front == *rear) {
//         *front = -1;    
//         *rear = -1;
//     } else {
//         *front = (*front + 1) % size;
//     }
//     return data;
// }
// void print(int *arr,int *front , int *rear){
//    int size = sizeof(arr)/sizeof(int);
//    if(*front ==-1 && *rear ==-1){
//       printf("the list is empty ....! ");
//       return ;
//    }
//    if(*rear<*front){
//       for(int i=*front;i<size;i++){
//          printf("%d ",arr[i]);
//       }
//       for(int i=0;i<=*rear;i++){
//          printf("%d ",arr[i]);
//       }
//       printf("\n");
//       return;
//    } 
//    else{
//       for(int i=*front;i<=*rear;i++){
//          printf("%d ",arr[i]);
//       }
//       return;
//    }
// }
// int main() {
//     int *arr = (int *)malloc(5 * sizeof(int));
//     int front = -1, rear = -1;

//     enqueue(arr, &front, &rear, 1, 5);
//     enqueue(arr, &front, &rear, 2, 5);
//     enqueue(arr, &front, &rear, 3, 5);

//     int data = dequeue(arr, &front, &rear, 5);
//     printf("Dequeued: %d\n", data);

//     print(arr, &front, &rear);

//     free(arr); // Don't forget to free the allocated memory.
//     return 0;
// }

//queue using linked list

#include<stdio.h>
#include<stdlib.h>

struct node{
   int data;
   struct node *next;
};

struct node *front=NULL;
struct node *rear=NULL;

void enqueue(int data){
   struct node *temp=(struct node *)malloc(sizeof(struct node));
   temp->data=data;
   temp->next=NULL;
   if(front==NULL && rear==NULL){
      front=temp;
      rear=temp;
      return;
   }
   rear->next=temp;
   rear=temp;
   return;
}

int dequeue(){
   if(front==NULL && rear==NULL){
      printf("the queue is empty...!\n");
      return -99;
   }
   struct node *temp=front;
   int data=temp->data;
   if(front==rear){
      front=NULL;
      rear=NULL;
      free(temp);
      return data;
   }
   front=front->next;
   free(temp);
   return data;
}

void print(){
   if(front==NULL && rear==NULL){
      printf("the queue is empty...!\n");
      return;
   }
   struct node *temp=front;
   while(temp!=NULL){
      printf("%d ",temp->data);
      temp=temp->next;
   }
   printf("\n");
   return;
}

int main(){
   enqueue(1);
   enqueue(2);
   enqueue(3);
   enqueue(4);
   enqueue(5);
   print();
   int data=dequeue();
   printf("the dequeued element is :%d\n",data);
   print();
   return 0;
}

