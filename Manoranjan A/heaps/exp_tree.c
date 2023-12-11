#include<stdio.h>
#include<stdlib.h>

struct node
{
    char data;
    struct node *left,*right;
};

struct node *stack[20];

int top=-1;

void push(struct node *temp)
{
    stack[++top]=temp;
}

struct node *pop()
{
    return(stack[top--]);
}

int check(char ch)
{
    if(ch=='+'||ch=='-'||ch=='*'||ch=='/')
        return 2;
    else
        return 1;
}

void inorder(struct node *temp)
{
    if(temp!=NULL)
    {
        inorder(temp->left);
        printf("%c",temp->data);
        inorder(temp->right);
    }
}

void main()
{
    struct node *temp;
    char postfix[20];
    int i=0;
    printf("Enter the postfix expression\n");
    scanf("%s",postfix);
    while(postfix[i]!='\0')
    {
        temp=(struct node*)malloc(sizeof(struct node));
        temp->data=postfix[i];
        temp->left=NULL;
        temp->right=NULL;
        if(check(postfix[i])==1)
            push(temp);
        else
        {
            temp->right=pop();
            temp->left=pop();
            push(temp);
        }
        i++;
    }
    printf("The inorder traversal of the expression tree is\n");
    inorder(stack[top]);
}

//insertion and deletion in singly,doubly and circular linked list(all cases)
//matrix multiplication, transporse and printing
//push pop using ll and array
//evaluaion
//infix to postfix
//circular queue ll and array
//binary search tree insertion and deletion 
