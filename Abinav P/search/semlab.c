// #include <stdio.h>
// #include <stdlib.h>

// int *insertionsort(int *arr, int size)
// {
//     int key, j;
//     for (int i = 1; i <= size; i++)
//     {
//         key = arr[i];
//         j = i - 1;
//         while (j >= 0 && arr[j] > key)
//         {
//             arr[j + 1] = arr[j];
//             j = j - 1;
//         }
//         arr[j + 1] = key;
//     }
//     return arr;
// }

// void main()
// {
//     int *arr;
//     int size;
//     printf("Enter the size of the array: ");
//     scanf("%d", &size);
//     arr = (int *)malloc(size * sizeof(int));
//     printf("Enter the elements of the array: ");
//     for (int i = 0; i < size; i++)
//     {
//         scanf("%d", &arr[i]);
//     }
//     arr = insertionsort(arr, size);
//     printf("The sorted array is: ");
//     for (int i = 0; i < size; i++)
//     {
//         printf("%d ", arr[i]);
//     }
// }

// bubble sort
// #include <stdio.h>
// #include <Stdlib.h>

// int *bubblesort(int *array, int size)
// {
//     int temp;
//     for (int i = 0; i < size; i++)
//     {
//         for (int j = 0; j < size - i - 1; j++)
//         {
//             if (array[j] > array[j + 1])
//             {
//                 temp = array[j];
//                 array[j] = array[j + 1];
//                 array[j + 1] = temp;
//             }
//         }
//     }
//     return array;
// }

// void main()
// {
//     int *arr;
//     int size;
//     printf("Enter the size of the array: ");
//     scanf("%d", &size);
//     arr = (int *)malloc(size * sizeof(int));
//     printf("Enter the elements of the array: ");
//     for (int i = 0; i < size; i++)
//     {
//         scanf("%d", &arr[i]);
//     }
//     arr = bubblesort(arr, size);
//     printf("The sorted array is: ");
//     for (int i = 0; i < size; i++)
//     {
//         printf("%d ", arr[i]);
//     }
// }

// Linear Search
// #include <stdio.h>
// #include <stdlib.h>

// int linearSearch(int *arr, int size, int element)
// {
//     for (int i = 0; i < size; i++)
//     {
//         if (arr[i] == element)
//         {
//             return i;
//         }
//     }
//     return -1;
// }

// void main()
// {
//     int *arr;
//     int size, element;
//     printf("Enter the size of the array: ");
//     scanf("%d", &size);
//     arr = (int *)malloc(size * sizeof(int));
//     printf("Enter the elements of the array: ");
//     for (int i = 0; i < size; i++)
//     {
//         scanf("%d", &arr[i]);
//     }
//     printf("Enter the element to be searched: ");
//     scanf("%d", &element);
//     int index = linearSearch(arr, size, element);
//     if (index == -1)
//     {
//         printf("The element is not present in the array");
//     }
//     else
//     {
//         printf("The element is present at index %d", index);
//     }
// }

// binary search :
// #include <stdio.h>
// #include <stdlib.h>

// int binarySearch(int *array, int size, int element)
// {
//     int low, mid, high;
//     low = 0;
//     high = size - 1;
//     while (low <= high)
//     {
//         mid = (low + high) / 2;
//         printf("%d\n", mid);
//         if (array[mid] == element)
//         {
//             return mid;
//         }
//         if (array[mid] < element)
//         {
//             low = mid + 1;
//         }
//         else
//         {
//             high = mid - 1;
//         }
//     }
//     return -1;
// }

// void main()
// {
//     int *arr;
//     int size, element;
//     printf("Enter the size of the array: ");
//     scanf("%d", &size);
//     arr = (int *)malloc(size * sizeof(int));
//     printf("Enter the elements of the array: ");
//     for (int i = 0; i < size; i++)
//     {
//         scanf("%d", &arr[i]);
//     }
//     printf("Enter the element to be searched: ");
//     scanf("%d", &element);
//     int index = binarySearch(arr, size, element);
//     if (index == -1)
//     {
//         printf("The element is not present in the array");
//     }
//     else
//     {
//         printf("The element is present at index %d", index);
//     }
// }

// binary search using recursion
// #include <stdio.h>
// #include <stdlib.h>

// int binarySearch(int *array, int low, int high, int element)
// {
//     int mid;
//     if (low <= high)
//     {
//         mid = (low + high) / 2;
//         if (array[mid] == element)
//         {
//             return mid;
//         }
//         if (array[mid] < element)
//         {
//             return binarySearch(array, mid + 1, high, element);
//         }
//         else
//         {
//             return binarySearch(array, low, mid - 1, element);
//         }
//     }
//     return -1;
// }

// void main()
// {
//     int *arr;
//     int size, element;
//     printf("Enter the size of the array: ");
//     scanf("%d", &size);
//     arr = (int *)malloc(size * sizeof(int));
//     printf("Enter the elements of the array: ");
//     for (int i = 0; i < size; i++)
//     {
//         scanf("%d", &arr[i]);
//     }
//     printf("Enter the element to be searched: ");
//     scanf("%d", &element);
//     int index = binarySearch(arr, 0, size - 1, element);
//     if (index == -1)
//     {
//         printf("The element is not present in the array");
//     }
//     else
//     {
//         printf("The element is present at index %d", index);
//     }
// }

// singly linked list

// #include <stdio.h>
// #include <stdlib.h>

// struct node
// {
//     int data;
//     struct node *next;
// };

// struct node *createnode(int data)
// {
//     struct node *newnode = (struct node *)malloc(sizeof(struct node));
//     newnode->data = data;
//     newnode->next = NULL;
//     return newnode;
// }

// struct node *createLL(int number)
// {
//     struct node *root = NULL;
//     struct node *old = NULL;
//     for (int i = 0; i < number; i++)
//     {
//         printf("enter the data:");
//         int data;
//         scanf("%d", &data);
//         struct node *newnode = createnode(data);
//         if (i == 0)
//         {
//             root = newnode;
//             old = newnode;
//         }
//         else
//         {
//             old->next = newnode;
//             old = newnode;
//         }
//     }
//     return root;
// }

// void display(struct noed *root)
// {
//     struct node *temp = root;
//     while (temp != NULL)
//     {
//         printf("[%d]->", temp->data);
//         temp = temp->next;
//     }
//     printf("[NULL]\n");
// }

// void main()
// {
//     struct node *root;
//     printf("enter the number of nodes:");
//     int number;
//     scanf("%d", &number);
//     root = createLL(number);
//     display(root);
// }

// doubly linked list

// #include <stdio.h>
// #include <stdlib.h>

// struct node
// {
//     int data;
//     struct node *next, *previous;
// };

// struct node *createnode(int data)
// {
//     struct node *newnode = (struct node *)malloc(sizeof(struct node));
//     newnode->data = data;
//     newnode->next = NULL;
//     newnode->previous = NULL;
//     return newnode;
// }

// struct node *createLL(int number)
// {
//     struct node *root = NULL;
//     struct node *old = NULL;
//     for (int i = 0; i < number; i++)
//     {
//         printf("enter the data:");
//         int data;
//         scanf("%d", &data);
//         struct node *newnode = createnode(data);
//         if (i == 0)
//         {
//             root = newnode;
//             old = newnode;
//         }
//         else
//         {
//             old->next = newnode;
//             newnode->previous = old;
//             old = newnode;
//         }
//     }
//     return root;
// }

// void display(struct node *root)
// {
//     struct node *temp = root;
//     while (temp != NULL)
//     {
//         printf("[%d]<->", temp->data);
//         temp = temp->next;
//     }
//     printf("[NULL]\n");
// }

// void main()
// {
//     struct node *root;
//     printf("enter the number of nodes:");
//     int number;
//     scanf("%d", &number);
//     root = createLL(number);
//     display(root);
// }

// circular singly linked list
// #include <stdio.h>
// #include <stdlib.h>

// struct node
// {
//     int data;
//     struct node *prev, *next;
// };

// struct node *createnode(int data)
// {
//     struct node *newnode = (struct node *)malloc(sizeof(struct node));
//     newnode->data = data;
//     newnode->next = NULL;
//     newnode->prev = NULL;
//     return newnode;
// }

// struct node *createLL(int number)
// {
//     struct node *root = NULL;
//     struct node *old = NULL;
//     for (int i = 0; i < number; i++)
//     {
//         printf("enter the data:");
//         int data;
//         scanf("%d", &data);
//         struct node *newnode = createnode(data);
//         if (i == 0)
//         {
//             root = newnode;
//             old = newnode;
//         }
//         else
//         {
//             old->next = newnode;
//             newnode->prev = old;
//             old = newnode;
//         }
//     }
//     old->next = root;
//     root->prev = old;
//     return root;
// }

// void display(struct node *root)
// {
//     struct node *temp = root;
//     while (temp->next != root)
//     {
//         printf("[%d]<->", temp->data);
//         temp = temp->next;
//     }
//     printf("[%d]<->", temp->data);
//     printf("[NULL]\n");
// }

// void main()
// {
//     int n = 5;
//     struct node *head = createLL(n);
//     display(head);
// }

// sum of two nodes

// #include <stdio.h>
// #include <Stdlib.h>

// struct node
// {
//     int data;
//     struct node *next;
// };

// struct node *createnode(int data)
// {
//     struct node *newnode = malloc(sizeof(struct node));
//     newnode->data = data;
//     newnode->next = NULL;
//     return newnode;
// }

// struct node *createLL(int size)
// {
//     struct node *root = NULL;
//     struct node *temp = NULL;
//     for (int i = 0; i < size; i++)
//     {
//         int x;
//         printf("enter the data:");
//         scanf("%d", &x);
//         struct node *newnode = createnode(x);
//         if (i == 0)
//         {
//             root = newnode;
//             temp = newnode;
//         }
//         else
//         {
//             temp->next = newnode;
//             temp = newnode;
//         }
//     }
//     return root;
// }

// void display(struct node *root)
// {
//     struct node *temp = root;
//     while (temp != NULL)
//     {
//         printf("[%d]->", temp->data);
//         temp = temp->next;
//     }
//     printf("[NULL]\n");
// }

// void findtwosum(struct node *root, int target)
// {
//     struct node *temp = root;

//     while (temp != NULL)
//     {
//         struct node *temp2 = temp->next;

//         while (temp2 != NULL)
//         {
//             if ((temp->data + temp2->data) == target)
//             {
//                 printf("[%d, %d]\n", temp->data, temp2->data);
//             }
//             temp2 = temp2->next;
//         }

//         temp = temp->next;
//     }

//     printf("the iteration is completed\n");
// }

// void main()
// {
//     int number;
//     printf("Enter the size of linked list: ");
//     scanf("%d", &number);
//     struct node *root = createLL(number);
//     printf("\nLinked List is:\n");
//     display(root);
//     int targ;
//     printf("enter the target:");
//     scanf("%d", &targ);
//     findtwosum(root, targ);
// }

// #include <Stdio.h>
// #include <stdlib.h>

// struct stack
// {
//     int data;
//     struct stack *next;
// };

// struct stack *createelement(int data)
// {
//     struct stack *newnode = malloc(sizeof(struct stack));
//     newnode->data = data;
//     newnode->next = NULL;
//     return newnode;
// }

// struct stack *push(int data, struct stack *root)
// {
//     struct stack *newnode = createelement(data);
//     newnode->next = root;
//     root = newnode;
//     return root;
// }

// void display(struct stack *root)
// {
//     if (root == NULL)
//         return;
//     while (root != NULL)
//     {
//         printf("%d->", root->data);
//         root = root->next;
//     }
//     printf("NULL");
// }

// void main()
// {
//     int n;
//     struct stack *root = NULL;
//     printf("Enter the operation to be performed: \n Push\n display\n");
//     scanf("%d", &n);
//     while (1)
//     {
//         switch (n)
//         {
//         case 1:
//             printf("Enter the data to be pushed into the stack:");
//             int data;
//             scanf("%d", data);
//             root = push(data, root);
//             break;
//         case 2:
//             display(root);
//             break;
//         default:
//             printf("invalid opinion:");

//             return;
//             break;
//         }
//     }
// }

// #include <stdio.h>

// void spiralPrint(int rows, int cols, int matrix[][cols])
// {
//     int top = 0, bottom = rows - 1, left = 0, right = cols - 1;

//     while (top <= bottom && left <= right)
//     {
//         // Print top row
//         for (int i = left; i <= right; i++)
//         {
//             printf("%d ", matrix[top][i]);
//         }
//         top++;

//         // Print right column
//         for (int i = top; i <= bottom; i++)
//         {
//             printf("%d ", matrix[i][right]);
//         }
//         right--;

//         // Print bottom row
//         if (top <= bottom)
//         {
//             for (int i = right; i >= left; i--)
//             {
//                 printf("%d ", matrix[bottom][i]);
//             }
//             bottom--;
//         }

//         // Print left column
//         if (left <= right)
//         {
//             for (int i = bottom; i >= top; i--)
//             {
//                 printf("%d ", matrix[i][left]);
//             }
//             left++;
//         }
//     }
// }

// int main()
// {
//     int rows, cols;

//     printf("Enter the number of rows and columns: ");
//     scanf("%d %d", &rows, &cols);

//     int matrix[rows][cols];

//     printf("Enter the elements of the matrix:\n");
//     for (int i = 0; i < rows; i++)
//     {
//         for (int j = 0; j < cols; j++)
//         {
//             scanf("%d", &matrix[i][j]);
//         }
//     }

//     printf("Spirally printed matrix: ");
//     spiralPrint(rows, cols, matrix);

//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>

// struct TreeNode
// {
//     int data;
//     struct TreeNode *left;
//     struct TreeNode *right;
// };

// // Function to create a new node
// struct TreeNode *createNode(int value)
// {
//     struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
//     newNode->data = value;
//     newNode->left = newNode->right = NULL;
//     return newNode;
// }

// // Function to insert a new node into the binary tree
// struct TreeNode *insertNode(struct TreeNode *root, int value)
// {
//     if (root == NULL)
//     {
//         return createNode(value);
//     }

//     if (root->left == NULL)
//     {
//         root->left = createNode(value);
//     }
//     else if (root->right == NULL)
//     {
//         root->right = createNode(value);
//     }
//     else
//     {
//         // If both left and right subtrees are present, choose one randomly
//         if (rand() % 2 == 0)
//         {
//             insertNode(root->left, value);
//         }
//         else
//         {
//             insertNode(root->right, value);
//         }
//     }

//     return root;
// }

// // Function to delete a node with a given value from the binary tree
// struct TreeNode *deleteNode(struct TreeNode *root, int value)
// {
//     if (root == NULL)
//     {
//         return root;
//     }

//     if (root->data == value && root->left == NULL && root->right == NULL)
//     {
//         // Node with no children
//         free(root);
//         return NULL;
//     }

//     // Recursive deletion
//     root->left = deleteNode(root->left, value);
//     root->right = deleteNode(root->right, value);

//     return root;
// }

// // Function to perform inorder traversal of the binary tree
// void inorderTraversal(struct TreeNode *root)
// {
//     if (root != NULL)
//     {
//         inorderTraversal(root->left);
//         printf("%d ", root->data);
//         inorderTraversal(root->right);
//     }
// }

// int main()
// {
//     struct TreeNode *root = createNode(1);

//     insertNode(root, 2);
//     insertNode(root, 3);
//     insertNode(root, 4);
//     insertNode(root, 5);

//     printf("Inorder traversal before deletion: ");
//     inorderTraversal(root);
//     printf("\n");

//     // Randomly choose a node to delete
//     int valueToDelete = rand() % 5 + 1;
//     root = deleteNode(root, valueToDelete);
//     printf("Deleted node with value %d\n", valueToDelete);

//     printf("Inorder traversal after deletion: ");
//     inorderTraversal(root);
//     printf("\n");

//     return 0;
// }
// #include <stdio.h>

// #define MAX_SIZE 100

// int tree[MAX_SIZE];
// int size = 0;

// // Function to insert a new node into the binary search tree
// void insertNode(int value)
// {
//     if (size == MAX_SIZE)
//     {
//         printf("Error: Tree is full\n");
//         return;
//     }

//     int index = size;
//     tree[index] = value;
//     size++;

//     // Perform the necessary swaps to maintain the binary search tree property
//     while (index > 0 && tree[index] < tree[(index - 1) / 2])
//     {
//         int parentIndex = (index - 1) / 2;
//         int temp = tree[index];
//         tree[index] = tree[parentIndex];
//         tree[parentIndex] = temp;
//         index = parentIndex;
//     }
// }

// // Function to delete a node with a given value from the binary search tree
// void deleteNode(int value)
// {
//     int index = -1;

//     // Find the index of the node with the given value
//     for (int i = 0; i < size; i++)
//     {
//         if (tree[i] == value)
//         {
//             index = i;
//             break;
//         }
//     }

//     if (index == -1)
//     {
//         printf("Error: Node not found\n");
//         return;
//     }

//     // Replace the node with the last node in the tree
//     tree[index] = tree[size - 1];
//     size--;

//     // Perform the necessary swaps to maintain the binary search tree property
//     while (1)
//     {
//         int leftChildIndex = 2 * index + 1;
//         int rightChildIndex = 2 * index + 2;

//         // Find the index of the smallest child
//         int smallestChildIndex = index;
//         if (leftChildIndex < size && tree[leftChildIndex] < tree[smallestChildIndex])
//         {
//             smallestChildIndex = leftChildIndex;
//         }
//         if (rightChildIndex < size && tree[rightChildIndex] < tree[smallestChildIndex])
//         {
//             smallestChildIndex = rightChildIndex;
//         }

//         if (smallestChildIndex == index)
//         {
//             break; // No more swaps needed
//         }

//         // Swap the node with the smallest child
//         int temp = tree[index];
//         tree[index] = tree[smallestChildIndex];
//         tree[smallestChildIndex] = temp;

//         index = smallestChildIndex;
//     }
// }

// // Function to perform inorder traversal of the binary search tree
// void inorderTraversal(int index)
// {
//     if (index < size)
//     {
//         inorderTraversal(2 * index + 1);
//         printf("%d ", tree[index]);
//         inorderTraversal(2 * index + 2);
//     }
// }

// int main()
// {
//     insertNode(4);
//     insertNode(2);
//     insertNode(6);
//     insertNode(1);
//     insertNode(3);
//     insertNode(5);
//     insertNode(7);

//     printf("Inorder traversal before deletion: ");
//     inorderTraversal(0);
//     printf("\n");

//     deleteNode(6);

//     printf("Inorder traversal after deletion: ");
//     inorderTraversal(0);
//     printf("\n");

//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>

// // Define a structure for a node in the binary search tree
// struct TreeNode
// {
//     int data;
//     struct TreeNode *left;
//     struct TreeNode *right;
// };

// // Function to create a new node with the given data
// struct TreeNode *createNode(int data)
// {
//     struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
//     if (newNode == NULL)
//     {
//         perror("Memory allocation error");
//         exit(EXIT_FAILURE);
//     }

//     newNode->data = data;
//     newNode->left = NULL;
//     newNode->right = NULL;

//     return newNode;
// }

// // Function to insert a new node with the given data into the BST
// struct TreeNode *insert(struct TreeNode *root, int data)
// {
//     // If the tree is empty, create a new node and return it as the root
//     if (root == NULL)
//     {
//         return createNode(data);
//     }

//     // If the data is less than the root's data, insert into the left subtree
//     if (data < root->data)
//     {
//         root->left = insert(root->left, data);
//     }
//     // If the data is greater than the root's data, insert into the right subtree
//     else if (data > root->data)
//     {
//         root->right = insert(root->right, data);
//     }

//     // If data is equal to the root's data, do nothing (no duplicate values in this example)

//     return root;
// }

// // Function to find the node with the minimum value in a BST
// struct TreeNode *findMin(struct TreeNode *node)
// {
//     while (node->left != NULL)
//     {
//         node = node->left;
//     }
//     return node;
// }

// // Function to delete a node with the given data from the BST
// struct TreeNode *deleteNode(struct TreeNode *root, int data)
// {
//     // If the tree is empty, return NULL
//     if (root == NULL)
//     {
//         return root;
//     }

//     // Search for the node to be deleted in the left or right subtrees
//     if (data < root->data)
//     {
//         root->left = deleteNode(root->left, data);
//     }
//     else if (data > root->data)
//     {
//         root->right = deleteNode(root->right, data);
//     }
//     else
//     {
//         // Node with only one child or no child
//         if (root->left == NULL)
//         {
//             struct TreeNode *temp = root->right;
//             free(root);
//             return temp;
//         }
//         else if (root->right == NULL)
//         {
//             struct TreeNode *temp = root->left;
//             free(root);
//             return temp;
//         }

//         // Node with two children: Get the inorder successor (smallest
//         // in the right subtree) and replace the current node's data with it
//         struct TreeNode *temp = findMin(root->right);
//         root->data = temp->data;

//         // Delete the inorder successor
//         root->right = deleteNode(root->right, temp->data);
//     }

//     return root;
// }

// // Function to perform an inorder traversal of the BST
// void inorderTraversal(struct TreeNode *root)
// {
//     if (root != NULL)
//     {
//         inorderTraversal(root->left);
//         printf("%d ", root->data);
//         inorderTraversal(root->right);
//     }
// }

// // Function to free the memory allocated for the BST nodes
// void freeTree(struct TreeNode *root)
// {
//     if (root != NULL)
//     {
//         freeTree(root->left);
//         freeTree(root->right);
//         free(root);
//     }
// }

// int main()
// {
//     // Create an empty BST
//     struct TreeNode *root = NULL;

//     // Insert nodes into the BST
//     root = insert(root, 50);
//     root = insert(root, 30);
//     root = insert(root, 20);
//     root = insert(root, 40);
//     root = insert(root, 70);
//     root = insert(root, 60);
//     root = insert(root, 80);

//     // Print the inorder traversal of the BST
//     printf("Inorder traversal before deletion: ");
//     inorderTraversal(root);
//     printf("\n");

//     // Delete a node from the BST
//     int dataToDelete = 30;
//     root = deleteNode(root, dataToDelete);
//     printf("Node with data %d deleted\n", dataToDelete);

//     // Print the inorder traversal after deletion
//     printf("Inorder traversal after deletion: ");
//     inorderTraversal(root);
//     printf("\n");

//     // Free the memory allocated for the BST
//     freeTree(root);

//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>

// // Define a structure for a tree node
// struct TreeNode
// {
//     int data;
//     struct TreeNode *left;
//     struct TreeNode *right;
// };

// // Function to create a new tree node
// struct TreeNode *createNode(int data)
// {
//     struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
//     newNode->data = data;
//     newNode->left = newNode->right = NULL;
//     return newNode;
// }

// // Function to find the lowest common ancestor of two nodes in a binary tree
// struct TreeNode *findLCA(struct TreeNode *root, int node1, int node2)
// {
//     if (root == NULL)
//     {
//         return NULL;
//     }

//     // If either node1 or node2 is the root, the root is the LCA
//     if (root->data == node1 || root->data == node2)
//     {
//         return root;
//     }

//     // Recursively search for LCA in the left and right subtrees
//     struct TreeNode *leftLCA = findLCA(root->left, node1, node2);
//     struct TreeNode *rightLCA = findLCA(root->right, node1, node2);

//     // If both nodes are found in the left and right subtrees, then the root is the LCA
//     if (leftLCA != NULL && rightLCA != NULL)
//     {
//         return root;
//     }

//     // If only one subtree contains an ancestor, that subtree's result is the LCA
//     return (leftLCA != NULL) ? leftLCA : rightLCA;
// }

// int main()
// {
//     // Construct a sample binary tree
//     struct TreeNode *root = createNode(3);
//     root->left = createNode(5);
//     root->right = createNode(1);
//     root->left->left = createNode(6);
//     root->left->right = createNode(2);
//     root->right->left = createNode(0);
//     root->right->right = createNode(8);
//     root->left->right->left = createNode(7);
//     root->left->right->right = createNode(4);

//     int node1, node2;
//     printf("Enter two nodes to find their lowest common ancestor: ");
//     scanf("%d %d", &node1, &node2);

//     // Find and print the lowest common ancestor
//     struct TreeNode *lca = findLCA(root, node1, node2);
//     if (lca != NULL)
//     {
//         printf("Lowest Common Ancestor of %d and %d is: %d\n", node1, node2, lca->data);
//     }
//     else
//     {
//         printf("Nodes not found in the tree.\n");
//     }

//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>

// // Define a structure for a tree node
// struct TreeNode
// {
//     int data;
//     struct TreeNode *left;
//     struct TreeNode *right;
// };

// // Function to create a new tree node
// struct TreeNode *createNode(int data)
// {
//     struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
//     newNode->data = data;
//     newNode->left = newNode->right = NULL;
//     return newNode;
// }

// // Function to perform reverse in-order traversal and convert BST to Greater Sum Tree
// void convertToGreaterSumTree(struct TreeNode *root, int *sum)
// {
//     if (root == NULL)
//     {
//         return;
//     }

//     // Recursively traverse the right subtree
//     convertToGreaterSumTree(root->right, sum);

//     // Update the current node with the sum of all nodes greater than itself
//     root->data += *sum;

//     // Update the sum to include the current node's value
//     *sum = root->data;

//     // Recursively traverse the left subtree
//     convertToGreaterSumTree(root->left, sum);
// }

// // Function to print the in-order traversal of a tree
// void printInOrder(struct TreeNode *root)
// {
//     if (root != NULL)
//     {
//         printInOrder(root->left);
//         printf("%d ", root->data);
//         printInOrder(root->right);
//     }
// }

// int main()
// {
//     // Construct a sample binary search tree
//     struct TreeNode *root = createNode(5);
//     root->left = createNode(2);
//     root->right = createNode(13);

//     // Perform reverse in-order traversal and convert to Greater Sum Tree
//     int sum = 0;
//     convertToGreaterSumTree(root, &sum);

//     // Print the in-order traversal of the Greater Sum Tree
//     printf("In-Order Traversal of Greater Sum Tree: ");
//     printInOrder(root);
//     printf("\n");

//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>

// // Define a structure for a tree node
// struct TreeNode
// {
//     int data;
//     struct TreeNode *left;
//     struct TreeNode *right;
// };

// // Create a new tree node
// struct TreeNode *createNode(int data)
// {
//     struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
//     newNode->data = data;
//     newNode->left = NULL;
//     newNode->right = NULL;
//     return newNode;
// }

// // Function to find the height of a tree
// int height(struct TreeNode *root)
// {
//     if (root == NULL)
//     {
//         return 0;
//     }

//     int leftHeight = height(root->left);
//     int rightHeight = height(root->right);

//     return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
// }

// // Function to find the diameter of a tree
// int diameter(struct TreeNode *root)
// {
//     if (root == NULL)
//     {
//         return 0;
//     }

//     // Calculate the height of the left and right subtrees
//     int leftHeight = height(root->left);
//     int rightHeight = height(root->right);

//     // Calculate the diameter passing through the current node
//     int currentDiameter = leftHeight + rightHeight + 1;

//     // Recursively calculate the diameter in the left and right subtrees
//     int leftDiameter = diameter(root->left);
//     int rightDiameter = diameter(root->right);

//     // Return the maximum of the three diameters
//     return (currentDiameter > leftDiameter) ? (currentDiameter > rightDiameter ? currentDiameter : rightDiameter) : (leftDiameter > rightDiameter ? leftDiameter : rightDiameter);
// }

// int main()
// {
//     // Create a sample tree
//     struct TreeNode *root = createNode(1);
//     root->left = createNode(2);
//     root->right = createNode(3);
//     root->left->left = createNode(4);
//     root->left->right = createNode(5);
//     root->right->right = createNode(6);
//     root->left->right->left = createNode(7);
//     root->left->right->right = createNode(8);

//     // Find the diameter of the tree
//     int treeDiameter = diameter(root);

//     printf("Diameter of the tree: %d\n", treeDiameter);

//     return 0;
// }
