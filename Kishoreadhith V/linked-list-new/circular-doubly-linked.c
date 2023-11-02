#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node * getNode(int val){
    struct Node * newNode = (struct Node *) malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    newNode->prev = NULL;
}

void insertFirst(struct Node ** head, int val){
    struct Node * newNode = getNode(val);
    if(*head == NULL){
        newNode->next = newNode;
        newNode->prev = newNode;
        *head = newNode;
        return;
    }
    newNode->next = *head;
    struct Node * last = (*head)->prev;
    (*head)->prev = newNode;
    newNode->prev = last;
    last->next = newNode;
    *head = newNode;
}

void insertLast(struct Node ** head, int val){
    struct Node * newNode = getNode(val);
    if(*head == NULL){
        newNode->next = newNode;
        newNode->prev = newNode;
        *head = newNode;
        return;
    }
    struct Node * last = (*head)->prev;
    last->next = newNode;
    newNode->prev = last;
    newNode->next = *head;
    (*head)->prev = newNode;
}

void display(struct Node * head){
    struct Node *current = head;
    printf("---\n");
    printf("Head: %p\n", head);
    printf("---\n");
    if (head == NULL)
    {
        printf("List is empty\n");
        printf("---\n");
        return;
    }    
    do
    {
        printf("Address: %p\n", current);
        printf("Data: %d\n", current->data);
        printf("Prev: %p\n", current->prev);
        printf("Next: %p\n", current->next);
        printf("---\n");
        current = current->next;
    } while (current != head);    
}

struct Node * search(struct Node ** head, int target){
    if (*head == NULL)
    {
        printf("List is empty\n");
        printf("---\n");
        return NULL;
    }
    struct Node *current = *head;
    do
    {
        if (current->data == target)
        {
            return current;
        }
        current = current->next;
    } while (current != NULL);
    return NULL;    
}

void insertBefore(struct Node ** head,int target, int data){
    struct Node * next = search(head, target);
    struct Node *newNode = getNode(data);
    newNode->next = next;
    newNode->prev = next->prev;
    newNode->prev->next = newNode;
    next->prev = newNode;
}

void insertAfter(struct Node ** head, int target, int val){
    struct Node * prev = search(head, target);
    struct Node * newNode = getNode(val);
    newNode->prev = prev;
    newNode->next = prev->next;
    prev->next = newNode;
    newNode->next->prev = newNode;
}

void deleteNode(struct Node * node){
    if (node == NULL)
    {
        printf("Node not found\n");
        return;
    }
    node->prev->next = node->next;
    node->next->prev = node->prev;
    free(node);
}

void deleteFirst(struct Node ** head){
    if(*head == NULL){
        printf("List is empty\n");
        return;
    }
    struct Node * del = *head;
    deleteNode(del);    
}

void deleteLast(struct Node ** head){
    if(*head == NULL){
        printf("List is empty\n");
        return;
    }
    struct Node *del = (*head)->prev;
    deleteNode(del);
}

void deleteBefore(struct Node ** head, int target){
    struct Node * next = search(head, target);
    deleteNode(next->prev);
}

void deleteAfter(struct Node ** head, int target){
    struct Node * prev = search(head, target);
    deleteNode(prev->next);
}

int main(){
    struct Node * head = NULL;
    display(head);
    insertFirst(&head, 1);
    insertFirst(&head, 2);
    insertFirst(&head, 3);
    display(head);
    insertLast(&head, 4);
    insertLast(&head, 5);
    display(head);
    return 0;
}