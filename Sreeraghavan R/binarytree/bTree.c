#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void swap(int*l, int i, int j){
    int temp = l[i];
    l[i] = l[j];
    l[j] = temp;
}


int power2(int a){
    int i = 1;
    int j = 1;
    for(i;i<=a;i++){
        j *= 2;
    }
    return j;
}

int greater(int a,int b){
    if(a>=b){
        return 1;
    }
    return 0;
}

void insertElement(int* tree,int x){
    int i = 0;
    while(tree[i] != 0){
        if(greater(x,tree[i])) i = 2*i + 2;
        else i = 2*i + 1;
    }
    tree[i] = x;
}

void insertElements(int* tree,int* arr,int size){
    for(int i = 0;i<size;i++){
        insertElement(tree,arr[i]);
    }
}

int* createBinaryTree(int size){
    int max = power2(size);
    int* tree = (int*)calloc(max,sizeof(int));
    return tree;
}


int numLevels(int size){
    int i = 0;
    while(size != 0){
        size /= 2;
        i++;
    }
    return i;
}

//traverse indorder the left subtree
//process root
//traverse indored the right subtree
void inorder(int* tree,int i){
    if(tree[2*i+1] != 0) inorder(tree,2*i+1);
    printf("%d ",tree[i]);
    if(tree[2*i+2] != 0) inorder(tree,2*i+2); 
}

//traverse postdorder the left subtree+
//traverse postorder the right subtree
//process root
void postorder(int* tree,int i){
    if(tree[2*i+1]) postorder(tree,2*i+1);
    if(tree[2*i+2]) postorder(tree,2*i+2); 
    printf("%d ",tree[i]);
}

//process root
//traverse predorder the left subtree
//traverse preorder the right subtree
void preorder(int* tree,int i){
    printf("%d ",tree[i]);
    if(tree[2*i+1]) preorder(tree,2*i+1);
    if(tree[2*i+2]) preorder(tree,2*i+2); 
}

int searchNode(int* tree,int val){
    int i = 0;
    while(tree[i] != 0 && tree[i] != val){
        if(greater(val,tree[i])) i = 2*i + 2;
        else i = 2*i + 1;
    }
    if(tree[i] == val) return i;
    return -1;
}


int main(){
    int size = 15;
    int arr[size];
    
    int* tree = createBinaryTree(5);
    int array[5] = {1,2,3,4,5};
    insertElements(tree,array,5);
    

    //for(int i = 0;i<32;i++) printf("%d ",tree[i]);
    printf("\n");
    inorder(tree,0);
    printf("\n");
    percolateDown(tree,0);
    printf("\n");
    inorder(tree,0);
    printf("\n");
    //for(int i = 0;i<32;i++) printf("%d ",tree[i]);

    //printf("\n%d\n",searchNode(tree,5));
}


//Steps for inorder traversal
