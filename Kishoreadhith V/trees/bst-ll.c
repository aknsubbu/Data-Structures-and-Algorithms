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

void inorder(struct Node *root){
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);    
}

void preorder(struct Node *root){
    if (root == NULL)
    {
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);    
}

void postorder(struct Node *root){
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);    
    printf("%d ", root->data);
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
    els        
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
    printf("Enter number of nodes: ");
    scanf("%d", &num);
    bst_iter(&root, num);
    display_tree(root, 0);
    printf("\nInorder: ");
    inorder(root);
    printf("\nPreorder: ");
    preorder(root);
    printf("\nPostorder: ");
    postorder(root);
    return 0;
}
