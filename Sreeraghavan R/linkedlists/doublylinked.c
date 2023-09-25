#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* prev;
    struct node* next;
};

void printNode(struct node* obj){
    printf("%d <-- %d --> %d\n",(obj->prev)->data,obj->data,(obj->next)->data);
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

struct node* insertAtEnd(struct node* start,int val){
    struct node* end = getEnd(start);
    struct node* new = (struct node*)malloc(sizeof(struct node));
    end->next = new;
    new->prev = end;
    new->data = val;
    new->next = NULL;
    
    return new;
}

void displayList(struct node* start){
    struct node* iter = start;
    while(1){
        printf(" %d <-->",iter->data);
        if(iter->next == NULL){
            printf(" NULL\n");
            break;
        }
        iter = iter->next;
    }
}

struct node* insertAtBeginning(struct node* start,int val){
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new->data = val;
    new->next = start;
    new->prev = NULL;
    start->prev = new;
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
    struct node* iter = start;
    while(1){
        if(iter->data == x){
            struct node* previous = iter->prev;
            insertAfterNode(start,previous->data,val);
            break;
        }
        iter = iter->next;
    }
}

struct node* deleteHead(struct node* start){
    struct node* newhead = start->next;
    free(start);
    return newhead;
}

void deleteEnd(struct node* start){
    struct node* end = getEnd(start);
    (end->prev)->next = NULL;
    free(end);
}

void deleteNode(struct node* start,struct node* toDelete){
    struct node* previous = toDelete->prev;
    struct node* nextobj = toDelete->next;
    printNode(previous);
    printNode(nextobj);
    free(toDelete);
}

void deleteBeforeNode(struct node* start,int val){
    struct node* temp = searchForNode(start,val);
    if(temp){
        
    }
    printf("Not Found\n");
}

int main(){
    struct node* head = (struct node*)malloc(sizeof(struct node));
    head->prev = NULL;
    head->data = 10;
    head->next = NULL;
    struct node* end = getEnd(head);
    int arrbeg[4] = {5,6,7,8};
    int arrend[4] = {11,12,13,14};
    head = insertAtBeginning(head,9);
    head = insertNNodesAtBeginning(head,arrbeg,4);
    end = insertNNodesAtEnd(head,arrend,4);
    struct node* mid = searchForNode(head,11);
    //printNode(mid);
    insertAfterNode(head,11,15);
    insertBeforeNode(head,10,16);
    head = deleteHead(head);
    deleteEnd(head);
    displayList(head);
    struct node* point10 = searchForNode(head,11);
    printNode(point10);
    deleteNode(head,point10);
    //displayList(head);
    
}