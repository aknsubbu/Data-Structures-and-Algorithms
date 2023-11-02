#include <stdio.h>
#include <stdlib.h>
struct Node
{
    float coeff;
    int exp;
    struct Node *next;
};

void display(struct Node *head){
    struct Node *current = head;
    printf("---\n");
    printf("Head: %p\n", head);
    printf("---\n");
    if (head == NULL)
    {
        printf("List is empty\n");
        printf("---\n");
        return;
    }
    while (current != NULL)
    {
        printf("%.2f X^%d", current->coeff, current->exp);
        if (current->next != NULL)
        {
            printf(" + ");
        }
        current = current->next;
    }
    printf("\n");
    printf("---\n");
}

void insertTerm(struct Node **head, float coeff, int exp){
    struct Node * same = (struct Node *) malloc(sizeof(struct Node));
    while(same->next != NULL){
        if(same->exp == exp){
            same->coeff += coeff;
            return;
        }
    }
    struct Node *newTerm = (struct Node *) malloc(sizeof(struct Node));
    newTerm->coeff = coeff;
    newTerm->exp = exp;
    same = *head;
    newTerm->next = NULL;
    if (*head == NULL)
    {
        *head = newTerm;
        return;
    }
    if ((*head)->exp < exp)
    {
        newTerm->next = *head;
        *head = newTerm;
        return;
    }
    struct Node *current = *head;
    while (current->next != NULL && current->next->exp > exp)
    {
        current = current->next;
    }
    newTerm->next = current->next;
    current->next = newTerm;    
}

void createPolynomial(struct Node **head){
    int n;
    float coeff;
    int exp;
    printf("Enter number of terms: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter coefficient: ");
        scanf("%f", &coeff);
        printf("Enter exponent: ");
        scanf("%d", &exp);
        insertTerm(head, coeff, exp);
    }
}

void addPolynomials(struct Node **head1, struct Node **head2, struct Node **head3){
    struct Node *current1 = *head1;
    struct Node *current2 = *head2;
    while (current1 != NULL && current2 != NULL)
    {
        if (current1->exp > current2->exp)
        {
            insertTerm(head3, current1->coeff, current1->exp);
            current1 = current1->next;
        }
        else if (current1->exp < current2->exp)
        {
            insertTerm(head3, current2->coeff, current2->exp);
            current2 = current2->next;
        }
        else
        {
            insertTerm(head3, current1->coeff + current2->coeff, current1->exp);
            current1 = current1->next;
            current2 = current2->next;
        }
    }
    if (current1 != NULL)
    {
        struct Node * temp = (struct Node *) malloc(sizeof(struct Node));
        temp = *head3;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = current1;
    }
    else if (current2 != NULL)
    {
        struct Node * temp = (struct Node *) malloc(sizeof(struct Node));
        temp = *head3;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = current2;
    }
}

int main(){
    struct Node *head1 = NULL;
    struct Node *head2 = NULL;
    struct Node *head3 = NULL;
    createPolynomial(&head1);
    createPolynomial(&head2);
    display(head1);
    display(head2);
    addPolynomials(&head1, &head2, &head3);
    display(head3);
    return 0;

}