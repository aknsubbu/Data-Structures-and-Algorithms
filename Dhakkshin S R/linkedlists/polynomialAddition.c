#include <stdio.h>
#include <stdlib.h>

struct Node{
    float coefficient;
    int exponent;
    struct Node * next;
};

struct Node * getNode(float c, int e);
struct Node * newLL();
struct Node * addPoly(struct Node * a, struct Node * b);
void print(struct Node * node);

int main(void){
    struct Node * poly1 = newLL();
    struct Node * poly2 = newLL();
    print(poly1);
    print(poly2);
    struct Node * polyAnswer = addPoly(poly1, poly2);
    print(polyAnswer);
}

struct Node * newLL()
{
    printf("Enter the number of terms: ");
    int numberOfNodes;
    scanf("%d", &numberOfNodes);
    struct Node * start = NULL;
    struct Node * old;
    for(int i = 0; i < numberOfNodes; i++)
    {
        printf("Enter a the coefficient: ");
        int a;
        scanf("%d", &a);
        printf("Enter a the exponent: ");
        int b;
        scanf("%d", &b);
        struct Node * new = getNode(a, b);
    
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

struct Node * getNode(float c, int e)
{
    struct Node * node = malloc(sizeof(struct Node));
    node -> coefficient = c;
    node -> exponent = e;
    node -> next = NULL;
    return node;
}

struct Node * addPoly(struct Node * a, struct Node * b)
{
    struct Node * ans = NULL;
    struct Node * new = NULL;
    struct Node * old = NULL;

    while (a && b)
    {
        if (a->exponent == b->exponent)
        {
            new = getNode((a->coefficient + b->coefficient), a->exponent);
            if (ans == NULL)
            {
                ans = new;
                old = new;
            }
            else
            {
                old -> next = new;
                old = new;
            }
            a = a->next;
            b = b->next;
        }

        else if (a->exponent > b->exponent)
        {
            new = getNode(a->coefficient, a->exponent);
            if (ans == NULL)
            {
                ans = new;
                old = new;
            }
            else
            {
                old -> next = new;
                old = new;
            }

            a = a->next;
        }

        else if (a->exponent < b->exponent)
        {
            new = getNode(b->coefficient, b->exponent);
            if (ans == NULL)
            {
                ans = new;
                old = new;
            }
            else
            {
                old -> next = new;
                old = new;
            }

            b = b->next;
        }
    }

    if (a) old -> next = a;

    if (b) old -> next = b;

    return ans;
}

void print(struct Node * node)
{
    if (node == NULL)
    {
        printf("NULL\n\n");
        return;
    } 
    printf("(Coefficient: %f | Exponent: %d | Current: %p | Next: %p) -> ", node -> coefficient, node -> exponent, node, node -> next);
    print(node -> next);
}