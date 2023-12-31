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

int main() {
    struct BinaryTree myTree;
    createtree(&myTree);

    insertNode(&myTree, 1);
    insertNode(&myTree, 2);
    insertNode(&myTree, 3);
    insertNode(&myTree, 4);
    insertNode(&myTree, 5);

    printf("Binary Tree:\n");
    printTree(&myTree, 0, 0);

    return 0;
}
