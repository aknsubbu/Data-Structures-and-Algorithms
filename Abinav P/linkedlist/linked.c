// linked list insert at beginning
// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>

// struct node *getnode(int data);
// struct node *toinsert(struct node *head, int n);
// struct node
// {
//     int data;
//     struct node *next;
// };

// struct node *head = NULL;

// void main(int arr[])
// {
//     struct node *p1 = getnode(1);
//     struct node *p2 = getnode(20);
//     struct node *p3 = getnode(30);
//     struct node *p4 = getnode(40);
//     int n;
//     printf("enter the node to be inserted at the beginning");
//     scanf("%d", &n);
//     head = toinsert(head, n);
//     // struct node *p1;  uncomment this statement for empty linked list
//     head->next = p1;
//     p1->next = p2;
//     p2->next = p3;
//     p3->next = p4;
//     display(head);
// }

// struct node *getnode(int data)
// {
//     struct node *head;
//     head = (struct node *)malloc(sizeof(struct node));
//     head->data = data;
//     head->next = NULL;
//     return head;
// }

// struct node *toinsert(struct node *head, int n)
// {
//     struct node *temp;
//     temp = getnode(n);
//     temp->next = head;
//     head = temp;
//     return head;
// }

// void display(struct node *head)
// {
//     struct node *temp;
//     temp = head;
//     while (temp != NULL)
//     {
//         if (!temp->data)
//         {
//             printf("NULL ");
//             temp = temp->next;
//             continue;
//         }
//         printf("%d ", temp->data);
//         temp = temp->next;
//     }
//}

// #include<Stdio.h>
// void main(){
//     int n=NULL;
//     printf("%s",n);
// }

// delete the node at beginning in linked list
#include <stdio.h>
#include <stdlib.h>
#
struct node *getnode(int data);

struct node
{
    int data;
    struct node *next;
};

struct node *start = NULL;

void main(int args[])
{
    struct node *p1 = getnode(1);
    struct node *p2 = getnode(20);
    struct node *p3 = getnode(30);
    start->next = p1;
    p1->next = p2;
    p2->next = p3;
    display(start);
}

struct node *getnode(int data)
{
    struct node *head;
    head = (struct node *)malloc(sizeof(struct node));
    head->data = data;
    head->next = NULL;
    printf("%d", head->data);
    return head;
}

void display(struct node *head)
{
    printf("the linked list is\n");
    struct node *temp = head;
    while (temp != NULL)
    {
        if (!temp->data)
        {
            printf("NULL ");
            temp = temp->next;
            continue;
        }
        printf("%d  ", temp->data);
        temp = temp->next;
    }
}

// double linked list

// #include <stdio.h>
// #include <stdlib.h>

// struct node
// {
//     int data;
//     struct node *next, *previous;
// };

// struct node *head = NULL;

// struct node *getnode(int data)
// {
//     struct node *new;
//     new->next = NULL;
//     new->previous = NULL;
//     new->data = data;
//     return new;
// }

// int main()
// {
//     struct node *element1 = getnode(10);
// }

// // insert at beginning in double linked list

// struct node *insertatbeginning(struct node *head, int data)
// {
//     struct node *new = getnode(data);
//     new->next = head;
//     new->previous = NULL;
//     head->previous = new;
//     head = new;
//     return head;
// }

// // insert at end in double linked list

// struct node *insertatend(struct node *head, int data)
// {
//     struct node *new = getnode(data);
//     struct node *temp = head;
//     while (temp->next != NULL)
//     {
//         temp = temp->next;
//     }
//     temp->next = new;
//     new->previous = temp;
//     new->next = NULL;
//     return head;
// }

// // insert after node x

// struct node *insertafternode(struct node *head, int data, int x)
// {
//     struct node *new = getnode(data);
//     struct node *temp = head;
//     while (temp->data != x)
//     {
//         temp = temp->next;
//     }
//     new->next = temp->next;
//     new->previous = temp;
//     temp->next = new;
//     return head;
// }