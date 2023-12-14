//stacks using linked list

#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int data;
    struct stack *next;
};

struct stack *top=NULL;

void push(int x)
{
    struct stack *temp;
    temp=(struct stack*)malloc(sizeof(struct stack));
    temp->data=x;
    temp->next=top;
    top=temp;
}

void pop()
{
    struct stack *temp;
    if(top==NULL)
    {
        printf("stack is empty\n");
        return;
    }
    temp=top;
    top=top->next;
    free(temp);
}

void display()
{
    struct stack *temp;
    if(top==NULL)
    {
        printf("stack is empty\n");
        return;
    }
    temp=top;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main()
{
    int ch,x;
    while(1)
    {
        printf("1.push\n");
        printf("2.pop\n");
        printf("3.display\n");
        printf("4.exit\n");
        printf("enter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("enter the element to be pushed\n");
                   scanf("%d",&x);
                   push(x);
                   break;
            case 2:pop();
                   break;
            case 3:display();
                   break;
            case 4:exit(0);
        }
    }
    return 0;
}