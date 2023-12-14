#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the expression tree
struct TreeNode {
    char data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new node with a given data
struct TreeNode* createNode(char data) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to check if a character is an operand
int isOperand(char ch) {
    return (ch >= '0' && ch <= '9');
}

// Function to construct an expression tree from a postfix expression
struct TreeNode* constructExpressionTree(char postfix[]) {
    struct TreeNode* stack[100];
    int top = -1;

    for (int i = 0; postfix[i] != '\0'; ++i) {
        struct TreeNode* newNode = createNode(postfix[i]);

        if (isOperand(postfix[i])) {
            stack[++top] = newNode;
        } else {
            newNode->right = stack[top--];
            newNode->left = stack[top--];
            stack[++top] = newNode;
        }
    }

    return stack[top];
}

// Function to perform in-order traversal of the expression tree
void inOrderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        if (isOperand(root->data))
            printf("%c ", root->data);
        else {
            printf("( ");
            inOrderTraversal(root->left);
            printf("%c ", root->data);
            inOrderTraversal(root->right);
            printf(") ");
        }
    }
}

// Function to evaluate the expression tree
int evaluateExpressionTree(struct TreeNode* root) {
    if (root == NULL)
        return 0;

    if (isOperand(root->data))
        return root->data - '0';

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
            return leftValue / rightValue;
        default:
            return 0; // Invalid operator
    }
}

int main() {
    char postfix[] = "34*5+";

    // Construct the expression tree
    struct TreeNode* root = constructExpressionTree(postfix);

    // Print the in-order traversal of the expression tree
    printf("In-order traversal of the expression tree: ");
    inOrderTraversal(root);
    printf("\n");

    // Evaluate the expression tree
    int result = evaluateExpressionTree(root);
    printf("Result of the expression: %d\n", result);

    return 0;
}
