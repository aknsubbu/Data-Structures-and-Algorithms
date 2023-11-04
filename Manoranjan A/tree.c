#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

typedef struct TreeNode TreeNode;

TreeNode* insert(TreeNode* root, int n) {
    if (root == NULL) {
        TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
        newNode->data = n;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }

    if (n < root->data) {
        root->left = insert(root->left, n);
    } else if (n > root->data) {
        root->right = insert(root->right, n);
    }

    return root;
}

TreeNode* search(TreeNode* root, int n) {
    if (root == NULL || root->data == n) {
        return root;
    }

    if (n < root->data) {
        return search(root->left, n);
    } else {
        return search(root->right, n);
    }
}

TreeNode* findMin(TreeNode* node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

TreeNode* delete(TreeNode* root, int n) {
    if (root == NULL) {
        return root;
    }

    if (n < root->data) {
        root->left = delete(root->left, n);
    } else if (n > root->data) {
        root->right = delete(root->right, n);
    } else {
        if (root->left == NULL) {
            TreeNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            TreeNode* temp = root->left;
            free(root);
            return temp;
        }

        TreeNode* temp = findMin(root->right);
        root->data = temp->data;
        root->right = delete(root->right, temp->data);
    }

    return root;
}

void inorder(TreeNode* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(TreeNode* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(TreeNode* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

void freeTree(TreeNode* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

// Function to print the binary tree structure
void printTree(TreeNode* root, int space) {
    if (root == NULL) {
        return;
    }

    space += 5; // Increase the distance between levels

    // Print the right subtree
    printTree(root->right, space);

    // Print the current node
    printf("\n");
    for (int i = 5; i < space; i++) {
        printf(" ");
    }
    printf("%d\n", root->data);

    // Print the left subtree
    printTree(root->left, space);
}

int main() {
    TreeNode* root = NULL;
    int choice, value;

    while (1) {
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Delete\n");
        printf("4. Inorder Traversal\n");
        printf("5. Preorder Traversal\n");
        printf("6. Postorder Traversal\n");
        printf("7. Print Tree\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to be inserted: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;
            case 2:
                printf("Enter the value to be searched: ");
                scanf("%d", &value);
                TreeNode* result = search(root, value);
                if (result != NULL) {
                    printf("Found\n");
                } else {
                    printf("Not found\n");
                }
                break;
            case 3:
                printf("Enter the value to be deleted: ");
                scanf("%d", &value);
                root = delete(root, value);
                break;
            case 4:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 5:
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
                break;
            case 6:
                printf("Postorder Traversal: ");
                postorder(root);
                printf("\n");
                break;
            case 7:
                printf("Binary Tree Structure:\n");
                printTree(root, 0);
                break;
            case 8:
                freeTree(root); // Free allocated memory
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}
