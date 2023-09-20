#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *getData(int data) {
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    p->data = data;
    p->next = NULL;
    return p; 
}

void insertAtBeginning(struct Node** head, int newData){
    struct Node* newNode = getData(newData);

    newNode->next = *head;
    if (*head != NULL) {
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
    } else {
        newNode->next = newNode; 
    }

    *head = newNode;
}

int main(){
    struct Node* head = NULL; 

    insertAtBeginning(&head, 1);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 3);

    // Print the circular linked list
    struct Node* current = head;
    if (head != NULL) {
        do {
            printf("Data in the node: %d\n", current->data);
            current = current->next;
        } while (current != head);
    }

    return 0;
}
