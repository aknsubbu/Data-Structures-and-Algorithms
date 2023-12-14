#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct Node{
    int key;
    struct Node* left;
    struct Node* right;
};

struct Node *createNode(int x){
    struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
    temp->key=x;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

struct Node *insert(struct Node *root,int x){
    if(root==NULL){
        root=createNode(x);
        return root;
    }
    else if(x<=root->key){
        root->left=insert(root->left,x);
    }
    else{
        root->right=insert(root->right,x);
    }
    return root;
}

int greater(int a , int b){
    return (a>b)?a:b;
}

int maxPathSum(struct Node *root,int *res){
    if(root==NULL){
        return 0;
    }
    //the sum of the elements in the left subtree
    int l=maxPathSum(root->left,res);
    //the sum of the elements in the right subtree
    int r=maxPathSum(root->right,res);
    //max path for parent call of root. This path must include at most one child of root
    int max_single=greater(greater(l,r)+root->key,root->key);
    //max top represents the sum when the node under consideration is the root of the maxSum path and no ancestor of root are there in max sum path
    int max_top=greater(max_single,l+r+root->key);
    *res=greater(*res,max_top);
    return max_single;
}

int main() {
    struct Node* root = NULL;
    int n;
    printf("Enter the number of elements in the tree: ");
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) {
        printf("Enter the element: ");
        scanf("%d", &a[i]);
        root = insert(root, a[i]);
    }
    int res = 0;
    maxPathSum(root, &res);
    printf("Maximum Path Sum: %d\n", res);
    return 0;
}
