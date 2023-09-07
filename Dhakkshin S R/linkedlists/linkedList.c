#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node * getNode(int num);
void print(struct Node * node);

int main(void)
{

    printf("Enter the number of nodes: ");
    int numberOfNodes;
    scanf("%d", &numberOfNodes);
    struct Node * start;
        struct Node * old;
    for(int i = 0; i < numberOfNodes; i++)
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
            old = new;
        }        
    }

    print(start);
}

struct Node * getNode(int num)
{
    struct Node * node = malloc(sizeof(struct Node));
    node -> data = num;
    node -> next = NULL;
    return node;
}

void print(struct Node * node)
{
    printf("Data: %d, Next: %p\n", node -> data, node -> next);
    if (node -> next != NULL) print(node -> next);
    else return;
}