#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node * next, * prev;
};

struct Node * getNode(int val){
    struct Node * newNode = (struct Node *) malloc(sizeof(struct Node *));
    newNode->data = val;
    newNode->next = NULL;
    newNode->prev = NULL;
}

void insertFirst(struct Node ** head, int val){
    if (*head == NULL)
    {
    struct Node * newNode = getNode(val);
    *head = newNode;
    }
    
    struct Node * newNode = getNode(val);
    newNode->next = *head;
    newNode->next->prev = newNode;
    *head = newNode;
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
    while (current != NULL) {
        printf("Address: %p\n", current);
        printf("Data: %d\n", current->data);
        printf("Prev: %p\n", current->prev);
        printf("Next: %p\n", current->next);
        printf("---\n");
        current = current->next;
    }
}

void InsertLast(struct Node ** head, int val){
    if (*head == NULL)
    {
        struct Node * newNode = getNode(val);
        *head = newNode;
        return;
    }
    
    struct Node * newNode = getNode(val);
    struct Node * current = *head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;
}

struct Node * search(struct Node ** head, int target){
    if (*head == NULL)
    {
        printf("List is empty\n");
        printf("---\n");
        return NULL;
    }
    struct Node *current = *head;
    while (current != NULL)
    {
        if (current->data == target)
        {
            return current;
        }
        current = current->next;
    }
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

void deleteFirst(struct Node ** head){
    if(*head == NULL){
        return;
    }
    struct Node * del = *head;
    *head = del->next;
    (*head)->prev = NULL;
    free(del);
}


void deleteNode(struct Node * node){
    if (node == NULL)
    {
        printf("Node not found\n");
        return;
    }
    if (node->next == NULL)
    {
        node->prev->next = NULL;
        free(node);
        return;
    }
    node->prev->next = node->next;
    node->next->prev = node->prev;
    free(node);
}

void deleteLast(struct Node ** head){
    if(*head == NULL){
        printf("List is empty\n");
        return;
    }
    struct Node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    deleteNode(temp);
}
void deleteNodeOf(struct Node ** head, int val){
    struct Node * del = search(head, val);
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
    display(head);
    insertFirst(&head, 3);
    display(head);
}