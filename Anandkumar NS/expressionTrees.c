//expression trees
#include <stdio.h>
#include <stdlib.h>


struct TreeNode {
    char data;
    struct TreeNode* left;
    struct TreeNode* right;
};


struct TreeNode* createNode(char data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}


void printInfix(struct TreeNode* root) {
    if (root != NULL) {
        // If the current node is an operator, add parentheses
        if (root->left != NULL || root->right != NULL) {
            printf("(");
        }

        printInfix(root->left);

        printf("%c", root->data);


        printInfix(root->right);

        if (root->left != NULL || root->right != NULL) {
            printf(")");
        }
    }
}

int main() {
    struct TreeNode* root = createNode('*');
    root->left = createNode('+');
    root->right = createNode('-');
    root->left->left = createNode('a');
    root->left->right = createNode('b');
    root->right->left = createNode('c');
    root->right->right = createNode('d');


    printf("Infix Notation: ");
    printInfix(root);
    printf("\n");

    return 0;
}
