#include <stdio.h>
#include <stdlib.h>

struct node
{
    char data;
    struct node *next;
};

struct node *top=NULL;

void push(char x)
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=x;
    temp->next=top;
    top=temp;
}

char pop()
{
    struct node *temp;
    char x;
    if(top==NULL)
    {
        printf("stack is empty\n");
        return -1;
    }
    temp=top;
    x=temp->data;
    top=top->next;
    free(temp);
    return x;
}

void display()
{
    struct node *temp;
    if(top==NULL)
    {
        printf("stack is empty\n");
        return;
    }
    temp=top;
    while(temp!=NULL)
    {
        printf("%c ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int priority(char x)
{
    if(x=='(')
        return 0;
    if(x=='+' || x=='-')
        return 1;
    if(x=='*' || x=='/')
        return 2;
}

int main()
{
    char exp[20],*e,x;
    printf("enter the expression\n");
    scanf("%s",exp);
    e=exp;
    while(*e!='\0')
    {
        if(isalnum(*e))
            printf("%c",*e);
        else if(*e=='(')
            push(*e);
        else if(*e==')')
        {
            while((x=pop())!='(')
                printf("%c",x);
        }
        else
        {
            while(priority(top->data)>=priority(*e))
                printf("%c",pop());
            push(*e);
        }
        e++;
    }
    while(top!=NULL)
    {
        printf("%c",pop());
    }
    return 0;
}