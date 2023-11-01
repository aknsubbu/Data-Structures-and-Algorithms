// incomplete 😀

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node * left;
    struct node * right;
};

int main(void)
{


}

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
        if (data > iter->data) 
        {
            parent = iter;
            iter = iter->left;
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


void bfsPrint(struct node* root)
{

}