#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct BinaryTree {
    struct Node* root;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insertNode(struct Node** root, int value) {
    if (*root == NULL) {
        *root = createNode(value);
    } else {
        if (value < (*root)->data) {
            insertNode(&((*root)->left), value);
        } else {
            insertNode(&((*root)->right), value);
        }
    }
}

void printTree(struct Node* root, int level) {
    if (root != NULL) {
        printTree(root->right, level + 1); // Print the right subtree
        for (int i = 0; i < level; i++) {
            printf("    ");
        }
        printf("%d\n", root->data); // Print the current node
        printTree(root->left, level + 1); // Print the left subtree
    }
}

int main() {
    struct BinaryTree myTree;
    myTree.root = NULL;

    insertNode(&(myTree.root), 4);
    insertNode(&(myTree.root), 2);
    insertNode(&(myTree.root), 6);
    insertNode(&(myTree.root), 1);
    insertNode(&(myTree.root), 3);

    printf("Binary Tree:\n");
    printTree(myTree.root, 0);

    return 0;
}
