#include <stdio.h>
#include <stdlib.h>

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

int main() {
  struct Node* root = NULL;  
  root = insert(root, 15);
  root = insert(root, 10);
  root = insert(root, 20);

  inOrder(root);

  return 0;
}