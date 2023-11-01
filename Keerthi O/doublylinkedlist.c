#include<stdio.h>
#include<stdlib.h>
struct node { int data;struct node* next;struct node* prev;} ;

struct node* getnode(int data){
    struct node *p;
    p=(struct node*)malloc(sizeof(struct node));
    p->data=data;
    p->next=NULL;
    p->prev=NULL;
    return p;


}
struct node* insertatend(struct node *p,int data){
    struct node *q;
    q=getnode(data);
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=q;
    q->prev=p;
    return q;
}

void display(struct node *p){
    while(p!=NULL){
        printf("%d",p->data);
        p=p->next;
    }
    printf("\n");
    
}

struct node* insertatbeg(struct node *p,int data){
    struct node *q;
    q=getnode(data);
    q->next=p;
    p->prev=q;
    return q;
}

struct node* insertatpos(struct node *p,int data,int pos){
    struct node *q,*r;
    q=getnode(data);
    int i=1;
    while(i<pos-1){
        p=p->next;
        i++;
    }
    r=p->next;
    p->next=q;
    q->prev=p;
    q->next=r;
    r->prev=q;
    return q;
}

int main(){
    //doubly linked list
    int data1=1,data2=2,data3=3;
    struct node *p,*start;
    p=getnode(data1);
    start=p;
    p->next=getnode(data2);
    p->prev=NULL;
    p->next->next=getnode(data3);
    p->next->prev=p;
    p->next->next->next=NULL;
    p->next->next->prev=p->next;
    display(p);
    p=insertatbeg(p,0);
    display(p);
    p=insertatend(p,4);
    display(start);
    p=insertatpos(start,5,5);
    display(start);
}