// traverse inorder the left sub tree
// process root
// traverse inorder the right sub tree

#include<stdio.h>
#include<stdlib.h>

void inorder(int *tree, int i)
{
    if(tree[i] != -1)
    {
        inorder(tree, 2*i+1);
        printf("%d ", tree[i]);
        inorder(tree, 2*i+2);
    }
}

void preorder(int *tree, int i)
{
    if(tree[i] != -1)
    {
        printf("%d ", tree[i]);
        preorder(tree, 2*i+1);
        preorder(tree, 2*i+2);
    }
}

void postorder(int *tree, int i)
{
    if(tree[i] != -1)
    {
        postorder(tree, 2*i+1);
        postorder(tree, 2*i+2);
        printf("%d ", tree[i]);
    }
}

void insert(int *tree, int n, int i)
{
    if(tree[i] == -1)
    {
        tree[i] = n;
        return;
    }
    if(n < tree[i])
        insert(tree, n, 2*i+1);
    else
        insert(tree, n, 2*i+2);
}

void search(int *tree, int n, int i)
{
    if(tree[i] == -1)
    {
        printf("Not found\n");
        return;
    }
    if(n == tree[i])
    {
        printf("Found\n");
        return;
    }
    if(n < tree[i])
        search(tree, n, 2*i+1);
    else
        search(tree, n, 2*i+2);
}

void delete(int *tree, int n, int i)
{
    if(tree[i] == -1)
    {
        printf("Not found\n");
        return;
    }
    if(n == tree[i])
    {
        if(tree[2*i+1] == -1 && tree[2*i+2] == -1)
        {
            tree[i] = -1;
            return;
        }
        if(tree[2*i+1] == -1)
        {
            tree[i] = tree[2*i+2];
            tree[2*i+2] = -1;
            return;
        }
        if(tree[2*i+2] == -1)
        {
            tree[i] = tree[2*i+1];
            tree[2*i+1] = -1;
            return;
        }
        int j = 2*i+2;
        while(tree[2*j+1] != -1)
            j = 2*j+1;
        tree[i] = tree[j];
        delete(tree, tree[j], j);
        return;
    }
    if(n < tree[i])
        delete(tree, n, 2*i+1);
    else
        delete(tree, n, 2*i+2);
}

void print(int *tree, int n)
{
    for(int i=0; i<n; i++)
        printf("%d ", tree[i]);
    printf("\n");
}

//main function with switch cases

int main()
{
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    int *tree = (int*)malloc(n*sizeof(int));
    for(int i=0; i<n; i++)
        tree[i] = -1;
    int choice, value;
    while(1)
    {
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Delete\n");
        printf("4. Inorder Traversal\n");
        printf("5. Preorder Traversal\n");
        printf("6. Postorder Traversal\n");
        printf("7. Print\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter the value to be inserted: ");
                scanf("%d", &value);
                insert(tree, value, 0);
                break;
            case 2:
                printf("Enter the value to be searched: ");
                scanf("%d", &value);
                search(tree, value, 0);
                break;
            case 3:
                printf("Enter the value to be deleted: ");
                scanf("%d", &value);
                delete(tree, value, 0);
                break;
            case 4:
                inorder(tree, 0);
                printf("\n");
                break;
            case 5:
                preorder(tree, 0);
                printf("\n");
                break;
            case 6:
                postorder(tree, 0);
                printf("\n");
                break;
            case 7:
                print(tree, n);
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}

