struct Queue{
    int size;
    int arr[size];
    int* front;
    int* rear;
}

struct PQueue{
    int priority;
    struct Queue* cur;
    struct Queue* next;
}

typedef struct Queue Queue;
typedef struct PQueue PQueue;

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

void enqueuePriority(PQueue* pq,int val,int p){
    PQueue* temp = pq;
    int bigP = pq->priority;
    while(temp->next){
        if(temp->priority > bigP){
            enqueue(temp->cur->arr,temp->cur->front,temp->cur->rear,temp->cur->size,val);
            return;
        }
        temp = temp->next;
    }
    printf("Priority Not Found");
}

int isEmpty(Queue* q){
    if(q->*front == -1) return 0;
    return -1;
}

int dequeuePriority(PQueue* pq){
    PQueue* temp = pq;
    PQueue* biggest = temp;
    while(temp->next){
        if(temp->priority > p){
            bigP = temp->priority;
        }
        temp = temp->next;
    }
    while(temp->next){
        if(temp->priority == p){
            return dequeue(temp->cur,temp->cur->*front,temp->cur->*rear,temp->cur->size);
        }
        temp = temp->next;
    }
    printf("Priority Not Found");
    return -99999;
}

PQueue* createPQueue(){
    PQueue* newPQ = 
}