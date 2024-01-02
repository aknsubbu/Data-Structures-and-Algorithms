#include <stdio.h>
#include <stdlib.h>
#include "utilities.h"

struct node{
    int data;
    struct node* next;
}head;


struct node* createNode(struct node* prev,int info){
    struct node* cur = (struct node*)malloc(sizeof(struct node));
    prev->next = cur;
    cur->data = info;
    cur->next = NULL;
    return cur;
}

void displayListRec(struct node* start){
    struct node* iter = start;
    while(1){
        printf("%d-->",iter->data);
        if(iter->next == NULL){
            printf("NULL\n");
            break;
        }
        iter = iter->next;
    }
}

void displayListLoop(struct node* start,int n){
    struct node* iter = start;
    int i = 0;
    while(i<n){
        printf("%d\n",iter->data);
        iter = iter->next;
        i++;
    }
}

void displayListLooped(struct node* start){
    for(;start;start = start ->next){
        printf("%d-->",start->data);
    }
    printf("NULL\n");

}

struct node* getEnd(struct node* start){
    struct node* iter = start;
    while(1){
        if(iter->next == NULL){
            break;
        }
        iter = iter->next;
    }
    return iter;
}

struct node* insertAtBeginning(struct node* start,int val){
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new->data = val;
    new->next = start;
    return new;
}

struct node* insertAtEnd(struct node* start,int info){
    struct node* new = createNode(getEnd(start),info);
    return new;
}

struct node* insertNNodesAtBeginning(struct node* start,int arr[],int n){
    struct node* new = start;
    for(int i = n-1;i>=0;i--){
        new = insertAtBeginning(new,arr[i]);
    }
    return new;
}

struct node* insertNNodesAtEnd(struct node* start,int arr[],int n){
    struct node* end = getEnd(start);
    
    for(int i = 0;i<n;i++){
        struct node* new = insertAtEnd(start,arr[i]);
        end->next = new;
        end = new;
        //printf("%d",end->data);
    }
    return end;
}

struct node* searchForNode(struct node* start,int val){
    if(start == NULL) return NULL;
    if(start->data == val) return start;
    searchForNode(start->next,val);
}

void insertAfterNode(struct node* start,int x,int val){
    struct node* point = searchForNode(start,x);
    struct node* nextpoint = point->next;
    point->next = NULL;
    struct node* added = insertAtEnd(start,val);
    added->next = nextpoint;
}

void insertBeforeNode(struct node* start,int x,int val){
    struct node* temp1 = start;
    struct node* temp2 = start->next;
    while(1){
        if(temp2->data == x){
            struct node* new = createNode(temp1,val);
            new->next = temp2;
            temp1->next = new;;
            break;
        }
        temp1 = temp2;
        temp2 = temp2->next;
    }
}

int toNumber(struct node* start){
    int num = 0;
    struct node* iter = start;
    int i = 0;
    while(1){
        num += (iter->data)*power10(i);
        if(iter->next == NULL){
            break;
        }
        iter = iter->next;
        i++;
    }
    return num;
}

struct node* numToList(int num){
    struct node *start = (struct node*)malloc(sizeof(struct node));
    start->data = num%10;
    start->next = NULL;
    num /= 10;
    while(num != 0){
        struct node* obj = insertAtEnd(start,num%10);
        num /= 10;
    }
    return start;
}


struct node* deleteHead(struct node* start){
    struct node* newhead = start->next;
    free(start);
    return newhead;
}

void deleteEnd(struct node* start){
    struct node* temp1 = start;
    struct node* temp2 = start->next;
    while(1){
        if(temp2->next == NULL){
            temp1->next = NULL;
            free(temp2);
            break;
        }
        temp1 = temp2;
        temp2 = temp2->next;
    }
}

void deleteBeforeNode(struct node* start,int val){
    struct node* temp1 = start;
    struct node* temp2 = start->next;
    while(1){
        if(temp2->data == val){
            temp1->next = temp2->next;
            free(temp2);
            break;
        }
        temp1 = temp2;
        temp2 = temp2->next;
    }
}

void deleteAfterNode(struct node* start,int x){
    struct node* point = searchForNode(start,x);
    struct node* nextpoint = point->next;
    point->next = nextpoint->next;
    free(nextpoint);
}

int main(){
    //TC1 has 4 elements in the list already
    struct node *start = (struct node*)malloc(sizeof(struct node));
    start->data = 0;
    struct node *n1 = createNode(start,1);
    struct node *n2 = createNode(n1,2);
    struct node *n3 = createNode(n2,3);
    struct node *n4 = createNode(n3,4);

    int arr[4] = {5,6,7,8};
    int arr1[4] = {-5,-4,-3,-2};

    struct node* end = insertNNodesAtEnd(start,arr,4);
    displayListRec(start);
    printf("\n");
    // deleteEnd(start);
    struct node* newhead = insertAtBeginning(start,-1);
    newhead = insertNNodesAtBeginning(newhead,arr1,4);
    displayListLooped(newhead);
    struct node* searched = searchForNode(newhead,3);
    insertAfterNode(newhead,1,10);
    deleteEnd(newhead);
    newhead = deleteHead(newhead);
    deleteBeforeNode(newhead,4);
    insertBeforeNode(newhead,10,9);
    deleteAfterNode(newhead,3);
    newhead = deleteHead(newhead);
    displayListRec(newhead);
    
}

int main1(){
    //TC2 One element
    struct node *start = &head;
    start->data = 10;

    int arr[4] = {1,2,3,4};
    struct node* end = insertNNodesAtEnd(start,arr,4);
    displayListRec(start);
}

int main2(){
    //TC2 No element
    struct node *start = &head;
    //start->data = 10;

    int arr[4] = {1,2,3,4};
    struct node* end = insertNNodesAtEnd(start,arr,4);
    displayListRec(start);
}

int main3(){
    struct node *start = &head;
    start->data = 10;
    struct node *n1 = createNode(start,11);
    struct node *n2 = createNode(n1,12);
    struct node *n3 = createNode(n2,13);
    struct node *n4 = createNode(n3,14);

    int arr[0] = {};
    struct node* end = insertNNodesAtEnd(start,arr,0);
    displayListRec(start);
}