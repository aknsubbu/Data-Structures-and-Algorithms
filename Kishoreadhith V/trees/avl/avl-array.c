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

int bst_search(int *tree, int data){
    int index = 0;
    while(tree[index] != data){
        if(data < tree[index]){
            index = 2 * index + 1;
        }
        else{
            index = 2 * index + 2;
        }
    }
    return index;
}

int height(int *tree, int index, int num){
    if(index >= pow(2, num) - 1){
        return 0;
    }
    int left = height(tree, 2 * index + 1, num);
    int right = height(tree, 2 * index + 2, num);
    if(left > right){
        return left + 1;
    }
    else{
        return right + 1;
    }
}

int balance_factor(int *tree, int index, int num){
    if(index >= pow(2, num) - 1){
        return 0;
    }
    int left = height(tree, 2 * index + 1, num);
    int right = height(tree, 2 * index + 2, num);
    return left - right;
}

void rotate_right(int *tree, int index, int num){
    if(index >= pow(2, num) - 1){
        return;
    }
    int temp = tree[index];
    tree[index] = tree[2 * index + 1];
    tree[2 * index + 1] = temp;
    return;
}

void rotate_left(int *tree, int index, int num){
    if(index >= pow(2, num) - 1){
        return;
    }
    int temp = tree[index];
    tree[index] = tree[2 * index + 2];
    tree[2 * index + 2] = temp;
    return;
}

void rotate_left_right(int *tree, int index, int num){
    if(index >= pow(2, num) - 1){
        return;
    }
    rotate_left(tree, 2 * index + 1, num);
    rotate_right(tree, index, num);
    return;
}

void rotate_right_left(int *tree, int index, int num){
    if(index >= pow(2, num) - 1){
        return;
    }
    rotate_right(tree, 2 * index + 2, num);
    rotate_left(tree, index, num);
    return;
}

void balance(int *tree, int index, int num){
    if(index >= pow(2, num) - 1){
        return;
    }
    balance(tree, 2 * index + 1, num);
    balance(tree, 2 * index + 2, num);
    int bf = balance_factor(tree, index, num);
    if(bf > 1){
        if(balance_factor(tree, 2 * index + 1, num) > 0){
            rotate_right(tree, index, num);
        }
        else{
            rotate_left_right(tree, index, num);
        }
    }
    else if(bf < -1){
        if(balance_factor(tree, 2 * index + 2, num) < 0){
            rotate_left(tree, index, num);
        }
        else{
            rotate_right_left(tree, index, num);
        }
    }
    return;
}

void avl_insert(int *tree, int data, int num){
    int index = bst_insert(tree, data);
    balance(tree, index, num);
    return;
}

void avl_delete(int *tree, int data, int num){
    int index = bst_search(tree, data);
    if(index >= pow(2, num) - 1){
        return;
    }
    if(tree[left_child(index)] == 0 && tree[right_child(index)] == 0){
        tree[index] = 0;
    }
    else if(tree[left_child(index)] == 0){
        tree[index] = tree[right_child(index)];
        tree[right_child(index)] = 0;
    }
    else if(tree[right_child(index)] == 0){
        tree[index] = tree[left_child(index)];
        tree[left_child(index)] = 0;
    }
    else{
        int temp = tree[right_child(index)];
        while(tree[left_child(temp)] != 0){
            temp = tree[left_child(temp)];
        }
        tree[index] = tree[temp];
        tree[temp] = 0;
    }
    balance(tree, index, num);
    return;
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
    printf("Enter number of nodes: ");
    scanf("%d", &num);
    int *tree = bst_iter(num);
    display(tree, 0, num);
    printf("\n");
    display_tree(tree, 0, num, 0);
    printf("\n");
    int data;
    printf("Enter data to insert: ");
    scanf("%d", &data);
    avl_insert(tree, data, num);
    display(tree, 0, num);
    printf("\n");
    display_tree(tree, 0, num, 0);
    printf("\n");
    printf("Enter data to delete: ");
    scanf("%d", &data);
    avl_delete(tree, data, num);
    display(tree, 0, num);
    printf("\n");
    display_tree(tree, 0, num, 0);
    printf("\n");
    return 0;
}