#include<stdio.h>
#include<stdlib.h>

struct deque{
    int *arr;
    int front;
    int rear;
};

int isEmpty(struct deque *dq){
    return dq->front== -1;
}

int isFull(struct deque *dq,int size){
     return (dq->front==0 && dq->rear==size-1)||(dq->front - dq->rear==1);
}


void initialize(struct deque *dq,int size){
    dq->arr=malloc(size*sizeof(int));
    dq->front=-1;
    dq->rear=-1;
}

void insertfront(struct deque *dq,int data,int size){
    if(isEmpty(dq)){
        dq->front =0;
        dq->rear=0;
    }
    else if(dq->front==0){
        dq->front=size-1;
    }
    else{
        dq->front--;
    }
    dq->arr[dq->front]=data;
}

void insertrear(struct deque *dq,int data, int size){
    if(isFull(dq,size)){
        printf("the deque is overflown....!");
        return;
    }
    if(isEmpty(dq)){
        dq->front=0;
        dq->rear=0;
    }else if(dq->rear==size-1){
        dq->rear=0;
    }else{
        dq->rear++;
    }
    dq->arr[dq->rear]=data;
}


void display(struct deque *dq, int size){
    if(isEmpty(dq)){
        printf("the deque is empty....!");
        return;
    }
    int i=dq->front;
    do{
        printf("%d ",dq->arr[i]);
        i=(i+1)%size;
    }while(i != (dq->rear + 1)% size);
    printf("\n");
}


int getFront(struct deque *dq){
    if(isEmpty(dq)){
        printf("the deque is empty....!");
        return -1;
    }
    return dq->arr[dq->front];
}


int getrear(struct deque *dq){
    if(isEmpty(dq)){
        printf("the deque is empty...!");
        return -1;
    }
    return dq->arr[dq->rear];
}

int  deletedFront(struct deque *dq,int size){
   if(isEmpty(dq)){
    printf("the deque is empty...!");
    return -1 ;
   }
   int data=dq->arr[dq->front];
   if(dq->front==dq->rear){
      dq->front=-1;
      dq->rear=-1;
   }else if(dq->front ==size -1){
      dq->front =0;
   }else{
    dq->front ++;
   }
   return data;
}

int deleterear(struct deque *dq,int size){
    if(isEmpty(dq)){
        printf("the deque is empty.....!");
        return -1;
    }
    int data= dq->arr[dq->rear];
    if(dq->front==dq->rear){
        dq->rear=-1;
        dq->front=-1;
    }else if(dq->rear==0){
        dq->rear=size-1;
    }
    else{
        dq->rear--;
    }
    return data;
}

int main(){
    struct deque dq;
    int n;
    printf("enter the number of elements:");
    scanf("%d",&n);
    initialize(&dq,n);
   
    insertfront(&dq,1,n);
    insertrear(&dq,2,n);
    insertfront(&dq,3,n);
    insertrear(&dq,4,n);

    display(&dq,n);

    int front=getFront(&dq);
    int rear=getrear(&dq);
    printf("The front is %d and the rear is : %d\n",front,rear);


    int frontdel=deletedFront(&dq,n);
    int reardel=deleterear(&dq,n);
     
    printf("the deleted elements are :%d and %d\n",frontdel,reardel);
    display(&dq,n);
}