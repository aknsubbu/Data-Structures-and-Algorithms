// #include <stdio.h>
// #define MAX_SIZE 100

// // Structure to represent a priority queue
// typedef struct {
//     int data[MAX_SIZE];
//     int size;
// } PriorityQueue;

// // Function to initialize the priority queue
// void init(PriorityQueue *pq) {
//     pq->size = 0;
// }

// // Function to check if the priority queue is empty
// int isEmpty(PriorityQueue *pq) {
//     return pq->size == 0;
// }

// // Function to check if the priority queue is full
// int isFull(PriorityQueue *pq) {
//     return pq->size == MAX_SIZE;
// }

// // Function to insert an element into the priority queue
// void insert(PriorityQueue *pq, int item) {
//     if (isFull(pq)) {
//         printf("Priority Queue is full. Cannot insert element.\n");
//         return;
//     }

//     int i = pq->size - 1;
//     while (i >= 0 && pq->data[i] > item) {
//         pq->data[i + 1] = pq->data[i];
//         i--;
//     }

//     pq->data[i + 1] = item;
//     pq->size++;
// }

// // Function to remove the highest priority element from the priority queue
// int removeHighestPriority(PriorityQueue *pq) {
//     if (isEmpty(pq)) {
//         printf("Priority Queue is empty. Cannot remove element.\n");
//         return -1;
//     }

//     int highestPriority = pq->data[pq->size - 1];
//     pq->size--;

//     return highestPriority;
// }

// // Function to display the elements of the priority queue
// void display(PriorityQueue *pq) {
//     if (isEmpty(pq)) {
//         printf("Priority Queue is empty.\n");
//         return;
//     }

//     printf("Priority Queue elements: ");
//     for (int i = pq->size - 1; i >= 0; i--) {
//         printf("%d ", pq->data[i]);
//     }
//     printf("\n");
// }

// int main() {
//     PriorityQueue pq;
//     init(&pq);

//     insert(&pq, 5);
//     insert(&pq, 3);
//     insert(&pq, 8);
//     insert(&pq, 1);

//     display(&pq);

//     int highestPriority = removeHighestPriority(&pq);
//     printf("Removed element with highest priority: %d\n", highestPriority);

//     display(&pq);

//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the priority queue
typedef struct Node {
    int data;
    int priority;
    struct Node* next;
} Node;

// Structure to represent a priority queue
typedef struct {
    Node* front;
} PriorityQueue;

// Function to initialize the priority queue
void init(PriorityQueue* pq) {
    pq->front = NULL;
}

// Function to check if the priority queue is empty
int isEmpty(PriorityQueue* pq) {
    return pq->front == NULL;
}

// Function to create a new node
Node* createNode(int data, int priority) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;
    return newNode;
}

// Function to insert an element into the priority queue
void insert(PriorityQueue* pq, int item, int priority) {
    Node* newNode = createNode(item, priority);

    if (isEmpty(pq) || priority < pq->front->priority) {
        newNode->next = pq->front;
        pq->front = newNode;
    } else {
        Node* current = pq->front;
        while (current->next != NULL && current->next->priority <= priority) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Function to remove the highest priority element from the priority queue
int removeHighestPriority(PriorityQueue* pq) {
    if (isEmpty(pq)) {
        printf("Priority Queue is empty. Cannot remove element.\n");
        return -1;
    }

    Node* temp = pq->front;
    int highestPriority = temp->data;
    pq->front = pq->front->next;
    free(temp);

    return highestPriority;
}

// Function to display the elements of the priority queue
void display(PriorityQueue* pq) {
    if (isEmpty(pq)) {
        printf("Priority Queue is empty.\n");
        return;
    }

    printf("Priority Queue elements: ");
    Node* current = pq->front;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    PriorityQueue pq;
    init(&pq);

    insert(&pq, 5, 2);
    insert(&pq, 3, 1);
    insert(&pq, 8, 3);
    insert(&pq, 1, 1);

    display(&pq);

    int highestPriority = removeHighestPriority(&pq);
    printf("Removed element with highest priority: %d\n", highestPriority);

    display(&pq);

    return 0;
}
