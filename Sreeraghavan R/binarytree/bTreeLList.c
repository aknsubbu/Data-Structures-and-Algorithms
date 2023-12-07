#include <stdlib.h>
#include <stdio.h>

struct node{
    int data;
    struct node* lc;
    struct node* rc;
};

typedef struct node node;

node* createNode(int val){
    node* newNode = (node*)malloc(sizeof(node));
    newNode-> data = val;
    newNode-> lc = NULL;
    newNode->rc = NULL;
    return newNode;
}

node *insertNode(node *root,node *newNode)
{
    //printf("test");
    if (root == NULL)
        return newNode;
    if (newNode->data < root->data)
        root->lc = insertNode(root->lc, newNode);
    else
        root->rc = insertNode(root->rc, newNode);
    return root;
}

node *insertElement(node *root,int val){
    return insertNode(root,createNode(val));
}

node *insertElements(node* root,int* arr,int len){
    int i = 0;
    if(!root) root = createNode(arr[i++]);
    for(i;i<len;i++) root = insertElement(root,arr[i]); 
    return root;
}

node *searchNode(node* root,int val){
    if(root->data == val) return root;
    if(root->lc) if(val < root->data) return searchNode(root->lc,val);
    if(root->rc) if(val > root->data) return searchNode(root->rc,val);
    return createNode(-1);
}

node *searchParent(node* root,int val,node* parent){
    if(root->data == val) return parent;
    if(root->lc) if(val < root->data) return searchParent(root->lc,val,root);
    if(root->rc) if(val > root->data) return searchParent(root->rc,val,root);
    return createNode(-1);
}

void inorder(node* tree){
    if(tree->lc) inorder(tree->lc);
    printf("%d ",tree->data);
    if(tree->rc) inorder(tree->rc);
}

void deleteNode(node* root,int val){
    node* parent = searchParent(root,val,root);
    if(val > parent->data){
        node* cur = parent->rc;
        if(!cur->lc && !cur->rc){
            free(cur);
            parent->rc = NULL;
        }
    }
    if(val < parent->data){
        node* cur = parent->rc;
        if(!cur->lc && !cur->rc){
            free(cur);
            parent->lc = NULL;
        }
    }
}

int main(){
    node* root1 = createNode(5);
    // node* root2 = createNode(5);

    int arr1[5] = {0,1,2,4,5};
    int arr2[5] = {5,4,3,2,1};
    //node* root1 = insertElements(root1,arr1,5);
    node* root2 = insertElements(root2,arr2,5);
    insertElement(root1,4);
    insertElement(root1,3);
    insertElement(root1,7);
    insertElement(root1,8);
    // printf("%d\n",searchParent(root1,8,root1)->data);
    // printf("%d\n",searchNode(root1,7)->data);
    deleteNode(root1,8);
    inorder(root1);
    //displayTree(root2);
}