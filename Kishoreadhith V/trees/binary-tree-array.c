#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int * createTree(int num){
    int *tree = (int *)calloc((int)((pow(2, (double)(num))) - 1), sizeof(int));
    return tree;
}

void buildTree(int *tree, int index, int num){
    if (tree[0] == 0)
    {
        printf("Enter data: ");
        scanf("%d", &tree[0]);
    }
    if (num == 0)
    {
        return;
    }
    int data, choice;
    printf("Do you want to enter left child of %d? (1/0): ", tree[index]);
    scanf("%d", &choice);
    if (choice == 1)
    {
        printf("Enter data: ");
        scanf("%d", &data);
        tree[2 * index + 1] = data;
        buildTree(tree, 2 * index + 1, num - 1);
    }
    printf("Do you want to enter right child of %d? (1/0): ", tree[index]);
    scanf("%d", &choice);
    if (choice == 1)
    {
        printf("Enter data: ");
        scanf("%d", &data);
        tree[2 * index + 2] = data;
        buildTree(tree, 2 * index + 2, num - 1);
    }
}

void display(int *tree, int index, int num){
    if (index >= pow(2, num) - 1)
    {
        return;
    }
    display(tree, 2 * index + 1, num);
    printf("%d ", tree[index]);
    display(tree, 2 * index + 2, num);
}

void display_tree(int *tree, int index, int num, int level){
    if (index >= pow(2, num) - 1)
    {
        return;
    }
    if (tree[index] == 0)
    {
        return;
    }
    
    display_tree(tree, 2 * index + 2, num, level + 1);
    for (int i = 0; i < level; i++)
    {
        printf("|\t");
    }
    printf("|------>%d\n", tree[index]);
    display_tree(tree, 2 * index + 1, num, level + 1);
}


int main(){
    int num;
    printf("Enter number of nodes: ");
    scanf("%d", &num);
    int *tree = createTree(num);
    buildTree(tree, 0, num - 1);
    display_tree(tree, 0, num - 1, 0);
    return 0;
}