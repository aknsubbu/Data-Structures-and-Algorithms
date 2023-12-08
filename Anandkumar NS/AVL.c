//create an avl tree with 29
//insert 30,5

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
    // int height;
};


struct node *createNode(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    // newNode->height = 1;
    return newNode;
}

int height(struct node *root)
{
    if (root == NULL)
        return 0;
    return 1 + fmax(height(root->left), height(root->right));
}

int getBalanceFactor(struct node *root)
{
    if (root == NULL)
        return 0;
    return height(root->left) - height(root->right);
}

struct node *leftRotate(struct node *root)
{
    struct node *newRoot = root->right;
    root->right = newRoot->left;
    newRoot->left = root;
    return newRoot;
}

struct node *rightRotate(struct node *root)
{
    struct node *newRoot = root->left;
    root->left = newRoot->right;
    newRoot->right = root;
    return newRoot;
}

struct node *insert(struct node *root, int data)
{
    if (root == NULL)
        return createNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    else
        return root;

    int balanceFactor = getBalanceFactor(root);

    if (balanceFactor > 1 && data < root->left->data)
        return rightRotate(root);
    if (balanceFactor < -1 && data > root->right->data)
        return leftRotate(root);
    if (balanceFactor > 1 && data > root->left->data)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balanceFactor < -1 && data < root->right->data)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

