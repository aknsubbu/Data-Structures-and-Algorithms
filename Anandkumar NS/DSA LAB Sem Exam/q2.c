//pairwise swap for linked list

#include <stdio.h> 
#include <stdlib.h>

struct Node{
    int key;
    struct Node* next;
};

struct Node *getNode(int val){
    struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
    if(temp==NULL){
        printf("Error");
    }
    temp->key=val;
    return temp;
}

void insertElement(struct Node *root){
    struct Node *temp=root;
        if(temp==NULL){
        printf("Error");
    }

    int val,n;
    printf("The number of values to be inserted: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter the element no. %d : ",i+2);
        scanf("%d",&val);
        temp->next=getNode(val);
        temp=temp->next;
    }
    
}

void display(struct Node *root){
    struct Node *temp=root;
    if(temp==NULL){
        printf("Error");
    }
    while(temp!=NULL){
        printf("%d->",temp->key);
        temp=temp->next;
    }
    printf("NULL");
}

void swapPairs(struct Node *root){
    struct Node *temp=root;
    int a=temp->key;
    int b=temp->next->key;
    temp->key=b;
    temp->next->key=a;
}

void swapLinkedList(struct Node *root){
    struct Node *temp=root;
    if(temp==NULL){
        printf("Error");
    }
    while(temp->next!=NULL){
        swapPairs(temp);
        if(temp->next->next==NULL){
            break;
        }
        else{
            temp=temp->next->next;
        }
    }
}

int main(){
    int ele1;
    printf("Enter the first element: ");
    scanf("%d",&ele1);
    struct Node *root=getNode(ele1);
    insertElement(root);
    printf("Original List: \n");
    display(root);
    printf("\n\n");
    printf("Swapped List: \n");
    swapLinkedList(root);
    display(root);


    return 0;
}


