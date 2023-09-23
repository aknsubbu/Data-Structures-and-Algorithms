#include<stdio.h>
#include<stdlib.h>

struct node *newLL();
struct node *getnode(int data);
void display(struct node *head);
struct node *insertatbeginning(struct node *head);
struct node *insertatend(struct node *head);
struct node *insertnnodesatbeginning(struct node *head);
struct node *insertnnodesatend(struct node *head);
struct node *search(struct node *head);
struct node *insertafter(struct node *head);
struct node *insertbefore(struct node *head);
struct node *delete(struct node *head);
struct node *deletelast(struct node *head);
struct node *deteteafter(struct node *head);

struct node{
    int data;
    struct node *next;
};

void main(){
    struct node *head = newLL();

    display(head);
    struct node *head2=deteteafter(head);
    display(head2);

}

struct node *newLL(){
    printf("Enter the number of nodes :");
    int numberofnodes;
    scanf("%d",&numberofnodes);
    struct node *start=NULL;
    struct node *old;
    for(int i=0;i<numberofnodes;i++){
        printf("enter the data :");
        int data;
        scanf("%d",&data);
        struct node *new=getnode(data);
        if(i==0){
            start=new;
            old=new;
        }
        else{
            old->next=new;
            old=new;
        }
    }
    return start;
}


struct node *getnode(int data){
    struct node *newnode=malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;     
}

void display(struct node *head){
    struct node *duplicate=head;
    while(duplicate!=NULL){
        printf("%d->",duplicate->data);
        duplicate=duplicate->next;
    }
    printf("NULL");
}


struct node *insertatbeginning(struct node *head){
    int data;
    printf("enter the data to be inserted at the beginning:");
    scanf("%d",&data);
    struct node *temp=getnode(data);
    temp->next=head;
    head=temp;
    return head;    
}

struct node *insertatend(struct node *head){
    struct node *temp=head;
    printf("enter the data to insert at end:");
    int data;
    scanf("%d",&data);
    struct node *new=getnode(data);
    if(temp==NULL){
        temp=new;
        return temp;
    }
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=new;
    return head;
}

struct node *insertnnodesatbeginning(struct node *head){
    int n ;
    printf("enter the number of nodes to be inserted at beginning:");
    scanf("%d",&n);
    struct node *temp=head;
    for(int i=0;i<n;i++){
         temp=insertatbeginning(temp);
    }
    return temp;
}

struct node *insertnnodesatend(struct node *head){
    int n;
    printf("enter the number of nodes to be inserted at the end:");
    scanf("%d",&n);
    struct node *temp=head;
    for(int i=0;i<n;i++){
        temp=insertatend(temp);
    }
    return temp;
}

struct node *search(struct node *head){
    int target;
    printf("enter the data to be searched for:");
    scanf("%d",&target);
    if(head==NULL){
        printf("linked list is empty");
        printf("----");
        return NULL;
    }
    struct node *temp=head;
    while(temp!=NULL){
        if(temp->data==target){
            printf("found:%d\n",temp->data);
            return temp;
        }
        temp=temp->next;
    }
    return NULL;
}

struct node *insertafter(struct node *head){
    struct node *prev=search(head);
    struct node *newnode=malloc(sizeof(struct node));
    printf("enter the data :");
    int data;
    scanf("%d",&data);
    newnode->data=data;
    struct node *next=prev->next;
    prev->next=newnode;
    newnode->next=next;
    return head;

}

struct node *insertbefore(struct node *head){
    struct node *next=search(head);
    struct node *newnode=malloc(sizeof(struct node));
    int data;
    printf("enter the data:");
    scanf("%d",&data);
    newnode->data=data;
    newnode->next=next;
    struct node *current=head;
    while(current->next!=next){
        current=current->next;
    }
    current->next=newnode;
    return head;
}

struct node *delete(struct node *head){
    if(head==NULL){
        return NULL;
    }
    head=head->next;
    return head;
}


struct node *deletelast(struct node *head){
    if(head==NULL){
        printf("the list is empty");
        return NULL;
    }
    struct node *temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    temp->next=NULL;
    return head;
}

struct node *deteteafter(struct node *head){
    if(head==NULL){
        printf("the list is empty");
        return NULL;
    }
    struct node *prev=search(head);
    struct node *del=prev->next;
    prev->next=del->next;
    return head;
}