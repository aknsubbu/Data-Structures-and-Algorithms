#include <stdio.h>
#include <stdlib.h>

struct node {
    char data;
    struct node* lc;
    struct node* rc;
}; 

typedef struct node node;


node* createNode(char data) {
    node* new = (node*)malloc(sizeof(node));
    new->data = data;
    new->lc = new->rc = NULL;
    return new;
}

int isOperator(char c){
    switch(c){
        case '+':
        case '-':
        case '*':
        case '/':
            return 1;
        default:
            return 0;
    }
}

node* constructExpressionTree(char postfix[]) {
    int i = 0;
    node* stack[100];
    int top = -1;
    while (postfix[i] != '\0') {
        char symbol = postfix[i];
        if (!isOperator(symbol)) {
            stack[++top] = createNode(symbol);
        } else {
            node* new = createNode(symbol);
            new->rc = stack[top--];
            new->lc = stack[top--];
            stack[++top] = new;
        }
        i++;
    }
    return stack[top];
}


int evalExp(node* root) {
    if (root == NULL) {
        return 0;
    }
    if (!isOperator(root->data)) {
        return root->data - '0';
    } else {
        int leftValue = evalExp(root->lc);
        int rightValue = evalExp(root->rc);
        switch (root->data) {
            case '+':
                return leftValue + rightValue;
            case '-':
                return leftValue - rightValue;
            case '*':
                return leftValue * rightValue;
            case '/':
                if (rightValue != 0) {
                    return leftValue / rightValue;
                } else {
                    printf("Error: Division by zero.\n");
                    
                }
            default:
                printf("Error: Invalid operator.\n");
                
        }
    }
}


int main() {
    char postfixExpression[100]; 
    printf("Enter a postfix expression: ");
    scanf("%s", postfixExpression);
    node* expressionTree = constructExpressionTree(postfixExpression);
    printf("Postfix Expression: %s\n", postfixExpression);
    printf("Result: %d\n", evalExp(expressionTree));
    return 0;
}