#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int index_check(int index, int num){
    if (index >= pow(2, num) - 1)
    {
        return 0;
    }
    return 1;
}

int left_child(int index){
    return (2 * index) + 1;
}
int right_child(int index){
    return (2 * index) + 2;
}

int* bst_iter(int num){
    int *tree = (int *)calloc((int)((pow(2, (double)(num))) - 1), sizeof(int));
    for(int i = 0; i < num; i++){
        int data;
        printf("Enter data: ");
        scanf("%d", &data);
        int index = 0;
        while(tree[index] != 0){
            if(data < tree[index]){
                index = 2 * index + 1;
            }
            else{
                index = 2 * index + 2;
            }
        }
        tree[index] = data;
    }
    return tree;
}

void display(int *tree, int index, int num){
    if(index >= pow(2, num) - 1){
        return;
    }
    display(tree, 2 * index + 1, num);
    printf("%d ", tree[index]);
    display(tree, 2 * index + 2, num);
}

void display_tree(int *tree, int index, int num, int level){
    if(index >= pow(2, num) - 1){
        return;
    }
    if(tree[index] == 0){
        return;
    }
    display_tree(tree, 2 * index + 2, num, level + 1);
    for(int i = 0; i < level; i++){
        printf("|\t");
    }
    printf("|------>%d\n", tree[index]);
    display_tree(tree, 2 * index + 1, num, level + 1);
}

void inorder(int *tree, int index, int num){
    if(index >= pow(2, num) - 1){
        return;
    }
    if (tree[index] == 0)
    {
        return;
    }    
    inorder(tree, 2 * index + 1, num);
    printf("%d ", tree[index]);
    inorder(tree, 2 * index + 2, num);
}

void preorder(int *tree, int index, int num){
    if(index >= pow(2, num) - 1){
        return;
    }
    if (tree[index] == 0)
    {
        return;
    }
    printf("%d ", tree[index]);
    preorder(tree, 2 * index + 1, num);
    preorder(tree, 2 * index + 2, num);
}

void postorder(int *tree, int index, int num){
    if(index >= pow(2, num) - 1){
        return;
    }
    if (tree[index] == 0)
    {
        return;
    }
    postorder(tree, 2 * index + 1, num);
    postorder(tree, 2 * index + 2, num);
    printf("%d ", tree[index]);
}

int search(int *tree, int value, int num){
    int index = 0;
    while (index_check(index, num))
    {
        if (value == tree[index])
        {
            return index;
        }        
        else if (value < tree[index])
        {
            index = left_child(index);
        }
        else {
            index = right_child(index);
        }        
    }
    return -1;
}

void delete(int *tree, int target, int num){
    int index = search(tree, target, num);
    if (index == -1)
    {
        printf("Target not found in tree\n");
        return;
    }
    if (index_check(right_child(index), num) && tree[left_child(index)] == 0 && tree[right_child(index)] == 0)
    {
        tree[index] = 0;
        return;
    } 
    else
    
}

int main(){
    int num;
    printf("Enter number of nodes: ");
    scanf("%d", &num);
    int *tree = bst_iter(num);
    display(tree, 0, num);
    printf("\n--------------------\n");
    display_tree(tree, 0, num, 0);
    // printf("\n--------------------\n");
    // printf("Inorder: ");
    // inorder(tree, 0, num);
    // printf("\n--------------------\n");
    // printf("Preorder: ");
    // preorder(tree, 0, num);
    // printf("\n--------------------\n");
    // printf("Postorder: ");
    // postorder(tree, 0, num);
    // printf("\n--------------------\n");
    printf("enter target value: ");
    int target;
    scanf("%d", &target);
    printf("%d", search(tree, target, num));
    return 0;
}