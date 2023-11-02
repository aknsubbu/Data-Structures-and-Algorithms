#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int data) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct node *insert(struct node *root, int data) {
    if (root == NULL) {
        root = createNode(data);
    } else if (data <= root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

// void deletenode(struct node *root, int data) {
//     if (root == NULL) {
//         printf("Not found\n");
//     } else if (data < root->data) {
//         deletenode(root->left, data);
//     } else if (data > root->data) {
//         deletenode(root->right, data);
//     } else {
//         if (root->left == NULL && root->right == NULL) {
//             free(root);
//             root = NULL;
//         } else if (root->left == NULL) {
//             struct node *temp = root;
//             root = root->right;
//             free(temp);
//         } else if (root->right == NULL) {
//             struct node *temp = root;
//             root = root->left;
//             free(temp);
//         } else {
//             struct node *temp = root->right;
//             while (temp->left != NULL) {
//                 temp = temp->left;
//             }
//             root->data = temp->data;
//             deletenode(root->right, temp->data);
//         }
//     }
// }

void deletenode(struct node *root, int data) {
    struct node *parent = NULL;
    int position;
    struct node *temp = search(root, data, &parent, &position);
    if (temp == NULL) {
        printf("Not found\n");
    } else {
        if (temp->left == NULL && temp->right == NULL) {
            if (position == 0) {
                parent->left = NULL;
            } else {
                parent->right = NULL;
            }
            free(temp);
        } else if (temp->left == NULL) {
            if (position == 0) {
                parent->left = temp->right;
            } else {
                parent->right = temp->right;
            }
            free(temp);
        } else if (temp->right == NULL) {
            if (position == 0) {
                parent->left = temp->left;
            } else {
                parent->right = temp->left;
            }
            free(temp);
        } else {
            struct node *temp2 = temp->right;
            while (temp2->left != NULL) {
                temp2 = temp2->left;
            }
            temp->data = temp2->data;
            deletenode(temp->right, temp2->data);
        }
    }
}

void inorder(struct node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// void search(struct node *root, int data) {
//     if (root == NULL) {
//         printf("Not found\n");
//     } else if (root->data == data) {
//         printf("Found\n");
//     } else if (data <= root->data) {
//         search(root->left, data);
//     } else {
//         search(root->right, data);
//     }
// }

// a search function that return the node and its parent and also postion of the node

struct node *search(struct node *root, int data, struct node **parent, int *position) {
    if (root == NULL) {
        return NULL;
    } else if (root->data == data) {
        return root;
    } else if (data <= root->data) {
        *parent = root;
        *position = 0;
        return search(root->left, data, parent, position);
    } else {
        *parent = root;
        *position = 1;
        return search(root->right, data, parent, position);
    }
}
void inordersuccesor(struct node *root, int data) {
    struct node *parent = NULL;
    int position;
    struct node *temp = search(root, data, &parent, &position);
    if (temp == NULL) {
        printf("Not found\n");
    } else {
        if (temp->right != NULL) {
            struct node *temp2 = temp->right;
            while (temp2->left != NULL) {
                temp2 = temp2->left;
            }
            printf("Inorder succesor: %d\n", temp2->data);
        } else {
            if (position == 0) {
                printf("Inorder succesor: %d\n", parent->data);
            } else {
                struct node *temp2 = root;
                while (temp2->data != parent->data) {
                    if (data <= temp2->data) {
                        temp2 = temp2->left;
                    } else {
                        temp2 = temp2->right;
                    }
                }
                printf("Inorder succesor: %d\n", temp2->data);
            }
        }
    }
}

void printtree(struct node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        printtree(root->left);
        printtree(root->right);
    }
}

int main() {
    struct node *root = NULL;
    int choice, data;
    while (1) {
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Inorder Traversal\n");
        printf("4. Preorder Traversal\n");
       //printf("4. Delete\n");
        printf("5. Print tree\n");
        printf("6. Inorder succesor\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the value to be inserted: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;
            case 2:
                printf("Enter the value to be searched: ");
                scanf("%d", &data);
                struct node *parent = NULL;
                int position;
                struct node *temp = search(root, data, &parent, &position);
                if (temp == NULL) {
                    printf("Not found\n");
                } else {
                    printf("Found\n");
                    printf("Parent: %d\n", parent->data);
                    printf("Position: %d\n", position);
                }
                break;
            case 3:
                inorder(root);
                printf("\n");
                break;
            case 4:
                preorder(root);
                printf("\n");
                break;
            // case 4:
            //     printf("Enter the value to be deleted: ");
            //     scanf("%d", &data);
            //     deletenode(root, data);
            //     break;
            case 5:
                printtree(root);
                printf("\n");
                break;
            case 6:
                inordersuccesor(root, 10);
                printf("\n");
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice\n"); 
                break;
        }
    }
    return 0;
}