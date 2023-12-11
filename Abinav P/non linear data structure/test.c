#include <stdio.h>
#include <stdlib.h>

// Structure for a tree node
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new tree node
struct TreeNode* createNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Recursive function to perform in-order traversal and find the kth smallest element
void kthSmallestUtil(struct TreeNode* root, int k, int* count, int* result) {
    if (root == NULL || *count >= k) {
        return;
    }

    // Traverse the left subtree
    kthSmallestUtil(root->left, k, count, result);

    // Increment the count
    (*count)++;

    // Check if the current node is the kth smallest
    if (*count == k) {
        *result = root->val;
        return;
    }

    // Traverse the right subtree
    kthSmallestUtil(root->right, k, count, result);
}

// Function to find the kth smallest element in a BST
int kthSmallest(struct TreeNode* root, int k) {
    int count = 0; // Counter to keep track of visited nodes
    int result = -1; // Variable to store the result

    // Call the utility function
    kthSmallestUtil(root, k, &count, &result);

    return result;
}

// Example usage
int main() {
    // Create a sample BST
    struct TreeNode* root = createNode(3);
    root->left = createNode(1);
    root->right = createNode(4);
    root->left->right = createNode(2);

    // Find the kth smallest element (e.g., k=2)
    int k = 1;
    int result = kthSmallest(root, k);

    if (result != -1) {
        printf("The %dth smallest element is: %d\n", k, result);
    } else {
        printf("Invalid input or k is out of bounds.\n");
    }

    return 0;
}
