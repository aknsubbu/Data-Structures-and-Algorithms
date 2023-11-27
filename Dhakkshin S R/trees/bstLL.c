#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node * left;
    struct node * right;
};

struct node* getNode(int data) {
    struct node* new = malloc(sizeof(struct node));
    new->data = data;
    new->left = NULL;
    new->right = NULL;
    return new;
}

struct node* insertNode(struct node* root, int data) {   
    if (root == NULL) {
        root = getNode(data);
        return root;
    }

    struct node* iter = root;

    while (iter) {
        if (data < iter->data) {
            if (iter->left) {
                iter = iter->left;
            }
            else {
                iter->left = getNode(data);
                break;
            }    
        }
        else {
            if (iter->right) {
                iter = iter->right;
            }
            else {
                iter->right = getNode(data);
                break;
            }
        }
    }
    return root;
}

struct node* newTree() {
    int num, data = 0;
    printf("How many elemnets do you want in your tree? ");
    scanf("%d", &num);

    struct node* tree = NULL;
    for (int i = 0; i < num; i++) { 
        printf("Enter the value: ");
        scanf("%d", &data);
        tree = insertNode(tree, data);
    }
    return tree;
}

void printBST(struct node* root) {
    if (root != NULL) {
        printBST(root->left);  
        printf("%d ", root->data);  
        printBST(root->right);  
    }
}

void printTree(struct node* root, int space) {
    int i;

    // Base case: if the node is null, return
    if (root == NULL) return;

    // Increase the space count for each level
    space += 10;

    // Recursively print the right subtree (on top)
    printTree(root->right, space);

    // Print the current node
    printf("\n");
    for (i = 2; i < space; i++) {
        printf(" ");
    }
    printf("%d\n", root->data);

    // Recursively print the left subtree (on bottom)
    printTree(root->left, space);
}

struct node* inorderPredecessor(struct node* node)
{
    struct node* curr = node -> right;

    while(curr -> left) {
        curr = curr -> left;
    }
    return curr;
}

struct node* findParent(struct node* node, int val, int* child) {
    struct node* parent = NULL;
    while (node) {
        if (node->data == val) return parent;
        parent = node;
        if (val < node->data) {
            *child = 2;
            node = node->left;
        }
        else {
            *child = 1;
            node = node->right;
        }
    }
    return parent;
}

struct node* deleteNode(struct node* root, int data) {
    int child = 0;
    struct node* parent = findParent(root, data, &child);
    struct node* TBDel = NULL; 
    struct node* tmp = NULL; 
    if (parent && child == 2) TBDel = parent->left;
    else if (parent && child == 1) TBDel = parent->right;
    else if (parent == NULL) TBDel = root;

    // case 1 left no right no
    if (!(TBDel->left) && !(TBDel->right)) {
        if (parent == NULL) {
            return NULL;
        }
        if (child == 2) {
           tmp = parent->left;
           parent->left = NULL;
        }
        else if (child == 1) {
            tmp = parent->right;
            parent->right = NULL;
        }
    }

    // case 2.1 left yes right no
    else if ((TBDel->left) && !(TBDel->right)) {
        if (parent == NULL) {
            return TBDel->left;
        }
        if (child == 2) {
            tmp = parent->left;
            parent->left = parent->left->left;
        }
        else if (child == 1) {
            tmp = parent->right;
            parent->right = parent->right->left;
        }
    }

    // case 2.2 left no right yes
    else if (!(TBDel->left) && (TBDel->right)) {
        if (parent == NULL) {
            return TBDel->right;
        }
        if (child == 2) {
            tmp = parent->left;
            parent->left = parent->left->right;
        }
        else if (child == 1) {
            tmp = parent->right;
            parent->right = parent->right->right;
        }
    }

    // case 3 left yes right yes
    else if ((TBDel->left) && (TBDel->right)) {
        struct node* IOSucc = inorderPredecessor(TBDel);
        int tmp = IOSucc->data;
        root = deleteNode(root, tmp);
        TBDel->data = tmp;
    }

    if (tmp) free(tmp);
    return root;
}

void displayMenu() {
    printf("\nMenu:\n");
    printf("1. New Tree\n");
    printf("2. Add New Element\n");
    printf("3. Delete Element\n");
    printf("4. Print BST\n");
    printf("5. Menu\n");
    printf("6. Exit\n");
}

int main() {
    struct node* tree = NULL; 

    int choice;
    int element;

    displayMenu();
    do {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                tree = newTree();
                printf("New tree created.\n");
                break;

            case 2:
                printf("Enter the element to add: ");
                scanf("%d", &element);
                tree = insertNode(tree, element);
                printf("Element %d added to the tree.\n", element);
                break;

            case 3:
                printf("Enter the element to delete: ");
                scanf("%d", &element);
                tree = deleteNode(tree, element);
                printf("Element %d deleted from the tree.\n", element);
                break;

            case 4:
                printf("BST in-order traversal:\n");
                printBST(tree);
                printTree(tree, 0);
                break;

            case 5:
                displayMenu();
                break;

            case 6:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 6);

    return 0;
}