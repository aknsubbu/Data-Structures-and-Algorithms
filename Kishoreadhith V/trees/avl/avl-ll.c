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

struct Node * bst_iter(struct Node ** root, int num){
    int data;
    for (int i = 0; i < num; i++)
    {
        printf("Enter data: ");
        scanf("%d", &data);
        struct Node *newNode = getNode(data);
        if(*root == NULL){
            *root = newNode;
        }
        else{
            struct Node *temp = *root;
            while(temp != NULL){
                if(data < temp->data){
                    if(temp->left == NULL){
                        temp->left = newNode;
                        break;
                    }
                    else{
                        temp = temp->left;
                    }
                }
                else{
                    if(temp->right == NULL){
                        temp->right = newNode;
                        break;
                    }
                    else{
                        temp = temp->right;
                    }
                }
            }
        }
    }    
}

struct Node * search(struct Node * root, int target, int *child_side){
    if (root -> data == target)
    {
        *child_side = 0;
        return root;
    }
    else if (root -> left -> data == target)
    {
        *child_side = 1;
        return root;
    }
    else if (root -> right -> data == target)
    {
        *child_side = 2;
        return root;
    }  
    else if (target < root -> data)
    {
        search(root->left, target, child_side);
    }
    else if (target > root -> data)
    {
        search(root->right, target, child_side);
    }
    else
    {
        printf("Not found\n");
        return NULL;
    }
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

void bst_insert(struct Node **root, int data){
    struct Node *newNode = getNode(data);
    if(*root == NULL){
        *root = newNode;
    }
    else{
        struct Node *temp = *root;
        while(temp != NULL){
            if(data < temp->data){
                if(temp->left == NULL){
                    temp->left = newNode;
                    break;
                }
                else{
                    temp = temp->left;
                }
            }
            else{
                if(temp->right == NULL){
                    temp->right = newNode;
                    break;
                }
                else{
                    temp = temp->right;
                }
            }
        }
    }
}

void avl_insert_rec(struct Node **root, int data){
    if(*root == NULL){
        *root = getNode(data);
    }
    else{
        if(data < (*root)->data){
            avl_insert_rec(&((*root)->left), data);
        }
        else{
            avl_insert_rec(&((*root)->right), data);
        }
    }
    rotate(*root);
}

int height(struct Node *root){
    if(root == NULL){
        return 0;
    }
    else{
        int left_height = height(root->left);
        int right_height = height(root->right);
        if(left_height > right_height){
            return left_height + 1;
        }
        else{
            return right_height + 1;
        }
    }
}

struct Node* rotate(struct Node *root){
    int left_height = height(root->left);
    int right_height = height(root->right);
    if (left_height - right_height > 1)
    {
        if (height(root->left->left) > height(root->left->right))
        {
            return right_rotate(root);
        }
        else
        {
            root->left = left_rotate(root->left);
            return right_rotate(root);
        }
    }
    else if (right_height - left_height > 1)
    {
        if (height(root->right->right) > height(root->right->left))
        {
            return left_rotate(root);
        }
        else
        {
            root->right = right_rotate(root->right);
            return left_rotate(root);
        }
    }
}

struct Node* left_rotate(struct Node *root){
    struct Node *newRoot = root->right;
    root->right = newRoot->left;
    newRoot->left = root;
    return newRoot;
}

struct Node* right_rotate(struct Node *root){
    struct Node *newRoot = root->left;
    root->left = newRoot->right;
    newRoot->right = root;
    return newRoot;
}

int main(){
    struct Node *root = NULL;
    int num;
    printf("Enter number of nodes: ");
    scanf("%d", &num);
    for(int i = 0; i < num; i++){
        int data;
        printf("Enter data: ");
        scanf("%d", &data);
        avl_insert_rec(&root, data);
        display_tree(root, 0);
        printf("\n\n");
    }
    return 0;
}