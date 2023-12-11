#include <stdlib.h>
#include <stdio.h>


struct Node{
    int data;
    struct Node* below;
};

struct Stack{
    struct Node* top;
    int size;
    int num;
};

typedef struct Stack Stack;
typedef struct Node Node;

Node* getNode(int val){
    Node* newNode = (Node *)malloc(sizeof(Node));
    newNode->data = val;
    newNode->below = NULL;
    return newNode;
}

void push(Stack* s,int val){
    if(s->num + 1 < s->size){
        Node* newTop = getNode(val);
        newTop->below = s->top;
        s->top = newTop;
        ++(s->num);
        return;
    }
    printf("OVERFLOW\n");
}

void print(Stack* s){
    Node* node = s->top;
    while(node){
        printf("%d ",node->data);
        node = node->below;
    }
}

Stack* createStack(int val,int size){
    Stack* newStack = (Stack *)malloc(sizeof(Stack));
    newStack->top = getNode(val);
    newStack->size = size;
    newStack->num = 0;
    return newStack;
}

int pop(Stack* s){
    if(!s->num){
        print("UNDERFLOW\n");
        return -99999;
    }
    if(s->num == 1){
        int temp = s->top->data;
        s->top = NULL;
        --(s->num);
        return temp;
    }
    int temp = s->top->data;
    s->top = s->top->below;
    --(s->num);
    return temp;
}

int main(){
    Stack* s = createStack(0,4);
    push(s,1);
    push(s,2);
    push(s,3);
    printf("%d\n",pop(s));
    push(s,4);
    print(s);
}