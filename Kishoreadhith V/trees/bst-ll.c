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

struct Node * inorder_successor(struct Node *root, int target){
    int child_side;
    struct Node *parent = search(root, target, &child_side);
    if(parent == NULL){
        printf("Target not found in tree\n");
        return NULL;
    }
    struct Node *temp = NULL;
    if (child_side = 0)
    {
        if (parent -> right != NULL)
        {
            temp = parent -> right;
            while (temp -> left != NULL)
            {
                temp = temp -> left;
            }
            return temp;
        }
        else
        {
            printf("No inorder successor\n");
            return NULL;
        }        
    }
    else if (child_side = 1)
    {
        if (parent -> left -> left == NULL && parent -> left -> right == NULL)
        {
            return parent;
        }
        if (parent -> right ->right != NULL)
        {
            temp = parent -> right -> right;
            while (temp -> left != NULL)
            {
                temp = temp -> left;
            }
            return temp;
        }
        else
        {
            return parent;
        }
    }
    else if (child_side = 2)
    {
        while (child_side == 2)
        {
            parent = search(root, parent -> data, &child_side);
        }
        if (child_side == 1)
        {
            return parent;
        }
        else
        {
            printf("No inorder successor\n");
            return NULL;
        }
    }    
}

struct Node * inorder_predecessor(struct Node *root, int target){
    int child_side;
    struct Node *parent = search(root, target, &child_side);
    if(parent == NULL){
        printf("Target not found in tree\n");
        return NULL;
    }
    struct Node *temp = NULL;
    if (child_side == 0)
    {
        if (parent -> left != NULL)
        {
            temp = parent -> left;
            while (temp -> right != NULL)
            {
                temp = temp -> right;
            }
            return temp;
        }
        else
        {
            printf("No inorder predecessor\n");
            return NULL;
        }        
    }
    else if (child_side == 1)
    {
        if (parent -> left ->left != NULL)
        {
            temp = parent -> left -> left;
            while (temp -> right != NULL)
            {
                temp = temp -> right;
            }
            return temp;
        }
        else
        {
            while (child_side == 1)
            {
                parent = search(root, parent -> data, &child_side);
            }
            if (child_side == 2)
            {
                return parent;
            }
            printf("No inorder predecessor\n");
            return NULL;
        }              
    }
    else if (child_side == 2)
    {
        if (parent -> right ->left != NULL)
        {
            temp = parent -> right -> left;
            while (temp -> right != NULL)
            {
                temp = temp -> right;
            }
            return temp;
        }
        else
        {
            return parent;
        }
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

void delete(struct Node ** root, int target){
    int child_side;
    struct Node * parent = search(*root, target, &child_side);
    // printf("Parent: %d\n", parent->data);
    struct Node * tn = NULL;
    switch (child_side){
        case 0:
            tn = parent;
            break;
        case 1:
            tn = parent->left;
            break;
        case 2:
            tn = parent->right;
            break;
    }
    // no children
    if (tn ->left == NULL && tn->right == NULL)
    {
        switch (child_side)
        {
        case 0:
            printf("root node deleted\n");
            *root = NULL;
            free(tn);
            return;
        case 1:
            parent->left = NULL;
            free(tn);
            return;
        case 2:
            parent->right;
            free(tn);
            return;
        }
    }
    // only left child
    if (tn->left != NULL && tn->right == NULL)
    {
        printf("only left child\n");
        switch (child_side)
        {
        case 0:
            parent = parent->left;
            free(tn);
            return;
        case 1:
            parent->left = tn->left;
            free(tn);
            return;
        
        case 2:
            parent->right = tn->left;
            free(tn);
            return;
        }
    }
    // only right child
    if (tn->left == NULL && tn->right != NULL)
    {
        printf("only right child\n");
        switch (child_side)
        {
        case 0:
            parent = parent->right;
            free(tn);
            return;
        case 1:
            parent->left = tn->right;
            free(tn);
            return;
        
        case 2:
            parent->right = tn->right;
            free(tn);
            return;
        }
    }
    // two children
    struct Node *successor = inorder_successor(*root, target);
    tn->data = successor->data;
    delete(root, successor->data);
}

int main(){
    struct Node *root = NULL;
    int num;
    printf("Enter number of nodes: ");
    scanf("%d", &num);
    bst_iter(&root, num);
    display_tree(root, 0);
    // printf("\nInorder: ");
    // inorder(root);
    // printf("\nPreorder: ");
    // preorder(root);
    // printf("\nPostorder: ");
    // postorder(root);
    printf("Enter element to search: ");
    int target;
    scanf("%d", &target);
    int child_side;
    struct Node *parent = search(root, target, &child_side);
    printf("Parent: %d\n", parent->data);
    switch (child_side)
    {
    case 0:
        printf("this node is the target node\n");
        break;
    case 1:
        printf("Left child\n");
        break;
    case 2:
        printf("Right child\n");
        break;
    default:
        break;
    }
    // struct Node *inorder_successor_node = inorder_successor(root, target);
    // if(inorder_successor_node != NULL)
    //     printf("Inorder successor: %d\n", inorder_successor_node->data);
    // struct Node *inorder_predecessor_node = inorder_predecessor(root, target);
    // if(inorder_predecessor_node != NULL)
    //     printf("Inorder predecessor: %d\n", inorder_predecessor_node->data);
    // printf("Inorder: ");
    // inorder(root);
    delete(&root, target);
    display_tree(root, 0);

    return 0;
}
