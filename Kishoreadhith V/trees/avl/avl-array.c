#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int index_check(int index, int num){
    if ((index >= pow(2, num) - 1) || (index < 0))
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

int parent(int index){
    return (index - 1) / 2;
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

int bst_insert(int *tree, int data){
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
    return index;
}

void avl_insert(int *tree, int val){
    int w = bst_insert(tree, val);
    
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



int main(){
    int num;
    printf("Enter number of elements: ");
    scanf("%d", &num);
    int *tree = bst_iter(num);
    display_tree(tree, 0, num, 0);
    printf("____________________________________\n\n");
    bst_insert(tree, 10);
    display_tree(tree, 0, num, 0);
}