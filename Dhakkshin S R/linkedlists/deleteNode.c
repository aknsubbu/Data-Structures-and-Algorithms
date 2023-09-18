// i phucked up :)

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node * getNode(int num);
void print(struct Node * node);
void removeLastNode(struct Node * a);

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
    printf("\nExisting linked list:\n");
    print(start);

    // delete the first node
    
    // struct node * tmp = start;
    // start = start -> next;
    // free(tmp);
    removeLastNode(start);
    printf("\nAltered linked list:\n");
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
    printf("(Data: %d, Current: %p Next: %p) -> ", node -> data, node, node -> next);
    if (node -> next != NULL) print(node -> next);
    else printf("NULL\n");
}

void removeLastNode(struct Node * a)
{
    if (a -> next != NULL)
    {
        removeLastNode(a -> next);
    }
    else 
    {
        free(a);
    }
}