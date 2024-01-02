#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char data;
    struct Node* left;
    struct Node* right;
} Node;

Node* GetNode(char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}
Node* constructExpressionTree(char postfix[]) {
    int i = 0;
    Node* stack[100];
    int top = -1;
    while (postfix[i] != '\0') {
        char symbol = postfix[i];
        if (!isOperator(symbol)) {
            stack[++top] = GetNode(symbol);
        } else {
            Node* newNode = GetNode(symbol);
            newNode->right = stack[top--];
            newNode->left = stack[top--];
            stack[++top] = newNode;
        }
        i++;
    }
    return stack[top];
}
int evaluateExpressionTree(Node* root) {
    if (root == NULL) {
        return 0;
    }
    if (!isOperator(root->data)) {
        return root->data - '0';
    } else {
        int leftValue = evaluateExpressionTree(root->left);
        int rightValue = evaluateExpressionTree(root->right);
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
    Node* expressionTree = constructExpressionTree(postfixExpression);
    printf("Postfix Expression: %s\n", postfixExpression);
    printf("Result: %d\n", evaluateExpressionTree(expressionTree));
    return 0;
}