// //binary tree using array
// #include<stdio.h>
// #include<stdlib.h>

// void main(){
//     int n;
//     printf("Enter the number of nodes: ");
//     scanf("%d",&n);
//     int *a=(int *)malloc(n*sizeof(int));

// }
//construct a binary tree ask the user for the input 

// //binary search tree
// #include<stdio.h>
// #include<stdlib.h>
// #include<math.h>
// int main(){
//     int n;
//     printf("Enter the number of nodes: ");
//     scanf("%d",&n);
//     int *array=(int *)calloc((pow(2,n)-1),sizeof(int));
//     printf("Enter the elements: ");
//     for(int i=0;i<n;i++){
//         int temp;
//         scanf("%d",&temp);
//         int i=0;
//         while(array[i]!=0){
//             if(temp>array[i]){
//                 i=2*i+2;
//             }
//             else{
//                 i=2*i+1;
//             }
//         }
//         array[i]=temp;
//     }
// }

// #include <stdio.h>
// #include <stdlib.h>

// struct node {
//     int data;
//     struct node* left;
//     struct node* right;
// };

// struct node* create_node(int data) {
//     struct node* new_node = (struct node*)malloc(sizeof(struct node));
//     new_node->data = data;
//     new_node->left = NULL;
//     new_node->right = NULL;
//     return new_node;
// }

// struct node* insert(struct node* root, int data) {
//     if (root == NULL) {
//         return create_node(data);
//     }
//     if (data < root->data) {
//         root->left = insert(root->left, data);
//     }
//     else if (data > root->data) {
//         root->right = insert(root->right, data);
//     }
//     return root;
// }

// void inorder_traversal(struct node* root) {
//     if (root != NULL) {
//         inorder_traversal(root->left);
//         printf("%d ", root->data);
//         inorder_traversal(root->right);
//     }
// }

// int main() {
//     int n;
//     printf("Enter the number of nodes: ");
//     scanf("%d", &n);
//     struct node* root = NULL;
//     printf("Enter the elements: ");
//     for (int i = 0; i < n; i++) {
//         int temp;
//         scanf("%d", &temp);
//         root = insert(root, temp);
//     }
//     printf("Inorder traversal of the binary search tree: ");
//     inorder_traversal(root);
//     return 0;
// }


// #include<stdio.h>
// #include<stdlib.h>

// struct node{
//     int data;
//     struct node *left,*right;
// }*root;

// struct node *getnode(int data){
//     struct node *temp=(struct node *)malloc(sizeof(struct node));
//     temp->data=data;
//     temp->left=NULL;
//     temp->right=NULL;
//     return temp;
// }

// struct node *insert(struct node *root,int data){
//     struct node *current = root;
//     if(root==NULL){
//         return getnode(data);
//     }
//     if(data<root->data){
//         root->left=insert(root->left,data);
//     }
//     else if(data>root->data){
//         root->right=insert(root->right,data);
//     }
//     // while(current==NULL){
//     //     if(data<current->data){
//     //         current=current->left;
//     //     }
//     //     else if(data>current->data){
//     //         current=current->right;
//     //     }
//     // }
//     return root;
// }

// void display(struct node *root){
//     if(root!=NULL){
//         display(root->left);
//         printf("%d ",root->data);
//         display(root->right);
//     }
// }

// void main(){
//     int n;
//     printf("Enter the number of nodes: ");
//     scanf("%d",&n);
//     printf("Enter the elements: ");
//     for(int i=0;i<n;i++){
//         int temp;
//         scanf("%d",&temp);
//         root=insert(root,temp);
//     }
//     display(root);
// }

//binary tree in array with insertion 


// #include <stdio.h>
// #include <stdlib.h>

// #define MAX_SIZE 100

// int tree[MAX_SIZE];
// int size = 0;

// void insert(int data) {
//     if (size == MAX_SIZE) {
//         printf("Error: Tree is full\n");
//         return;
//     }
//     tree[size++] = data;
// }

// void display() {
//     for (int i = 0; i < size; i++) {
//         printf("%d ", tree[i]);
//     }
// }

// int main() {
//     int n;
//     printf("Enter the number of nodes: ");
//     scanf("%d", &n);
//     printf("Enter the elements: ");
//     for (int i = 0; i < n; i++) {
//         int temp;
//         scanf("%d", &temp);
//         insert(temp);
//     }
//     printf("Elements in the binary tree: ");
//     display();
//     return 0;
// }

//traverse inorder the left subtree
//process root
//traverse inorder the right subtree


// #include <stdio.h>
// #include <stdlib.h>

// #define MAX_SIZE 100

// int *tree=(int *)calloc(MAX_SIZE,sizeof(int));
// int size = 0;

// void inorder_traversal(int i){
//     if(tree[2*i+1]!=0){
//         inorder_traversal(2*i+1);
//     }
//     printf("%d ",tree[i]);
//     if(tree[2*i+2]!=0){
//         inorder_traversal(2*i+2);
//     }
// }

// void preorder_traversal(int i){
//     printf("%d ",tree[i]);
//     if(tree[2*i+1]!=0){
//         preorder_traversal(2*i+1);
//     }
//     if(tree[2*i+2]!=0){
//         preorder_traversal(2*i+2);
//     }
// }

// void postorder_traversal(int i){
//     if(tree[2*i+1]!=0){
//         postorder_traversal(2*i+1);
//     }
//     if(tree[2*i+2]!=0){
//         postorder_traversal(2*i+2);
//     }
//     printf("%d ",tree[i]);
// }

// void insert(int data) {
//     if (size == MAX_SIZE) {
//         printf("Error: Tree is full\n");
//         return;
//     }
//     int i = size;
//     tree[i] = data;
//     size++;
//     while (i > 0 && tree[(i - 1) / 2] > data) {
//         tree[i] = tree[(i - 1) / 2];
//         i = (i - 1) / 2;
//     }
//     tree[i] = data;
// }

// void display(int i, int space) {
//     if (i >= size) {
//         return;
//     }
//     space += 5;
//     display(2 * i + 2, space);
//     printf("\n");
//     for (int j = 5; j < space; j++) {
//         printf(" ");
//     }
//     printf("%d\n", tree[i]);
//     display(2 * i + 1, space);
// }

// int main() {
//     int n;
//     printf("Enter the number of nodes: ");
//     scanf("%d", &n);
//     printf("Enter the elements: ");
//     for (int i = 0; i < n; i++) {
//         int temp;
//         scanf("%d", &temp);
//         insert(temp);
//     }
//     printf("Elements in the binary tree: \n");
//     display(0, 0);
//     inorder_traversal(n);
//     return 0;
// }



#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left,*right;
};

struct node *getnode(int data){
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

//insertion using loops
struct node *insert(struct node *root, int data) {
    if (root == NULL) {
        return getnode(data);
    }

    struct node *current = root;
    while (1) {
        if (data < current->data) {
            if (current->left == NULL) {
                current->left = getnode(data);
                break; // Inserted the node, so break out of the loop
            }
            current = current->left;
        } else if (data > current->data) {
            if (current->right == NULL) {
                current->right = getnode(data);
                break; // Inserted the node, so break out of the loop
            }
            current = current->right;
        } else {
            // You may choose to handle duplicate values differently if needed
            break;
        }
    }

    return root;
}

struct node *delete(struct node *head,int data){
    struct node *current=head;
    if(head==NULL){
        return NULL;
    }
    if(data<current->data){
        current->left=delete(current->left,data);
    }
    else if(data>current->data){
        current->right=delete(current->right,data);
    }
    else{
        if(current->left==NULL && current->right==NULL){
            free(current);
            return NULL;
        }
        else if(current->left==NULL){
            struct node *temp=current->right;
            free(current);
            return temp;
        }
        else if(current->right==NULL){
            struct node *temp=current->left;
            free(current);
            return temp;
        }
        else{
            struct node *temp=current->right;
            while(temp->left!=NULL){
                temp=temp->left;
            }
            current->data=temp->data;
            current->right=delete(current->right,temp->data);
        }
    }
}


struct node *search(int data,struct node *root){
    struct node *current=root;
    while(current!=NULL){
        if(data==current->data){
            return current;
        }
        else if(data<current->data){
            current=current->left;
        }
        else if(data>current->data){
            current=current->right;
        }
    }
    return NULL;
}



void display(struct node *root){
    if(root!=NULL){
        display(root->left);
        printf("%d ",root->data);
        display(root->right);
    }

}

void main(){
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    struct node *root=NULL;
    printf("Enter the elements: ");
    for(int i=0;i<n;i++){
        int temp;
        scanf("%d",&temp);
        root=insert(root,temp);
    }
    display(root);
    printf("Enter the element to be searched: ");
    int temp;
    scanf("%d",&temp);
    struct node *result=search(temp,root);
    if(result==NULL){
        printf("Element not found");
    }
    else{
        printf("Element found");
    }

}