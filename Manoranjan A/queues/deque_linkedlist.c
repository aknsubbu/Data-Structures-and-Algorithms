//deque using linked list

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front=NULL;

void enqueue_front(int x)
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

void enqueue_rear(int x)
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
        newnode->next=front;
        front=newnode;
    }
}

void dequeue_front()
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

void dequeue_rear()
{
    struct node *temp,*prev;
    if(front==NULL)
    {
        printf("queue is empty\n");
        return;
    }
    temp=front;
    while(temp->next!=NULL)
    {
        prev=temp;
        temp=temp->next;
    }
    prev->next=NULL;
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
        printf("1.enqueue_front\n2.enqueue_rear\n3.dequeue_front\n4.dequeue_rear\n5.display\n6.exit\n");
        printf("enter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("enter the element to be inserted\n");
                scanf("%d",&x);
                enqueue_front(x);
                break;
            case 2:
                printf("enter the element to be inserted\n");
                scanf("%d",&x);
                enqueue_rear(x);
                break;
            case 3:
                dequeue_front();
                break;
            case 4:
                dequeue_rear();
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
            default:
                printf("invalid choice\n");
        }
    }
    return 0;
}