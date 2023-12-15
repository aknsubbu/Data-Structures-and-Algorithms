#include <stdio.h>
#include <stdlib.h>

struct Node{
    int key;
    struct Node* left;
    struct Node* right;
};

struct Node *createNode(int x){
    struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
    temp->key=x;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

//construct tree from pre order and in order
int search(int arr[],int start,int end,int key){
    int i;
    for(i=start;i<=end;i++){
        if(arr[i]==key){
            return i;
        }
    }
    return -1;
}

struct Node* constructTree(int pre[], int in[], int start, int end, int* preIndex) {
    if (start > end) {
        return NULL;
    }
    struct Node* temp = createNode(pre[(*preIndex)++]);
    if (start == end) {
        return temp;
    }
    int inIndex = search(in, start, end, temp->key);
    temp->left = constructTree(pre, in, start, inIndex - 1, preIndex);
    temp->right = constructTree(pre, in, inIndex + 1, end, preIndex);
    return temp;
}



void printInorder(struct Node* node) 
{ 
    if (node == NULL) 
        return; 
    printInorder(node->left); 
    printf("%d ", node->key); 
    printInorder(node->right); 
}

int main() {
    struct Node* root = NULL;
    int n;
    printf("Enter the number of elements in the tree: ");
    scanf("%d", &n);
    int pre[n], in[n];
    printf("Enter the preorder traversal of the tree: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &pre[i]);
    }
    printf("Enter the inorder traversal of the tree: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &in[i]);
    }
    int preIndex = 0;  // Initialize preIndex
    root = constructTree(pre, in, 0, n - 1, &preIndex);
    printf("Inorder traversal of the constructed tree is: ");
    printInorder(root);
    return 0;
}
