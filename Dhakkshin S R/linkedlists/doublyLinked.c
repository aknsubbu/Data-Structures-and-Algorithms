#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node * next;
    struct Node * prev;
};

struct Node * getNode(int num);
void print(struct Node * node);
struct Node * newDLL();

int main(void)
{
    struct Node * start = newDLL();
    printf("Original linked List: ");
    print(start);
}

struct Node * getNode(int num)
{
    struct Node * node = malloc(sizeof(struct Node));
    node -> data = num;
    node -> next = NULL;
    node -> prev = NULL;
    // printf("%d", num);
    // print(node);
    return node;
}

void print(struct Node * node)
{
    if (node == NULL)
    {
        printf("NULL\n\n");
        return;
    } 
    printf("(Data: %d | Previous: %p | Current: %p | Next: %p) -> ", node -> data, node -> prev, node, node -> next);
    print(node -> next);
}

struct Node * newDLL()
{
    printf("Enter the number of nodes: ");
    int numberOfNodes;
    scanf("%d", &numberOfNodes);
    struct Node * start = NULL;
    struct Node * old = NULL;

    for (int i = 0; i < numberOfNodes; i++)
    {
        printf("Enter a number: ");
        int a;
        scanf("%d", &a);
        struct Node * new = getNode(a);  

        if (i == 0)
        {
            start = new;
            old = new;
        }
        else
        {
            old -> next = new;
            new -> prev = old;
            old = new;
        }
    }
    return start;
}

struct Node * insertAtTheBegining(struct Node * start, struct Node * new)
{
    
}