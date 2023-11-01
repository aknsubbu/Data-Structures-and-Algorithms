#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Node {
  int value;
  struct Node *left;
  struct Node *right;
};

struct Node* createNode(int value) {
  struct Node* newNode = malloc(sizeof(struct Node));
  newNode->value = value;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

struct Node* insert(struct Node* root, int value) {
  if (root == NULL) {
    return createNode(value);
  }

  if (value < root->value) {
    root->left = insert(root->left, value);
  } else {
    root->right = insert(root->right, value);
  }

  return root;
}

void inOrder(struct Node* root) {
  if (root == NULL) return;

  inOrder(root->left);
  printf("%d ", root->value);
  inOrder(root->right);
}


void deleteNode(struct Node *root,int data){
  if(root==NULL){
    return;
  }
  if(root->value==data){
    if(root->left==NULL && root->right==NULL){
      free(root);
      root=NULL;
    }
    else if(root->left==NULL){
      struct Node *temp=root;
      root=root->right;
      free(temp);
    }
    else if(root->right==NULL){
      struct Node *temp=root;
      root=root->left;
      free(temp);
    }
    else{
      struct Node *temp=root->right;
      while(temp->left!=NULL){
        temp=temp->left;
      }
      root->value=temp->value;
      deleteNode(root->right,temp->value);
    }
  }
  else if(root->value>data){
    deleteNode(root->left,data);
  }
  else{
    deleteNode(root->right,data);
}

}



int main() {
  struct Node* root = NULL;  
  root = insert(root, 15);
  root = insert(root, 10);
  root = insert(root, 20);

  inOrder(root);

  return 0;
}