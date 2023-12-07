#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node * left;
    struct node * right;
};

struct node* getNode(int data)
{
    struct node* new = malloc(sizeof(struct node));
    new->data = data;
    new->left = NULL;
    new->right = NULL;
    return new;
}

struct node* reconstruct(char* in, char* pre, struct node* node) {
    if (pre[0] == "\0") return NULL; 

    char curChar = pre[0];
    strncpy(pre, pre + 1, strlen(pre) + 1);

    if (!node) {
        node = getNode(curChar);
    }

    node -> left = reconstruct(in, pre, node);
    node -> right = reconstruct(in, pre, node);

    
}

int main(void) {
    char* inOrder = "DBEAFC";
    char* preOrder = "ABDECF";


}