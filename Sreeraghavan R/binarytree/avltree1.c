#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#define max(a,b) ((a>b)?a:b)
struct node {
    int key;
    int height;
    struct node *left;
    struct node *right;
};
struct node* root = NULL;

struct node *newNode(int key) {
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;  
    return (node);
}

int getheight(struct node *node) {
    if (node == NULL)
        return 0;
    return node->height;
}

int getbalancefactor(struct node *node) {
    if (node == NULL)
        return 0;
    return getheight(node->left) - getheight(node->right);
}


struct node* rotateright(struct node *y){
    struct node* x=y->left;
    struct node* t2=x->right;
    x->right=y;
    y->left=t2;
    y->height=1+max(getheight(y->left),getheight(y->right));
    x->height=1+max(getheight(x->left),getheight(x->right));
    return x;

}

struct node* rotateleft(struct node *y){
    struct node*x=y->right;
    struct node *t2=x->left;
    x->left=y;
    y->right=t2;
    y->height=1+max(getheight(y->left),getheight(y->right));
    x->height=1+max(getheight(x->left),getheight(x->right));
    return x;
}

struct node *search(struct node *root, int key) {
    if (root == NULL || root->key == key)
        return root;
    if (root->key < key)
        return search(root->right, key);
    return search(root->left, key);
}

struct node* insert(struct node * node, int key){
    if(node==NULL)
        return newNode(key);
    if(key<node->key)
        node->left=insert(node->left,key);
    else if(key>node->key)
        node->right=insert(node->right,key);
    else
        return node;
    node->height=1+max(getheight(node->left),getheight(node->right));
    int balance=getbalancefactor(node);
    if (balance > 1 && key < node->left->key)
        return rotateright(node);
    if (balance < -1 && key > node->right->key)
        return rotateleft(node);
    if (balance > 1 && key > node->left->key) {
        node->left = rotateleft(node->left);
        return rotateright(node);
    }
    if (balance < -1 && key < node->right->key) {
        node->right = rotateright(node->right);
        return rotateleft(node);
    }
    return node;

}

int inordersuccessor(struct node *node){
    struct node *current=node;
    while(current->left!=NULL)
        current=current->left;
    return current->key;
}

struct node* delete(struct node *root,int key){
    if(root==NULL)
        return root;
    if(key<root->key)
        root->left=delete(root->left,key);
    else if(key>root->key)
        root->right=delete(root->right,key);
    else{
        if(root->left==NULL){
            struct node *temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL){
            struct node *temp=root->left;
            free(root);
            return temp;
        }
        else{
            int temp=inordersuccessor(root->right);
            root->key=temp;
            root->right=delete(root->right,temp);
        }
    }
    if(root==NULL)
        return root;
    root->height=1+max(getheight(root->left),getheight(root->right));
    int balance=getbalancefactor(root);
    if (balance > 1 && getbalancefactor(root->left) >= 0)
        return rotateright(root);
    if (balance > 1 && getbalancefactor(root->left) < 0) {
        root->left = rotateleft(root->left);
        return rotateright(root);
    }
    if (balance < -1 && getbalancefactor(root->right) <= 0)
        return rotateleft(root);
    if (balance < -1 && getbalancefactor(root->right) > 0) {
        root->right = rotateright(root->right);
        return rotateleft(root);
    }
    return root;
}

void inorder(struct node *root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->key);
        inorder(root->right);
    }
}

void display(){
    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");
}

int main(){
    int choice, key;
    while(1){
        printf("1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter the key to be inserted: ");
                scanf("%d", &key);
                root = insert(root, key);
                break;
            case 2:
                printf("Enter the key to be deleted: ");
                scanf("%d", &key);
                root = delete(root, key);
                break;
            case 3:
                printf("Enter the key to be searched: ");
                scanf("%d", &key);
                if(search(root, key) == NULL)
                    printf("Key not found\n");
                else
                    printf("Key found\n");
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
       

