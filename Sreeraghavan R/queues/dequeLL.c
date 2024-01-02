#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* prev;
    struct node* next;
};

typedef struct node node;

struct Deque {
    node* front;
    node* rear;
};
typedef struct Deque Deque;

node* createNode(int data) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

Deque* createDeque() {
    Deque* deque = (Deque*)malloc(sizeof(Deque));
    deque->front = NULL;
    deque->rear = NULL;
    return deque;
}

int isEmpty(Deque* deque) {
    return (deque->front == NULL);
}

void insertFront(Deque* deque, int data) {
    node* newNode = createNode(data);
    if (isEmpty(deque)) {
        deque->front = newNode;
        deque->rear = newNode;
    } else {
        newNode->next = deque->front;
        deque->front->prev = newNode;
        deque->front = newNode;
    }
}

void insertRear(Deque* deque, int data) {
    node* newNode = createNode(data);
    if (isEmpty(deque)) {
        deque->front = newNode;
        deque->rear = newNode;
    } else {
        newNode->prev = deque->rear;
        deque->rear->next = newNode;
        deque->rear = newNode;
    }
}

void deleteFront(Deque* deque) {
    if (isEmpty(deque)) {
        printf("UNDERFLOW\n");
    } else {
        node* temp = deque->front;
        deque->front = deque->front->next;
        if (deque->front == NULL) {
            deque->rear = NULL;
        } else {
            deque->front->prev = NULL;
        }
        free(temp);
    }
}

void deleteRear(Deque* deque) {
    if (isEmpty(deque)) {
        printf("UNDERFLOW\n");
    } else {
        node* temp = deque->rear;
        deque->rear = deque->rear->prev;
        if (deque->rear == NULL) {
            deque->front = NULL;
        } else {
            deque->rear->next = NULL;
        }
        free(temp);
    }
}

void display(Deque* deque) {
    if (isEmpty(deque)) {
        printf("EMPTY QUEUE\n");
    } else {
        node* current = deque->front;
        while (current != NULL) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

int main() {
    Deque* deque = createDeque();

    insertFront(deque, 10);
    insertFront(deque, 20);
    insertRear(deque, 30);
    insertRear(deque, 40);

    display(deque);

    deleteFront(deque);
    deleteRear(deque);

    display(deque);

    return 0;
}
