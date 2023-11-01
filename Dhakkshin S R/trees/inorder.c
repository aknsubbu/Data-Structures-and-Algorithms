#include <stdio.h>

int main(void)
{

}

void printInorder(int* tree, int node, int treeLen)
{
    if (node >= treeLen) return;

    if (tree[2*node + 1] != 0) printInorder(tree, 2*node + 1, treeLen);
    printf("%d ",tree[node]);
    if (tree[2*node + 2] != 0) printInorder(tree, 2*node + 2, treeLen);
}


// traverse in order the left subtree, process root, traverse inorder the right subtree.