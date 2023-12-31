#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int val;
    struct Stack *next;
};

struct Stack *createStack(int x) {
    struct Stack *temp = (struct Stack *)malloc(sizeof(struct Stack));
    temp->next = NULL;
    temp->val = x;
    return temp;
}

void push(struct Stack **root, int x) {
    struct Stack *temp = createStack(x);
    temp->next = *root;
    *root = temp;
}

void pop(struct Stack **root){
    if(*root==NULL){
        printf("Stack is empty... UNDERFLOW\n");
        return;
    }
    struct Stack *temp=*root;
    *root=(*root)->next;
    free(temp);
}

int top(struct Stack *root){
    if(root==NULL){
        printf("Stack is empty... UNDERFLOW\n");
        return -1;
    }
    return root->val;
}

int isEmpty(struct Stack *root){
    return root==NULL;
}

int main() {
    struct Stack *root = NULL;
    int n;
    printf("Enter the number of elements in the stack: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter the elements of the stack: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        push(&root, a[i]);
    }
    printf("The elements of the stack are: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", top(root));
        pop(&root);
    }
    printf("\n");
    return 0;
}