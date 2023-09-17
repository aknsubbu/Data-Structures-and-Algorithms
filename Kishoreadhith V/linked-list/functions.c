#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node * next;
} *start;

struct Node * getNode(int data){
    struct Node * p = (struct Node *) malloc (sizeof(struct Node));
    p -> data = data;
    p -> next = NULL;
    return p;
}

void display(struct Node * start){
    struct Node * current = start;
    while (current != NULL)
    {
        printf("address: %p\n", current);
        printf("data = %d\n", current -> data);
        printf("next address: %p\n", current -> next);
        printf("---");
        current = current -> next;
    }    
}

struct Node * search(struct Node * start, int target){
    struct Node * current = start;
    while (current != NULL)
    {
        if (current -> data == target)
        {
            return current;
        }        
        current = current -> next;
    }
}

void insertEnd(struct Node ** head, int data){
    struct Node * p = (struct Node *) malloc (sizeof(struct Node));
    p -> data = data;
    p -> next = *head;
    *head = p;
}

void insertAfterNodex(struct Node * node, struct Node * position){
    struct Node * temp = position -> next;
    position -> next = node;
    node -> next = temp;
}

int main(){
    struct Node *p1, *p2, *p3, *pnew;
    p1 = getNode(10);
    p2 = getNode(20);
    p3 = getNode(30);
    p1 -> next = p2;
    p2 -> next = p3;
    start = p1;
    display(start);
}