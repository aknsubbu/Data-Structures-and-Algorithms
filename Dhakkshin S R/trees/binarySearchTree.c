#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// fix this mess, make it efficient
int* makeTree(int treeLen)
{
    int* tree = calloc(0, sizeof(int)), arrLen = 0;

    printf("Enter positive numbers only. enter 0 for no node\n\n");

    for (int n = 0; n < treeLen; n++)
    {
        int val;
        printf("Enter value: ");
        scanf("%d", &val);

        int i = 0;
        while (*(tree + i) != 0 && i < arrLen)
        {
            if (val < *(tree + i)) i = (i * 2) + 1;
            else i = (i * 2) + 2;
        }

        if (i >= arrLen)
        {
            arrLen = arrLen + i + 1;
            int* temp = realloc(tree, arrLen*sizeof(int));
            if (temp == NULL) exit(1);
            for (int j = arrLen-i-1; j < arrLen; j++) temp[j] = 0;
            tree = temp;
        }
        *(tree + i) = val;
    } 

    return tree;
}

// correct the print func
void print(int* tree, int treeLen)
{

    for (int i = 0; i < 20; i++ )
    {
        printf("%d ", tree[i]);
    }
    printf("\n");

    int m = 0, n = 0, i = 0, j = 0;
    // for (int i = 0; i < treeLen; i++)
    while (j < treeLen)
    {
        printf("%d ", *(tree + i));
        if (*(tree + i) != 0) j++;
        i++;
        m++;
        if (m == pow(2, n))
        {
            m = 0;
            n++;
            printf("\n");
        } 
    }
}

void printInorder(int* tree, int node, int treeLen)
{
    if (node >= treeLen) return;

    if (tree[2*node + 1] != 0) printInorder(tree, 2*node + 1, treeLen);
    printf("%d ",tree[node]);
    if (tree[2*node + 2] != 0) printInorder(tree, 2*node + 2, treeLen);
}

void printPreorder(int* tree, int node, int treeLen)
{
    if (node >= treeLen) return;

    printf("%d ",tree[node]);
    if (tree[2*node + 1] != 0) printInorder(tree, 2*node + 1, treeLen);
    if (tree[2*node + 2] != 0) printInorder(tree, 2*node + 2, treeLen);
}

void printPostorder(int* tree, int node, int treeLen)
{
    if (node >= treeLen) return;

    if (tree[2*node + 1] != 0) printInorder(tree, 2*node + 1, treeLen);
    if (tree[2*node + 2] != 0) printInorder(tree, 2*node + 2, treeLen);
    printf("%d ",tree[node]);
}

// void delete(int* tree, int treeLen, int delVal)
// {
//     int location = search(tree, treeLen, delVal);
//     if (location == -1) return;

//     if 
// }

int search(int* tree, int treeLen, int search)
{
    int i = 0;
    while(i < treeLen)
    {
        if (search < tree[i]) i = 2*i + 1;
        else if (search > tree[i]) i = 2*i + 2;
        else return i;
    }
    return -1;
}


int main(void)
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int treeLen = n;

    int* tree = makeTree(treeLen);
    // int tree[7] = {1,2,3,4,5,6,7}, treeLen = 7; 
    print(tree, treeLen);
    printf("\n\n");
    printf("%d\n", search(tree, treeLen, 5));

    // printf("Inorder: ");
    // printInorder(tree, 0, treeLen);
    // printf("\n\n");

    // printf("Preorder: ");
    // printPreorder(tree, 0, treeLen);
    // printf("\n\n");

    // printf("Preorder: ");
    // printPostorder(tree, 0, treeLen);
    // printf("\n\n");
    return 0;
}