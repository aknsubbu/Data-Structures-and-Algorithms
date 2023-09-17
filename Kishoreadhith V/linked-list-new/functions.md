# Linked List
Kishoreadhith V - 22z232
## Functions

### 1. Structure to create node in a linked list
```c
struct node
{
    int data;
    struct node *next;
};
```

### 2. Function to insert a new node at the beginning of a linked list
```c
void insertFirst(struct Node **head, int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}
```

Usage:
```c
insertFirst(&head, 10);
```

### 3. Function to insert a new node at the end of a linked list
```c
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
```

Usage:
```c
insertLast(&head, 10);
```

### 4. Function to insert n nodes at the beginning of a linked list
```c
void insertFirstN(struct Node **head, int n) {
    int val;
    for (int i = 0; i < n; i++) {
        printf("Enter data for new Node: ");
        scanf("%d", &val);
        insertFirst(head, val);
    }
}
```

Usage:
```c
insertFirstN(&head, 5);
```

### 5. Function to insert n nodes at the end of a linked list
```c
void insertLastN(struct Node **head, int n) {
    int val;
    for (int i = 0; i < n; i++) {
        printf("Enter data for new Node: ");
        scanf("%d", &val);
        insertLast(head, val);
    }
}
```

Usage:
```c
insertLastN(&head, 5);
```

### 6. Function to display a linked list
```c
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
```

Usage:
```c
display(&head);
```

### 7. Function to search for a node based on its value
```c
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
```

Usage:
```c
struct Node *result = search(&head, 10);
if (result != NULL)
{
    printf("Found at %p\n", result);
}
else
{
    printf("Not found\n");
}
``` 

### 8. Function to insert a new node after a specified node with a given value
```c
void insertAfter(struct Node ** head,int target, int data){
    struct Node * prev = search(head, target);
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    struct Node * next = prev->next;
    prev->next = newNode;
    newNode->next = next;
}
```

Usage:
```c
insertAfter(&head, 10, 20);
```

### 9. Function to insert a new node before a specified node with a given value
```c
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
```

Usage:
```c
insertBefore(&head, 10, 20);
```

### 10. Function to delete a node with a given value
```c
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
```

Usage:
```c
deleteNode(&head, 10);
```

### 11. Function to delete the first node
```c
void deleteFirst(struct Node ** head){
    if(*head == NULL){
        return;
    }
    struct Node * del = *head;
    *head = del->next;
    free(del);
}
```

Usage:
```c
deleteFirst(&head);
```

### 12. Function to delete the last node
```c
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
```

Usage:
```c
deleteLast(&head);
```

### 13. Function to delete the node after the node with a given value
```c
void deleteAfter(struct Node ** head, int target){
    struct Node * prev = search(head, target);
    struct Node * del = prev->next;
    prev->next = del->next;
    free(del);
}
```

Usage:
```c
deleteAfter(&head, 10);
```

### 14. Function to delete the node before the node with a given value
```c
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
```

Usage:
```c
deleteBefore(&head, 10);
```
