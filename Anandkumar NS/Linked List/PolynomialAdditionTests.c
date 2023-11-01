#include <stdio.h>
#include <stdlib.h>

struct node
{
    int coeff;
    int exp;
    struct node *next;
};

// Function to create a polynomial linked list
struct node *create()
{
    struct node *head = NULL;
    struct node *newnode, *temp;
    int n, i;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the coefficient and exponent of term %d: ", i + 1);
        scanf("%d%d", &newnode->coeff, &newnode->exp);
        newnode->next = NULL;
        if (head == NULL)
        {
            head = newnode;
            temp = head;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    }
    return head;
}

// Function to display a polynomial
void Display(struct node *head)
{
    struct node *temp;
    temp = head;
    printf("The polynomial is: ");
    while (temp != NULL)
    {
        printf("%dx^%d", temp->coeff, temp->exp);
        if (temp->next != NULL)
            printf(" + ");
        temp = temp->next;
    }
    printf("\n");
}

// Function to add a new node at the end of a linked list
void addNode(struct node *head, int coeff, int exp)
{
    struct node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    temp->next = newNode;
}

// Function to perform polynomial addition
struct node *PolynomialAddition(struct node *head1, struct node *head2)
{
    struct node *result = NULL;
    struct node *temp1 = head1;
    struct node *temp2 = head2;

    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->exp > temp2->exp)
        {
            addNode(result, temp1->coeff, temp1->exp);
            temp1 = temp1->next;
        }
        else if (temp2->exp > temp1->exp)
        {
            addNode(result, temp2->coeff, temp2->exp);
            temp2 = temp2->next;
        }
        else
        {
            int coeffSum = temp1->coeff + temp2->coeff;
            if (coeffSum != 0)
            {
                addNode(result, coeffSum, temp1->exp);
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }

    // Copy the remaining terms from both polynomials if any
    while (temp1 != NULL)
    {
        addNode(result, temp1->coeff, temp1->exp);
        temp1 = temp1->next;
    }
    while (temp2 != NULL)
    {
        addNode(result, temp2->coeff, temp2->exp);
        temp2 = temp2->next;
    }

    return result;
}

int main()
{
    struct node *head1 = NULL, *head2 = NULL, *result = NULL;
    
    printf("Enter the first polynomial:\n");
    head1 = create();
    
    printf("Enter the second polynomial:\n");
    head2 = create();

    Display(head1);
    Display(head2);

    result = PolynomialAddition(head1, head2);
    printf("Resultant polynomial after addition:\n");
    Display(result);

    return 0;
}
