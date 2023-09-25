#include <stdio.h>
#include <stdlib.h>
#include "utilities.h"

struct node{
    int data;
    struct node* next;
}head;

struct node* getEnd(struct node* start){
    struct node* iter = start;
    while(1){
        if(iter->next == start){
            break;
        }
        iter = iter->next;
    }
    return iter;
}

void convertToCirc(struct node* start){
    struct node* end = getEnd(start);
    end->next = start;
}

void displayList(struct node* start){
    struct node* iter = start;
    while(1){
        printf("%d-->",iter->data);
        if(iter->next == start){
            printf("%d-->LOOP\n",start->data);
            break;
        }
        iter = iter->next;
    }
}

struct node* insertAtBeginning(struct node* start,int val){
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new->data = val;
    new->next = start;
    struct node* end = getEnd(start);
    end->next = new;
    return new;
}

struct node* insertAtEnd(struct node* start,int info){
    struct node* cur = (struct node*)malloc(sizeof(struct node));
    struct node* end = getEnd(start);
    end->next = cur;
    cur->data = info;
    cur->next = start;
    return cur;
}

struct node* insertNNodesAtBeginning(struct node* start,int arr[],int n){
    struct node* new = start;
    for(int i = n-1;i>=0;i--){
        new = insertAtBeginning(new,arr[i]);
    }
    return new;
}

void insertNNodesAtEnd(struct node* start,int arr[],int n){
    struct node* end = getEnd(start);
    
    for(int i = 0;i<n;i++){
        struct node* new = insertAtEnd(start,arr[i]);
        end->next = new;
        end = new;
    }
}

struct node* searchForNode(struct node* start,struct node* cur,int val){
    if(cur == start) return NULL;
    if(cur->data == val) return cur;
    searchForNode(start,cur->next,val);
}

struct node* insertAfterNode(struct node* start,int x,int val){
    struct node* point = searchForNode(start,start->next,x);
    if(point){
        struct node* nextpoint = point->next;
        point->next = start;
        struct node* added = insertAtEnd(start,val);
        added->next = nextpoint;
        point->next = added;
        return point;
    }
    printf("Node not found\n");
    return NULL;
}

struct node* insertBeforeNode(struct node* start,int x,int val){
    struct node* temp1 = start;
    struct node* temp2 = start->next;
    while(1){
        if(temp2->data == x){
            temp1->next = start;
            struct node* new = insertAtEnd(temp1,val);
            new->next = temp2;
            temp1->next = new;
            break;
        }
        temp1 = temp2;
        temp2 = temp2->next;
    }
    return temp1;
}

struct node* deleteHead(struct node* start){
    struct node* end = getEnd(start);
    //struct node* newhead = start->next;
    end->next == start->next;
    free(start);
    return end->next;
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
    struct node* point = searchForNode(start,start->next,x);
    struct node* nextpoint = point->next;
    point->next = nextpoint->next;
    free(nextpoint);
}



int main(){
    struct node *start = (struct node*)malloc(sizeof(struct node));
    start->data = 0;
    start->next = start;
    struct node *n1 = insertAtEnd(start,1);
    struct node *n2 = insertAtEnd(start,2);
    struct node *n3 = insertAtEnd(start,3);
    struct node *n4 = insertAtEnd(start,4);
    int arrbeg[4] = {-4,-3,-2,-1};
    int arrend[4] = {5,6,7,8};
    start = insertNNodesAtBeginning(start,arrbeg,4);
    insertNNodesAtEnd(start,arrend,4);
    displayList(start);
    // struct node* mid = searchForNode(start,start->next,6);
    // if(mid){
    //     displayList(mid);
    // }
    // else{
    //     printf("Not Found");
    // }
    struct node* new = insertBeforeNode(start,6,10);
    struct node* newhead = deleteHead(start);
    displayList(newhead);

}