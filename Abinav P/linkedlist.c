//linked list

#include<stdio.h>
#include<Stdlib.h>

struct node *getnode(int data);

struct node{
    int data;
    struct node *next;
}start;

int main(){
    struct node *st=getnode(1);
    struct node *p2=getnode(13);
    struct node *p3=getnode(5);
    st->next=p2;
    p2->next=p3;
    p3->next=NULL;
    print(st);
    print(st);
    return 0;
    
}

void print(struct node *start){
    while(start!=NULL){
        printf("the values of data is :%d\n",start->data);
        start=start->next;
    }
    
}



struct node *getnode(int data){
   struct node *head;
   head=(struct node *)malloc(sizeof(struct node));
   head->data=data;
   head->next=NULL;
   return head;
}

