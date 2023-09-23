// //circular singly linked list

// #include<stdio.h>
// #include<stdlib.h>

// struct node *getnode(int data);

// struct node{
//     int data;
//     struct node *next;
// }start;

// int main(){
//     struct node *st=getnode(1);
//     struct node *p2=getnode(13);
//     struct node *p3=getnode(5);
//     st->next=p2;
//     p2->next=p3;
//     p3->next=st;
//     print(st);
//     return 0;    
// }

// void print(struct node *start){
//     struct node *temp=start;
//     do{
//         printf("the values of data is :%d\n",temp->data);
//         temp=temp->next;
//     }while(temp!=start);   
// }

// struct node *getnode(int data){
//    struct node *head;
//    head=(struct node *)malloc(sizeof(struct node));
//    head->data=data;
//    head->next=NULL;
//    return head;
// }



#include<Stdio.h>
#include<stdlib.h>

void main(){
    int range=INT_MAX;   
}