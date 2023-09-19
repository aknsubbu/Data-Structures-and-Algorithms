#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node* getNode(int data){
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    p->data = data;
    p->next = NULL;
    p->prev = NULL;
    return p; 
}

void insertAtBeginning(struct Node** head, int newData) {
    struct Node* newNode = getNode(newData);

    newNode->next = *head;
    if (*head != NULL) {
        (*head)->prev = newNode;
    }

    *head = newNode;
}

void insertAtEnd(struct Node** head, int newData) {
    struct Node* newNode = getNode(newData);

    if (*head == NULL) {
        // If the list is empty, make the new node the head
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }

    printf("Node with data %d inserted at the end\n", newData);
}


void insertAfterNodex(int x,struct Node**head, int newData){
    struct Node* newNode = getNode(newData);

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current != NULL && current->data != x) {
            current = current->next;
        }
        if (current == NULL) {
            printf("Node with data %d not found\n", x);
            free(newNode);
            return;
        }
        newNode->next=current->next;
        if (current->next != NULL) {
            current->next->prev = newNode;
        }
        current->next=newNode;
        newNode->prev = current;
    }

    printf("Node with data %d inserted after %d\n", newData,x);
}

void insertBeforeNodex(int x,struct Node**head, int newData){
    struct Node* newNode = getNode(newData);

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current != NULL && current->data != x) {
            current = current->next;
        }
        if (current == NULL) {
            printf("Node with data %d not found\n", x);
            free(newNode);
            return;
        }
        newNode->next=current;
        newNode->prev = current->prev;
        if (current->prev != NULL) {
            current->prev->next = newNode;
        } else {
            *head = newNode;
        }
        current->prev=newNode;
    }

    printf("Node with data %d inserted before %d\n", newData,x);
}

void deleteNode(int x,struct Node**head){
    struct Node* current = *head;
    while (current != NULL && current->data != x) {
        current = current->next;
    }
    if (current == NULL) {
        printf("Node with data %d not found\n", x);
        return;
    }
    if (current->prev != NULL) {
        current->prev->next = current->next;
    } else {
        *head = current->next;
    }
    if (current->next != NULL) {
        current->next->prev = current->prev;
    }
    free(current);
    printf("Node with data %d deleted\n", x);
}

int main(){
    struct Node *head = NULL;

    //testing
    insertAtBeginning(&head, 1);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 4);

    insertAtEnd(&head, 5);
    insertAtEnd(&head, 6);
    insertAtEnd(&head, 7);

    insertAfterNodex(3,&head, 8);
    insertAfterNodex(5,&head, 9);
    insertAfterNodex(7,&head, 10);

    insertBeforeNodex(3,&head, 11);
    insertBeforeNodex(5,&head, 12);
    insertBeforeNodex(7,&head, 13);

    deleteNode(3,&head);
    deleteNode(5,&head);
    deleteNode(7,&head);
    return 0;
}