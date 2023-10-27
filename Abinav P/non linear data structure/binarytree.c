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


#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left,*right;
}*root;

struct node *getnode(int data){
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

struct node *insert(struct node *root,int data){
    struct node *current = root;
    if(root==NULL){
        return getnode(data);
    }
    if(data<root->data){
        root->left=insert(root->left,data);
    }
    else if(data>root->data){
        root->right=insert(root->right,data);
    }
    // while(current==NULL){
    //     if(data<current->data){
    //         current=current->left;
    //     }
    //     else if(data>current->data){
    //         current=current->right;
    //     }
    // }
    return root;
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
    printf("Enter the elements: ");
    for(int i=0;i<n;i++){
        int temp;
        scanf("%d",&temp);
        root=insert(root,temp);
    }
    display(root);
}