#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node * getNode(int data){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void buildTree(struct Node * node){
    int data, choice;
    printf("Do you want to enter left child of %d? (1/0): ", node->data);
    scanf("%d", &choice);
    if (choice == 1)
    {
        printf("Enter data: ");
        scanf("%d", &data);
        node->left = getNode(data);
        buildTree(node->left);
    }
    printf("Do you want to enter right child of %d? (1/0): ", node->data);
    scanf("%d", &choice);
    if (choice == 1)
    {
        printf("Enter data: ");
        scanf("%d", &data);
        node->right = getNode(data);
        buildTree(node->right);
    }   
}

void display(struct Node *root){
    if (root == NULL)
    {
        return;
    }
    display(root->left);
    printf("%d ", root->data);
    display(root->right);    
}

void display_tree(struct Node *root, int level){
    if (root == NULL)
    {
        return;
    }
    display_tree(root->right, level + 1);
    for (int i = 0; i < level; i++)
    {
        printf("|\t");
    }
    printf("|------>%d\n", root->data);
    display_tree(root->left, level + 1);
}

int main(){
    struct Node *root = NULL;
    int num;
    printf("Enter data: ");
    scanf("%d", &num);
    root = getNode(num);
    buildTree(root);
    display_tree(root, 0);
    return 0;
}