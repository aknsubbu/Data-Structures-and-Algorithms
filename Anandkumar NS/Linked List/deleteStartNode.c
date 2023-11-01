#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void deletefirstNode(struct Node ** head){
    struct Node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deletelastElement(struct Node **head){
    struct Node* current = *head;
    struct Node* after = current->next;
    while (1) {
        if(after->next==NULL){
            current->next=NULL;
            break;
        }
        current = after;
        after = after->next;
    }
    printf("NULL\n");
}

void insertAtBeginning(struct Node** head, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    newNode->data = newData;

    newNode->next = *head;

    *head = newNode;
}

// Function to print the elements of the linked list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

struct Node *getData(int data) {
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    p->data = data;
    p->next = NULL;
    return p; 
}

int main() {
    // Linked List with one element
    // struct Node* head1 = (struct Node*)malloc(sizeof(struct Node));
    // if (head1 == NULL) {
    //     printf("Memory allocation failed.\n");
    //     return 1; //  error code
    // }
    // head1->data = 1; //  data of the head node
    // head1->next = NULL;
    // insertAtBeginning(&head1, 3);
    // printf("Linked List with one element insert with function: ");
    // printList(head1);
    // printf("Linked List with one element above");

    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");

    return 0;
}