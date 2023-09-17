#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

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
    //empty linked list testcase
    // struct Node* head = NULL; 
    // printf("Empty Linked List: ");
    // printList(head);
    // insertAtBeginning(&head, 3);
    // printf("Linked List: ");
    // printList(head);
    // // inserted element 1 into empty linked list


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


// Linked list with 3 elements
    // struct Node* head2_1,*head2_2,*head2_3; 
    // head2_1=getData(1);
    // head2_2=getData(2);
    // head2_3=getData(3);
    // head2_1->next=head2_2;
    // head2_2->next=head2_3;
    // printf("Linked List: ");
    // printList(head2_1);

    // insertAtBeginning(&head2_1, 3);
    // printf("Linked List with one element insert with function: ");
    // printList(head2_1);
    // printf("Linked List with one element above");
    

// // Linked list with 5 elements
//     struct Node* head3_1,*head3_2,*head3_3,*head3_4,*head3_5; 
//     head3_1=getData(1);
//     head3_2=getData(2);
//     head3_3=getData(3);
//     head3_4=getData(4);
//     head3_5=getData(5);
//     head3_1->next=head3_2;
//     head3_2->next=head3_3;
//     head3_3->next=head3_4;
//     head3_4->next=head3_5;

//     printf("Linked List: ");
//     printList(head3_1);

//     insertAtBeginning(&head3_1, 3);
//     printf("Linked List with five element insert with function: ");
//     printList(head3_1);
//     printf("Linked List with one element above");
    
//Linked List with 10 elements
    struct Node* head4_1,*head4_2,*head4_3,*head4_4,*head4_5,*head4_6,*head4_7,*head4_8,*head4_9,*head4_10;; 
    head4_1=getData(1);
    head4_2=getData(2);
    head4_3=getData(3);
    head4_4=getData(4);
    head4_5=getData(5);
    head4_6=getData(6);
    head4_7=getData(7);
    head4_8=getData(8);
    head4_9=getData(9);
    head4_10=getData(10);
    head4_1->next=head4_2;
    head4_2->next=head4_3;
    head4_3->next=head4_4;
    head4_4->next=head4_5;
    head4_5->next=head4_6;
    head4_6->next=head4_7;
    head4_7->next=head4_8;
    head4_8->next=head4_9;
    head4_9->next=head4_10;

    printf("Linked List: ");
    printList(head4_1);

    insertAtBeginning(&head4_1, 3);

    printf("Linked List with one element insert with function: ");
    printList(head4_1);
    printf("Linked List with one element above");
    
    
    
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");



    return 0;
}


