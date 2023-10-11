#include<stdio.h>
#include<stdlib.h>

struct node *newLL();
struct node *getnode(int data);
void display(struct node *head);


struct node {
    int data;
    struct node *next,*prev;

};

void main(){
    struct node *head=NULL;
    head=newLL();
    display(head);
}


struct node *newLL(){
    int count=0;
    printf("enter the number of elements in the linked list:");
    scanf("%d",&count);
    struct node *current,*old;
    for(int i=0;i<count;i++){
        int data;
        printf("enter the data :");
        scanf("%d",&data);
        struct node *newnode=getnode(data);
        if(i==0){
            current=newnode;
            old=newnode;
        }else{
        old->next=newnode;
        newnode->prev=old;
        old=newnode;
        }
    }
    return current;
}

struct node *getnode(int data){
    struct node *newnode=malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    newnode->prev=NULL;
    return newnode;
}

void display(struct node *head){
    struct node *current=head;
    while(current!=NULL){
        printf("(%p)%d(%p)<->",current->prev,current->data,current->next);
        current=current->next;
    }
 
    printf("NULL");
}