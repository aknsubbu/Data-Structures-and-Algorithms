#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


struct node{
    int data;
    struct node* lc;
    struct node* rc;
};

typedef struct node node;

enum type{BOTH,LEFT,RIGHT,NONE};

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
    if(typeNode(cur) == RIGHT){
        succ = cur->rc;
        while(succ->lc) succ = succ->lc;
        return succ;
    }
    return searchParent(cur,cur->data,cur);
}

void deleteNode(node* tree,int val){
    node* parent = searchParent(tree,val,tree);
    if(val > parent->data){
        node* cur = parent->rc;
        if(!cur->lc && !cur->rc){
            free(cur);
            parent->rc = NULL;
            return;
        }
        if(cur->lc && cur->rc){
            node* tempNode = inorderSuccessor(cur);
            int tempVal = tempNode->data;
            deleteNode(tree,tempNode->data);
            cur->data = tempNode->data;
        }
        if(cur->lc){
            parent->rc = cur->lc;
            free(cur);
        }
        if(cur->rc){
            parent->rc = cur->rc;
            free(cur);
        }
    }
    if(val < parent->data){
        node* cur = parent->lc;
        if(!cur->lc && !cur->rc){
            free(cur);
            parent->lc = NULL;
            return;
        }
        if(cur->lc && cur->rc){
            node* tempNode = inorderSuccessor(cur);
            int tempVal = tempNode->data;
            deleteNode(tree,tempNode->data);
            cur->data = tempNode->data;
        }
        if(cur->lc){
            parent->lc = cur->lc;
            free(cur);
        }
        if(cur->rc){
            parent->lc = cur->rc;
            free(cur);
        }
    }
}


bool isUnival(node* tree){
    switch(typeNode(tree)){
        case BOTH:
            if((tree->data == tree->lc->data)&&(tree->data == tree->rc->data)){
                return isUnival(tree->lc) && isUnival(tree->rc);
            }
            else{
                return false;
            }
            break;
        case LEFT:
            if(tree->data == tree->lc->data){
                return isUnival(tree->lc);
            }            
            else{
                return false;
            }
            break;
        case RIGHT:
            if(tree->data == tree->rc->data){
                return isUnival(tree->rc);
            }            
            else{
                return false;
            }
            break;
        case NONE:
            return true;
        default:
            printf("type failed");
    }
}

void countUnival(node* tree,int* count){
    if(tree->lc) countUnival(tree->lc,count);
    if(isUnival(tree)) ++(*count);
    if(tree->rc) countUnival(tree->rc,count);
}

char* serializeBT(node* tree){

}

node* deserializeBT(char* exp){

}

node* findMin(node* tree){
    if(tree->lc) return findMin(tree->lc);
    return tree;
}

node *kthSmallest(node* tree,int k){
    node* smallest = findMin(tree);
    node* kthSmallestNode = emptyNode(); 
    for(int i = 0;i < k;i++){
        kthSmallestNode = inorderSuccessor(smallest);
    }
    return kthSmallestNode;
}

node* lowestAncestor(node* root,node* n1,node* n2){
    
    // if any node is equal to the current value, that must be the LCA
    if(root->data == n1->data || root->data == n2->data) return root;
    
    // if any node is greater/lesser than both nodes, that must be the direction of the LCA
    if(root->data > n1->data && root->data > n2->data) if(root->lc) return lowestAncestor(root->lc,n1,n2); else return emptyNode();
    if(root->data < n1->data && root->data < n2->data) if(root->rc) return lowestAncestor(root->rc,n1,n2); else return emptyNode();
    
    // the only other case is if the two nodes are in different directions from the current node ie this is the LCA

    return root;
}

int main(){
    int arr[5] = {1,1,1,1,1};
    int arr1[10] = {7,10,9,11,4,5,6,2,1,3};
    int arr2[1] = {1};

    node* tree = insertElements(NULL,arr,5);
    node* tree1 = insertElements(NULL,arr1,10);
    node* tree2 = insertElements(NULL,arr2,1);

    inordernl(tree1);

    printNode(inorderSuccessor(searchNode(tree1,4)));
    printNode(kthSmallest(tree1,1));

}