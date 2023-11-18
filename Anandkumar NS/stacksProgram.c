//fucntions to create update delete and print a stack

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

struct Node* push(struct Node* root,int value){
  struct Node* newNode=createNode(value);
  newNode->next=root;
  root=newNode;
  return root;
}

struct Node* pop(struct Node* root){
  if(root==NULL){
    printf("Stack is empty\n");
    return root;
  }
  struct Node* temp=root;
  root=root->next;
  free(temp);
  return root;
}

void printStack(struct Node* root){
  if(root==NULL){
    printf("Stack is empty\n");
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
  root=push(root,10);
  root=push(root,20);
  root=push(root,30);
  root=push(root,40);
  root=push(root,50);
  printStack(root);
  root=pop(root);
  root=pop(root);
  printStack(root);
  return 0;
}

