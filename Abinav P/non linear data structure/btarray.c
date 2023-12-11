// #include<Stdio.h>
// #include<stdlib.h>
// #include<math.h>

// int *createtree(int size){
//     int *tree=calloc((int)(pow(2,size)-1),sizeof(int));
//     return tree;
// }

// void buildtree(int *tree,int index,int nodes){
//     if(tree[0]==0){
//         printf("enter the data:");
//         scanf("%d",&tree[index]);  
//     }
//     if(nodes == 0){
//         return;
//     }
//     int data,choice;
//     printf("do you want to enter the left child of %d:",tree[index]);
//     scanf("%d",&choice);
//     if(choice){
//         printf("enter the data:");
//         scanf("%d",&data);
//         tree[2*index+1]=data;
//         buildtree(tree,2*index+1,nodes-1);
//     }
//     printf("do you want to enter the right child of %d:",tree[index]);
//     scanf("%d",&choice);
//     if(choice){
//         printf("enter the data:");
//         scanf("%d",&data);
//         tree[2*index+2]=data;
//         buildtree(tree,2*index+2,nodes-1);
//     }
// }

// void display(int *tree,int index,int nodes){
//     if(nodes == 0){
//         return;
//     }
//     printf("the left child of %d is %d\n",tree[index],tree[2*index+1]);
//     printf("the right child of %d is %d\n",tree[index],tree[2*index+2]);
//     display(tree,2*index+1,nodes-1);
//     display(tree,2*index+2,nodes-1);
// }

// void inorder_traversal(int *tree, int index, int nodes) {
//     if (index < nodes) {
//         inorder_traversal(tree, 2 * index + 1, nodes);  // Visit left subtree
//         printf("%d ", tree[index]);                     // Visit current node
//         inorder_traversal(tree, 2 * index + 2, nodes);  // Visit right subtree
//     }
// }
// void preorder_traversal(int *tree, int index, int nodes) {
//     if (index < nodes) {
//         printf("%d ", tree[index]);               // Visit current node
//         preorder_traversal(tree, 2 * index + 1, nodes);  // Visit left subtree
//         preorder_traversal(tree, 2 * index + 2, nodes);  // Visit right subtree
//     }
// }

// // Post-order traversal
// void postorder_traversal(int *tree, int index, int nodes) {
//     if (index < nodes) {
//         postorder_traversal(tree, 2 * index + 1, nodes);  // Visit left subtree
//         postorder_traversal(tree, 2 * index + 2, nodes);  // Visit right subtree
//         printf("%d ", tree[index]);               // Visit current node
//     }
// }

// int main(){
//     int n;
//     printf("enter the number of levels:");
//     scanf("%d",&n);
//     int *tree=createtree(n);
//     buildtree(tree,0,n-1);
//     display(tree,0,n-1);
//     int choice;
//     int size=(pow(2,n)-1);
//     while(1){
//         printf("enter your choice :\n1. inorder traversal\n2. preorder traversal\n3. postorder traversal\n4. exit\n");
//         scanf("%d",&choice);
//         switch(choice){
//             case 1:
//             inorder_traversal(tree,0,size);
//                 break;
//             case 2:
//             preorder_traversal(tree,0,size);
//                 break;
//             case 3:
//             postorder_traversal(tree,0,size);
//                 break;
//             default:
//                 exit(0);
//         }
//     }
// }