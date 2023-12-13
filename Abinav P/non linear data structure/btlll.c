#include <stdio.h>
#include <stdlib.h>

// Structure for a node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to display the binary tree using inorder traversal
void inorderTraversal(struct Node* root) {
    if (root == NULL)
        return;
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

// Function to display the binary tree using preorder traversal
void preorderTraversal(struct Node* root) {
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// Function to display the binary tree using postorder traversal
void postorderTraversal(struct Node* root) {
    if (root == NULL)
        return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
}

int main() {
    // Create the root node
    struct Node* root = createNode(1);
    // Create the left and right child nodes
    root->left = createNode(2);
    root->right = createNode(3);
    // Create the left and right child nodes of the left child
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    // Display the binary tree using inorder traversal
    printf("Inorder Traversal: ");
    inorderTraversal(root);
    printf("\n");

    // Display the binary tree using preorder traversal
    printf("Preorder Traversal: ");
    preorderTraversal(root);
    printf("\n");

    // Display the binary tree using postorder traversal
    printf("Postorder Traversal: ");
    postorderTraversal(root);
    printf("\n");

    return 0;
}
