#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node {
    int* arr;
    int levels;
    int size;
};

struct node* insertNode(struct node* tree, int data) {
    if (tree->arr[0] == 0) {
        tree->arr[0] = data;
        return tree;
    }

    int i = 0;
    while (i < tree->size) {
        if (data < tree->arr[i]) {
            if (2*i+1 > tree->size) {
                i = 2*i+1;
                break;
            }
            if (tree->arr[2*i+1] == 0) {
                tree->arr[2*i+1] = data;
                return tree;
            }
            else {
                i = 2*i+1;
            }
        }
        else {
            if (2*i+2 > tree->size) {
                i = 2*i+2;
                break;
            }
            if (tree->arr[2*i+2] == 0) {
                tree->arr[2*i+2] = data;
                return tree;
            }
            else {
                i = 2*i+2;
            }
        }
    }

    int oldSize = tree->size;
    tree->size = pow(2, ++(tree->levels)) - 1;
    int* tmp = realloc(tree->arr, (tree->size)*sizeof(int));
    if (tmp == NULL) {
        printf("Reallocation Error!\n");
        exit(1);
    }

    for (int j = 0; j < oldSize; j++) {
        tmp[j] = tree->arr[j];
    }
    for (int j = oldSize; j < tree->size; j++) {
        tmp[j] = 0;
    }
    tree->arr = tmp;

    tree->arr[i] = data;
    return tree;
    
}

struct node* initialise() {
    struct node* new = malloc(sizeof(struct node));
    new->levels = 1;
    new->size = pow(2, new->levels) - 1;
    new->arr = calloc(new->size, sizeof(int));
    return new;
}

struct node* newTree() {

    struct node* tree = initialise();

    printf("Enter number of elements:");
    int val, num;
    scanf("%d", &num);

    for (int n = 0; n < num; n++)
    {
        printf("Enter value: ");
        scanf("%d", &val);
        tree = insertNode(tree, val);
    } 

    return tree;
}

void printLevelOrder(struct node* tree) {
    if (tree->size == 0) {
        printf("Tree is empty.\n");
        return;
    }

    printf("Tree Structure:\n ");
    int lastSize = pow(2, tree->levels - 1);
    int i = 0, levelSize = 1, level = 1;
    int space = (lastSize - pow(2, level - 1)) / 2;
    for (int j = 0; j < space; j++) printf("  ");
    

    while (i < tree->size) {
        printf("%d ", tree->arr[i++]);
        if (i == levelSize) {
            printf("\n");
            levelSize = pow(2, ++level) - 1;
            int space = (lastSize - pow(2, level - 1)) / 2;
            for (int j = 0; j < space; j++) printf("  ");
        }
    }
}

void printInorder(struct node* tree, int node) {
    if (node < tree->size && tree->arr[node] != 0) {
        printInorder(tree, 2 * node + 1);
        printf("%d ", tree->arr[node]);
        printInorder(tree, 2 * node + 2);
    }
}

int delIndex(struct node* tree, int data, int i){
    if (i > tree->size) return -1;
    if (tree->arr[i] == 0) return -1;
    if (data == tree->arr[i]) return i;

    if (data < tree->arr[i]) return delIndex(tree, data, 2*i+1);
    if (data > tree->arr[i]) return delIndex(tree, data, 2*i+2);
}

void fixTree(struct node* tree, int i) {
    tree->arr[(i-1)/2] = tree->arr[i];
    tree->arr[i] = 0;

    if (2*i+1 < tree->size && tree->arr[2*i+1] != 0) fixTree(tree, 2*i+1);
    if (2*i+2 < tree->size && tree->arr[2*i+2] != 0) fixTree(tree, 2*i+2);
}

int inOrderSuccessor(struct node* tree, int delPos) {
    int succ = 2*delPos+2;

    while (2*succ+1 < tree->size && tree->arr[2*succ+1] != 0) {
        succ = 2*succ+1;
    }
    return succ;
}

struct node* delete(struct node* tree, int data) {
    int delPos = delIndex(tree, data, 0);

    // doesn't exist
    if (delPos == -1) return tree;

    // no children
    if (2*delPos+1>tree->size && 2*delPos+2>tree->size) {
        tree->arr[delPos] = 0;
        return tree;
    }
    if (tree->arr[2*delPos+1] == 0 && tree->arr[2*delPos+2] == 0) {
        tree->arr[delPos] = 0;
        return tree;
    }

    // right child
    if (tree->arr[2*delPos+1] == 0 && tree->arr[2*delPos+2] != 0) {
        fixTree(tree, 2*delPos+2);
        return tree;
    }
    // left child
    if (tree->arr[2*delPos+1] != 0 && tree->arr[2*delPos+2] == 0) {
        fixTree(tree, 2*delPos+1);
        return tree;
    }

    // two children
    if (tree->arr[2*delPos+1] != 0 && tree->arr[2*delPos+2] != 0) {
        int IOSuccPos = inOrderSuccessor(tree, delPos);
        int IOSuccVal = tree->arr[IOSuccPos];
        tree = delete(tree, IOSuccVal);
        tree->arr[delPos] = IOSuccVal;
        return tree;
    }
    return tree;
}



void printMenu() {
    printf("\nMenu:\n");
    printf("1. Create a new tree\n");
    printf("2. Insert a node\n");
    printf("3. Delete a node\n");
    printf("4. Print tree\n");
    printf("5. Print menu\n");
    printf("6. Exit\n");
}

int main(void) {
    struct node* tree = NULL; // Initialize tree to NULL

    int option;
    printMenu();
    do {
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                // Create a new tree
                tree = newTree();
                break;

            case 2:
                // Insert a node
                if (tree == NULL) {
                    printf("Error: Create a new tree first.\n");
                } 
                else {
                    int val;
                    printf("Enter value to insert: ");
                    scanf("%d", &val);
                    tree = insertNode(tree, val);
                    printf("Node %d inserted.\n", val);
                }
                break;

            case 3:
                // Delete a node
                if (tree == NULL) {
                    printf("Error: Create a new tree first.\n");
                } else {
                    int val;
                    printf("Enter value to delete: ");
                    scanf("%d", &val);
                    tree = delete(tree, val);
                    printf("Node %d deleted.\n", val);
                }
                break;

            case 4:
                // Print tree
                if (tree == NULL) {
                    printf("Error: Create a new tree first.\n");
                } else {
                    printf("\nArray in memory:\n");
                    for (int i = 0; i < tree->size; i++) printf("%d", tree->arr[i]);
                    printf("\n\nInorder: ");
                    printInorder(tree, 0);
                    printf("\n\nTree Structure: ");
                    printLevelOrder(tree);
                }
                break;

            case 5:
                // Print menu
                printMenu();
                break;

            case 6:
                // Exit
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (option != 6);

    return 0;
}