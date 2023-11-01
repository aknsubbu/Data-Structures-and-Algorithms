#include<stdio.h>
#include<stdlib.h>
struct node{int data;struct node *next;};
//allocate space for this node
struct node* getnode(int data){
    struct node *p;
   p=(struct node*)malloc(sizeof(struct node));
   p->data=data;
   p->next=NULL;

   return p;
}
struct node *head=NULL;


struct node* insertatbeg(struct node* p ,int data){
    struct node *temp;
    temp=getnode(data);
    temp->next=p;
    p=temp;
    return p;
}

struct node * insertatend(struct node *p,int data){
    struct node *temp;
    temp=getnode(data);
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=temp;
    return p;
}
// insert n nodes at the beginning of the list
struct node * insertatbegn(struct node *p,int n){
    int i;
    for(i=0;i<n;i++){
        p=insertatbeg(p,i);
    }
    return p;
}
// insert n nodes at the end of the list
struct node * insertatendn(struct node *p,int n){
    int i;
    for(i=0;i<n;i++){
        p=insertatend(p,i);
    }
    return p;
}
//search for a node with given data value
struct node* search(struct node *p,int data){
    while(p!=NULL){
        if(p->data==data){
            return p;
        }
        p=p->next;
    }
}

//search takes start pointer and stat value
//returns pointer to the node if found
struct node* searchptr( struct node *start,struct node *ptr){
    while(start!=NULL){
        if(start==ptr){
            return start;
        }
        start=start->next;
    }
    return NULL;
}
//returns pointer to the node if found


//display() print all nodes including start address data part node address
struct node *display(struct node *start){
    struct node *p;
    p=start;
    while(p!=NULL){
        printf("%d  ",p->data);
        p=p->next;
    }
    printf("\n");
}
// insert after a given node
struct node * insertafter(struct node *p,int data,int item){
    struct node *temp;
    temp=getnode(data);
    struct node *ptr;
    ptr=search(p,item);
    temp->next=ptr->next;
    ptr->next=temp;
    return p;
}

// insert before a given node
struct node* insertbefore(struct node*p,int data,int item){
    struct node*temp;
    temp=getnode(data);
    struct node *ptr;
    ptr=search(p,data);
    while(p->next!=ptr){
        p=p->next;
    }
    temp->next=ptr;
    p->next=temp;
    return p;
}

int main(){
    struct node *node1,*node2,*node3;
    int n2=1;
    int n1=13,n3=5;
    node1=getnode(n1);
    node2=getnode(n2);
    node3=getnode(n3);
    node1->next=node2;
    node2->next=node3;
     // printf("%d\n",node1->data);
     // printf("%d\n",node1->next->data);
     // printf("%d\n",node1->next->next->data);
     //create a start pointer
    struct node *start;
    start=node1;
    display(start);
    // printf("insert at beg\n");
    // start=insertatbeg(start,0);
    // display(start);
    // printf("insert at end\n");
    // start=insertatend(start,6);
    // display(start);
    // printf("insert at beg n\n");
    // start=insertatbegn(start,3);
    // display(start);
    // printf("insert at end n\n");
    // start=insertatendn(start,3);
    // display(start);
    // printf("search\n");
    // struct node *ptr;
    // struct node *k;
    // ptr=search(start,5);
    // printf("%d\n",ptr->data);
    // printf("searchptr\n");
    // k=searchptr(start,ptr);
    // printf("%p",k);
    start=insertafter(start,5,5);
    display(start);
    start=insertbefore(start,5,1);
    display(start);







       
}

