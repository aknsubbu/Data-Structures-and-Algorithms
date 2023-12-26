#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node{
    int data;
    struct node* prev;
    struct node* next;
};

typedef struct node node;

void printNode(node* obj){
    printf("%d <-- %d --> %d\n",(obj->prev)->data,obj->data,(obj->next)->data);
}

node* getEnd(node* start){
    node* iter = start;
    while(1){
        if(iter->next == NULL){
            break;
        }
        iter = iter->next;
    }
    
    return iter;
}

node* insertAtEnd(node* start,int val){
    node* end = getEnd(start);
    node* new = (node*)malloc(sizeof(node));
    end->next = new;
    new->prev = end;
    new->data = val;
    new->next = NULL;
    
    return new;
}

void displayList(node* start){
    node* iter = start;
    while(1){
        printf(" %d <-->",iter->data);
        if(iter->next == NULL){
            printf(" NULL\n");
            break;
        }
        iter = iter->next;
    }
}

void deleteNode(node* start,node* toDelete){
    node* previous = toDelete->prev;
    node* nextobj = toDelete->next;
    printNode(previous);
    printNode(nextobj);
    free(toDelete);
}

node* searchNode(node* start,int val){
    if(start == NULL) return NULL;
    if(start->data == val) return start;
    searchNode(start->next,val);
}

node* createPath(int val){
    node* new = (node*)malloc(sizeof(node));
    new->prev = new->next = NULL;
    new->data = val;
    return new;
}

node** createAdjacencyList(int numNodes){
    node** new = (node**)malloc(sizeof(node*)*numNodes);
    for(int i = 0;i<numNodes;i++){
        new[i] = createPath(i);
    }
    return new;
}

void addEdge(node** adjList,int source, int destination){
    insertAtEnd(adjList[source],destination);
}

void displayAdjlist(node** adjList,int numNodes){
    for(int i = 0;i<numNodes;i++){
        displayList(adjList[i]);
    }
}

int push(int* arr,int size,int top,int val){
    if(++top<=size){
        arr[top] = val;
        return top;
    }
    printf("Stack Overflow\n");
    return top;
}

int pop(int* arr,int* top){
    if((*top)<0){
        printf("Stack Overflow");
        return *top;
    }
    int temp = arr[*top];
    (*top)--;
    return temp;
}


void bfs(node** adjList, int s){
    bool visited[100];
    for (int i = 0; i < 100; i++) {
        visited[i] = false;
    }
 
    int queue[100];
    int front = 0, rear = 0;
 
    visited[s] = true;
    queue[rear++] = s;
 
    while (front != rear){
        int u = queue[++front];
        printf("%d ", u);
        struct node *temp = adjList[u];
        while (temp){
            if (!visited[temp->data]){
                queue[++rear] = temp->data;
                visited[temp->data] = 1;
            }
            temp = temp->next;
        }
    }
}


void dfs(struct node **adjList,int start){
    bool visited[100];
    int stack[100];
    int top = -1;
    stack[++top] = start;
    visited[start] = 1;
    while (top != -1){
        int u = stack[top--];
        printf("%d ", u);
        struct node *temp = adjList[u];
        while (temp){
            if (!visited[temp->data]){
                stack[++top] = temp->data;
                visited[temp->data] = 1;
            }
            temp = temp->next;
        }
    }
}

int main() {
    int numNodes = 5;


    node** adjList = createAdjacencyList(numNodes);


    addEdge(adjList, 0, 1);
    addEdge(adjList, 0, 2);
    addEdge(adjList, 1, 3);
    addEdge(adjList, 2, 4);


    displayAdjlist(adjList, numNodes);
    bfs(adjList,0);
    return 0;
}

