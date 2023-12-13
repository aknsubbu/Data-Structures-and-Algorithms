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

int balance_factor(struct Node *root){
    if(root == NULL){
        return 0;
    }
    else{
        int left_height = height(root->left);
        int right_height = height(root->right);
        return left_height - right_height;
    }
}

struct Node * left_rotate(struct Node *root){
    struct Node *newRoot = root->right;
    root->right = newRoot->left;
    newRoot->left = root;
    return newRoot;
}

struct Node * right_rotate(struct Node *root){
    struct Node *newRoot = root->left;
    root->left = newRoot->right;
    newRoot->right = root;
    return newRoot;
}

struct Node * left_right_rotate(struct Node *root){
    struct Node *newRoot = root->left;
    root->left = left_rotate(newRoot);
    return right_rotate(root);
}

struct Node * right_left_rotate(struct Node *root){
    struct Node *newRoot = root->right;
    root->right = right_rotate(newRoot);
    return left_rotate(root);
}

struct Node * balance(struct Node *root){
    if(root == NULL){
        return NULL;
    }
    else{
        root->left = balance(root->left);
        root->right = balance(root->right);
        int bf = balance_factor(root);
        if(bf > 1){
            if(balance_factor(root->left) > 0){
                root = right_rotate(root);
            }
            else{
                root = left_right_rotate(root);
            }
        }
        else if(bf < -1){
            if(balance_factor(root->right) < 0){
                root = left_rotate(root);
            }
            else{
                root = right_left_rotate(root);
            }
        }
        return root;
    }
}

struct Node * bst_delete(struct Node *root, int data){
    if(root == NULL){
        return NULL;
    }
    else{
        if(data < root->data){
            root->left = bst_delete(root->left, data);
        }
        else if(data > root->data){
            root->right = bst_delete(root->right, data);
        }
        else{
            if(root->left == NULL && root->right == NULL){
                free(root);
                return NULL;
            }
            else if(root->left == NULL){
                struct Node *temp = root->right;
                free(root);
                return temp;
            }
            else if(root->right == NULL){
                struct Node *temp = root->left;
                free(root);
                return temp;
            }
            else{
                struct Node *temp = root->right;
                while(temp->left != NULL){
                    temp = temp->left;
                }
                root->data = temp->data;
                root->right = bst_delete(root->right, temp->data);
            }
        }
        root = balance(root);
        return root;
    }
}

// avl insert
struct Node * avl_insert(struct Node *root, int data){
    if(root == NULL){
        root = getNode(data);
        return root;
    }
    else{
        if(data < root->data){
            root->left = avl_insert(root->left, data);
        }
        else if(data > root->data){
            root->right = avl_insert(root->right, data);
        }
        else{
            printf("Duplicate data!\n");
            return root;
        }
        root = balance(root);
        return root;
    }
}

// avl delete
struct Node * avl_delete(struct Node *root, int data){
    if(root == NULL){
        return NULL;
    }
    else{
        if(data < root->data){
            root->left = avl_delete(root->left, data);
        }
        else if(data > root->data){
            root->right = avl_delete(root->right, data);
        }
        else{
            if(root->left == NULL && root->right == NULL){
                free(root);
                return NULL;
            }
            else if(root->left == NULL){
                struct Node *temp = root->right;
                free(root);
                return temp;
            }
            else if(root->right == NULL){
                struct Node *temp = root->left;
                free(root);
                return temp;
            }
            else{
                struct Node *temp = root->right;
                while(temp->left != NULL){
                    temp = temp->left;
                }
                root->data = temp->data;
                root->right = avl_delete(root->right, temp->data);
            }
        }
        root = balance(root);
        return root;
    }
}

int main(){
    struct Node *root = NULL;
    int num, data, target, child_side;
    printf("Enter number of nodes: ");
    scanf("%d", &num);
    bst_iter(&root, num);
    display_tree(root, 0);
    printf("Enter data to insert: ");
    scanf("%d", &data);
    bst_insert(&root, data);
    display_tree(root, 0);
    printf("Enter data to delete: ");
    scanf("%d", &data);
    root = bst_delete(root, data);
    display_tree(root, 0);
    printf("Enter data to search: ");
    scanf("%d", &target);
    struct Node *parent = search(root, target, &child_side);
    printf("Parent: %d\n", parent->data);
    printf("Child side: %d\n", child_side);
    printf("Height: %d\n", height(root));
    return 0;
}