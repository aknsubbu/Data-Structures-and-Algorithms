//linked list insert at beginning 
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct node *getnode(int data);
struct node *toinsert(struct node *head,int n);
struct node{
    int data;
    struct node *next;
};

struct node *head=NULL;

void main(int arr[]){
    struct node *p1=getnode(1);
    struct node *p2=getnode(20);
    struct node *p3=getnode(30);
    struct node *p4=getnode(40);
    int n;
    printf("enter the node to be inserted at the beginning");
    scanf("%d",&n);
    head=toinsert(head,n);
    // struct node *p1;
    head->next=p1;
    p1->next=p2;
    p2->next=p3;
    p3->next=p4;
    display(head);
}

struct node *getnode(int data){
    struct node *head;
    head=(struct node *)malloc(sizeof(struct node));
    head->data=data;
    head->next=NULL;
    return head;
}

struct node *toinsert(struct node *head,int n){
    struct node *temp;
    temp=getnode(n);
    temp->next=head;
    head=temp;
    return head;
}

void display(struct node *head){
    struct node *temp;
    temp=head;
    while(temp!=NULL){
        if(!temp->data){
            printf("NULL ");
            temp=temp->next;
            continue;
        }
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

