// functions to create update read and delete queue

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct Node{
  int value;
  struct Node *next;
};

struct Node* createNode(int value){
  struct Node* newNode=malloc(sizeof(struct Node));
  newNode->value=value;
  newNode->next=NULL;
  return newNode;
}

struct Node* enqueue(struct Node* root,int value){
  struct Node* newNode=createNode(value);
  if(root==NULL){
    root=newNode;
    return root;
  }
  struct Node* temp=root;
  while(temp->next!=NULL){
    temp=temp->next;
  }
  temp->next=newNode;
  return root;
}

struct Node* dequeue(struct Node* root){
  if(root==NULL){
    printf("Queue is empty\n");
    return root;
  }
  struct Node* temp=root;
  root=root->next;
  free(temp);
  return root;
}

void printQueue(struct Node* root){
  if(root==NULL){
    printf("Queue is empty\n");
    return;
  }
  struct Node* temp=root;
  while(temp!=NULL){
    printf("%d ",temp->value);
    temp=temp->next;
  }
  printf("\n");
}

int main(){
  struct Node* root=NULL;
  root=enqueue(root,10);
  root=enqueue(root,20);
  root=enqueue(root,30);
  root=enqueue(root,40);
  root=enqueue(root,50);
  printQueue(root);
  root=dequeue(root);
  root=dequeue(root);
  printQueue(root);
  return 0;
}

