// #include <stdio.h>
// #include <stdlib.h>

// #define MAX_SIZE 100

// struct Deque {
//     int arr[MAX_SIZE];
//     int front, rear;
// };

// void initialize(struct Deque* dq) {
//     dq->front = -1;
//     dq->rear = -1;
// }

// int isEmpty(struct Deque* dq) {
//     return dq->front == -1;
// }

// int isFull(struct Deque* dq) {
//     return (dq->front == 0 && dq->rear == MAX_SIZE - 1) || (dq->front == dq->rear + 1);
// }

// void insertFront(struct Deque* dq, int data) {
//     if (isFull(dq)) {
//         printf("Deque is full, cannot insert at the front.\n");
//         return;
//     }
//     if (isEmpty(dq)) {
//         dq->front = dq->rear = 0;
//     } else if (dq->front == 0) {
//         dq->front = MAX_SIZE - 1;
//     } else {
//         dq->front--;
//     }
//     dq->arr[dq->front] = data;
// }

// void insertRear(struct Deque* dq, int data) {
//     if (isFull(dq)) {
//         printf("Deque is full, cannot insert at the rear.\n");
//         return;
//     }
//     if (isEmpty(dq)) {
//         dq->front = dq->rear = 0;
//     } else if (dq->rear == MAX_SIZE - 1) {
//         dq->rear = 0;
//     } else {
//         dq->rear++;
//     }
//     dq->arr[dq->rear] = data;
// }

// int deleteFront(struct Deque* dq) {
//     if (isEmpty(dq)) {
//         printf("Deque is empty, cannot delete from the front.\n");
//         return -1;
//     }
//     int data = dq->arr[dq->front];
//     if (dq->front == dq->rear) {
//         dq->front = dq->rear = -1;
//     } else if (dq->front == MAX_SIZE - 1) {
//         dq->front = 0;
//     } else {
//         dq->front++;
//     }
//     return data;
// }

// int deleteRear(struct Deque* dq) {
//     if (isEmpty(dq)) {
//         printf("Deque is empty, cannot delete from the rear.\n");
//         return -1;
//     }
//     int data = dq->arr[dq->rear];
//     if (dq->front == dq->rear) {
//         dq->front = dq->rear = -1;
//     } else if (dq->rear == 0) {
//         dq->rear = MAX_SIZE - 1;
//     } else {
//         dq->rear--;
//     }
//     return data;
// }

// int getFront(struct Deque* dq) {
//     if (isEmpty(dq)) {
//         printf("Deque is empty.\n");
//         return -1;
//     }
//     return dq->arr[dq->front];
// }

// int getRear(struct Deque* dq) {
//     if (isEmpty(dq)) {
//         printf("Deque is empty.\n");
//         return -1;
//     }
//     return dq->arr[dq->rear];
// }

// void display(struct Deque* dq) {
//     if (isEmpty(dq)) {
//         printf("Deque is empty.\n");
//         return;
//     }

//     int i = dq->front;
//     do {
//         printf("%d ", dq->arr[i]);
//         i = (i + 1) % MAX_SIZE;
//     } while (i != (dq->rear + 1) % MAX_SIZE);
//     printf("\n");
// }

// int main() {
//     struct Deque dq;
//     initialize(&dq);

//     insertFront(&dq, 1);
//     insertRear(&dq, 2);
//     insertFront(&dq, 3);
//     insertRear(&dq, 4);

//     display(&dq);

//     int front = getFront(&dq);
//     int rear = getRear(&dq);
//     printf("Front: %d, Rear: %d\n", front, rear);

//     int deletedFront = deleteFront(&dq);
//     int deletedRear = deleteRear(&dq);

//     printf("Deleted from Front: %d, Deleted from Rear: %d\n", deletedFront, deletedRear);

//     display(&dq);

//     return 0;
// }


#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Deque {
    struct Node* front;
    struct Node* rear;
};

void initialize(struct Deque* dq) {
    dq->front = NULL;
    dq->rear = NULL;
}

int isEmpty(struct Deque* dq) {
    return dq->front == NULL;
}

void insertFront(struct Deque* dq, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = dq->front;

    if (isEmpty(dq)) {
        dq->front = newNode;
        dq->rear = newNode;
    } else {
        dq->front->prev = newNode;
        dq->front = newNode;
    }
}

void insertRear(struct Deque* dq, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = dq->rear;
    newNode->next = NULL;

    if (isEmpty(dq)) {
        dq->front = newNode;
        dq->rear = newNode;
    } else {
        dq->rear->next = newNode;
        dq->rear = newNode;
    }
}

int deleteFront(struct Deque* dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty, cannot delete from the front.\n");
        return -1;
    }

    int data = dq->front->data;
    struct Node* temp = dq->front;

    if (dq->front == dq->rear) {
        dq->front = NULL;
        dq->rear = NULL;
    } else {
        dq->front = dq->front->next;
        dq->front->prev = NULL;
    }

    free(temp);
    return data;
}

int deleteRear(struct Deque* dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty, cannot delete from the rear.\n");
        return -1;
    }

    int data = dq->rear->data;
    struct Node* temp = dq->rear;

    if (dq->front == dq->rear) {
        dq->front = NULL;
        dq->rear = NULL;
    } else {
        dq->rear = dq->rear->prev;
        dq->rear->next = NULL;
    }

    free(temp);
    return data;
}

int getFront(struct Deque* dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty.\n");
        return -1;
    }

    return dq->front->data;
}

int getRear(struct Deque* dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty.\n");
        return -1;
    }

    return dq->rear->data;
}

void display(struct Deque* dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty.\n");
        return;
    }

    struct Node* current = dq->front;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Deque dq;
    initialize(&dq);

    insertFront(&dq, 1);
    insertRear(&dq, 2);
    insertFront(&dq, 3);
    insertRear(&dq, 4);

    display(&dq);

    int front = getFront(&dq);
    int rear = getRear(&dq);
    printf("Front: %d, Rear: %d\n", front, rear);

    int deletedFront = deleteFront(&dq);
    int deletedRear = deleteRear(&dq);

    printf("Deleted from Front: %d, Deleted from Rear: %d\n", deletedFront, deletedRear);

    display(&dq);

    return 0;
}
