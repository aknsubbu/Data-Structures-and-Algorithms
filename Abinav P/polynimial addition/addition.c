#include<Stdio.h>
#include<stdlib.h>

struct node {
    int coeff;
    int exp;
    struct node *next;
};

struct node *create(struct node *head) {
    struct node *newnode, *temp;
    int n;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the coefficient and exponent: ");
        scanf("%d %d", &newnode->coeff, &newnode->exp);
        newnode->next = NULL;
        if(head == NULL) {
            head = newnode;
            temp = newnode;
        }
        else {
            temp->next = newnode;
            temp = newnode;
        }
    }
    return head;
}

void display(struct node *head) {
    struct node *temp = head;
    while(temp != NULL) {
        printf("%dx^%d", temp->coeff, temp->exp);
        temp = temp->next;
        if(temp != NULL)
            printf(" + ");
    }
    printf("\n");
}

void main(){
    struct node *head1=NULL, *head2=NULL, *head3=NULL;
    printf("Enter the first polynomial:\n");
    head1 = create(head1);
    printf("Enter the second polynomial:\n");
    head2 = create(head2);
    printf("The first polynomial is: ");
    display(head1);
    printf("The second polynomial is: ");
    display(head2);
    struct node *temp1 = head1, *temp2 = head2,*temp3=head3;
    while(temp1&&temp2!=NULL){
        if(temp1->exp == temp2->exp){
            struct node *newnode = (struct node *)malloc(sizeof(struct node));
            newnode->coeff = temp1->coeff + temp2->coeff;
            newnode->exp = temp1->exp;
            newnode->next = NULL;
            if(head3 == NULL){
                head3 = newnode;
                temp3 = newnode;
            }
            else{
                temp3->next = newnode;
                temp3 = newnode;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else if(temp1->exp > temp2->exp){
            struct node *newnode = (struct node *)malloc(sizeof(struct node));
            newnode->coeff = temp1->coeff;
            newnode->exp = temp1->exp;
            newnode->next = NULL;
            if(head3 == NULL){
                head3 = newnode;
                temp3 = newnode;
            }
            else{
                temp3->next = newnode;
                temp3 = newnode;
            }
            temp1 = temp1->next;
        }
        else{
            struct node *newnode = (struct node *)malloc(sizeof(struct node));
            newnode->coeff = temp2->coeff;
            newnode->exp = temp2->exp;
            newnode->next = NULL;
            if(head3 == NULL){
                head3 = newnode;
                temp3 = newnode;
            }
            else{
                temp3->next = newnode;
                temp3 = newnode;
            }
            temp2 = temp2->next;
        }

    }
    while(temp1!=NULL){
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        newnode->coeff = temp1->coeff;
        newnode->exp = temp1->exp;
        newnode->next = NULL;
        if(head3 == NULL){
            head3 = newnode;
            temp3 = newnode;
        }
        else{
            temp3->next = newnode;
            temp3 = newnode;
        }
        temp1 = temp1->next;
    }
    while(temp2!=NULL){
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        newnode->coeff = temp2->coeff;
        newnode->exp = temp2->exp;
        newnode->next = NULL;
        if(head3 == NULL){
            head3 = newnode;
            temp3 = newnode;
        }
        else{
            temp3->next = newnode;
            temp3 = newnode;
        }
        temp2 = temp2->next;
    }
    printf("The sum of the two polynomials is: ");
    display(head3);

}
