#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void insertFirst(struct Node **head, int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

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

void insertFirstN(struct Node **head, int n) {
    int val;
    for (int i = 0; i < n; i++) {
        printf("Enter data for new Node: ");
        scanf("%d", &val);
        insertFirst(head, val);
    }
}

void insertLastN(struct Node **head, int n) {
    int val;
    for (int i = 0; i < n; i++) {
        printf("Enter data for new Node: ");
        scanf("%d", &val);
        insertLast(head, val);
    }
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

void insertAfter(struct Node ** head,int target, int data){
    struct Node * prev = search(head, target);
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    struct Node * next = prev->next;
    prev->next = newNode;
    newNode->next = next;
}

void insertBefore(struct Node ** head,int target, int data){
    struct Node * next = search(head, target);
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = next;
    struct Node * current = *head;
    while (current->next != next)
    {
        current = current->next;
    }
    current->next = newNode;
}

void deleteFirst(struct Node ** head){
    if(*head == NULL){
        return;
    }
    struct Node * del = *head;
    *head = del->next;
    free(del);
}

void deleteLast(struct Node ** head){
    if(*head == NULL){
        printf("List is empty\n");
        return;
    }
    struct Node *temp = *head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    struct Node * del = temp->next;
    temp->next = NULL;
    free(del);
}

void deleteNode(struct Node ** head, int target){
    struct Node * targetNode = search(head, target);
    struct Node * current = *head;
    while (current->next != targetNode)
    {
        current = current->next;
    }
    struct Node * del = current->next;
    current->next = del->next;
    free(del);
}

void deleteAfter(struct Node ** head, int target){
    struct Node * prev = search(head, target);
    struct Node * del = prev->next;
    prev->next = del->next;
    free(del);
}


void deleteBefore(struct Node ** head, int target){
    struct Node * next = search(head, target);
    struct Node * current = *head;
    while (current->next->next != next)
    {
        current = current->next;
    }
    struct Node * del = current->next;
    current->next = next;
    free(del);
}

int main() {
    struct Node *head = NULL;
    // int n;
    // printf("Enter number of nodes: ");
    // scanf("%d", &n);
    // display(&head);
    // insertLastN(&head, n);
    // display(&head);
    // printf("Enter value to search: ");
    // int target;
    // scanf("%d", &target);
    // struct Node *result = search(&head, target);
    // if (result != NULL)
    // {
    //     printf("Element found at %p\n", result);
    // } else {
    //     printf("Element not found\n");
    // }
    // for (int i = 0; i < 5; i++)
    // {
    //     insertLast(&head, i);
    // }
    // display(&head);
    // printf("Enter value before which you want to insert: ");
    // int target;
    // scanf("%d", &target);
    // printf("Enter value to insert: ");
    // int data;
    // scanf("%d", &data);
    // insertBefore(&head, target, data);
    // display(&head);
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    insertLastN(&head, n);
    display(&head);
    printf("Enter value after which you want to delete: ");
    int target;
    scanf("%d", &target);
    deleteAfter(&head, target);
    display(&head);
    printf("Enter value before which you want to delete: ");
    scanf("%d", &target);
    deleteBefore(&head, target);
    display(&head);
    printf("Enter value to delete: ");
    scanf("%d", &target);
    deleteNode(&head, target);
    display(&head);
    
    return 0;
}
