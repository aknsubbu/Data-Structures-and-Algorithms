// add node at the beginging

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
    struct Node * new;
    for(int i = 0; i < numberOfNodes; i++)
    {
        printf("Enter a number: ");
        int a;
        scanf("%d", &a);

        if (i == 0)
        {
            start = getNode(a);
        }
        else{
            new = getNode(a);
            new -> next = start;
            start = new;
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