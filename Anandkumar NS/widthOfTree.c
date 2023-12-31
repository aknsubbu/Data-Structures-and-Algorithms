#include <stdio.h>
#include <stdlib.h>

// Structure representing a binary tree node
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new tree node
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to calculate the width of a binary tree
int calculateWidth(struct TreeNode* root, int level) {
    if (root == NULL) {
        return 0;
    }

    if (level == 1) {
        return 1;
    }

    return calculateWidth(root->left, level - 1) + calculateWidth(root->right, level - 1);
}

// Function to find the height of a binary tree
int findHeight(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }

    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);

    return (leftHeight > rightHeight) ? (leftHeight + 1) : (rightHeight + 1);
}

// Function to find the maximum width of a binary tree
int findMaxWidth(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }

    int maxWidth = 0;
    int height = findHeight(root);

    for (int level = 1; level <= height; level++) {
        int width = calculateWidth(root, level);
        if (width > maxWidth) {
            maxWidth = width;
        }
    }

    return maxWidth;
}

int main() {
    // Example binary tree
    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->right = createNode(8);
    root->right->right->left = createNode(6);
    root->right->right->right = createNode(7);

    int maxWidth = findMaxWidth(root);

    printf("Maximum width of the binary tree: %d\n", maxWidth);

    return 0;
}
