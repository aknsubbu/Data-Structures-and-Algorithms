#include<stdio.h>
struct node{int data;struct node *next;};
//allocate space for this node
struct node* getnode(int data){
    struct node *p;
   p=(struct node*)malloc(sizeof(struct node));
   p->data=data;
   p->next=NULL;

   return p;
}
void display(struct node *start){
    struct node *p;
    p=start;
    while(p!=NULL){
        printf("%d\n",p->data);
        p=p->next;
    }
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
    

}