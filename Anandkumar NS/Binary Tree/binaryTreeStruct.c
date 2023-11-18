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


//create a function to traverse the tree and find the node
struct Node* findNode(struct Node *root,int data){
  if(root==NULL){
    return NULL;
  }
  if(root->value==data){
    return root;
  }
  else if(root->value>data){
    return findNode(root->left,data);
  }
  else{
    return findNode(root->right,data);
  }
}


void deleteNode(struct Node *element,int data){
  struct Node *root=findNode(element,data);
  if(root==NULL){
    return;
  }
  if(root->value==data){
    if(root->left==NULL && root->right==NULL){
      free(root);
      root=NULL;
    }
    else if(root->left==NULL && root->right!=NULL){
      struct Node *temp=root;
      root=root->right;
      free(temp);
      printf("Right Child is promoted\n");
    }
    else if(root->right==NULL && root->left!=NULL){
      struct Node *temp=root;
      root=root->left;
      free(temp);
      printf("Left Child is promoted\n");
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

// ! Notes
// ! Find the in-order successor of the node that needs to be deleted
// ! It will always be a leaf node or a node with only one child
// ! It will be in the left-most position of the right subtree of the node to be delete
// ! Replace the node to be deleted with the in-order successor
// ! Delete the in-order successor

// * Find the in-order successor
struct Node* findInorderSuccessor(struct Node *root){
  struct Node *temp=root->right;
  while(temp->left!=NULL){
    temp=temp->left;
  }
  return temp;
}


int main() {
  struct Node* root = NULL;  
  root = insert(root, 15);
  root = insert(root, 10);
  root = insert(root, 20);

  inOrder(root);

  return 0;
}