#include<stdio.h>
#include<stdlib.h>


struct Node{
    struct Node *next, *prev;
    int data;
};

//circular doubly linked list

struct Node* getdata(int data, struct Node *head){
    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next = NULL;
    newnode->prev = NULL;
    if(head == NULL){
        head = newnode;
        head->next = head;
        head->prev = head;
    }
    else{
        struct Node *temp = head;
        while(temp->next != head){
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->prev = temp;
        newnode->next = head;
        head->prev = newnode;
    }
    return head;
}

void display(struct Node *head){
    struct Node *temp = head;
    while(temp->next != head){
        printf("Data - %d ", temp->data);
        printf("Current Address - %p ", temp);
        printf("Next - %p ", temp->next);
        temp = temp->next;
    }
    printf("%d ", temp->data);
}

struct Node* insertAtEnd(int data, struct Node *head){
    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next = NULL;
    newnode->prev = NULL;
    if(head == NULL){
        head = newnode;
        head->next = head;
        head->prev = head;
    }
    else{
        struct Node *temp = head;
        while(temp->next != head){
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->prev = temp;
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }
    return head;
}

void insertAtStart(int data, struct Node *head){
    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next = NULL;
    newnode->prev = NULL;
    if(head == NULL){
        head = newnode;
        head->next = head;
        head->prev = head;
    }
    else{
        struct Node *temp = head;
        head=newnode;
        head->next = temp;
        head->prev = temp;
        
    }
}