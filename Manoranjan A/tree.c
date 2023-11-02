// traverse inorder the left sub tree
// process root
// traverse inorder the right sub tree

#include<stdio.h>
#include<stdlib.h>

void inorder(int *tree, int i)
{
    if(tree[i] != -1)
    {
        inorder(tree, 2*i+1);
        printf("%d ", tree[i]);
        inorder(tree, 2*i+2);
    }
}

void preorder(int *tree, int i)
{
    if(tree[i] != -1)
    {
        printf("%d ", tree[i]);
        preorder(tree, 2*i+1);
        preorder(tree, 2*i+2);
    }
}

void postorder(int *tree, int i)
{
    if(tree[i] != -1)
    {
        postorder(tree, 2*i+1);
        postorder(tree, 2*i+2);
        printf("%d ", tree[i]);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int *tree = (int *)malloc(n*sizeof(int));
    for(int i=0; i<n; i++)
        scanf("%d", &tree[i]);
    inorder(tree, 0);
    printf("\n");
    preorder(tree, 0);
    printf("\n");
    postorder(tree, 0);
    printf("\n");
    return 0;
    
}

