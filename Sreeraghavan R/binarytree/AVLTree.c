#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


struct node{
    int data;
    struct node* lc;
    struct node* rc;
};

typedef struct node node;

enum nodeType{BOTH,LEFT,RIGHT,NONE};
enum childType{LC,RC,HEAD};

int typeNode(node* tree){
    if(tree->lc && tree->rc) return BOTH;
    if(tree->lc) return LEFT;
    if(tree->rc) return RIGHT;
    return NONE;
}


node* createNode(int val){
    node* newNode = (node*)malloc(sizeof(node));
    newNode-> data = val;
    newNode-> lc = NULL;
    newNode->rc = NULL;
    return newNode;
}

node* emptyNode(){
    return createNode(-1);
}

void printNode(node* cur){
    printf("%d\n",cur->data);
}

node *insertNodeBST(node *tree,node *newNode)
{
    //printf("test");
    if (tree == NULL)
        return newNode;
    if (newNode->data < tree->data)
        tree->lc = insertNodeBST(tree->lc, newNode);
    else
        tree->rc = insertNodeBST(tree->rc, newNode);
    return tree;
}

node *insertElement(node *tree,int val){
    return insertNodeBST(tree,createNode(val));
}

node *insertElements(node* tree,int* arr,int len){
    int i = 0;
    if(!tree) tree = createNode(arr[i++]);
    for(i;i<len;i++) tree = insertElement(tree,arr[i]); 
    return tree;
}

node *searchNode(node* tree,int val){
    if(tree->data == val) return tree;
    if(tree->lc) if(val < tree->data) return searchNode(tree->lc,val);
    if(tree->rc) if(val > tree->data) return searchNode(tree->rc,val);
    return emptyNode();
}

node *searchParent(node* tree,int val,node* parent){
    if(tree->data == val) return parent;
    if(tree->lc) if(val < tree->data) return searchParent(tree->lc,val,tree);
    if(tree->rc) if(val > tree->data) return searchParent(tree->rc,val,tree);
    return emptyNode();
}

int typeChild(node* tree,int val){
    node* parent = searchParent(tree,val,tree);
    if(parent->data == val) return HEAD;
    if(val > parent->data) return RC;
    if(val < parent->data) return LC;
}
void inorder(node* tree){
    if(tree->lc) inorder(tree->lc);
    printf("%d ",tree->data);
    if(tree->rc) inorder(tree->rc);
}

void inordernl(node* tree){
    inorder(tree);
    printf("\n");
}

int nodeExists(node* cur){
    return cur->data != -1;
}

node* inorderSuccessor(node* cur){
    node* succ = cur;
    if(cur->rc) succ = cur->rc; else return succ;
    while(succ->lc) succ = succ->lc;
    return succ;
}

void deleteNode(node* tree,int val){
    node* cur = searchNode(tree,val);
    node* parent = searchParent(tree,val,tree);
    node* temp;

    if(typeNode(cur) == NONE){
        if(typeChild(tree,val) == LC){
            parent->lc = NULL;            
            return;
        }
        parent->rc = NULL;
        
    }

    node* child;
    if(typeNode(cur) == LEFT){
        child = cur->lc;
        if(typeChild(tree,val) == LC){
            parent->lc = child;
            
            return;
        }
        parent->rc = child;
    }

    if(typeNode(cur) == RIGHT){
        child = cur->rc;
        if(typeChild(tree,val) == LC){
            parent->lc = child;

            return;
        }
        parent->rc = child;
    }

    if(typeNode(cur) == BOTH){
        int temp = inorderSuccessor(cur)->data;
        deleteNode(tree,temp);
        cur->data = temp;
    }
}

void rightRotate(node* tree,node* x){
    node* y = x->lc;
    node* T3;
    if(y->rc) T3 = y->rc;
    y->rc = x;
    x->lc = T3;

    node* parent = searchParent(tree,x->data,tree);
    if(typeChild(tree,x->data) == LC) parent->lc = y;
    if(typeChild(tree,x->data) == RC) parent->rc = y;
}

void LeftRotate(node* cur);


int main(){
    node* root1 = createNode(9);
    
    insertElement(root1,7);
    insertElement(root1,4);
    insertElement(root1,8);
    insertElement(root1,12);
    insertElement(root1,11);
    insertElement(root1,16);
    insertElement(root1,18);
    insertElement(root1,2);


    
    inordernl(root1);
    rightRotate(root1,searchNode(root1,9));
    inorder(root1);

}