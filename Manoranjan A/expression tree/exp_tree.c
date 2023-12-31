#include <stdio.h>
#include <stdlib.h>
 
struct Node
{
    char data;
    struct Node *left;
    struct Node *right;
};
 
struct Node *createNode(char data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
 
struct Node *buildExpressionTree(char postfix[])
{
    struct Node *stack[100];
    int top = -1;
 
    for (int i = 0; postfix[i] != '\0'; i++)
    {
        if (isalnum(postfix[i]))
        {
            struct Node *newNode = createNode(postfix[i]);
            stack[++top] = newNode;
        }
        else
        {
            struct Node *newNode = createNode(postfix[i]);
            newNode->right = stack[top--];
            newNode->left = stack[top--];
            stack[++top] = newNode;
        }
    }
 
    return stack[top];
}
 
void inorderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        printf("%c ", root->data);
        inorderTraversal(root->right);
    }
}
 
int main()
{
    char postfix[] = "ab+ef*g*-";
    struct Node *root = buildExpressionTree(postfix);
 
    printf("Inorder traversal of expression tree: ");
    inorderTraversal(root);
 
    return 0;
}
