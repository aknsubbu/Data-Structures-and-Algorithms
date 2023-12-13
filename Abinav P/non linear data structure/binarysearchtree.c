// #include <stdio.h>

// #define MAX_SIZE 100

// int tree[MAX_SIZE];
// int size = 0;

// void insert(int value) {
//     if (size == MAX_SIZE) {
//         printf("Error: Tree is full\n");
//         return;
//     }

//     int index = 0;
//     while (tree[index] != 0) {
//         if (value < tree[index]) {
//             index = 2 * index + 1; // Go to left child
//         } else {
//             index = 2 * index + 2; // Go to right child
//         }
//     }

//     tree[index] = value;
//     size++;
// }

// void delete(int value) {
//     int index = 0;
//     while (tree[index] != value) {
//         if (value < tree[index]) {
//             index = 2 * index + 1; // Go to left child
//         } else {
//             index = 2 * index + 2; // Go to right child
//         }

//         if (index >= size) {
//             printf("Error: Value not found in the tree\n");
//             return;
//         }
//     }

//     // Delete the node by shifting all subsequent nodes
//     for (int i = index; i < size - 1; i++) {
//         tree[i] = tree[i + 1];
//     }

//     tree[size - 1] = 0;
//     size--;
// }

// int main() {
//     insert(5);
//     insert(3);
//     insert(7);
//     insert(2);
//     insert(4);
//     insert(6);
//     insert(8);

//     delete(4);

//     // Print the tree
//     for (int i = 0; i < size; i++) {
//         printf("%d ", tree[i]);
//     }
//     printf("\n");

//     return 0;
// }


#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

struct Node* deleteNode(struct Node* root, int value) {
    if (root == NULL) {
        return root;
    }

    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    } else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        struct Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main() {
    struct Node* root = NULL;

    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 6);
    root = insert(root, 8);

    root = deleteNode(root, 4);

    printf("Inorder traversal: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
