#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void insertLast(struct Node **head, int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void display(struct Node **head) {
    struct Node *current = *head;
    printf("---\n");
    printf("Head: %p\n", *head);
    printf("---\n");
    if (*head == NULL)
    {
        printf("List is empty\n");
        printf("---\n");
        return;
    }
    
    while (current != NULL) {
        printf("Address: %p\n", current);
        printf("Data: %d\n", current->data);
        printf("Next: %p\n", current->next);
        printf("---\n");
        current = current->next;
    }
}

void displayArrow(struct Node **head) {
    struct Node *current = *head;
    printf("---\n");
    printf("Head: %p\n", *head);
    printf("---\n");
    if (*head == NULL)
    {
        printf("List is empty\n");
        printf("---\n");
        return;
    }
    
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
    printf("---\n");
}

// even first

void evenFirst(struct Node ** head){
    if((*head)->next == NULL){
        return;
    }
    struct Node *odd = *head;
    struct Node *even = (*head)->next;
    struct Node *newHead = even;
    while (even != NULL && even->next != NULL)
    {
        struct Node *temp = even->next;
        odd->next = temp;
        if (temp->next == NULL)
        {
            temp->next = NULL;
            break;
        }
        even->next = temp->next;
        odd = odd->next;
        even = even->next;
    }
    odd->next = NULL;
    even->next = *head;
    *head = newHead;
}



int main(){
    struct Node *head = NULL;
    for(int i = 1; i < 9; i++){
        insertLast(&head, i);
    }
    displayArrow(&head);
    evenFirst(&head);
    displayArrow(&head);
}