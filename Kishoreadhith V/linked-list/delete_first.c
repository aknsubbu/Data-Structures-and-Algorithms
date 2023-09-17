#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node * next;
} * start;

void display(struct Node *start){
    if (start == NULL)
    {
        printf("emtpy linked list\n");
        return;
    }
    
    struct Node * current = start;
    while (current != NULL)
    {
        printf("address: %p\n", current);
        printf("data = %d\n", current -> data);
        printf("next address: %p\n", current -> next);
        printf("---\n");
        current = current -> next;
    }    
}

void insertNode(struct Node ** head, int data){
    struct Node * p = (struct Node *) malloc (sizeof(struct Node));
    p -> data = data;
    p -> next = *head;
    *head = p;
}

void insertLast(struct Node **start, int data) {
    struct Node *current = *start;
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    p->data = data;
    p->next = NULL;
    if (*start == NULL) {
        *start = p; // If the list is empty, set start to the new node
    } else {
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = p;
    }
}

struct Node * deleteList(struct Node * start){
    struct Node * current = start;

    while (current->next->next != NULL)
    {
        current = current -> next;
    }
    struct Node * del = current->next;
    current->next = NULL;
    free(del);
    return del;
}

int main(){
    printf("start");
    struct Node * start;
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int inp;
        scanf("%d", &inp);
        insertLast(&start, inp);
    }
    printf("before\n");
    display(start);
    printf("after\n");
    deleteList(start);
    display(start);
}