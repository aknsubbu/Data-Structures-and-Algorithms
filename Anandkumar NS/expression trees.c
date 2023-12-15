#include <stdio.h>

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int data){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int isOperand(char ch){
    return (ch >= '0' && ch <= '9');
}

struct Node *constructExpressionTree(char postfix[]){
    struct Node *stack[100];
    int top = -1;

    for(int i = 0; postfix[i] != '\0'; ++i){
        struct Node *newNode = createNode(postfix[i]);

        if(isOperand(postfix[i])){
            stack[++top] = newNode;
        }
        else{
            newNode->right = stack[top--];
            newNode->left = stack[top--];
            stack[++top] = newNode;
        }
    }

    return stack[top];
}

void inOrderTraversal(struct Node *root){
    if(root != NULL){
        if(isOperand(root->data))
            printf("%c ", root->data);
        else{
            printf("( ");
            inOrderTraversal(root->left);
            printf("%c ", root->data);
            inOrderTraversal(root->right);
            printf(") ");
        }
    }
}

int evaluate(struct Node *root){
    if(root == NULL)
        return 0;
    if(isOperand(root->data))
        return root->data - '0';
    else{
        int left = evaluate(root->left);
        int right = evaluate(root->right);
        switch(root->data){
            case '+': return left + right;
            case '-': return left - right;
            case '*': return left * right;
            case '/': return left / right;
            case '%': return left % right;
            case '^': return left ^ right;
        }
    }
}

int main(){
    char postfix[100];
    printf("Enter the postfix expression: ");
    scanf("%s", postfix);
    struct Node *root = constructExpressionTree(postfix);
    printf("Infix expression: ");
    inOrderTraversal(root);
    printf("\n");
    printf("Value of expression: %d\n", evaluate(root));
    return 0;
}

