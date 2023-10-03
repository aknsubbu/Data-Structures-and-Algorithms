#include <stdio.h>
#include <stdlib.h>

struct node
{
    int coeff;
    int exp;
    struct node *next;
};


struct node *create(struct node *head)
{
    struct node *newnode,*temp;
    int n,i;
    printf("Enter the number of terms: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        newnode=(struct node *)malloc(sizeof(struct node));
        printf("Enter the coefficient and exponent of term %d: ",i+1);
        scanf("%d%d",&newnode->coeff,&newnode->exp);
        newnode->next=NULL;
        if(head==NULL)
        {
            head=newnode;
            temp=head;
        }
        else
        {
            temp->next=newnode;
            temp=newnode;
        }
    }
    return head;
}

struct node* addNode(struct node *head,int coeff,int exp){
    struct node* temp=NULL, *newNode;
    temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    newNode=(struct node *)malloc(sizeof(struct node));
    temp->next=newNode;
    newNode->coeff=coeff;
    newNode->exp=exp;
    newNode->next=NULL;

}

void Display(struct node* head){
    struct node *temp;
    temp=head;
    printf("The polynomial is: ");
    while(temp!=NULL){
        
        printf("%dx^%d + ",temp->coeff,temp->exp);
        temp=temp->next;
    }
    printf("\n");
}

void PolynomialAdditon(struct node *head1, struct node *head2, struct node *finalList){
    struct node* temp1 = NULL;
    temp1 = head1;
    struct node* temp2 = NULL;
    temp2 = head2;
    struct node* final=NULL;
    final=finalList;

    while(temp1->next!=NULL && temp2->next!=NULL){
        if(temp1->exp>temp2->exp){
            addNode(final,temp1->coeff,temp1->exp);
            temp1=temp1->next;
            }
            else if(temp2->exp>temp1->exp){
                addNode(final,temp2->coeff,temp2->exp);
            temp2=temp2->next;
        }
        else if(temp1->exp==temp2->exp){
            int coeffNew= temp1->coeff+temp2->coeff;
            addNode(final,coeffNew,temp1->exp);
        }
    }

    return final;
}

int main(){
    struct node *head1=NULL,*head2=NULL,*head3=NULL, *final=NULL,*temp,*newnode;
    head1=create(head1);
    head2=create(head2);
    Display(head1);
    Display(head2);
    temp=head1;
    //initializing the final list
    final=(struct node *)malloc(sizeof(struct node));
    PolynomialAdditon(head1,head2,final);
    Display(final);
    return 0;
    
}