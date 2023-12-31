//queue using linked list

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front=NULL;

void enqueue(int x)
{
    struct node *temp,*newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=NULL;
    if(front==NULL)
    {
        front=newnode;
    }
    else
    {
        temp=front;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
    }
}

void dequeue()
{
    struct node *temp;
    if(front==NULL)
    {
        printf("queue is empty\n");
        return;
    }
    temp=front;
    front=front->next;
    free(temp);
}

void display()
{
    struct node *temp;
    if(front==NULL)
    {
        printf("queue is empty\n");
        return;
    }
    temp=front;
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
        printf("1.enqueue\n");
        printf("2.dequeue\n");
        printf("3.display\n");
        printf("4.exit\n");
        printf("enter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("enter the element to be inserted\n");
                scanf("%d",&x);
                enqueue(x);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
        }
    }
    return 0;
}

