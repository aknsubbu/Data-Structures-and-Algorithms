#include<stdio.h> 
#include<stdlib.h> 
#define max(a,b) ((a>b)?a:b)

struct node{ 
	int data; 
	struct node *lc; 
	struct node *rc;
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



int height(node *n) { 
	if (!n) return 0; 
	return 1+max(height(n->lc),height(n->rc)); 
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

node *searchNode(node* tree,int val){
    if(tree->data == val) return tree;
    if(tree->lc) if(val < tree->data) return searchNode(tree->lc,val);
    if(tree->rc) if(val > tree->data) return searchNode(tree->rc,val);
    return emptyNode();
}


node* inorderSuccessor(node* cur){
    node* succ = cur;
    if(cur->rc) succ = cur->rc; else return succ;
    while(succ->lc) succ = succ->lc;
    return succ;
}


node* newNode(int data){ 
	node* new = (node*)malloc(sizeof(node));
	new->data = data; 
	new->lc = NULL; 
	new->rc = NULL; 
	return(new); 
} 


node *rightRotate(node* y) { 
	node* x = y->lc;
	node* T2 = x->rc;

	x->rc = y;
	y->lc = T2;

	return x;
} 

node *leftRotate(node *x) { 
	node *y = x->rc; 
	node *T2 = y->lc; 

	y->lc = x; 
	x->rc = T2; 

	return y; 
} 

int getBalance(node *N){ 
	if (N == NULL) 
		return 0; 
	return height(N->lc) - height(N->rc); 
} 

node* reBalance(node* tree,int val){
	int balance = getBalance(tree);

	if(balance > 1 && val < tree->lc->data) return rightRotate(tree); //LL
	if(balance < -1 && val > tree->rc->data) return leftRotate(tree); //RR

	//LR
	if(balance > 1 && val > tree->lc->data){
		tree->lc = leftRotate(tree->lc);
		return rightRotate(tree);
	}

	//RL
	if(balance < -1 && val < tree->rc->data){
		tree->rc = rightRotate(tree->rc);
		return leftRotate(tree);
	}

	return tree;
}

node* insert(node* tree,int val){
	if(!tree) return createNode(val);
	if(val > tree->data) tree-> rc = insert(tree->rc,val);
	else if(val < tree->data) tree->rc = insert(tree->lc,val);

	tree = reBalance(tree,val);

	return tree;
}

node* deleteNode(node* tree,node* cur){
    //node* cur = searchNode(tree,val);
    int val = cur->data;
    node* parent = searchParent(tree,val,tree);
    node* temp;

    if(typeNode(cur) == NONE){
        if(typeChild(tree,val) == LC){
            parent->lc = NULL;            
        }
        parent->rc = NULL;
    }

    node* child;
    if(typeNode(cur) == LEFT){
        child = cur->lc;
        if(typeChild(tree,val) == LC){
            parent->lc = child;     
        }
        parent->rc = child;

    }

    if(typeNode(cur) == RIGHT){
        child = cur->rc;
        if(typeChild(tree,val) == LC){
            parent->lc = child;
        }
        parent->rc = child;
    }

    if(typeNode(cur) == BOTH){
        int temp = inorderSuccessor(cur)->data;
        deleteNode(tree,temp);
        cur->data = temp;
    }


}

node deleteNodeAVL(node* tree,int val){
    
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

void printTree(node* tree, int level) {
	if (tree == NULL)
		return;

	printTree(tree->rc, level + 1);

	for (int i = 0; i < level; i++)
		printf("    ");

	printf("%d\n", tree->data);

	printTree(tree->lc, level + 1);
}

int main(){
	node *root = NULL;

	root = insert(root, 1);
	root = insert(root, 2);
	root = insert(root, 3);
	root = insert(root, 4);
	root = insert(root, 5);
	root = insert(root, 6);
    deleteNode(root,4);
	printTree(root, 0);

	return 0;
}



// /* Driver program to test above function*/
// int main() { 
// 	node *root = NULL; 

// 	root = insert(root, 1); 
// 	root = insert(root, 2); 
// 	root = insert(root, 3); 
// 	root = insert(root, 4); 
// 	root = insert(root, 5); 
// 	root = insert(root, 6); 

// 	inordernl(root); 

// 	return 0; 
// } 
