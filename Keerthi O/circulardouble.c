#include<stdio.h>
#include<stdlib.h>
struct node{int data;struct node *next; struct node* prev;};
//circular doubly linked list
struct node *head=NULL;
struct node *tail=NULL;
struct node *createnode(int data){
    struct node *n=(struct node*)malloc(sizeof(struct node));
    n->data=data;
    n->next=NULL;
    n->prev=NULL;
    return n;
}

// struct node* insertatpos(int data,int pos){
//     struct node *n=createnode(data);
//     struct node *ptr=head;
//     int i=1;
//     while(i<pos-1){
//         ptr=ptr->next;
//         i++;
//     }
//     n->next=ptr->next;
//     ptr->next->prev=n;
//     ptr->next=n;
//     n->prev=ptr;
//     return head;
//}
//given the data in a node insert after that particular data
struct node * insertaftx(int data,int x){
    struct node *n=createnode(data);
    struct node *ptr=head;
    while(ptr->data!=x){
        ptr=ptr->next;
    }
    n->next=ptr->next;
    ptr->next->prev=n;
    ptr->next=n;
    n->prev=ptr;
    return head;
}

struct node *deleteaftx(int data,int x){
    struct node *ptr=head;
    while(ptr->data!=x){
        ptr=ptr->next;
    }
    ptr->next=ptr->next->next;
    ptr->next->prev=ptr;
    return head;
}

void display(){
     struct node *ptr=head;
    do{
        printf("%d ",ptr->data);
        ptr=ptr->next;}
    while(ptr!=head);
    printf("\n");
}
//print adresses of node+
void address(){
    struct node *ptr=head;
    do{
        printf("%p",ptr);
        ptr=ptr->next;
        printf("\n");
    }
    while(ptr!=head);
}

// struct node *deleteatpos(int pos){
//     struct node *ptr=head;
//     int i=1;
//     while(i<pos-1){
//         ptr=ptr->next;
//         i++;
//     }
//     ptr->next=ptr->next->next;
//     ptr->next->prev=ptr;
//     return head;
// }

//insert before x
struct node *insertbefore(int data,int x){
    struct node *p=head;
    struct node *n=createnode(data);
    while(p->next->data!=x){
        p=p->next;
    }
    n->next=p->next;
    p->next->prev=n;
    p->next=n;
    n->prev=p;
    return head;
}
// delete before x
struct node *deletebefore(int x){
    struct node *p=head;
    while(p->next->next->data!=x){
        p=p->next;
    }
    p->next=p->next->next;
    p->next->prev=p;
    return head;
}


int main(){
    //crcular linked list
    struct node *n1=createnode(10);
    struct node *n2=createnode(20);
    struct node *n3=createnode(30);
    struct node *n4=createnode(40);
    struct node *n5=createnode(50);
    n1->next=n2;
    n2->next=n3;
    n3->next=n4;
    n4->next=n5;
    n5->next=n1;
    n1->prev=NULL;
    n2->prev=n1;
    n3->prev=n2;
    n4->prev=n3;
    n5->prev=n4;
    head=n1;
    tail=n5;
    //traversing
    display();
    printf("\n");
    address();
    printf("\n");
    struct node *p;
    // p=insertatpos(25,3);
    // display();
    // p=deleteatpos(3);
    // display();
    p=insertaftx(25,20);
    display();
    printf("\n");
    address();
    printf("\n");
    p=deleteaftx(25,20);
    display();
    printf("\n");
    address();
    printf("\n");
    p=insertbefore(25,30);
    display();
    printf("\n");
    p=deletebefore(25);
    display();


}