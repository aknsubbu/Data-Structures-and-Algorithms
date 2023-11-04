//step 1 : find the inorder successor of the node to be deleted
//step 2: replace the value of the node to be deleted with the value in the order succesor
//step 3: delete the inorder successor


//binary search tree in array
#include<stdio.h>
#include<stdlib.h>

int *createTree(int n){
    int *tree = (int *)calloc(n,sizeof(int));
    return tree;
}

void buildTree(int *tree,int index,int n){
    if(tree[0]==0){
        printf("enter the data:");
        scanf("%d",&tree[0]);
    }
    if(n==0){
        return;
    }
    int data,choice;
    printf("do you want to enter left child of %d? (1/0):",tree[index]);
    scanf("%d",&choice);
    if(choice==1){
        printf("enter the data:");
        scanf("%d",&data);
        tree[2*index+1]=data;
        buildTree(tree,2*index+1,n-1);
    }
    printf("do you want to enter right child of %d? (1/0):",tree[index]);
    scanf("%d",&choice);
    if(choice==1){
        printf("enter the data:");
        scanf("%d",&data);
        tree[2*index+2]=data;
        buildTree(tree,2*index+2,n-1);
    }
}

void display(int *tree,int index,int n){
    if(index>=n){
        return;
    }
    display(tree,2*index+1,n);
    printf("%d ",tree[index]);
    display(tree,2*index+2,n);
}


void main(){
    int n;
    printf("enter the number of nodes:");
    scanf("%d",&n);
    int *tree = createTree(n);
    buildTree(tree,0,n-1);
    display(tree,0,n-1);
    
}