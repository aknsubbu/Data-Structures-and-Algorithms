#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int tree[MAX_SIZE];

void insert(int value) {
    int i = 0;
    while (tree[i] != 0) {
        if (value < tree[i]) {
            i = 2 * i + 1;
        } else {
            i = 2 * i + 2;
        }
    }
    tree[i] = value;
}

int search(int value) {
    int i = 0;
    while (tree[i] != 0) {
        if (value == tree[i]) {
            return 1;
        } else if (value < tree[i]) {
            i = 2 * i + 1;
        } else {
            i = 2 * i + 2;
        }
    }
    return 0;
}

void inorder(int i) {
    if (tree[i] != 0) {
        inorder(2 * i + 1);
        printf("%d ", tree[i]);
        inorder(2 * i + 2);
    }
}

int main() {
    int choice, value;
    while (1) {
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Inorder Traversal\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the value to be inserted: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                printf("Enter the value to be searched: ");
                scanf("%d", &value);
                if (search(value)) {
                    printf("Value found in the tree.\n");
                } else {
                    printf("Value not found in the tree.\n");
                }
                break;
            case 3:
                printf("Inorder Traversal: ");
                inorder(0);
                printf("\n");
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
