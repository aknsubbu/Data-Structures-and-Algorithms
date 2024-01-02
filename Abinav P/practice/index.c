// singly linked list
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *getnode(int data)
{
    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

struct node *createLL()
{
    printf("Enter the number of elements in the linked list:");
    int num;
    scanf("%d", &num);
    struct node *head = NULL;
    struct node *old = NULL;
    for (int i = 0; i < num; i++)
    {
        printf("enter the data:");
        int data;
        scanf("%d", &data);
        struct node *newnode = getnode(data);
        if (i == 0)
        {
            head = newnode;
            old = newnode;
        }
        else
        {
            old->next = newnode;
            old = newnode;
        }
    }
    return head;
}

void display(struct node *head)
{
    if (head == NULL)
    {
        printf("the linked list is empty...!");
        return;
    }
    struct node *duplicate = head;
    while (duplicate != NULL)
    {
        printf("[%d]->", duplicate->data);
        duplicate = duplicate->next;
    }
    printf("[NULL]");
}

struct node *insertatbeginning(struct node *head)
{
    printf("enter the data to insert at beginning:");
    int data;
    scanf("%d", &data);
    struct node *newnode = getnode(data);
    newnode->next = head;
    head = newnode;
    return head;
}

struct node *insertatend(struct node *head)
{
    printf("enter the data to insert at end:");
    int data;
    scanf("%d", &data);
    struct node *newnode = getnode(data);
    if (head == NULL)
    {
        return newnode;
    }
    struct node *current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = newnode;
    return head;
}

struct node *insertnnodesatbeginning(struct node *head)
{
    printf("enter the number of nodes to be inserted at beginning:");
    int data;
    scanf("%d", &data);
    for (int i = 0; i < data; i++)
    {
        head = insertatbeginning(head);
    }
    return head;
}

struct node *insertnnodesatend(struct node *head)
{
    printf("enter the number of nodes to insert at end:");
    int data;
    scanf("%d", &data);
    for (int i = 0; i < data; i++)
    {
        head = insertatend(head);
    }
    return head;
}

struct node *search(struct node *head)
{
    printf("enter the element to search for :");
    int data;
    scanf("%d", &data);
    if (head == NULL)
    {
        printf("the linked list emply...!");
        return NULL;
    }
    struct node *current = head;
    while (current != NULL)
    {
        if (current->data == data)
        {
            return current;
        }
        current = current->next;
    }
    printf("the element is not found...!");
    return NULL;
}

struct node *insertafter(struct node *head)
{
    printf("\nenter the data:");
    int data;
    scanf("%d", &data);
    printf("enter the element before which the data should be inserted:");
    int search;
    scanf("%d", &search);
    struct node *current = head;
    struct node *newnode = getnode(data);
    int i = 0;
    while (current->data != search && current != NULL)
    {
        current = current->next;
        i++;
    }
    if (i)
    {

        newnode->next = current->next;
        current->next = newnode;
    }
    else
    {
        printf("the element is not found in the list");
    }
    return head;
}

struct node *insertbefore(struct node *head)
{
    printf("enter the data:");
    int data;
    scanf("%d", &data);
    printf("enter the element before which to be inserted:");
    int search;
    scanf("%d", &search);
    struct node *newnode = getnode(data);
    struct node *current = head;

    // Corrected comparison operator
    if (current->data == search)
    {
        newnode->next = head;
        head = newnode;
    }
    else
    {
        int i = 0;
        if (current->next->data == search)
        {
            newnode->next = current->next;
            current->next = newnode;
            return head;
        }
        while (current->next != NULL && current->next->data != search)
        {
            current = current->next;
            i++;
        }
        if (i)
        {
            newnode->next = current->next;
            current->next = newnode;
            return head;
        }
        else
        {
            // Handle the case when 'i' is 0
            printf("element not found\n");
            return NULL;
        }
    }
}

int main()
{
    struct node *head = NULL;
    head = createLL();
    head = insertnnodesatbeginning(head);
    head = insertnnodesatend(head);
    display(head);
    head = insertbefore(head);
    display(head);
}

// #include <stdio.h>
// #include <stdlib.h>

// int *bubblesort(int *array, int size)
// {
//     int flag = 0;
//     for (int i = 0; i < size - 1; i++)
//     {
//         for (int j = i; j < size; j++)
//         {
//             if (array[i] > array[j])
//             {
//                 flag = 1;
//                 break;
//             }
//         }
//     }
//     int temp;
//     if (flag)
//     {
//         for (int i = 0; i < size - 1; i++)
//         {
//             for (int j = i; j < size; j++)
//             {
//                 if (array[i] > array[j])
//                 {
//                     temp = array[i];
//                     array[i] = array[j];
//                     array[j] = temp;
//                 }
//             }
//         }
//     }
//     return array;
// }

// int main()
// {
//     printf("enter the size of the array:");
//     int size;
//     scanf("%d", &size);
//     int *array = malloc(size * sizeof(int));
//     for (int i = 0; i < size; i++)
//     {
//         printf("%d).", i + 1);
//         scanf("%d", &array[i]);
//     }
//     int *sorted = bubblesort(array, size);
//     printf("the sorted array is ...\n");
//     for (int i = 0; i < size; i++)
//     {
//         printf("%d ", sorted[i]);
//     }
// }

// #include <stdio.h>
// #include <stdlib.h>

// int *insertionsort(int *array, int size)
// {
//     int key, j;
//     for (int i = 1; i < size; i++)
//     {
//         key = array[i];
//         j = i - 1;
//         while (j >= 0 && array[j] > key)
//         {
//             array[j + 1] = array[j];
//             j = j - 1;
//         }
//         array[j + 1] = key;
//     }
//     return array;
// }

// int main()
// {
//     printf("enter the array size:");
//     int size;
//     scanf("%d", &size);
//     int *array = malloc(size * sizeof(int));
//     printf("enter the array elements:\n");
//     for (int i = 0; i < size; i++)
//     {
//         printf("%d).", i + 1);
//         scanf("%d", &array[i]);
//     }
//     int *sorted = insertionsort(array, size);
//     printf("the sorted arrays is :\n");
//     for (int i = 0; i < size; i++)
//     {
//         printf("%d ", array[i]);
//     }
// }

// #include <stdio.h>
// #include <stdlib.h>

// void printTree(int *tree, int index, int level, int size)
// {
//     if (index >= size || tree[index] == -1)
//     {
//         return;
//     }

//     printTree(tree, 2 * index + 2, level + 1, size); // Right child

//     for (int i = 0; i < level; i++)
//     {
//         printf("    ");
//     }
//     printf("%d\n", tree[index]); // Current node

//     printTree(tree, 2 * index + 1, level + 1, size); // Left child
// }

// void reheapify(int *heapobject, int heapsize, int pointer)
// {
//     int leftchild = 2 * pointer + 1;
//     int rightchild = 2 * pointer + 2;

//     if (leftchild >= heapsize)
//     {
//         return;
//     }
//     else if (rightchild >= heapsize)
//     {
//         if (*(heapobject + leftchild) > *(heapobject + pointer))
//         {
//             int temp = *(heapobject + leftchild);
//             *(heapobject + leftchild) = *(heapobject + pointer);
//             *(heapobject + pointer) = temp;
//         }
//     }
//     else
//     {
//         if (*(heapobject + leftchild) >= *(heapobject + rightchild) && *(heapobject + leftchild) > *(heapobject + pointer))
//         {
//             int temp = *(heapobject + leftchild);
//             *(heapobject + leftchild) = *(heapobject + pointer);
//             *(heapobject + pointer) = temp;

//             reheapify(heapobject, heapsize, leftchild);
//         }
//         else if (*(heapobject + leftchild) <= *(heapobject + rightchild) && *(heapobject + rightchild) > *(heapobject + pointer))
//         {
//             int temp = *(heapobject + rightchild);
//             *(heapobject + rightchild) = *(heapobject + pointer);
//             *(heapobject + pointer) = temp;

//             reheapify(heapobject, heapsize, rightchild);
//         }
//     }
// }

// void heapsort(int *heapobject, int heapsize)
// {
//     int limit = 0;

//     for (int iterable = 0; iterable < heapsize; iterable++)
//     {
//         printf("SWAP %d %d\n\n", *(heapobject), *(heapobject + heapsize - 1 - iterable));

//         int temp = *(heapobject);
//         *(heapobject) = *(heapobject + heapsize - 1 - iterable);
//         *(heapobject + heapsize - 1 - iterable) = temp;

//         printf("AFTER SWAP\n");
//         printTree(heapobject, 0, 0, heapsize);
//         printf("\n");

//         reheapify(heapobject, heapsize - 1 - iterable, 0);

//         printf("AFTER SWAP, RH5\n");
//         printTree(heapobject, 0, 0, heapsize);
//         printf("\n");
//         printf("\n");
//     }
// }

// int main()
// {
//     int maxheaparray[] = {94, 84, 78, 42, 40, 42, 31, 22, 2, 31};
//     int *maxheappointer = maxheaparray;
//     int maxheapsize = sizeof(maxheaparray) / sizeof(int);

//     printf("INIT\n");

//     printTree(maxheappointer, 0, 0, maxheapsize);
//     printf("\n");
//     for (int i = 0; i < maxheapsize; i++)
//     {
//         printf("%d-", maxheaparray[i]);
//     }

//     printf("\n");

//     heapsort(maxheappointer, maxheapsize);

//     printf("\n");

//     printf("AFTER SORT\n");

//     printTree(maxheappointer, 0, 0, maxheapsize);
//     printf("\n");
//     for (int i = 0; i < maxheapsize; i++)
//     {
//         printf("%d-", maxheaparray[i]);
//     }

//     printf("\n");
//     return 0;
// }
