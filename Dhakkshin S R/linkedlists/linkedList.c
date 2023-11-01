#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node * newLL();
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

    struct Node * start = newLL();
    printf("\nExisting linked list:\n");
    print(start);

    // printf("Enter the value to search: ");
    // int search;
    // scanf("%d", &search);
    // printf(searchNode(start, search));

    start = deleteNodeBeforeX(start, 1);
    printf("\nAltered linked list:\n");
    print(start);
    
}

struct Node * newLL()
{
    printf("Enter the number of nodes: ");
    int numberOfNodes;
    scanf("%d", &numberOfNodes);
    struct Node * start = NULL;
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

    return start;
}

struct Node * insertNodesAtTheBegining(struct Node * start, struct Node * new)
{
    struct Node * newDuplicate = new;
    while (new)
    {
        if (new -> next == NULL) 
        {
            new -> next = start;
            start = newDuplicate;  
            break;  
        }
        new = new -> next;
    }
    return start;
}

struct Node * insertNodesAtTheEnd(struct Node * start, struct Node * new, struct Node * nextNode)
{
    if (nextNode == NULL)
    {
        if (start == NULL) 
        {
            start = new;
            return start;
        }
        nextNode = start;
    }
    if (nextNode -> next == NULL)
    {
        nextNode -> next = new;
        return start;
    }
    else
    {
        insertNodesAtTheEnd(start, new, nextNode -> next);
    }
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
    if (node == NULL)
    {
        printf("NULL\n\n");
        return;
    } 
    printf("(Data: %d | Current: %p | Next: %p) -> ", node -> data, node, node -> next);
    print(node -> next);
}

char * searchNode(struct Node * x, int val)
{
    if (x == NULL) return "Not Found\n";
    if (x -> data == val) return "Found\n";
    searchNode(x -> next, val);
}

struct Node * insertAfterNodeX(struct Node * start, struct Node * new, int x)
{
    if (new == NULL) return start;
    else if (start == NULL) return new;

    struct Node * newIterator = new, * lastOfNew = new, * orginalIterator = start;

    for (; newIterator; newIterator = newIterator -> next) lastOfNew = newIterator;
    // new points to 1st node of new linked list and lastOfNew points to the last node of the new linked list

    for (int i = 1; i <= x; i++, orginalIterator = orginalIterator -> next)
    {
        if (orginalIterator == NULL) return start;
        if (i == x)
        {
            // originalIterator points to node x now
            // the end of the new linkde list is joines with the begining of the 2nd part of the original one
            lastOfNew -> next = orginalIterator -> next;
            // the begining of the new one is joined with the end of the 1st part of the original
            orginalIterator -> next = new;
            return start;
        }
    }
}

struct Node * insertBeforeNodeX(struct Node * start, struct Node * new, int x)
{
    if (new == NULL) return start;
    else if (start == NULL) return new;
    
    struct Node * newIterator = new, * lastOfNew = new, * orginalIterator = start;

    for (; newIterator; newIterator = newIterator -> next) lastOfNew = newIterator;
    // new points to 1st node of new linked list and lastOfNew points to the last node of the new linked list

    for (int i = 1; i <= x+1; i++, orginalIterator = orginalIterator -> next)
    {
        if (orginalIterator == NULL) return start;
        if (x == 1)
        {
            lastOfNew -> next = start;
            start = new;
            return start;
        }
        if (i == x-1)
        {
            // originalIterator points to node x now
            // the end of the new linkde list is joines with the begining of the 2nd part of the original one
            lastOfNew -> next = orginalIterator -> next;
            // the begining of the new one is joined with the end of the 1st part of the original
            orginalIterator -> next = new;
            return start;
        }
    }
}

struct Node * deleteFirstNode(struct Node * start)
{
    if (start == NULL) return NULL;
    else
    {
        struct Node * tmp = start;
        start = start -> next;
        free(tmp);
        return start;
    }
}

struct Node * deleteLastNode(struct Node * start)
{
    if (start == NULL) return NULL;
    if (start -> next == NULL)
    {
        free(start);
        return NULL;
    }
    else
    {
        struct Node * tmp = start;
        while (tmp)
        {
            if (tmp -> next -> next == NULL) 
            {
                free(tmp -> next);
                tmp -> next = NULL;
                return start;
            } 
            tmp = tmp -> next;
        }
    }
    
}

struct Node * deleteNodeAfterX(struct Node * start, int x)
{
    struct Node * iterator = start;
    for (int i = 1; i <= x; i++, iterator = iterator -> next)
    {
        if (iterator == NULL) return start;
        if (i == x)
        {
            struct Node * tmp = iterator -> next;
            iterator -> next = iterator -> next -> next;
            free(tmp);
            return start;
        }
    }
}

struct Node * deleteNodeBeforeX(struct Node * start, int x)
{
    struct Node * iterator = start;
    for (int i = 1; i <= x+1; i++, iterator = iterator -> next)
    {
        if (iterator == NULL || x == 1) return start;
        if (x == 2) 
        {
            struct Node * tmp = start;
            start = start -> next;
            free(tmp);
            return start;         
        }
        if (i == x-2)
        {
            struct Node * tmp = iterator -> next;
            iterator -> next = iterator -> next -> next;
            free(tmp);
            return start;
        }
    }
}