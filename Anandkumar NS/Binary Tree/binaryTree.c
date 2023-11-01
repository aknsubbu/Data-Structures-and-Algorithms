#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

int binaryTree[MAX_NODES];
int root = -1; // Index of the root node

// Initialize all pos in tree
void initialize() {
    for (int i = 0; i < MAX_NODES; i++) {
        binaryTree[i] = -1; //giving empty value as -1 
    }
}

void insert(int data) {
    if (root == -1) {
        root = 0;
        binaryTree[root] = data;
    } else {
        int current = root;
        while (1) {
            if (data < binaryTree[current]) {
                if (binaryTree[2 * current + 1] == -1) {
                    binaryTree[2 * current + 1] = data;
                    break;
                } else {
                    current = 2 * current + 1;
                }
            } else {
                if (binaryTree[2 * current + 2] == -1) {
                    binaryTree[2 * current + 2] = data;
                    break;
                } else {
                    current = 2 * current + 2;
                }
            }
        }
    }
}
//inorder print
void printInOrder(int current) {
    if (binaryTree[current] != -1) {
        printInOrder(2 * current + 1);
        printf("%d ", binaryTree[current]);
        printInOrder(2 * current + 2);
    }
}

//preorder print
void printPreOrder(int current) {
    if (binaryTree[current] != -1) {
        printf("%d ", binaryTree[current]);
        printPreOrder(2 * current + 1);
        printPreOrder(2 * current + 2);
    }
}

//postorder print
void printPostOrder(int current) {
    if (binaryTree[current] != -1) {
        printPostOrder(2 * current + 1);
        printPostOrder(2 * current + 2);
        printf("%d ", binaryTree[current]);
    }
}


int searchTree(int *arr,int data){
    int i=0;
    while(arr[i]!=-1){
        if(arr[i]==data){
        printf("Found\n");
        return i;
        }
        else if(arr[i]>data){
        i=2*i+1;
        }
        else{
        i=2*i+2;
        }
    }
    printf("Not Found\n");
    return -1;
}

//delete the node using the search function
void deleteNode(int *arr,int data){
    int i=searchTree(arr,data);
    if(i==-1){
    printf("Not Found");
    }
    else{

        //if there is not chlid 
        if(arr[2*i+1]==-1 && arr[2*i+2]==-1){
            arr[i]=-1;
        }

        // right child alone 
        else if(arr[2*i+1]==-1 && arr[2*i+2]!=-1){
            arr[i]=arr[2*i+2];
            arr[2*i+2]=-1;
        }

        //left child alone
        else if(arr[2*i+2]==-1 && arr[2*i+1]!=-1){
            arr[i]=arr[2*i+1];
            arr[2*i+1]=-1;
        }

        //both child
        else{
            int j=2*i+2;
            while(arr[2*j+1]!=-1){
                j=2*j+1;
            }
            arr[i]=arr[j];
            arr[j]=-1;
        }
    }

}

int main() {
    initialize();

    // Insert nodes into the binary tree
    insert(50);
    insert(30);
    insert(70);
    insert(20);
    insert(40);
    insert(60);
    insert(80);

    // Print the binary tree in in-order
    printf("In-order traversal: ");
    printInOrder(root);
    printf("\n");

    return 0;
}


//traverse in order the left subtree
//crosses root
//traverse in order the right subtree