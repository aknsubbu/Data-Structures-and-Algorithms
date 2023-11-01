//create a linked list 
#include<stdio.h>
#include<stdlib.h>
struct node{ 
    int data;
    struct node *next;};
    struct node *head=NULL;

 struct node * create(int data){
     struct node *temp;
     temp=(struct node*)malloc(sizeof(struct node));
     temp->data=data;
     temp->next=NULL;
     return temp;
 }

struct node *deleteatpos(struct node *p,int pos){
    struct node *temp;
    int i;
    if(pos==1){
        temp=p;
        p=p->next;
        free(temp);
        return p;
    }
    for(i=0;i<pos-2;i++){
        p=p->next;
    }
    temp=p->next;
    p->next=temp->next;
    free(temp);
    return head;
}
int main(){
    struct node *node1,*node2,*node3;
    int n2=1;
    int n1=13,n3=5;
    node1=create(n1);
    node2=create(n2);
    node3=create(n3);
    node1->next=node2;
    node2->next=node3;
    head=node1;
    struct node *start;
    start=head;
    int pos=2;
    head=deleteatpos(start,pos);
    start=head;
    while(start!=NULL){
        printf("%d\n",start->data);
        start=start->next;
    }
}