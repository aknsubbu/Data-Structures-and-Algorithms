#include <stdio.h>
#include <stdlib.h>

void inorder(int *tree, int i, int size)
{
    if (i < size && tree[i] != -1)
    {
        inorder(tree, 2 * i + 1, size);
        printf("%d ", tree[i]);
        inorder(tree, 2 * i + 2, size);
    }
}

void insert(int *tree, int n, int i, int size)
{
    if (i >= size)
    {
        printf("Binary tree is full. Cannot insert.\n");
        return;
    }

    if (tree[i] == -1)
    {
        tree[i] = n;
        return;
    }

    if (n < tree[i])
        insert(tree, n, 2 * i + 1, size);
    else
        insert(tree, n, 2 * i + 2, size);
}

void delete(int *tree, int n, int i, int size)
{
    if (i >= size)
    {
        printf("Binary tree is empty. Cannot delete.\n");
        return;
    }

    if (tree[i] == -1)
    {
        printf("Not found\n");
        return;
    }

    if (n == tree[i])
    {
        if (tree[2 * i + 1] == -1 && tree[2 * i + 2] == -1)
        {
            tree[i] = -1;
            return;
        }

        if (tree[2 * i + 1] == -1)
        {
            tree[i] = tree[2 * i + 2];
            tree[2 * i + 2] = -1;
            return;
        }

        if (tree[2 * i + 2] == -1)
        {
            tree[i] = tree[2 * i + 1];
            tree[2 * i + 1] = -1;
            return;
        }

        int j = 2 * i + 2;
        while (tree[2 * j + 1] != -1 && 2 * j + 1 < size)
            j = 2 * j + 1;
        tree[i] = tree[j];
        delete(tree, tree[j], j, size);
        return;
    }

    if (n < tree[i])
        delete(tree, n, 2 * i + 1, size);
    else
        delete(tree, n, 2 * i + 2, size);
}

void display(int *tree, int size)
{
    for (int i = 0; i < size; i++) {
        if (tree[i] != -1) {
            printf("%d ", tree[i]);
        }
    }
    printf("\n");
}

int main()
{
    int tree[100] = {-1};
    int n = 10;
    int arr[10] = {5, 3, 7, 2, 4, 6, 8, 1, 9, 10};
    for (int i = 0; i < n; i++)
        insert(tree, arr[i], 0, 100);

    int choice, value;
    while (1)
    {
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Delete\n");
        printf("4. Inorder Traversal\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the value to be inserted: ");
            scanf("%d", &value);
            insert(tree, value, 0, 100);
            break;
        case 2:
            printf("Enter the value to be searched: ");
            scanf("%d", &value);
            // Implement the search function
            break;
        case 3:
            printf("Enter the value to be deleted: ");
            scanf("%d", &value);
            // Implement the delete function
            break;
        case 4:
            inorder(tree, 0, 100);
            printf("\n");
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
        display(tree, 100);
    }
    return 0;
}
