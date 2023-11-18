// incomplete 😀

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node * left;
    struct node * right;
};

struct node* insertNode(struct node* root, int data)
{   
    if (root == NULL)
    {
        root = getNode(data);
        return root;
    }

    struct node* iter = root, *parent = NULL;

    while (iter)
    {
        if (data < iter->data) 
        {
            if (iter->left)
            {
                iter = iter->left;
            }
            else
            {
                
            }
           
        }
        else 
        {
            parent = iter;
            iter = iter -> right;
        }
    }
    parent = getNode(data);
    return root;
}

struct node* getNode(int data)
{
    struct node* new = malloc(sizeof(struct node));
    new->data = data;
    new->left = NULL;
    new->right = NULL;
    return new;
}

struct node* newTree()
{
    int num;
    printf("How many elemnets do you want in your tree? ");
    scanf("%d", &num);

    struct node* tree = NULL;
    for
}

int main(void)
{


}

void bfsPrint(struct node* root)
{

}

struct node* inorderPredecessor(struct node* node)
{
    struct node* curr = node -> right;

    while(curr -> left)
    {
        curr = curr -> left;
    }
    return curr;
}

// case 3 - 2 children
// 1. find the inorder successor of the node to be deleted (it will be compulsorily leaf node or node with only right child.)
// 2. replace the value of the node to be deleted with the value in the inorder successor.
// 3. delete the inorder successor.