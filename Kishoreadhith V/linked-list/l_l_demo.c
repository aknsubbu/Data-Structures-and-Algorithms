#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node * next;
} *start;

// struct Node * get_node(int data, struct ){
//     struct Node * p = (struct Node *) malloc (sizeof(struct Node));
//     p -> data = data;
//     p -> next = NULL;
//     return p;
// }

void insertNode(struct Node ** head, int data){
    struct Node * p = (struct Node *) malloc (sizeof(struct Node));
    p -> data = data;
    p -> next = *head;
    *head = p;
}

void insertEnd(struct Node ** head, int data){
    struct Node * p = (struct Node *) malloc (sizeof(struct Node));
    p -> data = data;
    p -> next = *head;
    *head = p;
}

void displayFrom(struct Node * head){
    struct Node * current = head;
    while (current != NULL)
    {
        printf("data = %d\n", current -> data);
        current = current -> next;
    }    
}

int main(){
    struct Node * head = NULL;
    for (int i = 0; i < 5; i++)
    {
        insertNode(&head, i);
    }
    displayFrom(head);      
}