#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *newCircularLL();
struct Node * getNode(int num);
void print(struct Node * node);
struct Node * insertNodesAtTheEnd(struct Node * start, struct Node * new, struct Node * nextNode);
struct Node * insertNodesAtTheBegining(struct Node * start, struct Node * new);
char * searchNode(struct Node * x, int val);
struct Node * insertAfterNodeX(struct Node * start, struct Node * new, int x);
struct Node * insertBeforeNodeX(struct Node * start, struct Node * new, int x);
struct Node * deleteFirstNode(struct Node * start);
struct Node * deleteLastNode(struct Node * start);
struct Node * deleteNodeAfterX(struct Node * start, int x);
struct Node * deleteNodeBeforeX(struct Node * start, int x);

int main(void)
{
    struct Node *start = NULL;

    int choice;
    int num, x;
    char *result;

    do
    {
        printf("\nCircular Linked List Menu:\n");
        printf("1. Create a new circular linked list\n");
        printf("2. Insert nodes at the beginning\n");
        printf("3. Insert nodes at the end\n");
        printf("4. Insert after a specific node\n");
        printf("5. Insert before a specific node\n");
        printf("6. Delete the first node\n");
        printf("7. Delete the last node\n");
        printf("8. Delete node after a specific node\n");
        printf("9. Delete node before a specific node\n");
        printf("10. Search for a value in the list\n");
        printf("11. Print the circular linked list\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            start = newCircularLL();
            break;
        case 2:
            start = insertNodesAtTheBegining(start, newCircularLL());
            break;
        case 3:
            start = insertNodesAtTheEnd(start, newCircularLL());
            break;
        case 4:
            printf("Enter a number to insert: ");
            scanf("%d", &num);
            printf("Enter the value after which to insert: ");
            scanf("%d", &x);
            start = insertAfterNodeX(start, getNode(num), x);
            break;
        case 5:
            printf("Enter a number to insert: ");
            scanf("%d", &num);
            printf("Enter the value before which to insert: ");
            scanf("%d", &x);
            start = insertBeforeNodeX(start, getNode(num), x);
            break;
        case 6:
            start = deleteFirstNode(start);
            break;
        case 7:
            start = deleteLastNode(start);
            break;
        case 8:
            printf("Enter the value after which to delete: ");
            scanf("%d", &x);
            start = deleteNodeAfterX(start, x);
            break;
        case 9:
            printf("Enter the value before which to delete: ");
            scanf("%d", &x);
            start = deleteNodeBeforeX(start, x);
            break;
        case 10:
            printf("Enter the value to search: ");
            scanf("%d", &num);
            result = searchNode(start, num);
            printf("Search result: %s\n", result);
            break;
        case 11:
            printf("\nCircular Linked List: ");
            print(start);
            break;
        case 0:
            printf("Exiting the program.\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    // Free memory for the circular linked list nodes before exiting

    while (start != NULL)
    {
        struct Node *temp = start;
        start = start->next;

        // If we've come back to the start node, free the node and exit the loop
        if (start == temp)
        {
            free(temp);
            break;
        }
        
        free(temp);
    }

    return 0;
}


struct Node *newCircularLL()
{
    printf("Enter the number of nodes: ");
    int numberOfNodes;
    scanf("%d", &numberOfNodes);

    struct Node *start = NULL;
    struct Node *old = NULL;

    for (int i = 0; i < numberOfNodes; i++)
    {
        printf("Enter a number: ");
        int a;
        scanf("%d", &a);
        struct Node *new = getNode(a);

        if (i == 0)
        {
            start = new;
            old = new;
            start->next = start; 
        }
        else
        {
            old->next = new;
            old = new;
            new->next = start; 
        }
    }

    return start;
}

struct Node *insertNodesAtTheBegining(struct Node *start, struct Node *new)
{
    if (new == NULL)
        return start;

    if (start == NULL)
    {
        new->next = new;  
        return new;
    }

    struct Node *last = start;
    while (last->next != start)
    {
        last = last->next;
    }

    last->next = new;
    new->next = start;

    return new; 

}

struct Node *insertNodesAtTheEnd(struct Node *start, struct Node *new)
{
    if (new == NULL)
        return start;

    if (start == NULL)
    {
        new->next = new;  // Circular link for the new node
        return new;
    }

    struct Node *last = start;
    while (last->next != start)
    {
        last = last->next;
    }

    last->next = new;
    new->next = start;

    return start; // Start remains the same
}


struct Node * getNode(int num)
{
    struct Node * node = malloc(sizeof(struct Node));
    node -> data = num;
    node -> next = NULL;
    return node;
}

void print(struct Node *node)
{
    if (node == NULL)
    {
        printf("Circular Linked List is empty.\n");
        return;
    }

    struct Node *current = node;

    do
    {
        printf("(Data: %d | Current: %p | Next: %p) -> ", current->data, current, current->next);
        current = current->next;
    } while (current != node);

    printf("NULL\n\n");
}


char *searchNode(struct Node *start, int val)
{
    struct Node *current = start;

    if (current == NULL)
    {
        return "Not Found\n"; // List is empty
    }

    do
    {
        if (current->data == val)
        {
            return "Found\n";
        }
        current = current->next;
    } while (current != start);

    return "Not Found\n"; // Value not found in the list
}


struct Node *insertAfterNodeX(struct Node *start, struct Node *new, int x)
{
    if (new == NULL)
    {
        return start;
    }
    
    if (start == NULL)
    {
        new->next = new; // Make the new node circular
        return new;
    }

    struct Node *current = start;
    struct Node *nextNode;

    do
    {
        if (current->data == x)
        {
            nextNode = current->next; // Store the next node
            current->next = new; // Set the current node's next to the new node
            new->next = nextNode; // Set the new node's next to the nextNode
            return start;
        }
        current = current->next;
    } while (current != start); // Loop back to the start node

    return start; // Node 'x' not found in the list
}


struct Node *insertBeforeNodeX(struct Node *start, struct Node *new, int x)
{
    if (new == NULL)
    {
        return start;
    }

    if (start == NULL)
    {
        new->next = new; // Make the new node circular
        return new;
    }

    struct Node *current = start;
    struct Node *previous = NULL;

    do
    {
        if (current->data == x)
        {
            if (previous == NULL)
            {
                struct Node *last = start;

                // Find the last node in the circular list
                while (last->next != start)
                {
                    last = last->next;
                }

                last->next = new; // Update the last node to point to the new node
                new->next = start; // Set the new node's next to the start node
                start = new; // Update the start to the new node
            }
            else
            {
                previous->next = new; // Update the previous node to point to the new node
                new->next = current; // Set the new node's next to the current node
            }
            return start;
        }
        previous = current;
        current = current->next;
    } while (current != start); // Loop back to the start node

    return start; // Node 'x' not found in the list
}


struct Node *deleteFirstNode(struct Node *start)
{
    if (start == NULL)
    {
        return NULL; // Empty list
    }

    if (start->next == start)
    {
        // If there is only one node, delete it
        free(start);
        return NULL;
    }

    struct Node *last = start;

    // Find the last node in the circular list
    while (last->next != start)
    {
        last = last->next;
    }

    struct Node *tmp = start;
    start = start->next; // Move the start pointer to the next node
    last->next = start; // Update the last node to point to the new start
    free(tmp); // Free the deleted node

    return start;
}


struct Node *deleteLastNode(struct Node *start)
{
    if (start == NULL)
    {
        return NULL; // Empty list
    }

    if (start->next == start)
    {
        // If there is only one node, delete it
        free(start);
        return NULL;
    }

    struct Node *current = start;
    struct Node *previous = NULL;

    // Traverse the circular list to find the last and the previous nodes
    do
    {
        previous = current;
        current = current->next;
    } while (current->next != start);

    previous->next = start; // Update the previous node to point to the start
    free(current); // Free the deleted node

    return start;
}


struct Node *deleteNodeAfterX(struct Node *start, int x)
{
    if (start == NULL)
    {
        return NULL; // Empty list
    }

    struct Node *current = start;
    struct Node *previous = NULL;

    for (int i = 1; i <= x; i++)
    {
        previous = current;
        current = current->next;

        if (current == start && i < x)
        {
            // x is greater than the number of nodes in the circular list
            return start;
        }
    }

    // If x is the last node, handle it as a circular linked list should
    if (current->next == start)
    {
        previous->next = start;
    }
    else
    {
        previous->next = current->next;
    }

    free(current); // Free the deleted node

    return start;
}


struct Node *deleteNodeBeforeX(struct Node *start, int x)
{
    if (start == NULL)
    {
        return NULL; // Empty list
    }

    struct Node *current = start;
    struct Node *previous = NULL;

    if (x == 1)
    {
        // Special case: deleting the node before the first node
        while (current->next != start)
        {
            current = current->next;
        }

        struct Node *tmp = start;
        start = start->next;
        current->next = start;
        free(tmp);
    }
    else
    {
        for (int i = 1; i < x; i++)
        {
            previous = current;
            current = current->next;

            if (current == start)
            {
                // x is greater than or equal to the number of nodes in the circular list
                return start;
            }
        }

        previous->next = current->next;
        free(current); // Free the deleted node
    }

    return start;
}
