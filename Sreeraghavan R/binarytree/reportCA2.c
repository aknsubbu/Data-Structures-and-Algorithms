#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#define max(a,b) ((a>b)?a:b)


struct node{
    int data;
    struct node* lc;
    struct node* rc;
};

typedef struct node node;

enum type{BOTH,LEFT,RIGHT,NONE};
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

node* inorderSuccessor(node* tree,node* cur){
    node* succ = cur;
    if(cur->rc){
        succ = cur->rc;
        while(succ->lc) succ = succ->lc;
        return succ;
    }
    int temp = succ->data;
    while(typeChild(tree,succ->data) != HEAD){
        succ = searchParent(tree,succ->data,tree);
        if(succ->data > temp) return succ;
    }
    return searchNode(tree,temp);
}

// void deleteNode(node* tree,int val){
//     node* parent = searchParent(tree,val,tree);
//     if(val > parent->data){
//         node* cur = parent->rc;
//         if(!cur->lc && !cur->rc){
//             free(cur);
//             parent->rc = NULL;
//             return;
//         }
//         if(cur->lc && cur->rc){
//             node* tempNode = inorderSuccessor(cur);
//             int tempVal = tempNode->data;
//             deleteNode(tree,tempNode->data);
//             cur->data = tempNode->data;
//         }
//         if(cur->lc){
//             parent->rc = cur->lc;
//             free(cur);
//         }
//         if(cur->rc){
//             parent->rc = cur->rc;
//             free(cur);
//         }
//     }
//     if(val < parent->data){
//         node* cur = parent->lc;
//         if(!cur->lc && !cur->rc){
//             free(cur);
//             parent->lc = NULL;
//             return;
//         }
//         if(cur->lc && cur->rc){
//             node* tempNode = inorderSuccessor(cur);
//             int tempVal = tempNode->data;
//             deleteNode(tree,tempNode->data);
//             cur->data = tempNode->data;
//         }
//         if(cur->lc){
//             parent->lc = cur->lc;
//             free(cur);
//         }
//         if(cur->rc){
//             parent->lc = cur->rc;
//             free(cur);
//         }
//     }
// }

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

int power2(int a){
    int i = 1;
    int j = 1;
    for(i;i<=a;i++){
        j *= 2;
    }
    return j;
}

int heightTree(node* tree){
    if (tree == NULL) {
        return 0;
    }
    
    int leftHeight = heightTree(tree->lc);
    int rightHeight = heightTree(tree->rc);
    
    return 1 + max(leftHeight, rightHeight);
}

void addtoArray(node* tree,int* arr,int i){
    arr[i] = tree->data;
    if(tree->lc) addtoArray(tree->lc,arr,2*i+1);
    if(tree->rc) addtoArray(tree->rc,arr,2*i+2);
}

void serializeBST(node* tree,char* s){
    int size = power2(heightTree(tree));
    int* array = (int*)calloc(size,sizeof(int));
    int i = 0;
    addtoArray(tree,array,i);

    int offset = 0;
    for (i = 0; i < size; i++) {
        offset += sprintf(s + offset, "%d,", array[i]); // Convert integer to string and append
    }
}

node* deserializeBST(char* exp){
    int i = 0;
    node* tree;
    if(exp[i] > 47 && exp[i] < 58){
        int num = 0;
        while(exp[i] != ','){
            num *= 10;
            num += exp[i]-48;
            i++;
        }
        tree = createNode(num);  
    }

    while(exp[i] != '\0'){
        if(exp[i] > 47 && exp[i] < 58){
            int num = 0;
            while(exp[i] != ','){
                num *= 10;
                num += exp[i]-48;
                i++;
            }
            if(num) insertElement(tree,num);
        }
        else i++;
    }

    return tree;
}

node* findMin(node* tree){
    if(tree->lc) return findMin(tree->lc);
    return tree;
}

node *kthSmallest(node* tree,int k){
    node* smallest = findMin(tree);
    node* kthSmallestNode = smallest; 
    for(int i = 0;i < k-1;i++){
        kthSmallestNode = inorderSuccessor(tree,kthSmallestNode);
    }
    return kthSmallestNode;
}

node* lowestAncestor(node* tree,node* n1,node* n2){
    
    // if any node is equal to the current value, that must be the LCA
    if(tree->data == n1->data || tree->data == n2->data) return tree;
    
    // if any node is greater/lesser than both nodes, that must be the direction of the LCA
    if(tree->data > n1->data && tree->data > n2->data) if(tree->lc) return lowestAncestor(tree->lc,n1,n2); else return emptyNode();
    if(tree->data < n1->data && tree->data < n2->data) if(tree->rc) return lowestAncestor(tree->rc,n1,n2); else return emptyNode();
    
    // the only other case is if the two nodes are in different directions from the current node ie this is the LCA

    return tree;
}



int main(){
    int arr[5] = {1,1,1,1,1};
    int arr1[10] = {7,10,9,11,4,5,6,2,1,3};
    int arr2[1] = {1};

    node* tree = insertElements(NULL,arr,5);
    node* tree1 = insertElements(NULL,arr1,10);
    node* tree2 = insertElements(NULL,arr2,1);

    printf("Original Tree\n");
    inordernl(tree1);

    printf("Inorder Successor of 2 (works for all nodes): ");
    printNode(inorderSuccessor(tree1,searchNode(tree1,2)));

    printf("Kth(4th) Smallest Node: ");
    printNode(kthSmallest(tree1,4));

    printf("Tree (has not been modified):\n");
    inordernl(tree1);
    
    
    char s[1000];
    serializeBST(tree1,s);
    printf("Serialized BST:\n%s\n",s);
    node* tree3 = deserializeBST(s);
    printf("Tree after being Deserialized:\n");
    inordernl(tree3);

    
    printf("Unival Tree:\n");
    inordernl(tree);
    int c = 0;
    countUnival(tree,&c);
    printf("Number of unival subtree = %d\n",c);

    
}