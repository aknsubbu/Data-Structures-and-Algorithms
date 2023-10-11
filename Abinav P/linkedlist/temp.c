// #include <stdio.h>
// #include <stdlib.h>

// // Define the structure for a doubly linked list node
// struct ListNode {
//     int val;
//     struct ListNode* prev;
//     struct ListNode* next;
// };

// // Function to reverse a doubly linked list and return the new head
// struct ListNode* reverseList(struct ListNode* head) {
//     struct ListNode* temp = NULL;
//     struct ListNode* current = head;

//     while (current != NULL) {
//         temp = current->prev;
//         current->prev = current->next;
//         current->next = temp;
//         current = current->prev;
//     }

//     // Update the head pointer
//     if (temp != NULL) {
//         head = temp->prev;
//     }

//     return head;
// }

// // Function to create a new node with the given value
// struct ListNode* createNode(int val) {
//     struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
//     if (newNode == NULL) {
//         printf("Memory allocation failed\n");
//         exit(1);
//     }
//     newNode->val = val;
//     newNode->prev = NULL;
//     newNode->next = NULL;
//     return newNode;
// }

// // Function to insert a node at the end of the list
// void insertEnd(struct ListNode** head, int val) {
//     struct ListNode* newNode = createNode(val);
//     if (*head == NULL) {
//         *head = newNode;
//     } else {
//         struct ListNode* current = *head;
//         while (current->next != NULL) {
//             current = current->next;
//         }
//         current->next = newNode;
//         newNode->prev = current;
//     }
// }

// // Function to print the doubly linked list
// void printList(struct ListNode* head) {
//     struct ListNode* current = head;
//     while (current != NULL) {
//         printf("%d <-> ", current->val);
//         current = current->next;
//     }
//     printf("NULL\n");
// }

// // Function to free the doubly linked list
// void freeList(struct ListNode* head) {
//     struct ListNode* current = head;
//     while (current != NULL) {
//         struct ListNode* temp = current;
//         current = current->next;
//         free(temp);
//     }
// }

// int main() {
//     int num, val, continueFlag;

//     do {
//         struct ListNode* head = NULL;
//         int i;

//         // Get the number of elements from the user
//         printf("Enter the number of elements in the linked list: ");
//         scanf("%d", &num);

//         // Get the elements from the user
//         printf("Enter the elements of the linked list:\n");
//         for (i = 0; i < num; ++i) {
//             scanf("%d", &val);
//             insertEnd(&head, val);
//         }

//         // Print the original doubly linked list
//         printf("Original Doubly Linked List: ");
//         printList(head);

//         // Reverse the doubly linked list
//         head = reverseList(head);

//         // Print the reversed doubly linked list
//         printf("Reversed Doubly Linked List: ");
//         printList(head);

//         // Free allocated memory
//         freeList(head);

//         // Ask the user if they want to continue
//         printf("Enter 1 to continue or any other number to exit: ");
//         scanf("%d", &continueFlag);

//     } while (continueFlag == 1);

//     return 0;
// }


// #include <stdio.h>
// #include <stdlib.h>

// // Define the structure for a doubly linked list node
// struct ListNode {
//     int val;
//     struct ListNode* prev;
//     struct ListNode* next;
// };

// // Function to create a new node with the given value
// struct ListNode* createNode(int val) {
//     struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
//     if (newNode == NULL) {
//         printf("Memory allocation failed\n");
//         exit(EXIT_FAILURE);
//     }
//     newNode->val = val;
//     newNode->prev = NULL;
//     newNode->next = NULL;
//     return newNode;
// }

// // Function to insert a node at the end of the list
// void insertEnd(struct ListNode** head, int val) {
//     struct ListNode* newNode = createNode(val);
//     if (*head == NULL) {
//         *head = newNode;
//     } else {
//         struct ListNode* current = *head;
//         while (current->next != NULL) {
//             current = current->next;
//         }
//         current->next = newNode;
//         newNode->prev = current;
//     }
// }

// // Function to remove duplicate elements from a doubly linked list
// void removeDuplicates(struct ListNode* head) {
//     struct ListNode* current = head;
//     while (current != NULL) {
//         struct ListNode* runner = current->next;
//         while (runner != NULL) {
//             if (current->val == runner->val) {
//                 struct ListNode* temp = runner;
//                 if (runner->next != NULL) {
//                     runner->next->prev = current;
//                 }
//                 current->next = runner->next;
//                 free(temp);
//             }
//             runner = runner->next;
//         }
//         current = current->next;
//     }
// }

// // Function to print the doubly linked list
// void printList(struct ListNode* head) {
//     struct ListNode* current = head;
//     while (current != NULL) {
//         printf("%d <-> ", current->val);
//         current = current->next;
//     }
//     printf("NULL\n");
// }

// // Function to free the doubly linked list
// void freeList(struct ListNode* head) {
//     struct ListNode* current = head;
//     while (current != NULL) {
//         struct ListNode* temp = current;
//         current = current->next;
//         free(temp);
//     }
// }

// int main() {
//     int num, val, continueFlag;

//     do {
//         struct ListNode* head = NULL;
//         int i;

//         // Get the number of elements from the user
//         printf("Enter the number of elements in the linked list: ");
//         scanf("%d", &num);

//         // Get the elements from the user
//         printf("Enter the elements of the linked list:\n");
//         for (i = 0; i < num; ++i) {
//             scanf("%d", &val);
//             insertEnd(&head, val);
//         }

//         // Print the original doubly linked list
//         printf("Original Doubly Linked List: ");
//         printList(head);

//         // Remove duplicate elements from the doubly linked list
//         removeDuplicates(head);

//         // Print the list after removing duplicates
//         printf("Doubly Linked List after removing duplicates: ");
//         printList(head);

//         // Free allocated memory
//         freeList(head);

//         // Ask the user if they want to continue
//         printf("Enter 1 to continue or any other number to exit: ");
//         scanf("%d", &continueFlag);

//     } while (continueFlag == 1);

//     return 0;
// }


// #include <stdio.h>
// #include <stdlib.h>

// struct ListNode {
//     int val;
//     struct ListNode* next;
// };

// struct ListNode* createNode(int val) {
//     struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
//     if (newNode == NULL) {
//         printf("Memory allocation failed\n");
//         exit(EXIT_FAILURE);
//     }
//     newNode->val = val;
//     newNode->next = NULL;
//     return newNode;
// }

// void insertEnd(struct ListNode** head, int val) {
//     struct ListNode* newNode = createNode(val);
//     if (*head == NULL) {
//         *head = newNode;
//     } else {
//         struct ListNode* temp = *head;
//         while (temp->next != NULL) {
//             temp = temp->next;
//         }
//         temp->next = newNode;
//     }
// }

// struct ListNode* reverseList(struct ListNode* head) {
//     struct ListNode* prev = NULL;
//     struct ListNode* current = head;
//     while (current != NULL) {
//         struct ListNode* nextTemp = current->next;
//         current->next = prev;
//         prev = current;
//         current = nextTemp;
//     }
//     return prev;
// }

// int isPalindrome(struct ListNode* head) {
//     if (head == NULL || head->next == NULL) {
//         return 1; // Empty or single-node list is a palindrome
//     }

//     struct ListNode* slow = head;
//     struct ListNode* fast = head;

//     // Find the middle of the linked list
//     while (fast->next != NULL && fast->next->next != NULL) {
//         slow = slow->next;
//         fast = fast->next->next;
//     }

//     // Reverse the second half of the linked list
//     struct ListNode* secondHalf = reverseList(slow->next);
//     struct ListNode* firstHalf = head;

//     // Compare the first half with the reversed second half
//     while (secondHalf != NULL) {
//         if (firstHalf->val != secondHalf->val) {
//             return 0; // Not a palindrome
//         }
//         firstHalf = firstHalf->next;
//         secondHalf = secondHalf->next;
//     }

//     return 1; // Palindrome
// }

// void printList(struct ListNode* head) {
//     struct ListNode* temp = head;
//     while (temp != NULL) {
//         printf("%d -> ", temp->val);
//         temp = temp->next;
//     }
//     printf("NULL\n");
// }

// int main() {
//     struct ListNode* head = NULL;
//     int num, val;

//     // Get the number of elements from the user
//     printf("Enter the number of elements in the linked list: ");
//     scanf("%d", &num);

//     // Get the elements from the user
//     printf("Enter the elements of the linked list:\n");
//     for (int i = 0; i < num; ++i) {
//         scanf("%d", &val);
//         insertEnd(&head, val);
//     }

//     // Print the original linked list
//     printf("Original Linked List: ");
//     printList(head);

//     // Check if the linked list is a palindrome
//     if (isPalindrome(head)) {
//         printf("The linked list is a palindrome.\n");
//     } else {
//         printf("The linked list is not a palindrome.\n");
//     }

//     // Free allocated memory
//     struct ListNode* temp = head;
//     while (temp != NULL) {
//         struct ListNode* nodeToDelete = temp;
//         temp = temp->next;
//         free(nodeToDelete);
//     }

//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a singly linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to insert an element at the end of the linked list
void insert(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to perform Bubble Sort on a linked list
void bubbleSort(struct Node* head) {
    int swapped;
    struct Node* ptr1;
    struct Node* lptr = NULL;

    // Checking for empty list
    if (head == NULL) {
        return;
    }

    do {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                // Swap data
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

// Function to display the linked list
void display(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    // Insert elements into the linked list
    insert(&head, 12);
    insert(&head, 11);
    insert(&head, 13);
    insert(&head, 5);
    insert(&head, 6);

    printf("Original List: ");
    display(head);

    bubbleSort(head);

    printf("Sorted List: ");
    display(head);

    return 0;
}

