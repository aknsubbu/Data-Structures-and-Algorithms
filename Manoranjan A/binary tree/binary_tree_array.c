#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct BinaryTree {
    int arr[MAX_SIZE];
    int size;
};

void createtree(struct BinaryTree* tree) {
    tree->size = 0;
}

void insertNode(struct BinaryTree* tree, int value) {
    if (tree->size < MAX_SIZE) {
        tree->arr[tree->size] = value;
        tree->size++;
    } else {
        printf("Tree is full. Cannot insert node.\n");
    }
}

void printTree(struct BinaryTree* tree, int index, int level) {
    if (index < tree->size) {
        printTree(tree, 2 * index + 2, level + 1);
        for (int i = 0; i < level; i++) {
            printf("    ");
        }
        printf("%d\n", tree->arr[index]);
        printTree(tree, 2 * index + 1, level + 1);
    }
}

int inorder(struct BinaryTree* tree, int index) {
    if (index < tree->size) {
        inorder(tree, 2 * index + 1);
        printf("%d ", tree->arr[index]);
        inorder(tree, 2 * index + 2);
    }
}

int main() {
    struct BinaryTree myTree;
    createtree(&myTree);

    insertNode(&myTree, 100);
    insertNode(&myTree, 90);
    insertNode(&myTree, 80);
    insertNode(&myTree, 95);
    insertNode(&myTree, 120);
    insertNode(&myTree, 110);

    printf("Inorder traversal:\n");
    inorder(&myTree, 0);
    

    printf("Binary Tree:\n");
    printTree(&myTree, 0, 0);

    return 0;
}
