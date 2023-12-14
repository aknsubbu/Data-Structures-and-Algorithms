###### 15 - 12 - 2023 - PSG College of Technology

---

# 19z310 - Data Structures Laboratory

## Leetcode questions solved

#### Kishoreadhith V

#### 22z232

#### BE CSE G1

---

## Arrays - sorting and searching algorithms

### Linear Search

```c
#include <stdio.h>
#include "../swap.h"
#include <time.h>
#include <stdlib.h>
#define N 100000

int linearSearch(int * arr, int len, int target){
    for (int i = 0; i < len; i++)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }
    return -1;
}

void readArrayFromFile(int * array, int len, char * fileName){
    FILE * file = fopen(fileName, "r");
    for (int i = 0; i < len; i++)
    {
        fscanf(file, "%d", array + i);
    }
    fclose(file);
}

int main() {
    int* nums = (int *) malloc (N * sizeof(int));
    readArrayFromFile(nums, N, "100k-random.txt");
    // Measure the time before sorting
    clock_t start_time = clock();

    linearSearch(nums, 100000, 0);

    // Measure the time after sorting
    clock_t end_time = clock();

    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    // printf("Sorted array: ");
    // printArray(a, 5);
    printf("Time taken: %f seconds\n", time_taken);

    return 0;
}
```

### Binary Search

```c
#include <stdio.h>

int binarySearchIterative(int * arr, int len, int target){
    int start = 0;
    int end = len - 1;

    while (start <= end)
    {
        int mid = (start + end)/2;
        if (*(arr + mid) == target)
        {
            return mid;
        }
        else if (*(arr + mid) > target)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return -1;
}

int binarySearchRecursive(int * arr, int start, int end, int target){
    if (start > end)
    {
        return -1;
    }
    else
    {
        int mid = (start + end)/2;
        if (*(arr + mid) == target)
        {
            return mid;
        }
        else if (*(arr + mid) > target)
        {
            return binarySearchRecursive(arr, start, mid - 1, target);
        }
        else
        {
            return binarySearchRecursive(arr, mid + 1, end, target);
        }
    }
}

int main(){
    int arr[] = {10,20,30,40,50,60,70,80,90,100};
    int target = 50;
    int result = binarySearchIterative(arr, 10, target);
    int result2 = binarySearchRecursive(arr, 0, 9, target);
    printf("%d \n %d", result, result2);
}
```

### Bubble Sort

```c
#include <stdio.h>
#include "../swap.h"
#include <time.h>
#include <stdlib.h>
#define N 100000

void readArrayFromFile(int * array, int len, char * fileName){
    FILE * file = fopen(fileName, "r");
    for (int i = 0; i < len; i++)
    {
        fscanf(file, "%d", array + i);
    }
    fclose(file);
}

void writeArrayToFile(int * array, int len, char * fileName){
    FILE * file = fopen(fileName, "a");
    for (int i = 0; i < len; i++)
    {
        fprintf(file, "%d ", *(array + i));
    }
    fprintf(file, "\n");
    fclose(file);
}



void printArray(int * array, int len){
    for (int i = 0; i < len; i++)
    {
        printf("%d\t", *(array + i));
    }
    printf("\n");
}

void bubbleSort(int * arr, int len){
    int swapsMadeInCurrentIteration, totalSwaps = 0, comparisons = 0;
    for (int i = 0; i < len - 1; i++)
    {
        swapsMadeInCurrentIteration = 0;
        for (int j = 0; j < len - i - 1; j++)
        {
            comparisons++;
            if (*(arr + j) > *(arr + j + 1))
            {
                swap(j, j+1, arr);
                swapsMadeInCurrentIteration++;
                totalSwaps++;
                // writeArrayToFile(arr, len, fileName);
            }

        }
        if (!swapsMadeInCurrentIteration)
        {
            break;
        }

    }
    // FILE * file = fopen(fileName, "a");
    // fprintf(file, "Number of swaps: %d\nSwaps: %d", totalSwaps);
    // fclose(file);

}


void bubbleSortIterDemo (int * arr, int len, char * fileName){
    int swapsMadeInCurrentIteration, totalSwaps = 0, comparisons = 0;
    for (int i = 0; i < len - 1; i++)
    {
        swapsMadeInCurrentIteration = 0;
        for (int j = 0; j < len - i - 1; j++)
        {
            comparisons++;
            if (*(arr + j) > *(arr + j + 1))
            {
                swap(j, j+1, arr);
                swapsMadeInCurrentIteration++;
                totalSwaps++;
                writeArrayToFile(arr, len, fileName);
            }

        }
        if (!swapsMadeInCurrentIteration)
        {
            break;
        }

    }
    FILE * file = fopen(fileName, "a");
    fprintf(file, "Number of swaps: %d\nComparisons: %d", totalSwaps);
    fclose(file);

}


void reverseBubbleSort (int * arr, int len, char * fileName){
    int swapsMadeInCurrentIteration, totalSwaps = 0, comparisons = 0;
    for (int i = len - 1; i > 0; i--)
    {
        swapsMadeInCurrentIteration = 0;
        for (int j = len - 1; j > i; j--)
        {
            comparisons++;
            if (*(arr + j) < *(arr + j - 1))
            {
                swap(j, j-1, arr);
                swapsMadeInCurrentIteration++;
                totalSwaps++;
                writeArrayToFile(arr, len, fileName);
            }

        }
        if (!swapsMadeInCurrentIteration)
        {
            break;
        }

    }
    FILE * file = fopen(fileName, "a");
    fprintf(file, "Number of swaps: %d\nComparisons: %d", totalSwaps);
    fclose(file);

}



int main() {
    int* nums = (int *) malloc (N * sizeof(int));
    readArrayFromFile(nums, N, "100k-random.txt");
    // Measure the time before sorting
    clock_t start_time = clock();

    bubbleSort(nums, 100000);

    // Measure the time after sorting
    clock_t end_time = clock();

    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    // printf("Sorted array: ");
    // printArray(a, 5);
    printf("Time taken: %f seconds\n", time_taken);

    return 0;
}
```

### Insertion sort

```c
#include <stdio.h>
#include "../swap.h"
#include <time.h>
#include <stdlib.h>
#define N 100000

void readArrayFromFile(int * array, int len, char * fileName){
    FILE * file = fopen(fileName, "r");
    for (int i = 0; i < len; i++)
    {
        fscanf(file, "%d", array + i);
    }
    fclose(file);
}

void printArray(int * array, int len){
    for (int i = 0; i < len; i++)
    {
        printf("%d\t", *(array + i));
    }
    printf("\n");
}
void insertionSortUnoptimised(int * arr, int len){
    for (int i = 1; i < len; i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (arr[j] < arr[j-1])
            {
                swap(j, j-1, arr);
                // printArray(arr, len);
            } else {
                break;
            }
        }
    }
}

int main() {
    int* nums = (int *) malloc (N * sizeof(int));
    readArrayFromFile(nums, N, "100k-random.txt");
    // Measure the time before sorting
    clock_t start_time = clock();

    insertionSortUnoptimised(nums, 100000);

    // Measure the time after sorting
    clock_t end_time = clock();

    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    // printf("Sorted array: ");
    // printArray(a, 5);
    printf("Time taken: %f seconds\n", time_taken);

    return 0;
}
```

---

## Linked Lists

### Singly Linked List

```c
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void insertFirst(struct Node **head, int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void insertLast(struct Node **head, int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertFirstN(struct Node **head, int n) {
    int val;
    for (int i = 0; i < n; i++) {
        printf("Enter data for new Node: ");
        scanf("%d", &val);
        insertFirst(head, val);
    }
}

void insertLastN(struct Node **head, int n) {
    int val;
    for (int i = 0; i < n; i++) {
        printf("Enter data for new Node: ");
        scanf("%d", &val);
        insertLast(head, val);
    }
}

void display(struct Node **head) {
    struct Node *current = *head;
    printf("---\n");
    printf("Head: %p\n", *head);
    printf("---\n");
    if (*head == NULL)
    {
        printf("List is empty\n");
        printf("---\n");
        return;
    }

    while (current != NULL) {
        printf("Address: %p\n", current);
        printf("Data: %d\n", current->data);
        printf("Next: %p\n", current->next);
        printf("---\n");
        current = current->next;
    }
}

struct Node * search(struct Node ** head, int target){
    if (*head == NULL)
    {
        printf("List is empty\n");
        printf("---\n");
        return NULL;
    }
    struct Node *current = *head;
    while (current != NULL)
    {
        if (current->data == target)
        {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void insertAfter(struct Node ** head,int target, int data){
    struct Node * prev = search(head, target);
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    struct Node * next = prev->next;
    prev->next = newNode;
    newNode->next = next;
}

void insertBefore(struct Node ** head,int target, int data){
    struct Node * next = search(head, target);
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = next;
    struct Node * current = *head;
    while (current->next != next)
    {
        current = current->next;
    }
    current->next = newNode;
}

void deleteFirst(struct Node ** head){
    if(*head == NULL){
        return;
    }
    struct Node * del = *head;
    *head = del->next;
    free(del);
}

void deleteLast(struct Node ** head){
    if(*head == NULL){
        printf("List is empty\n");
        return;
    }
    struct Node *temp = *head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    struct Node * del = temp->next;
    temp->next = NULL;
    free(del);
}

void deleteNode(struct Node ** head, int target){
    struct Node * targetNode = search(head, target);
    struct Node * current = *head;
    while (current->next != targetNode)
    {
        current = current->next;
    }
    struct Node * del = current->next;
    current->next = del->next;
    free(del);
}

void deleteAfter(struct Node ** head, int target){
    struct Node * prev = search(head, target);
    struct Node * del = prev->next;
    prev->next = del->next;
    free(del);
}


void deleteBefore(struct Node ** head, int target){
    struct Node * next = search(head, target);
    struct Node * current = *head;
    while (current->next->next != next)
    {
        current = current->next;
    }
    struct Node * del = current->next;
    current->next = next;
    free(del);
}

int main() {
    struct Node *head = NULL;
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    display(&head);
    insertLastN(&head, n);
    display(&head);
    printf("Enter value to search: ");
    int target;
    scanf("%d", &target);
    struct Node *result = search(&head, target);
    if (result != NULL)
    {
        printf("Element found at %p\n", result);
    } else {
        printf("Element not found\n");
    }
    for (int i = 0; i < 5; i++)
    {
        insertLast(&head, i);
    }
    display(&head);
    printf("Enter value before which you want to insert: ");
    int target;
    scanf("%d", &target);
    printf("Enter value to insert: ");
    int data;
    scanf("%d", &data);
    insertBefore(&head, target, data);
    display(&head);
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    insertLastN(&head, n);
    display(&head);
    printf("Enter value after which you want to delete: ");
    int target;
    scanf("%d", &target);
    deleteAfter(&head, target);
    display(&head);
    printf("Enter value before which you want to delete: ");
    scanf("%d", &target);
    deleteBefore(&head, target);
    display(&head);
    printf("Enter value to delete: ");
    scanf("%d", &target);
    deleteNode(&head, target);
    display(&head);

    return 0;
}
```

### Doubly Linked List

```c
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node * next, * prev;
};

struct Node * getNode(int val){
    struct Node * newNode = (struct Node *) malloc(sizeof(struct Node *));
    newNode->data = val;
    newNode->next = NULL;
    newNode->prev = NULL;
}

void insertFirst(struct Node ** head, int val){
    if (*head == NULL)
    {
    struct Node * newNode = getNode(val);
    *head = newNode;
    }

    struct Node * newNode = getNode(val);
    newNode->next = *head;
    newNode->next->prev = newNode;
    *head = newNode;
}

void display(struct Node * head){
    struct Node *current = head;
    printf("---\n");
    printf("Head: %p\n", head);
    printf("---\n");
    if (head == NULL)
    {
        printf("List is empty\n");
        printf("---\n");
        return;
    }
    while (current != NULL) {
        printf("Address: %p\n", current);
        printf("Data: %d\n", current->data);
        printf("Prev: %p\n", current->prev);
        printf("Next: %p\n", current->next);
        printf("---\n");
        current = current->next;
    }
}

void InsertLast(struct Node ** head, int val){
    if (*head == NULL)
    {
        struct Node * newNode = getNode(val);
        *head = newNode;
        return;
    }

    struct Node * newNode = getNode(val);
    struct Node * current = *head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;
}

struct Node * search(struct Node ** head, int target){
    if (*head == NULL)
    {
        printf("List is empty\n");
        printf("---\n");
        return NULL;
    }
    struct Node *current = *head;
    while (current != NULL)
    {
        if (current->data == target)
        {
            return current;
        }
        current = current->next;
    }
    return NULL;
}


void insertBefore(struct Node ** head,int target, int data){
    struct Node * next = search(head, target);
    struct Node *newNode = getNode(data);
    newNode->next = next;
    newNode->prev = next->prev;
    newNode->prev->next = newNode;
    next->prev = newNode;
}

void insertAfter(struct Node ** head, int target, int val){
    struct Node * prev = search(head, target);
    struct Node * newNode = getNode(val);
    newNode->prev = prev;
    newNode->next = prev->next;
    prev->next = newNode;
    newNode->next->prev = newNode;
}

void deleteFirst(struct Node ** head){
    if(*head == NULL){
        return;
    }
    struct Node * del = *head;
    *head = del->next;
    (*head)->prev = NULL;
    free(del);
}


void deleteNode(struct Node * node){
    if (node == NULL)
    {
        printf("Node not found\n");
        return;
    }
    if (node->next == NULL)
    {
        node->prev->next = NULL;
        free(node);
        return;
    }
    node->prev->next = node->next;
    node->next->prev = node->prev;
    free(node);
}

void deleteLast(struct Node ** head){
    if(*head == NULL){
        printf("List is empty\n");
        return;
    }
    struct Node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    deleteNode(temp);
}
void deleteNodeOf(struct Node ** head, int val){
    struct Node * del = search(head, val);
    deleteNode(del);
}

void deleteBefore(struct Node ** head, int target){
    struct Node * next = search(head, target);
    deleteNode(next->prev);
}

void deleteAfter(struct Node ** head, int target){
    struct Node * prev = search(head, target);
    deleteNode(prev->next);
}

int main(){
    struct Node * head = NULL;
    display(head);
    insertFirst(&head, 1);
    insertFirst(&head, 2);
    display(head);
    insertFirst(&head, 3);
    display(head);
}
```

### Circular Linked List

```c
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node * getNode(int val){
    struct Node * newNode = (struct Node *) malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    newNode->prev = NULL;
}

void insertFirst(struct Node ** head, int val){
    struct Node * newNode = getNode(val);
    if(*head == NULL){
        newNode->next = newNode;
        newNode->prev = newNode;
        *head = newNode;
        return;
    }
    newNode->next = *head;
    struct Node * last = (*head)->prev;
    (*head)->prev = newNode;
    newNode->prev = last;
    last->next = newNode;
    *head = newNode;
}

void insertLast(struct Node ** head, int val){
    struct Node * newNode = getNode(val);
    if(*head == NULL){
        newNode->next = newNode;
        newNode->prev = newNode;
        *head = newNode;
        return;
    }
    struct Node * last = (*head)->prev;
    last->next = newNode;
    newNode->prev = last;
    newNode->next = *head;
    (*head)->prev = newNode;
}

void display(struct Node * head){
    struct Node *current = head;
    printf("---\n");
    printf("Head: %p\n", head);
    printf("---\n");
    if (head == NULL)
    {
        printf("List is empty\n");
        printf("---\n");
        return;
    }
    do
    {
        printf("Address: %p\n", current);
        printf("Data: %d\n", current->data);
        printf("Prev: %p\n", current->prev);
        printf("Next: %p\n", current->next);
        printf("---\n");
        current = current->next;
    } while (current != head);
}

struct Node * search(struct Node ** head, int target){
    if (*head == NULL)
    {
        printf("List is empty\n");
        printf("---\n");
        return NULL;
    }
    struct Node *current = *head;
    do
    {
        if (current->data == target)
        {
            return current;
        }
        current = current->next;
    } while (current != NULL);
    return NULL;
}

void insertBefore(struct Node ** head,int target, int data){
    struct Node * next = search(head, target);
    struct Node *newNode = getNode(data);
    newNode->next = next;
    newNode->prev = next->prev;
    newNode->prev->next = newNode;
    next->prev = newNode;
}

void insertAfter(struct Node ** head, int target, int val){
    struct Node * prev = search(head, target);
    struct Node * newNode = getNode(val);
    newNode->prev = prev;
    newNode->next = prev->next;
    prev->next = newNode;
    newNode->next->prev = newNode;
}

void deleteNode(struct Node * node){
    if (node == NULL)
    {
        printf("Node not found\n");
        return;
    }
    node->prev->next = node->next;
    node->next->prev = node->prev;
    free(node);
}

void deleteFirst(struct Node ** head){
    if(*head == NULL){
        printf("List is empty\n");
        return;
    }
    struct Node * del = *head;
    deleteNode(del);
}

void deleteLast(struct Node ** head){
    if(*head == NULL){
        printf("List is empty\n");
        return;
    }
    struct Node *del = (*head)->prev;
    deleteNode(del);
}

void deleteBefore(struct Node ** head, int target){
    struct Node * next = search(head, target);
    deleteNode(next->prev);
}

void deleteAfter(struct Node ** head, int target){
    struct Node * prev = search(head, target);
    deleteNode(prev->next);
}

int main(){
    struct Node * head = NULL;
    display(head);
    insertFirst(&head, 1);
    insertFirst(&head, 2);
    insertFirst(&head, 3);
    display(head);
    insertLast(&head, 4);
    insertLast(&head, 5);
    display(head);
    return 0;
}
```

---

## Arrays and Linked Lists leetcode questions

## 1. Find the Highest Altitude - 1732 | `Easy`

### Problem Statement

There is a biker going on a road trip. The road trip consists of n + 1 points at different altitudes. The biker starts his trip on point 0 with altitude equal 0.

You are given an integer array gain of length n where gain[i] is the net gain in altitude between points i​​​​​​ and i + 1 for all (0 <= i < n). Return the highest altitude of a point.

### Solution

```java
class Solution {
    public int largestAltitude(int[] gain) {
        int[] alt = new int[gain.length + 1];
        alt[0] = 0;
        int max = 0;
        for(int i = 1; i < alt.length; i++){
            alt[i] = alt[i-1] + gain[i-1];
            if(alt[i] > max){
                max = alt[i];
            }
        }
        return max;
    }
}
```

### Complexity Analysis

- Time Complexity: O(n)
- Space Complexity: O(n)

### Runtime Stats

- Runtime: `0 ms`, faster than `100.00%` of Java online submissions for Find the Highest Altitude.
- Memory Usage: `41.2 MB`, less than `6.57%` of Java online submissions for Find the Highest Altitude.

---

## 2. Cells with Odd Values in a Matrix - 1252 | `Easy`

### Problem Statement

There is an m x n matrix that is initialized to all 0's. There is also a 2D array indices where each indices[i] = [ri, ci] represents a 0-indexed location to perform some increment operations on the matrix.

For each location indices[i], do both of the following:

Increment all the cells on row ri.
Increment all the cells on column ci.
Given m, n, and indices, return the number of odd-valued cells in the matrix after applying the increment to all locations in indices.

### Solution

```java
class Solution {
    public int oddCells(int m, int n, int[][] indices) {
        int[][] matrix = new int[m][n];
        for(int[] index: indices){
            for(int c = 0; c < n; c++){
                matrix[index[0]][c]++;
            }
            for(int r = 0; r < m; r++){
                matrix[r][index[1]]++;
            }
        }
        int count = 0;
        for(int[] row: matrix){
            for(int col: row){
                if(col % 2 == 1){
                    count++;
                }
            }
        }
        return count;
    }
}
```

### Complexity Analysis

- Time Complexity: O(indices.length \* (mn))
- Space Complexity: O(mn)

### Runtime Stats

- Runtime: `2 ms`, faster than `64.40%` of Java online submissions for Cells with Odd Values in a Matrix.
- Memory Usage: `40.8 MB`, less than `19.49%` of Java online submissions for Cells with Odd Values in a Matrix.

---

## 3. Matrix Diagonal Sum - 1572 | `Easy`

### Problem Statement

Given a square matrix mat, return the sum of the matrix diagonals.

Only include the sum of all the elements on the primary diagonal and all the elements on the secondary diagonal that are not part of the primary diagonal.

### Solution

```java
class Solution {
    public int diagonalSum(int[][] mat) {
        int size = mat.length - 1;
        // here size refers to max index
        int sum = 0;
        for(int i = 0; i <= size; i++){
            sum += mat[i][i];
            sum += mat[i][size - i];
        }
        // mid element is subtracted from even size as size here is max index hence odd size
        if(size %2 == 0){
            return sum - mat [size / 2][size / 2];
        }
        return sum;
    }
}
```

### Complexity Analysis

- Time Complexity: O(n)
- Space Complexity: O(1)

### Runtime Stats

- Runtime: `0 ms`, faster than `100.00%` of Java online submissions for Matrix Diagonal Sum.
- Memory Usage: `43.6 MB`, less than `77.92%` of Java online submissions for Matrix Diagonal Sum.

---

## 4. Convert Binary Number in a Linked List - 1290 | `Easy`

### Problem Statement

Given head which is a reference node to a singly-linked list. The value of each node in the linked list is either 0 or 1. The linked list holds the binary representation of a number.

Return the decimal value of the number in the linked list.

The most significant bit is at the head of the linked list.

### Solution

```java
class Solution {
    public int getDecimalValue(ListNode head) {
        ListNode temp = head;
        int size = 0;
        while(temp != null){
            temp = temp.next;
            size++;
        }
        System.out.print(size);
        int res = 0;
        temp = head;
        for(int i = size-1; i >= 0; i--){
            res += (temp.val * Math.pow(2, i));
            temp = temp.next;
        }
        return res;
    }
}
```

### Complexity Analysis

- Time Complexity: O(n^2)
- Space Complexity: O(1)

### Runtime Stats

- Runtime: `1 ms`, faster than `20.85%` of Java online submissions for Convert Binary Number in a Linked List.
- Memory Usage: `39.9 MB`, less than `52.66%` of Java online submissions for Convert Binary Number in a Linked List.

---

## 5. Merge Two Sorted Lists - 21 | `Easy`

### Problem Statement

You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

### Solution

```java
class Solution {
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        ListNode current = new ListNode();
        ListNode head = current;

        while(list1 != null && list2 != null){
            if(list1.val < list2.val){
                current.next = list1;
                list1 = list1.next;
                current = current.next;
            } else {
                current.next = list2;
                list2 = list2.next;
                current = current.next;
            }
        }

        if(list1 != null){
            current.next = list1;
        } else {
            current.next = list2;
        }
        return head.next;
    }
}
```

### Complexity Analysis

- Time Complexity: O(n)
- Space Complexity: O(1)

### Runtime Stats

- Runtime: `0 ms`, faster than `100.00%` of Java online submissions for Merge Two Sorted Lists.
- Memory Usage: `41.3 MB`, less than `60.7%` of Java online submissions for Merge Two Sorted Lists.

---

## 6. Linked List Cycle - 141 | `Easy`

### Problem Statement

Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.

### Solution

```java
public class Solution {
    public boolean hasCycle(ListNode head) {
        ListNode slow = head;
        ListNode fast = head;
        while(fast != null && fast.next != null){
            slow = slow.next;
            fast = fast.next.next;
            if(slow == fast){
                return true;
            }
        }
        return false;
    }
}
```

### Complexity Analysis

- Time Complexity: O(n)
- Space Complexity: O(1)

### Runtime Stats

- Runtime: `0 ms`, faster than `100.00%` of Java online submissions for Linked List Cycle.
- Memory Usage: `43.4 MB`, less than `59.93%` of Java online submissions for Linked List Cycle.

---

## 7. Set Matrix Zeros - 73 | `Medium`

### Problem Statement

Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place.

### Solution

```java
class Solution {
    public void setZeroes(int[][] matrix) {
        int m = matrix.length;
        int n = matrix[0].length;
        int[] zero_rows = new int[m];
        int[] zero_cols = new int[n];
        Arrays.fill(zero_rows, 0);
        Arrays.fill(zero_cols, 0);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 0){
                    if(zero_rows[i] == 0){
                        zero_rows[i] = 1;
                    }
                    if(zero_cols[j] == 0){
                        zero_cols[j] = 1;
                    }
                }
            }
        }
        System.out.println(Arrays.toString(zero_rows));
        System.out.println(Arrays.toString(zero_cols));
        for(int i = 0; i < m; i++){
            if(zero_rows[i] == 1){
                for(int j = 0; j < n; j++){
                    matrix[i][j] = 0;
                }
            } else {
                for(int j = 0; j < n; j++){
                    if(zero_cols[j] == 1){
                        matrix[i][j] = 0;
                    }
                }
            }
        }
    }
}
```

### Complexity Analysis

- Time Complexity: O(mn)
- Space Complexity: O(m+n)

### Runtime Stats

- Runtime: `4 ms`, faster than `7.34%` of Java online submissions for Set Matrix Zeroes.
- Memory Usage: `44.6 MB`, less than `58.23%` of Java online submissions for Set Matrix Zeroes.

---

## 8. House Robber - 198 | `Medium`

### Problem Statement

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

### Solution

```java
int isLootable(int h1, int h2){
    return ((h1 - h2 == 1)||(h2 - h1 == 1)) ? 0 : 1;
}

int rob(int* nums, int numsSize){
    int loot[numsSize];
    for(int i = 0; i < numsSize; i++){
        loot[i] = nums[i];
        int lootablesSize = i > 1 ? i-1 : 1;
        int lootablesArray[lootablesSize];
        int lootables = 0;
        for(int j = 0; j < i-1; j++){
            if(isLootable(j,i)){
                lootablesArray[lootables] = j;
                lootables++;
            }
        }
        int max = 0;
        for(int k=0; k < lootables; k++){
            if(loot[lootablesArray[k]] > max){
                max = loot[lootablesArray[k]];
            }
        }
        loot[i] = nums[i] + max;
    }

    int maxLoot=0;
    for(int i = 0; i < numsSize; i++){
        if(loot[i] > maxLoot){
            maxLoot = loot[i];
        }
    }
    return maxLoot;
}
```

### Complexity Analysis

- Time Complexity: O(n^2)
- Space Complexity: O(n)

### Runtime Stats

- Runtime: `3 ms`, faster than `45.74%` of C online submissions for House Robber.
- Memory Usage: `5.6 MB`, less than `90.70%` of C online submissions for House Robber.

---

## 9. Spiral Matrix - 54 | `Medium`

### Problem Statement

Given an m x n matrix, return all elements of the matrix in spiral order.

![Alt text](https://assets.leetcode.com/uploads/2020/11/13/spiral1.jpg)

### Solution

```java
class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        int rows = matrix.length;
        int cols = matrix[0].length;
        int res_len = rows * cols;
        int rotationsLimit = rows > cols ? (rows/2)+1 : (cols/2)+1;
        int i = 0, j = 0;
        List<Integer> res = new ArrayList<Integer>();
        for(int r = 0; r < rotationsLimit; r++){
            j = r;
            for(int j1 = j ; j1 < cols - r; j1++){
                j = j1;
                res.add(matrix[i][j]);
            }
            if(res.size() == res_len){
                break;
            }
            for(int i1 = i + 1; i1 < rows - r; i1++){
                i = i1;
                res.add(matrix[i][j]);
            }
            if(res.size() == res_len){
                break;
            }
            for(int j1 = j - 1; j1 >= r; j1--){
                j = j1;
                res.add(matrix[i][j]);
            }
            if(res.size() == res_len){
                break;
            }
            for(int i1 = i - 1; i1 > r; i1--){
                i = i1;
                res.add(matrix[i][j]);
            }
        }
        return res;
        }
    }
```

### Complexity Analysis

- Time Complexity: O(n^2)
- Space Complexity: O(n)

### Runtime Stats

- Runtime: `0 ms`, faster than `100.00%` of Java online submissions for Spiral Matrix.
- Memory Usage: `40.7 MB`, less than `35.76%` of Java online submissions for Spiral Matrix.

---

## 10. Add Two Numbers - 2 | `Medium`

### Problem Statement

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

### Solution

```java
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode current = new ListNode();
        ListNode res = current;
        int carry = 0;
        // adding digits when both lists have digits
        while(l1 != null && l2 != null){
            int dig = l1.val + l2.val + carry;
            carry = dig / 10;
            ListNode digit = new ListNode(dig % 10);
            current.next = digit;
            l1 = l1.next;
            l2 = l2.next;
            current = current.next;
        }
        // adding digits when l1 has digits
        while(l1 != null){
            int dig = l1.val + carry;
            carry = dig / 10;
            ListNode digit = new ListNode(dig % 10);
            current.next = digit;
            l1 = l1.next;
            current = current.next;
        }
        // adding digits when l2 has digits
        while(l2 != null){
            int dig = l2.val + carry;
            carry = dig / 10;
            ListNode digit = new ListNode(dig % 10);
            current.next = digit;
            l2 = l2.next;
            current = current.next;
        }
        // adding carry if any
        if(carry == 1){
            ListNode digit = new ListNode(1);
            current.next = digit;
        }
        return res.next;
    }
}
```

### Complexity Analysis

- Time Complexity: O(n)
- Space Complexity: O(n)
  where n is the length of the longer list

### Runtime Stats

- Runtime: `1 ms`, faster than `100.00%` of Java online submissions for Add Two Numbers.
- Memory Usage: `43 MB`, less than `83.18%` of Java online submissions for Add Two Numbers.

---

## 11. Remove Nth Node From End of List - 19 | `Medium`

### Problem Statement

Given the head of a linked list, remove the nth node from the end of the list and return its head.

### Solution

```java
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode temp = head;
        int size = 0;
        while(temp != null){
            size++;
            temp = temp.next;
        }
        if(size == 1){
            return null;
        }
        if(size == n){
            return head.next;
        }
        temp = head;
        for(int i = 1; i < size-n; i++){
            temp = temp.next;
        }
        System.out.print(temp.next.val);
        temp.next = (n == 1)? null : temp.next.next;
        return head;
    }
}
```

### Complexity Analysis

- Time Complexity: O(n)
- Space Complexity: O(1)

### Runtime Stats

- Runtime: `2 ms`, faster than `6.94%` of Java online submissions for Remove Nth Node From End of List.
- Memory Usage: `40.2 MB`, less than `93.13%` of Java online submissions for Remove Nth Node From End of List.

---

## 12. Linked List Cycle 2 - 142 | `Medium`

### Problem Statement

Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.

Do not modify the linked list.

### Solution

```java
public class Solution {
    public ListNode detectCycle(ListNode head) {
                ListNode slow = head;
        ListNode fast = head;
        while(fast != null && fast.next != null){
            slow = slow.next;
            fast = fast.next.next;

            if(slow == fast){
                ListNode temp = slow;
                int length = 0;
                do{
                    temp = temp.next;
                    length++;
                } while(temp != slow);
                // now we have the length, so we start the two pointers.
                ListNode first = head;
                ListNode second = head;
                for(int i = 0; i < length; i++){
                    second = second.next;
                }
                while(first != second){
                    first = first.next;
                    second = second.next;
                }
                return first;
            }
        }
        return null;

    }
}
```

### Complexity Analysis

- Time Complexity: O(n)
- Space Complexity: O(1)

### Runtime Stats

- Runtime: `0 ms`, faster than `100.00%` of Java online submissions for Linked List Cycle II.
- Memory Usage: `43.9 MB`, less than `22.49%` of Java online submissions for Linked List Cycle II.

---

## 13. Delete the Middle Node of a Linked List - 2095 | `Medium`

### Problem Statement

You are given the head of a linked list. Delete the middle node, and return the head of the modified linked list.

The middle node of a linked list of size n is the ⌊n / 2⌋th node from the start using 0-based indexing, where ⌊x⌋ denotes the largest integer less than or equal to x.

For n = 1, 2, 3, 4, and 5, the middle nodes are 0, 1, 1, 2, and 2, respectively.

### Solution

```java
class Solution {
    public ListNode deleteMiddle(ListNode head) {
        ListNode temp = head;
        int size = 0;
        while(temp != null){
            size++;
            temp = temp.next;
        }
        if(size == 1){
            return null;
        }
        ListNode prev = head;
        for(int i = 0; i < size/2 - 1; i++){
            prev = prev.next;
        }
        // System.out.print(prev.val);
        prev.next = (prev.next == null)? null : prev.next.next;
        return head;
    }
}
```

### Complexity Analysis

- Time Complexity: O(n)
- Space Complexity: O(1)

### Runtime Stats

- Runtime: `3 ms`, faster than `96.46%` of Java online submissions for Delete Middle of Linked List.
- Memory Usage: `63 MB`, less than `98.28%` of Java online submissions for Delete Middle of Linked List.

---

## 14. Median of Two Sorted Arrays - 4 | `Hard`

### Problem Statement

Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

### Solution

```java
class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int[] res = new int[nums1.length + nums2.length];
        int c1 = 0;
        int c2 = 0;
        int count = 0;
        while(c1 < nums1.length && c2 < nums2.length){
            if(nums1[c1] < nums2[c2]){
                res[count] = nums1[c1];
                c1++;
            } else {
                res[count] = nums2[c2];
                c2++;
            }
            count++;
        }
        if(c1 < nums1.length){
            while(c1 < nums1.length){
                res[count] = nums1[c1];
                c1++;
                count++;
            }
        } else {
            while(c2 < nums2.length){
                res[count] = nums2[c2];
                c2++;
                count++;
            }
        }
        double median;
        System.out.print(Arrays.toString(res));
        if(res.length % 2 == 0){
            median = ((double)res[res.length/2] + (double)res[res.length/2 -1])/2;

        } else {
            median = res[res.length/2];
        }
        System.out.print(median);
        return median;
    }
}
```

### Complexity Analysis

- Time Complexity: O(m + n)
- Space Complexity: O(m + n)

### Runtime Stats

- Runtime: `16 ms`, faster than `6.81%` of Java online submissions for Median of Two Sorted Arrays.
- Memory Usage: `45 MB`, less than `6.28%` of Java online submissions for Median of Two Sorted Arrays.

---

## 15. Reverse Nodes in k-Group - 25 | `Hard`

### Problem Statement

Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.

### Solution

```java
class Solution {
    public ListNode reverseKGroup(ListNode head, int k) {
        int size = 0;
        ListNode current = head;
        while(current != null && size < k){
            size++;
            current = current.next;
        }
        if(size < k){
            return head;
        }
        ListNode nextRec = current;
        ListNode prev = null;
        current = head;
        System.out.println(current.val);
        for(int i = 0; i < k; i++){
            ListNode next = current.next;
            current.next = prev;
            prev = current;
            current = next;
        }
        head.next = reverseKGroup(nextRec, k);
        return prev;
    }
}
```

### Complexity Analysis

- Time Complexity: O(n)
- Space Complexity: O(1)

### Runtime Stats

- Runtime: `4 ms`, faster than `6.84%` of Java online submissions for Reverse Nodes in k-Group.
- Memory Usage: `42.8 MB`, less than `92.87%` of Java online submissions for Reverse Nodes in k-Group.

---

## Polynomial addition using linked lists

```c
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    float coeff;
    int exp;
    struct Node *next;
};

void display(struct Node *head){
    struct Node *current = head;
    printf("---\n");
    printf("Head: %p\n", head);
    printf("---\n");
    if (head == NULL)
    {
        printf("List is empty\n");
        printf("---\n");
        return;
    }
    while (current != NULL)
    {
        printf("%.2f X^%d", current->coeff, current->exp);
        if (current->next != NULL)
        {
            printf(" + ");
        }
        current = current->next;
    }
    printf("\n");
    printf("---\n");
}

void insertTerm(struct Node **head, float coeff, int exp){
    struct Node * same = (struct Node *) malloc(sizeof(struct Node));
    while(same->next != NULL){
        if(same->exp == exp){
            same->coeff += coeff;
            return;
        }
    }
    struct Node *newTerm = (struct Node *) malloc(sizeof(struct Node));
    newTerm->coeff = coeff;
    newTerm->exp = exp;
    same = *head;
    newTerm->next = NULL;
    if (*head == NULL)
    {
        *head = newTerm;
        return;
    }
    if ((*head)->exp < exp)
    {
        newTerm->next = *head;
        *head = newTerm;
        return;
    }
    struct Node *current = *head;
    while (current->next != NULL && current->next->exp > exp)
    {
        current = current->next;
    }
    newTerm->next = current->next;
    current->next = newTerm;
}

void createPolynomial(struct Node **head){
    int n;
    float coeff;
    int exp;
    printf("Enter number of terms: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter coefficient: ");
        scanf("%f", &coeff);
        printf("Enter exponent: ");
        scanf("%d", &exp);
        insertTerm(head, coeff, exp);
    }
}

void addPolynomials(struct Node **head1, struct Node **head2, struct Node **head3){
    struct Node *current1 = *head1;
    struct Node *current2 = *head2;
    while (current1 != NULL && current2 != NULL)
    {
        if (current1->exp > current2->exp)
        {
            insertTerm(head3, current1->coeff, current1->exp);
            current1 = current1->next;
        }
        else if (current1->exp < current2->exp)
        {
            insertTerm(head3, current2->coeff, current2->exp);
            current2 = current2->next;
        }
        else
        {
            insertTerm(head3, current1->coeff + current2->coeff, current1->exp);
            current1 = current1->next;
            current2 = current2->next;
        }
    }
    if (current1 != NULL)
    {
        struct Node * temp = (struct Node *) malloc(sizeof(struct Node));
        temp = *head3;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = current1;
    }
    else if (current2 != NULL)
    {
        struct Node * temp = (struct Node *) malloc(sizeof(struct Node));
        temp = *head3;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = current2;
    }
}

int main(){
    struct Node *head1 = NULL;
    struct Node *head2 = NULL;
    struct Node *head3 = NULL;
    createPolynomial(&head1);
    createPolynomial(&head2);
    display(head1);
    display(head2);
    addPolynomials(&head1, &head2, &head3);
    display(head3);
    return 0;
}
```

---

## Stacks

### Stack implementation using Arrays

```c
#include <stdio.h>
#include <stdlib.h>

void push(int * arr, int * top, int data, int size){
    if(*top >= size - 1){
        printf("Overflow!\n");
        return;
    }
    arr[++(*top)] = data;
    return;
}

int pop(int * arr, int * top){
    if(*top == -1){
        printf("Underflow!\n");
        return -99999999;
    }
    return arr[(*top)--];
}

void printArray(int * arr, int top){
    if(top == -1){
        printf("Stack is empty\n");
        return;
    }
    for(int i = 0; i <= top; i++){
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

int main() {
    int stack_size = 50;
    int * stack = (int *) malloc (stack_size * sizeof(int));
    int top = -1;
    int choice;
    printf("---\n");
    printf("1 - push and print\n");
    printf("2 - pop and print\n");
    printf("3 - exit\n");
    printf("---\n");
    do{
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("---\n");
        switch(choice){
            case 1:
                printf("Enter number to push: ");
                int val;
                scanf("%d", &val);
                push(stack, &top, val, stack_size);
                printArray(stack, top);
                break;
            case 2:
                printf("Popped element: %d\n", pop(stack, &top));
                printArray(stack, top);
                break;
            case 3:
                printf("exit\n");
                break;
        }

    } while (choice != 3);
}
```

---

### Stack implementation using Linked Lists

```c
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Stack{
    struct Node *top;
    int size;
};

struct Stack* createStack(){
    struct Stack *stack = (struct Stack*) malloc (sizeof(struct Stack));
    stack->top = NULL;
    stack->size = 0;
    return stack;
}

void push(struct Stack *stack, int data){
    struct Node *node = (struct Node*) malloc (sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    if(stack->top == NULL){
        stack->top = node;
    }
    else{
        stack->top->next = node;
        node->prev = stack->top;
        stack->top = node;
    }
    stack->size++;
    return;
}

int pop(struct Stack *stack){
    if(stack->top == NULL){
        printf("Underflow!\n");
        return -1;
    }
    int data = stack->top->data;
    struct Node *temp = stack->top;
    stack->top = stack->top->prev;
    free(temp);
    stack->size--;
    return data;
}

void printStack(struct Stack *stack){
    struct Node *temp = stack->top;
    while (temp != NULL)
    {
        printf("|%d| \n", temp->data);
        temp = temp->prev;
    }
    printf("---\n");
    return;
}

int main(){
    struct Stack *stack = createStack();
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    printStack(stack);
    printf("%d\n", pop(stack));
    printf("%d\n", pop(stack));
    printf("%d\n", pop(stack));
    printf("%d\n", pop(stack));
    printStack(stack);
    return 0;
}
```

---

### Stack implementation using Queues

```c
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Queue{
    struct Node *front;
    struct Node *rear;
    int size;
};

struct Queue* createQueue(){
    struct Queue *queue = (struct Queue*) malloc (sizeof(struct Queue));
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
    return queue;
}

struct Stack{
    struct Queue *queue1;
    struct Queue *queue2;
    int size;
};

struct Stack* createStack(){
    struct Stack *stack = (struct Stack*) malloc (sizeof(struct Stack));
    stack->queue1 = createQueue();
    stack->queue2 = createQueue();
    stack->size = 0;
    return stack;
}

struct Node* getNode(int data){
    struct Node *node = (struct Node*) malloc (sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

void enqueue(struct Queue *queue, int data){
    struct Node *node = getNode(data);
    if(queue->front == NULL){
        queue->front = node;
        queue->rear = node;
    }
    else{
        queue->rear->next = node;
        node->prev = queue->rear;
        queue->rear = node;
    }
    queue->size++;
    return;
}

int dequeue(struct Queue *queue){
    if(queue->front == NULL){
        printf("Underflow!\n");
        return -1;
    }
    int data = queue->front->data;
    struct Node *temp = queue->front;
    queue->front = queue->front->next;
    if(queue->front == NULL){
        queue->rear = NULL;
    }
    else{
        queue->front->prev = NULL;
    }
    free(temp);
    queue->size--;
    return data;
}

void push(struct Stack *stack, int data){
    enqueue(stack->queue1, data);
    stack->size++;
    return;
}

int pop(struct Stack *stack){
    if(stack->queue1->front == NULL){
        printf("Underflow!\n");
        return -1;
    }
    while (stack->queue1->size > 1)
    {
        enqueue(stack->queue2, dequeue(stack->queue1));
    }
    int data = dequeue(stack->queue1);
    struct Queue *temp = stack->queue1;
    stack->queue1 = stack->queue2;
    stack->queue2 = temp;
    stack->size--;
    return data;
}

void printStack(struct Stack *stack){
    struct Node *temp = stack->queue1->rear;
    while (temp != NULL)
    {
        printf("|%d| \n", temp->data);
        temp = temp->prev;
    }
    printf("---\n");
    return;
}

int main(){
    struct Stack *stack = createStack();
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    printStack(stack);
    printf("%d\n", pop(stack));
    printf("%d\n", pop(stack));
    printf("%d\n", pop(stack));
    printf("%d\n", pop(stack));
    printStack(stack);
    return 0;
}
```

---

### Valid Parentheses - 20 | `Easy`

#### Problem Statement

Given a string s containing just the characters `'('`, `')'`, `'{'`, `'}'`, `'['` and `']'`, determine if the input string is valid.

An input string is valid if:

1. Open brackets must be closed by the same type of brackets.
2. Open brackets must be closed in the correct order.
3. Every close bracket has a corresponding open bracket of the same type.

#### Solution

```c
void push(char * arr, int * top, char data, int size){
    if(*top >= size - 1){
        printf("Overflow!\n");
        return;
    }
    arr[++(*top)] = data;
    return;
}
char pop(char * arr, int * top){
    if(*top == -1){
        printf("Underflow!\n");
        return ' ';
    }
    return arr[(*top)--];
}


bool isValid(char* s) {
    int len = strlen(s);
    char * stack = (char *) malloc (len * sizeof(char));
    int top = -1;
    for (int i = 0; i < len; i++)
    {
        if(s[i] == '(' || s[i] == '{' || s[i] == '['){
            push(stack, &top, s[i], len);
        }
        else if(s[i] == ')'){
            if(pop(stack, &top) != '('){
                return 0;
            }
        }
        else if(s[i] == '}'){
            if(pop(stack, &top) != '{'){
                return 0;
            }
        }
        else if(s[i] == ']'){
            if(pop(stack, &top) != '['){
                return 0;
            }
        }
    }
    if(top == -1)    return 1;
    return 0;
}
```

#### Complexity Analysis

- Time Complexity: O(n)
- Space Complexity: O(n)

#### Runtime Stats

- Runtime: `3 ms`, faster than `42.5%` of C online submissions for Valid Parentheses.
- Memory Usage: `6.69 MB`, less than `17.02%` of C online submissions for Valid Parentheses.

---

### Baseball Game - 682 | `Easy`

#### Problem Statement

You are keeping the scores for a baseball game with strange rules. At the beginning of the game, you start with an empty record.

You are given a list of strings operations, where operations[i] is the ith operation you must apply to the record and is one of the following:

- An integer x.
  Record a new score of x.
- '+'.
  Record a new score that is the sum of the previous two scores.
- 'D'.
  Record a new score that is the double of the previous score.
- 'C'.
  Invalidate the previous score, removing it from the record.
  Return the sum of all the scores on the record after applying all the operations.

The test cases are generated such that the answer and all intermediate calculations fit in a 32-bit integer and that all operations are valid.

#### Solution

```c
void pushInt(int * arr, int * top, int data, int size){
    if(*top >= size - 1){
        printf("Overflow!\n");
        return;
    }
    arr[++(*top)] = data;
    return;
}


int popInt(int * arr, int * top){
    if(*top == -1){
        printf("Underflow!\n");
        return -99999999;
    }
    return arr[(*top)--];
}

int calPoints(char** operations, int operationsSize) {
    int * stack = (int *) malloc (operationsSize * sizeof(int));
    int top = -1;
    for(int i=0;i < operationsSize; i++){
        if(operations[i][0] == '+'){
            int temp = popInt(stack, &top);
            int temp2 = popInt(stack, &top);
            pushInt(stack, &top, temp2, operationsSize);
            pushInt(stack, &top, temp, operationsSize);
            pushInt(stack, &top, temp + temp2, operationsSize);
        }
        else if(operations[i][0] == 'D'){
            int temp = popInt(stack, &top);
            pushInt(stack, &top, temp, operationsSize);
            pushInt(stack, &top, temp * 2, operationsSize);
        }
        else if(operations[i][0] == 'C'){
            popInt(stack, &top);
        }
        else {
            int temp = atoi(operations[i]);
            pushInt(stack, &top, temp, operationsSize);
        }
    }
    int res = 0;
    while(top > -1){
        res += popInt(stack, &top);
    }
    return res;
}
```

#### Complexity Analysis

- Time Complexity: O(n)
- Space Complexity: O(n)

#### Runtime Stats

- Runtime: `0 ms`, faster than `100.00%` of C online submissions for Baseball Game.
- Memory Usage: `6.96 MB`, less than `33.46%` of C online submissions for Baseball Game.

---

## Infix to Postfix Conversion

```c
int precedence(char op){
    switch (op)
    {
    case '+':
    case '-':
        return 1;
        break;
    case '*':
    case '/':
    case '%':
        return 2;
        break;
    case '^':
        return 3;
        break;
    default:
        return 0;
        break;
    }
}

void push(char * arr, int * top, char data, int size){
    if(*top >= size - 1){
        printf("Overflow!\n");
        return;
    }
    arr[++(*top)] = data;
    return;
}

char pop(char * arr, int * top){
    if(*top == -1){
        printf("Underflow!\n");
        return '|';
    }
    return arr[(*top)--];
}

void push_float(float * arr, int * top, float data, int size){
    if(*top >= size - 1){
        printf("Overflow!\n");
        return;
    }
    arr[++(*top)] = data;
    return;
}

float pop_float(float * arr, int * top){
    if(*top == -1){
        printf("Underflow!\n");
        return '|';
    }
    return arr[(*top)--];
}

void printArray(char * arr, int top){
    if(top == -1){
        printf("Stack is empty\n");
        return;
    }
    for(int i = 0; i <= top; i++){
        printf("%c\t", arr[i]);
    }
    printf("\n");
}

char * toPostfix(char * infix){
    int len = strlen(infix);
    char * postfix = (char *) malloc ((len+1) * sizeof(char));
    char * operators = (char *) malloc ((len+1) * sizeof(char));
    int top = -1, pin = -1;
    for (int i = 0; i < len; i++)
    {
        if(infix[i] >= '0' && infix[i] <= '9'){
            postfix[++pin] = infix[i];
            if(i < len - 1 && !isalnum(infix[i+1])){
                postfix[++pin] = ' ';
            }
            continue;
        }
        if (isalnum(infix[i]))
        {
            postfix[++pin] = infix[i];

        }
        else if(infix[i] == '('){
            push(operators, &top, infix[i], len);
        }
        else if (infix[i] == ')') {
            while (top > -1 && operators[top] != '(') {
                postfix[++pin] = pop(operators, &top);
            }
            if (top > -1 && operators[top] == '(') {
                pop(operators, &top);
            } else {
                printf("Invalid expression!\n");
                free(postfix);
                free(operators);
                return NULL;
            }
        }

        else if(precedence(infix[i])){
            char op;
            while ((top > -1 && precedence(operators[top]) >= precedence(infix[i])) && operators[top] != '(')
            {
                postfix[++pin] = pop(operators, &top);
            }
            push(operators, &top, infix[i], len);
        }
    }
    while (top > -1)
    {
        if(operators[top] == '('){
            printf("Invalid expression!\n");
            return NULL;
        }
        postfix[++pin] = pop(operators, &top);
    }
    postfix[++pin] = '\0';
    return postfix;
}
```

---

## Postfix Evaluation

```c
float eval_postfix(char *postfix){
    int len = strlen(postfix);
    float * operands = (float *) malloc (len * sizeof(float)); // change to float array
    int top = -1;
    float current = 0; // change to float
    int digitFlag = 0;
    for (int i = 0; i < len; i++)
    {
        if (postfix[i] == ' ')
        {
            if (digitFlag) { // if we're in the middle of a number, push it to the stack
                push_float(operands, &top, current, len);
                current = 0;
                digitFlag = 0;
            }
            continue;
        }
        if(isdigit(postfix[i])){
            current = current * 10 + (postfix[i] - '0');
            digitFlag = 1; // set the flag to indicate we're in the middle of a number
            continue;
        }
        if(precedence(postfix[i])){
            if (digitFlag) { // if we're in the middle of a number, push it to the stack
                push_float(operands, &top, current, len);
                current = 0;
                digitFlag = 0;
            }
            float op2 = pop_float(operands, &top); // change to pop_float
            float op1 = pop_float(operands, &top); // change to pop_float
            switch (postfix[i])
            {
            case '+':
                push_float(operands, &top, op1 + op2, len); // change to push_float
                break;
            case '-':
                push_float(operands, &top, op1 - op2, len); // change to push_float
                break;
            case '*':
                push_float(operands, &top, op1 * op2, len); // change to push_float
                break;
            case '/':
                if (op2 != 0) {
                    push_float(operands, &top, (float)op1 / op2, len); // change to push_float
                } else {
                    printf("Error: Division by zero\n");
                    return -1;
                }
                break;
            default:
                break;
            }
        }
    }
    return operands[top];
}
```

---

## Queues

### Queue implementation using Arrays

```c
#include <stdio.h>
#include <stdlib.h>

void enqueue(int * arr, int *front, int * rear, int data, int size){
    // empty check
    if (*front == -1 && *rear == -1)
    {
        arr[0] = data;
        *front = 0;
        *rear = 0;
        return;
    }
    // overflow
    if ((*front == 0 && *rear == size-1) || (*front - *rear == 1))
    {
        printf("Overflow!\n");
        return;
    }
    // not overflow, but rear is at end
    if(*rear == size - 1){
        *rear = 0;
        arr[*rear] = data;
        return;
    }
    // normal case
    arr[++(*rear)] = data;
    return;
}

int dequeue(int *arr, int *front, int *rear, int size){
    // empty check
    if (*front == -1 && *rear == -1)
    {
        printf("Empty queue\n");
        return -999999;
    }
    // one element
    if (*front == *rear)
    {
        int data = arr[*front];
        *front = -1;
        *rear = -1;
        return data;
    }
    // front at end
    if (*front == size - 1)
    {
        int data = arr[*front];
        *front = 0;
        return data;
    }
    //normal case
    return arr[(*front)++];
}

void printArray(int * arr, int front, int rear){
    int size = sizeof(arr)/sizeof(int);
    if (front == -1 && rear == -1)
    {
        printf("Empty queue\n");
        return;
    }
    if (rear < front)
    {
        for (int i = front; i < size; i++)
        {
            printf("%d\t", arr[i]);
        }
        for (int i = 0; i <= rear; i++)
        {
            printf("%d\t", arr[i]);
        }
        printf("\n");
        return;
    }
    for (int i = front; i <= rear; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}
```

---

### Queue implementation using Linked Lists

```c
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node * next;
};

struct Queue{
    struct Node * front;
    struct Node * rear;
};

struct Queue * createQueue(){
    struct Queue * q = (struct Queue *)malloc(sizeof(struct Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

void enqueue(struct Queue * queue, int data){
    struct Node * newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    // empty
    if (queue->front == NULL && queue->rear == NULL)
    {
        queue->front = newNode;
        queue->rear = newNode;
        return;
    }
    queue->rear->next = newNode;
    queue->rear = newNode;
}

int dequeue(struct Queue * queue){
    // last element
    if (queue->front == queue->rear)
    {
        int data = queue->front->data;
        queue->front = NULL;
        queue->rear = NULL;
        return data;
    }
    // empty queue
    if (queue->front == NULL && queue->rear == NULL)
    {
        printf("Underflow!\n");
        return -999999;
    }
    int data = queue->front->data;
    queue->front = queue->front->next;
    return data;
}

void printQueue(struct Queue * queue){
    if(queue->front == NULL && queue->rear == NULL){
        printf("Empty queue\n");
        return;
    }
    struct Node * temp = queue->front;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
```

---

### Implement Stack using Queues

```c
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Stack{
    struct Node *top;
    int size;
};

struct Stack* createStack(){
    struct Stack *stack = (struct Stack*) malloc (sizeof(struct Stack));
    stack->top = NULL;
    stack->size = 0;
    return stack;
}

struct Queue{
    struct Stack *stack1;
    struct Stack *stack2;
    int size;
};

struct Queue* createQueue(){
    struct Queue *queue = (struct Queue*) malloc (sizeof(struct Queue));
    queue->stack1 = createStack();
    queue->stack2 = createStack();
    queue->size = 0;
    return queue;
}

struct Node* getNode(int data){
    struct Node *node = (struct Node*) malloc (sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

void push(struct Stack *stack, int data){
    struct Node *node = getNode(data);
    if(stack->top == NULL){
        stack->top = node;
    }
    else{
        stack->top->next = node;
        node->prev = stack->top;
        stack->top = node;
    }
    stack->size++;
    return;
}

int pop(struct Stack *stack){
    if(stack->top == NULL){
        printf("Underflow!\n");
        return -1;
    }
    int data = stack->top->data;
    struct Node *temp = stack->top;
    stack->top = stack->top->prev;
    free(temp);
    stack->size--;
    return data;
}

void enqueue(struct Queue *queue, int data){
    push(queue->stack1, data);
    queue->size++;
    return;
}

int dequeue(struct Queue *queue){
    if(queue->stack1-> size == 0){
        printf("Underflow!\n");
        return -1;
    }
    while (queue->stack1->size != 1)
    {
        push(queue->stack2, pop(queue->stack1));
    }
    int data = pop(queue->stack1);
    while (queue->stack2->size != 0)
    {
        push(queue->stack1, pop(queue->stack2));
    }
    queue->size--;
    return data;
}

void printQueue(struct Queue *queue){
    if(queue->stack1->size == 0){
        printf("Queue is empty!\n");
        return;
    }
    while (queue->stack1->size != 0)
    {
        push(queue->stack2, pop(queue->stack1));
    }
    while (queue->stack2->size != 0)
    {
        int data = pop(queue->stack2);
        printf("|%d| \n", data);
        push(queue->stack1, data);
    }
    printf("---\n");
    return;
}
```

---

### Deque implementation using Arrays

```c
#include <stdio.h>
#include <stdlib.h>

void enqueue_front(int *queue, int *front, int *rear, int data, int size){
    // empty check
    if (*front == -1 && *rear == -1)
    {
        queue[0] = data;
        *front = 0;
        *rear = 0;
        return;
    }
    //overflow
    if((*front == 0 && *rear == size - 1) || (*front - *rear == 1)){
        printf("Overflow!\n");
        return;
    }
    // not overflow, but front is at start
    if(*front == 0){
        *front = size - 1;
        queue[*front] = data;
        return;
    }
    // normal case
    queue[--(*front)] = data;
}

void enqueue_rear(int *queue, int *front, int *rear, int data, int size){
    // empty check
    if (*front == -1 && *rear == -1)
    {
        queue[0] = data;
        *front = 0;
        *rear = 0;
        return;
    }
    //overflow
    if((*front == 0 && *rear == size - 1) || (*front - *rear == 1)){
        printf("Overflow!\n");
        return;
    }
    // not overflow, but rear is at end
    if(*rear == size - 1){
        *rear = 0;
        queue[*rear] = data;
        return;
    }
    // normal case
    queue[++(*rear)] = data;
}

int dequeue_front(int *queue, int *front, int *rear, int size){
    // empty check
    if (*front == -1 && *rear == -1)
    {
        printf("Empty queue\n");
        return -999999;
    }
    // one element
    if (*front == *rear)
    {
        int data = queue[*front];
        *front = -1;
        *rear = -1;
        return data;
    }
    // front at end
    if (*front == size - 1)
    {
        int data = queue[*front];
        *front = 0;
        return data;
    }
    //normal case
    return queue[(*front)++];
}

int dequeue_rear(int *queue, int *front, int *rear, int size){
    // empty check
    if (*front == -1 && *rear == -1)
    {
        printf("Empty queue\n");
        return -999999;
    }
    // one element
    if (*front == *rear)
    {
        int data = queue[*front];
        *front = -1;
        *rear = -1;
        return data;
    }
    // rear at start
    if (*rear == 0)
    {
        int data = queue[*rear];
        *rear = size - 1;
        return data;
    }
    //normal case
    return queue[(*rear)--];
}

void printArray(int * arr, int front, int rear, int size){
    if (front == -1 && rear == -1)
    {
        printf("Empty queue\n");
        return;
    }
    if (rear < front)
    {
        for (int i = front; i < size; i++)
        {
            printf("%d\t", arr[i]);
        }
        for (int i = 0; i <= rear; i++)
        {
            printf("%d\t", arr[i]);
        }
        printf("\n");
        return;
    }
    for (int i = front; i <= rear; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

int main(){
    // menu driven
    int size;
    printf("Enter size of queue: ");
    scanf("%d", &size);
    int * queue = (int *) malloc (size * sizeof(int));
    int front = -1, rear = -1;
    int choice = 0;
    while (choice != 5)
    {
        printf("1. Enqueue front\n2. Enqueue rear\n3. Dequeue front\n4. Dequeue rear\n5. Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter data: ");
            int data;
            scanf("%d", &data);
            enqueue_front(queue, &front, &rear, data, size);
            break;
        case 2:
            printf("Enter data: ");
            scanf("%d", &data);
            enqueue_rear(queue, &front, &rear, data, size);
            break;
        case 3:
            printf("Dequeued %d\n", dequeue_front(queue, &front, &rear, size));
            break;
        case 4:
            printf("Dequeued %d\n", dequeue_rear(queue, &front, &rear, size));
            break;
        case 5:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
        printArray(queue, front, rear, size);
    }
    return 0;
}
```

### Deque implementation using Linked Lists

```c
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node * next;
};

struct Queue{
    struct Node * front;
    struct Node * rear;
};

struct Queue * createQueue(){
    struct Queue * q = (struct Queue *)malloc(sizeof(struct Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

void enqueue_front(struct Queue * queue, int data){
    struct Node * newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    // empty
    if (queue->front == NULL && queue->rear == NULL)
    {
        queue->front = newNode;
        queue->rear = newNode;
        return;
    }
    newNode->next = queue->front;
    queue->front = newNode;
}

void enqueue_rear(struct Queue * queue, int data){
    struct Node * newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    // empty
    if (queue->front == NULL && queue->rear == NULL)
    {
        queue->front = newNode;
        queue->rear = newNode;
        return;
    }
    queue->rear->next = newNode;
    queue->rear = newNode;
}

int dequeue_front(struct Queue * queue){
    // last element
    if (queue->front == queue->rear)
    {
        int data = queue->front->data;
        queue->front = NULL;
        queue->rear = NULL;
        return data;
    }
    // empty queue
    if (queue->front == NULL && queue->rear == NULL)
    {
        printf("Underflow!\n");
        return -999999;
    }
    int data = queue->front->data;
    queue->front = queue->front->next;
    return data;
}

int dequeue_rear(struct Queue * queue){
    // last element
    if (queue->front == queue->rear)
    {
        int data = queue->front->data;
        queue->front = NULL;
        queue->rear = NULL;
        return data;
    }
    // empty queue
    if (queue->front == NULL && queue->rear == NULL)
    {
        printf("Underflow!\n");
        return -999999;
    }
    int data = queue->rear->data;
    struct Node * temp = queue->front;
    while (temp->next != queue->rear)
    {
        temp = temp->next;
    }
    temp->next = NULL;
    queue->rear = temp;
    return data;
}

void printQueue(struct Queue * queue){
    if(queue->front == NULL && queue->rear == NULL){
        printf("Empty queue\n");
        return;
    }
    struct Node * temp = queue->front;
    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    struct Queue * queue = createQueue();
    enqueue_front(queue, 1);
    enqueue_front(queue, 2);
    enqueue_front(queue, 3);
    enqueue_front(queue, 4);
    enqueue_front(queue, 5);
    enqueue_rear(queue, 6);
    enqueue_rear(queue, 7);
    enqueue_rear(queue, 8);
    enqueue_rear(queue, 9);
    enqueue_rear(queue, 10);
    printQueue(queue);
    printf("%d\n", dequeue_front(queue));
    printf("%d\n", dequeue_front(queue));
    printf("%d\n", dequeue_front(queue));
    printf("%d\n", dequeue_front(queue));
    printf("%d\n", dequeue_front(queue));
    printf("%d\n", dequeue_rear(queue));
    printf("%d\n", dequeue_rear(queue));
    printf("%d\n", dequeue_rear(queue));
    printf("%d\n", dequeue_rear(queue));
    printf("%d\n", dequeue_rear(queue));
    printQueue(queue);
    return 0;
}
```

---

## Priority Queues

### Priority Queue implementation using Linked Lists

```c
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    int priority;
    struct Node * next;
};

struct Queue{
    struct Node * front;
    struct Node * rear;
};

struct Queue ** createPriorityQueue(int size){
    struct Queue **pq = (struct Queue **)malloc(sizeof(struct Queue *) * size);
    for (int i = 0; i < size; i++)
    {
        pq[i] = (struct Queue *)malloc(sizeof(struct Queue));
        pq[i]->front = NULL;
        pq[i]->rear = NULL;
    }
    return pq;
}

void enqueue(struct Queue **pq, int data, int priority){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    // empty check
    if (pq[priority]->front == NULL && pq[priority]->rear == NULL)
    {
        newNode->next = NULL;
        pq[priority]->front = newNode;
        pq[priority]->rear = newNode;
        return;
    }
    // non-empty
    pq[priority]->rear->next = newNode;
    pq[priority]->rear = newNode;
    return;
}

int dequeue(struct Queue **pq, int size){
    for(int i = 0; i < size; i++){
        if(pq[i]->front != NULL){
            struct Node *temp = pq[i]->front;
            int data = temp->data;
            pq[i]->front = pq[i]->front->next;
            free(temp);
            return data;
        }
    }
    printf("Queue is empty!\n");
    return -1;
}

void printQueue(struct Queue **pq, int size){
    for(int i = 0; i < size; i++){
        if(pq[i]->front == NULL){
            printf("Queue %d is empty\n", i);
            continue;
        }
        struct Node *temp = pq[i]->front;
        while(temp != NULL){
            printf("%d\t", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main(){
    int size, data, priority, choice;
    printf("Enter the number of queues: ");
    scanf("%d", &size);
    struct Queue **pq = createPriorityQueue(size);
    while (1)
    {
        printf("1. Enqueue\n2. Dequeue\n3. Print\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter data and priority: ");
            scanf("%d %d", &data, &priority);
            enqueue(pq, data, priority);
            break;
        case 2:
            printf("Dequeued %d\n", dequeue(pq, size));
            break;
        case 3:
            printQueue(pq, size);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice!\n");
            break;
        }
    }
    return 0;
}
```

---

## Trees

### Binary tree implementation using Linked Lists

```c
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node * getNode(int data){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void buildTree(struct Node * node){
    int data, choice;
    printf("Do you want to enter left child of %d? (1/0): ", node->data);
    scanf("%d", &choice);
    if (choice == 1)
    {
        printf("Enter data: ");
        scanf("%d", &data);
        node->left = getNode(data);
        buildTree(node->left);
    }
    printf("Do you want to enter right child of %d? (1/0): ", node->data);
    scanf("%d", &choice);
    if (choice == 1)
    {
        printf("Enter data: ");
        scanf("%d", &data);
        node->right = getNode(data);
        buildTree(node->right);
    }
}

void display(struct Node *root){
    if (root == NULL)
    {
        return;
    }
    display(root->left);
    printf("%d ", root->data);
    display(root->right);
}

void display_tree(struct Node *root, int level){
    if (root == NULL)
    {
        return;
    }
    display_tree(root->right, level + 1);
    for (int i = 0; i < level; i++)
    {
        printf("|\t");
    }
    printf("|------>%d\n", root->data);
    display_tree(root->left, level + 1);
}

int main(){
    struct Node *root = NULL;
    int num;
    printf("Enter data: ");
    scanf("%d", &num);
    root = getNode(num);
    buildTree(root);
    display_tree(root, 0);
    return 0;
}
```

---

### Binary Tree implementation using Arrays

```c
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
```

---

### Binary Search Tree implementation using Linked Lists

```c
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node * getNode(int data){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node * bst_iter(struct Node ** root, int num){
    int data;
    for (int i = 0; i < num; i++)
    {
        printf("Enter data: ");
        scanf("%d", &data);
        struct Node *newNode = getNode(data);
        if(*root == NULL){
            *root = newNode;
        }
        else{
            struct Node *temp = *root;
            while(temp != NULL){
                if(data < temp->data){
                    if(temp->left == NULL){
                        temp->left = newNode;
                        break;
                    }
                    else{
                        temp = temp->left;
                    }
                }
                else{
                    if(temp->right == NULL){
                        temp->right = newNode;
                        break;
                    }
                    else{
                        temp = temp->right;
                    }
                }
            }
        }
    }
}

void inorder(struct Node *root){
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(struct Node *root){
    if (root == NULL)
    {
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct Node *root){
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

struct Node * search(struct Node * root, int target, int *child_side){
    if (root == NULL) {
        printf("Not found\n");
        return NULL;
    }
    else if (root->data == target) {
        *child_side = 0;
        return root;
    }
    else if (root->left != NULL && root->left->data == target) {
        *child_side = 1;
        return root;
    }
    else if (root->right != NULL && root->right->data == target) {
        *child_side = 2;
        return root;
    }
    else if (target < root->data) {
        return search(root->left, target, child_side);
    }
    else {
        return search(root->right, target, child_side);
    }
}

struct Node * inorder_successor(struct Node *root, int target){
    int child_side;
    struct Node *parent = search(root, target, &child_side);
    if(parent == NULL){
        printf("Target not found in tree\n");
        return NULL;
    }
    struct Node *temp = NULL;
    if (child_side = 0)
    {
        if (parent -> right != NULL)
        {
            temp = parent -> right;
            while (temp -> left != NULL)
            {
                temp = temp -> left;
            }
            return temp;
        }
        else
        {
            printf("No inorder successor\n");
            return NULL;
        }
    }
    else if (child_side = 1)
    {
        if (parent -> left -> left == NULL && parent -> left -> right == NULL)
        {
            return parent;
        }
        if (parent -> right ->right != NULL)
        {
            temp = parent -> right -> right;
            while (temp -> left != NULL)
            {
                temp = temp -> left;
            }
            return temp;
        }
        else
        {
            return parent;
        }
    }
    else if (child_side = 2)
    {
        while (child_side == 2)
        {
            parent = search(root, parent -> data, &child_side);
        }
        if (child_side == 1)
        {
            return parent;
        }
        else
        {
            printf("No inorder successor\n");
            return NULL;
        }
    }
}

struct Node * inorder_predecessor(struct Node *root, int target){
    int child_side;
    struct Node *parent = search(root, target, &child_side);
    if(parent == NULL){
        printf("Target not found in tree\n");
        return NULL;
    }
    struct Node *temp = NULL;
    if (child_side == 0)
    {
        if (parent -> left != NULL)
        {
            temp = parent -> left;
            while (temp -> right != NULL)
            {
                temp = temp -> right;
            }
            return temp;
        }
        else
        {
            printf("No inorder predecessor\n");
            return NULL;
        }
    }
    else if (child_side == 1)
    {
        if (parent -> left ->left != NULL)
        {
            temp = parent -> left -> left;
            while (temp -> right != NULL)
            {
                temp = temp -> right;
            }
            return temp;
        }
        else
        {
            while (child_side == 1)
            {
                parent = search(root, parent -> data, &child_side);
            }
            if (child_side == 2)
            {
                return parent;
            }
            printf("No inorder predecessor\n");
            return NULL;
        }
    }
    else if (child_side == 2)
    {
        if (parent -> right ->left != NULL)
        {
            temp = parent -> right -> left;
            while (temp -> right != NULL)
            {
                temp = temp -> right;
            }
            return temp;
        }
        else
        {
            return parent;
        }
    }
}

void display(struct Node *root){
    if (root == NULL)
    {
        return;
    }
    display(root->left);
    printf("%d ", root->data);
    display(root->right);
}

void display_tree(struct Node *root, int level){
    if (root == NULL)
    {
        return;
    }
    display_tree(root->right, level + 1);
    for (int i = 0; i < level; i++)
    {
        printf("|\t");
    }
    printf("|------>%d\n", root->data);
    display_tree(root->left, level + 1);
}

struct Node * leftmostRsub(struct Node *root){
    if (root == NULL)
    {
        return NULL;
    }
    if (root->right == NULL)
    {
        root = root->right;
        while(root->left != NULL){
            root = root->left;
        }
        return root;
    }
}

void delete(struct Node ** root, int target){
    int child_side;
    struct Node * parent = search(*root, target, &child_side);
    struct Node * tn = NULL;
    switch (child_side){
        case 0:
            tn = parent;
            break;
        case 1:
            tn = parent->left;
            break;
        case 2:
            tn = parent->right;
            break;
    }
    // no children
    if (tn ->left == NULL && tn->right == NULL)
    {
        switch (child_side)
        {
        case 0:
            printf("root node deleted\n");
            *root = NULL;
            free(tn);
            return;
        case 1:
            parent->left = NULL;
            free(tn);
            return;
        case 2:
            parent->right = NULL;
            free(tn);
            return;
        }
    }
    // only left child
    if (tn->left != NULL && tn->right == NULL)
    {
        printf("only left child\n");
        switch (child_side)
        {
        case 0:
            *root = tn->left;
            free(tn);
            return;
        case 1:
            parent->left = tn->left;
            free(tn);
            return;

        case 2:
            parent->right = tn->left;
            free(tn);
            return;
        }
    }
    // only right child
    if (tn->left == NULL && tn->right != NULL)
    {
        printf("only right child\n");
        switch (child_side)
        {
        case 0:
            *root = tn->right;
            free(tn);
            return;
        case 1:
            parent->left = tn->right;
            free(tn);
            return;

        case 2:
            parent->right = tn->right;
            free(tn);
            return;
        }
    }
    // two children
    struct Node *successor = leftmostRsub(tn);
    printf("successor: %d\n", successor->data);
    int rData = successor->data;
    delete(root, successor->data);
    tn->data = rData;
}

struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;

    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL)
        current = current->left;

    return current;
}
int main(){
    struct Node *root = NULL;
    int num;
    printf("Enter number of nodes: ");
    scanf("%d", &num);
    bst_iter(&root, num);
    display_tree(root, 0);
    printf("Enter element to search: ");
    int target;
    scanf("%d", &target);
    int child_side;
    struct Node *parent = search(root, target, &child_side);
    printf("Parent: %d\n", parent->data);
    switch (child_side)
    {
    case 0:
        printf("this node is the target node\n");
        break;
    case 1:
        printf("Left child\n");
        break;
    case 2:
        printf("Right child\n");
        break;
    default:
        break;
    }
    delete(&root, target);
    display_tree(root, 0);

    return 0;
}

```

---

### Binary Search Tree implementation using Arrays

```c
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

int inorder_successor(int *tree, int target, int num){
    int index = search(tree, target, num);
    if (index == -1)
    {
        printf("Target not found in tree\n");
        return -1;
    }
    if (tree[right_child(index)] != 0)
    {
        int successor = right_child(index);
        while (tree[left_child(successor)] != 0)
        {
            successor = left_child(successor);
        }
        return successor;
    }
    else
    {
        int successor = parent(index);
        while (tree[successor] < tree[index])
        {
            successor = parent(successor);
        }
        return successor;
    }
}

void delete(int *tree, int target, int num){
    int index = search(tree, target, num);
    if (index == -1)
    {
        printf("Target not found in tree\n");
        return;
    }
    // no children
    if (tree[left_child(index)] == 0 && tree[right_child(index)] == 0)
    {
        tree[index] = 0;
        return;
    }
    // only left child
    if (tree[left_child(index)] != 0 && tree[right_child(index)] == 0)
    {
        tree[index] = tree[left_child(index)];
        tree[left_child(index)] = 0;
        return;
    }
    // only right child
    if (tree[left_child(index)] == 0 && tree[right_child(index)] != 0)
    {
        tree[index] = tree[right_child(index)];
        tree[right_child(index)] = 0;
        return;
    }
    // two children
    int successor = right_child(index);
    while (tree[left_child(successor)] != 0)
    {
        successor = left_child(successor);
    }
    tree[index] = tree[successor];
    tree[successor] = 0;
    return;
}

int main(){
    int num;
    printf("Enter number of nodes: ");
    scanf("%d", &num);
    int *tree = bst_iter(num);
    display(tree, 0, num);
    printf("\n--------------------\n");
    display_tree(tree, 0, num, 0);
    printf("\n--------------------\n");
    printf("Inorder: ");
    inorder(tree, 0, num);
    printf("\n--------------------\n");
    printf("Preorder: ");
    preorder(tree, 0, num);
    printf("\n--------------------\n");
    printf("Postorder: ");
    postorder(tree, 0, num);
    printf("\n--------------------\n");
    printf("enter target value: ");
    int target;
    scanf("%d", &target);
    printf("%d", search(tree, target, num));
    return 0;
}
```

---

### Same Tree - 100 | `Easy`

#### Problem Statement

Given the roots of two binary trees p and q, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

#### Solution

```c
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool symRec(struct TreeNode* left, struct TreeNode* right){
    if(left == NULL || right == NULL){
        return 0;
    }
    if(left->val != right->val){
        return 0;
    }

    if(left->left != NULL && right->left != NULL){
        if(symRec(left->left, right->left) == 0){
            return 0;
        }
    } else if(left->left != NULL || right->left != NULL){
        return 0;
    }
    if(left->right != NULL && right->right != NULL){
        if(symRec(left->right, right->right) == 0){
            return 0;
        }
    } else if(left->right != NULL || right->right != NULL){
        return 0;
    }
    return 1;
}
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if(p == NULL && q == NULL){
        return 1;
    }
    return symRec(p, q);
}
```

#### Complexity Analysis

- Time Complexity: O(n)
- Space Complexity: O(n)

#### Runtime Stats

- Runtime: `0 ms`, faster than `100.00%` of C online submissions for Same Tree.
- Memory Usage: `6.38 MB`, less than `93.56%` of C online submissions for Same Tree.

---

### Symmetric Tree - 101 | `Easy`

#### Problem Statement

Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

#### Solution

```c
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool symRec(struct TreeNode* left, struct TreeNode* right){
    if(left == NULL || right == NULL){
        return 0;
    }
    if(left->val != right->val){
        return 0;
    }

    if(left->left != NULL && right->right != NULL){
        if(symRec(left->left, right->right) == 0){
            return 0;
        }
    } else if(left->left != NULL || right->right != NULL){
        return 0;
    }
    if(left->right != NULL && right->left != NULL){
        if(symRec(left->right, right->left) == 0){
            return 0;
        }
    } else if(left->right != NULL || right->left != NULL){
        return 0;
    }
    return 1;
}
bool isSymmetric(struct TreeNode* root) {
    if(root->left == NULL && root->right == NULL){
        return 1;
    }
    return symRec(root->left, root->right);
}
```

#### Complexity Analysis

- Time Complexity: O(n)
- Space Complexity: O(n)

#### Runtime Stats

- Runtime: `0 ms`, faster than `100.00%` of C online submissions for Symmetric Tree.
- Memory Usage: `7.69 MB`, less than `29.83%` of C online submissions for Symmetric Tree.

---

### Lowest Common Ancestor of a Binary Search Tree - 235 | `Medium`

#### Problem Statement

Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

#### Solution

```c
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if(root->val > p->val && root->val > q->val){
        return lowestCommonAncestor(root->left, p, q);}
    else if(root->val < p->val && root->val < q->val){
        return lowestCommonAncestor(root->right, p, q);
    }
    else {
        return root;
    }
}
```

#### Complexity Analysis

- Time Complexity: O(n)
- Space Complexity: O(n)

#### Runtime Stats

- Runtime: `36 ms`, faster than `7.33%` of C online submissions for Lowest Common Ancestor of a Binary Search Tree.
- Memory Usage: `27.6 MB`, less than `36.07%` of C online submissions for Lowest Common Ancestor of a Binary Search Tree.

---

## AVL trees and expression trees

### AVL tree implementation using Linked Lists

```c
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node * getNode(int data){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node * bst_iter(struct Node ** root, int num){
    int data;
    for (int i = 0; i < num; i++)
    {
        printf("Enter data: ");
        scanf("%d", &data);
        struct Node *newNode = getNode(data);
        if(*root == NULL){
            *root = newNode;
        }
        else{
            struct Node *temp = *root;
            while(temp != NULL){
                if(data < temp->data){
                    if(temp->left == NULL){
                        temp->left = newNode;
                        break;
                    }
                    else{
                        temp = temp->left;
                    }
                }
                else{
                    if(temp->right == NULL){
                        temp->right = newNode;
                        break;
                    }
                    else{
                        temp = temp->right;
                    }
                }
            }
        }
    }
}

struct Node * search(struct Node * root, int target, int *child_side){
    if (root -> data == target)
    {
        *child_side = 0;
        return root;
    }
    else if (root -> left -> data == target)
    {
        *child_side = 1;
        return root;
    }
    else if (root -> right -> data == target)
    {
        *child_side = 2;
        return root;
    }
    else if (target < root -> data)
    {
        search(root->left, target, child_side);
    }
    else if (target > root -> data)
    {
        search(root->right, target, child_side);
    }
    else
    {
        printf("Not found\n");
        return NULL;
    }
}

void display_tree(struct Node *root, int level){
    if (root == NULL)
    {
        return;
    }
    display_tree(root->right, level + 1);
    for (int i = 0; i < level; i++)
    {
        printf("|\t");
    }
    printf("|------>%d\n", root->data);
    display_tree(root->left, level + 1);
}

void bst_insert(struct Node **root, int data){
    struct Node *newNode = getNode(data);
    if(*root == NULL){
        *root = newNode;
    }
    else{
        struct Node *temp = *root;
        while(temp != NULL){
            if(data < temp->data){
                if(temp->left == NULL){
                    temp->left = newNode;
                    break;
                }
                else{
                    temp = temp->left;
                }
            }
            else{
                if(temp->right == NULL){
                    temp->right = newNode;
                    break;
                }
                else{
                    temp = temp->right;
                }
            }
        }
    }
}

int height(struct Node *root){
    if(root == NULL){
        return 0;
    }
    else{
        int left_height = height(root->left);
        int right_height = height(root->right);
        if(left_height > right_height){
            return left_height + 1;
        }
        else{
            return right_height + 1;
        }
    }
}

int balance_factor(struct Node *root){
    if(root == NULL){
        return 0;
    }
    else{
        int left_height = height(root->left);
        int right_height = height(root->right);
        return left_height - right_height;
    }
}

struct Node * left_rotate(struct Node *root){
    struct Node *newRoot = root->right;
    root->right = newRoot->left;
    newRoot->left = root;
    return newRoot;
}

struct Node * right_rotate(struct Node *root){
    struct Node *newRoot = root->left;
    root->left = newRoot->right;
    newRoot->right = root;
    return newRoot;
}

struct Node * left_right_rotate(struct Node *root){
    struct Node *newRoot = root->left;
    root->left = left_rotate(newRoot);
    return right_rotate(root);
}

struct Node * right_left_rotate(struct Node *root){
    struct Node *newRoot = root->right;
    root->right = right_rotate(newRoot);
    return left_rotate(root);
}

struct Node * balance(struct Node *root){
    if(root == NULL){
        return NULL;
    }
    else{
        root->left = balance(root->left);
        root->right = balance(root->right);
        int bf = balance_factor(root);
        if(bf > 1){
            if(balance_factor(root->left) > 0){
                root = right_rotate(root);
            }
            else{
                root = left_right_rotate(root);
            }
        }
        else if(bf < -1){
            if(balance_factor(root->right) < 0){
                root = left_rotate(root);
            }
            else{
                root = right_left_rotate(root);
            }
        }
        return root;
    }
}

struct Node * bst_delete(struct Node *root, int data){
    if(root == NULL){
        return NULL;
    }
    else{
        if(data < root->data){
            root->left = bst_delete(root->left, data);
        }
        else if(data > root->data){
            root->right = bst_delete(root->right, data);
        }
        else{
            if(root->left == NULL && root->right == NULL){
                free(root);
                return NULL;
            }
            else if(root->left == NULL){
                struct Node *temp = root->right;
                free(root);
                return temp;
            }
            else if(root->right == NULL){
                struct Node *temp = root->left;
                free(root);
                return temp;
            }
            else{
                struct Node *temp = root->right;
                while(temp->left != NULL){
                    temp = temp->left;
                }
                root->data = temp->data;
                root->right = bst_delete(root->right, temp->data);
            }
        }
        root = balance(root);
        return root;
    }
}

// avl insert
struct Node * avl_insert(struct Node *root, int data){
    if(root == NULL){
        root = getNode(data);
        return root;
    }
    else{
        if(data < root->data){
            root->left = avl_insert(root->left, data);
        }
        else if(data > root->data){
            root->right = avl_insert(root->right, data);
        }
        else{
            printf("Duplicate data!\n");
            return root;
        }
        root = balance(root);
        return root;
    }
}

// avl delete
struct Node * avl_delete(struct Node *root, int data){
    if(root == NULL){
        return NULL;
    }
    else{
        if(data < root->data){
            root->left = avl_delete(root->left, data);
        }
        else if(data > root->data){
            root->right = avl_delete(root->right, data);
        }
        else{
            if(root->left == NULL && root->right == NULL){
                free(root);
                return NULL;
            }
            else if(root->left == NULL){
                struct Node *temp = root->right;
                free(root);
                return temp;
            }
            else if(root->right == NULL){
                struct Node *temp = root->left;
                free(root);
                return temp;
            }
            else{
                struct Node *temp = root->right;
                while(temp->left != NULL){
                    temp = temp->left;
                }
                root->data = temp->data;
                root->right = avl_delete(root->right, temp->data);
            }
        }
        root = balance(root);
        return root;
    }
}

int main(){
    struct Node *root = NULL;
    int num, data, target, child_side;
    printf("Enter number of nodes: ");
    scanf("%d", &num);
    bst_iter(&root, num);
    display_tree(root, 0);
    printf("Enter data to insert: ");
    scanf("%d", &data);
    bst_insert(&root, data);
    display_tree(root, 0);
    printf("Enter data to delete: ");
    scanf("%d", &data);
    root = bst_delete(root, data);
    display_tree(root, 0);
    printf("Enter data to search: ");
    scanf("%d", &target);
    struct Node *parent = search(root, target, &child_side);
    printf("Parent: %d\n", parent->data);
    printf("Child side: %d\n", child_side);
    printf("Height: %d\n", height(root));
    return 0;
}
```

---

### AVL tree implementation using Arrays

```c
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
```

---

### Expression tree insertion using Linked Lists

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char data;
    struct Node *left;
    struct Node *right;
};

struct Node * getNode(char data){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node * stack[100];
int top = -1;

void push(struct Node *node){
    stack[++top] = node;
}

struct Node * pop(){
    return stack[top--];
}

int isOperator(char c){
    if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^'){
        return 1;
    }
    return 0;
}

void inorder(struct Node *root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    printf("%c ", root->data);
    inorder(root->right);
}

void preorder(struct Node *root){
    if(root == NULL){
        return;
    }
    printf("%c ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct Node *root){
    if(root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%c ", root->data);
}

void display_tree(struct Node *root, int level){
    if (root == NULL)
    {
        return;
    }
    display_tree(root->right, level + 1);
    for (int i = 0; i < level; i++)
    {
        printf("|\t");
    }
    printf("|------>%c\n", root->data);
    display_tree(root->left, level + 1);
}

struct Node * expression_tree(char *postfix){
    for(int i = 0; i < strlen(postfix); i++){
        if(isOperator(postfix[i])){
            struct Node *newNode = getNode(postfix[i]);
            newNode->right = pop();
            newNode->left = pop();
            push(newNode);
        }
        else{
            struct Node *newNode = getNode(postfix[i]);
            push(newNode);
        }
    }
    return pop();
}

int evaluate(struct Node *root){
    if(root == NULL){
        return 0;
    }
    if(isOperator(root->data)){
        switch (root->data)
        {
        case '+':
            return evaluate(root->left) + evaluate(root->right);
        case '-':
            return evaluate(root->left) - evaluate(root->right);
        case '*':
            return evaluate(root->left) * evaluate(root->right);
        case '/':
            return evaluate(root->left) / evaluate(root->right);
        case '^':
            return evaluate(root->left) ^ evaluate(root->right);
        default:
            break;
        }
    }
    else{
        return root->data - '0';
    }
}
```

---

### Expression tree insertion using Arrays

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int isOperator(char c){
    if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^'){
        return 1;
    }
    return 0;
}

struct Node * stack[100];
int top = -1;

void push(struct Node *node){
    stack[++top] = node;
}

struct Node * pop(){
    return stack[top--];
}

struct Node * expression_tree(char *postfix){
    for(int i = 0; i < strlen(postfix); i++){
        if(isOperator(postfix[i])){
            struct Node *newNode = getNode(postfix[i]);
            newNode->right = pop();
            newNode->left = pop();
            push(newNode);
        }
        else{
            struct Node *newNode = getNode(postfix[i]);
            push(newNode);
        }
    }
    return pop();
}

int evaluate(struct Node *root){
    if(root == NULL){
        return 0;
    }
    if(isOperator(root->data)){
        switch (root->data)
        {
        case '+':
            return evaluate(root->left) + evaluate(root->right);
        case '-':
            return evaluate(root->left) - evaluate(root->right);
        case '*':
            return evaluate(root->left) * evaluate(root->right);
        case '/':
            return evaluate(root->left) / evaluate(root->right);
        case '^':
            return evaluate(root->left) ^ evaluate(root->right);
        default:
            break;
        }
    }
    else{
        return root->data - '0';
    }
}
```

---

## Heaps

### Min Heap implementation using Arrays

```c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Heap{
    int* arr;
    int last, size;
};

struct Heap* createHeap(int size){
    struct Heap *heap = (struct Heap*) malloc (sizeof(struct Heap));
    heap->arr = (int *) calloc (size, sizeof(int));
    heap->size = size;
    heap->last = -1;
}

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

void percolate_up(int *arr, int index){
    if (index == 0)
    {
        return;
    }
    if (arr[parent(index)] > arr[index])
    {
        int temp = arr[parent(index)];
        arr[parent(index)] = arr[index];
        arr[index] = temp;
    } else {
        return;
    }
    percolate_up(arr, parent(index));
}

void percolate_down(int *arr, int index, int last){
    if(index > last){
        return;
    }
    if (arr[index] < arr[left_child(index)] && arr[index] < arr[right_child(index)])
    {
        return;
    }
    if (arr[left_child(index)] < arr[right_child(index)])
    {
        // left child is smaller
        if (arr[index] > arr[left_child(index)])
        {
            int temp = arr[index];
            arr[index] = arr[left_child(index)];
            arr[left_child(index)] = temp;
            percolate_down(arr, left_child(index), last);
        }
    } else {
        if (arr[index] > arr[right_child(index)])
        {
            int temp = arr[index];
            arr[index] = arr[right_child(index)];
            arr[right_child(index)] = temp;
            percolate_down(arr, right_child(index), last);
        }
    }

}

void insert(struct Heap *h, int val) {
    if (h->last + 1 >= h->size) {
        h->size++;
        h->arr = (int *)realloc(h->arr, h->size * sizeof(int));

        for (int i = h->last + 1; i < h->size; ++i) {
            h->arr[i] = 0;
        }
    }
    h->last++;
    h->arr[h->last] = val;
    percolate_up(h->arr, h->last);
}

void delete_min(struct Heap *h){
    h->arr[0] = h->arr[h->last];
    // h->arr[h->last] = 0;
    h->last--;
    h->size--;
    percolate_down(h->arr, 0, h->last);
}

void display_tree(int *tree, int index, int size, int level){
    if(index > size){
        return;
    }
    if(tree[index] == 0){
        return;
    }

    display_tree(tree, 2 * index + 2, size, level + 1);
    for(int i = 0; i < level; i++){
        printf("|\t");
    }
    printf("|------>%d\n", tree[index]);
    display_tree(tree, 2 * index + 1, size, level + 1);
}

int main(){
    int n, data;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    struct Heap *heap = createHeap(n);
    heap->size = n;
    for (int i = 0; i < n; i++)
    {
        printf("Enter data: ");
        scanf("%d", &data);
        insert(heap, data);
    }
    display_tree(heap->arr, 0, heap->size, 0);
    printf("____________________________________\n\n");
    delete_min(heap);
    display_tree(heap->arr, 0, heap->size, 0);
}
```

---

### Max Heap implementation using Arrays

```c
#include <stdio.h>
#include <stdlib.h>

struct Heap{
    int* arr;
    int last, size;
};

struct Heap* createHeap(int size){
    struct Heap *heap = (struct Heap*) malloc (sizeof(struct Heap));
    heap->arr = (int *) calloc (size, sizeof(int));
    heap->size = size;
    heap->last = -1;
}

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

void percolate_up(int *arr, int index){
    if (index == 0)
    {
        return;
    }
    if (arr[parent(index)] < arr[index])
    {
        int temp = arr[parent(index)];
        arr[parent(index)] = arr[index];
        arr[index] = temp;
    } else {
        return;
    }
    percolate_up(arr, parent(index));
}

void percolate_down(int *arr, int index, int last){
    if(index > last){
        return;
    }
    if (arr[index] > arr[left_child(index)] && arr[index] > arr[right_child(index)])
    {
        return;
    }
    if (arr[left_child(index)] > arr[right_child(index)])
    {
        // left child is smaller
        if (arr[index] < arr[left_child(index)])
        {
            int temp = arr[index];
            arr[index] = arr[left_child(index)];
            arr[left_child(index)] = temp;
            percolate_down(arr, left_child(index), last);
        }
    } else {
        if (arr[index] < arr[right_child(index)])
        {
            int temp = arr[index];
            arr[index] = arr[right_child(index)];
            arr[right_child(index)] = temp;
            percolate_down(arr, right_child(index), last);
        }
    }

}

void insert(struct Heap *h, int val) {
    if (h->last + 1 >= h->size) {
        h->size++;
        h->arr = (int *)realloc(h->arr, h->size * sizeof(int));

        for (int i = h->last + 1; i < h->size; ++i) {
            h->arr[i] = 0;
        }
    }
    h->last++;
    h->arr[h->last] = val;
    percolate_up(h->arr, h->last);
}

void delete_max(struct Heap *h){
    h->arr[0] = h->arr[h->last];
    // h->arr[h->last] = 0;
    h->last--;
    h->size--;
    percolate_down(h->arr, 0, h->last);
}

void display_tree(int *tree, int index, int size, int level){
    if(index > size){
        return;
    }
    if(tree[index] == 0){
        return;
    }

    display_tree(tree, 2 * index + 2, size, level + 1);
    for(int i = 0; i < level; i++){
        printf("|\t");
    }
    printf("|------>%d\n", tree[index]);
    display_tree(tree, 2 * index + 1, size, level + 1);
}

int main(){
    int n, data;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    struct Heap *heap = createHeap(n);
    heap->size = n;
    for (int i = 0; i < n; i++)
    {
        printf("Enter data: ");
        scanf("%d", &data);
        insert(heap, data);
    }
    display_tree(heap->arr, 0, heap->size, 0);
    printf("____________________________________\n\n");
    delete_max(heap);
    display_tree(heap->arr, 0, heap->size, 0);
}
```

---

### Heap Sort implementation using Arrays

```c
void heapify(int *arr, int size, int root){
    int largest = root;
    int left = left_child(root);
    int right = right_child(root);

    if(left < size && arr[left] > arr[largest]){
        largest = left;
    }

    if(right < size && arr[right] > arr[largest]){
        largest = right;
    }

    if(largest != root){
        int temp = arr[root];
        arr[root] = arr[largest];
        arr[largest] = temp;
        heapify(arr, size, largest);
    }
}

void heap_sort(int *arr, int size){
    for(int i = size / 2 - 1; i >= 0; i--){
        heapify(arr, size, i);
    }

    for(int i = size - 1; i >= 0; i--){
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}
```

---

## Graphs

### Graph implementation using Adjacency Matrix

```c
#include <stdio.h>
#include <stdlib.h>

struct Graph{
    int **adj;
    int size;
};

struct Graph* createGraph(int size){
    size++;
    struct Graph *graph = (struct Graph*) malloc (sizeof(struct Graph));
    graph->adj = (int **) calloc (size, sizeof(int *));
    for (int i = 0; i < size; i++)
    {
        graph->adj[i] = (int *) calloc (size, sizeof(int));
    }
    graph->size = size;
    return graph;
}

void addEdge(struct Graph *graph, int src, int dest){
    graph->adj[src][dest] = 1;
    graph->adj[dest][src] = 1;
}

void addDirectedEdge(struct Graph *graph, int src, int dest){
    graph->adj[src][dest] = 1;
}

void printGraph(struct Graph *graph){
    printf("  ");
    for (int i = 1; i < graph->size; i++)
    {
        printf("%d ", i);
    }
    printf("\n");
    for (int i = 1; i < graph->size; i++)
    {
        printf("%d ", i);
        for (int j = 1; j < graph->size; j++)
        {
            printf("%d ", graph->adj[i][j]);
        }
        printf("\n");
    }
}

void buildGraph(struct Graph *graph){
    int src, dest;
    printf("Enter the source and destination vertices (-1 -1 to exit): ");
    while (1)
    {
        scanf("%d %d", &src, &dest);
        if (src == -1 && dest == -1)
        {
            break;
        }
        addDirectedEdge(graph, src, dest);
    }
}

void dfs(struct Graph *graph, int src){
    int *stack = (int *) malloc (graph->size * sizeof(int));
    int top = -1;
    int *visited = (int *) calloc (graph->size, sizeof(int));
    stack[++top] = src;
    visited[src] = 1;
    while (top != -1)
    {
        int curr = stack[top--];
        printf("%d ", curr);
        visited[curr] = 2;
        for (int i = 1; i < graph->size; i++)
        {
            if (graph->adj[curr][i] == 1 && visited[i] == 0)
            {
                stack[++top] = i;
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

void bfs(struct Graph *graph, int src){
    int *queue = (int *) malloc (graph->size * sizeof(int));
    int front = -1, rear = -1;
    int *visited = (int *) calloc (graph->size, sizeof(int));
    queue[++rear] = src;
    front++;
    visited[src] = 1;
    while (front != rear)
    {
        int curr = queue[++front];
        printf("%d ", curr);
        visited[curr] = 2;
        for (int i = 1; i < graph->size; i++)
        {
            if (graph->adj[curr][i] == 1 && visited[i] == 0)
            {
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

int main(){
    int size;
    printf("Enter the number of vertices: ");
    scanf("%d", &size);
    struct Graph *graph = createGraph(size);
    buildGraph(graph);
    printGraph(graph);
    printf("DFS: ");
    dfs(graph, 1);
    printf("BFS: ");
    bfs(graph, 1);
}
```

### Graph implementation using Adjacency List

```c
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Graph{
    struct Node **adj;
    int size;
};

struct Graph* createGraph(int size){
    size++;
    struct Graph *graph = (struct Graph*) malloc (sizeof(struct Graph));
    graph->adj = (struct Node **) calloc (size, sizeof(struct Node *));
    for (int i = 0; i < size; i++)
    {
        graph->adj[i] = NULL;
    }
    graph->size = size;
    return graph;
}

void addEdge(struct Graph *graph, int src, int dest){
    struct Node *newNode = (struct Node *) malloc (sizeof(struct Node));
    newNode->data = dest;
    newNode->next = graph->adj[src];
    graph->adj[src] = newNode;

    newNode = (struct Node *) malloc (sizeof(struct Node));
    newNode->data = src;
    newNode->next = graph->adj[dest];
    graph->adj[dest] = newNode;
}

void addDirectedEdge(struct Graph *graph, int src, int dest){
    struct Node *newNode = (struct Node *) malloc (sizeof(struct Node));
    newNode->data = dest;
    newNode->next = graph->adj[src];
    graph->adj[src] = newNode;
}

void printGraph(struct Graph *graph){
    for (int i = 1; i < graph->size; i++)
    {
        printf("%d: ", i);
        struct Node *temp = graph->adj[i];
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

void buildGraph(struct Graph *graph){
    int src, dest;
    printf("Enter the source and destination vertices (-1 -1 to exit): ");
    while (1)
    {
        scanf("%d %d", &src, &dest);
        if (src == -1 && dest == -1)
        {
            break;
        }
        addDirectedEdge(graph, src, dest);
    }
}

void dfs(struct Graph *graph, int src){
    int *stack = (int *) malloc (graph->size * sizeof(int));
    int top = -1;
    int *visited = (int *) calloc (graph->size, sizeof(int));
    stack[++top] = src;
    visited[src] = 1;
    while (top != -1)
    {
        int curr = stack[top--];
        printf("%d ", curr);
        visited[curr] = 2;
        struct Node *temp = graph->adj[curr];
        while (temp != NULL)
        {
            if (visited[temp->data] == 0)
            {
                stack[++top] = temp->data;
                visited[temp->data] = 1;
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

void bfs(struct Graph *graph, int src){
    int *queue = (int *) malloc (graph->size * sizeof(int));
    int front = -1, rear = -1;
    int *visited = (int *) calloc (graph->size, sizeof(int));
    queue[++rear] = src;
    front++;
    visited[src] = 1;
    while (front != rear)
    {
        int curr = queue[++front];
        printf("%d ", curr);
        visited[curr] = 2;
        struct Node *temp = graph->adj[curr];
        while (temp != NULL)
        {
            if (visited[temp->data] == 0)
            {
                queue[++rear] = temp->data;
                visited[temp->data] = 1;
            }
            temp = temp->next;
        }
    }
    printf("\n");
}
```

---

### Topological Sort implementation using Adjacency Matrix

```c
int indegree(struct Graph *graph, int vertex){
    int count = 0;
    for (int i = 1; i < graph->size; i++)
    {
        if (graph->adj[i][vertex] == 1)
        {
            count++;
        }
    }
    return count;
}

void topological_sort(struct Graph *graph){
    int *queue = (int *) malloc (graph->size * sizeof(int));
    int front = -1, rear = -1;
    int *visited = (int *) calloc (graph->size, sizeof(int));
    for (int i = 1; i < graph->size; i++)
    {
        if (indegree(graph, i) == 0)
        {
            queue[++rear] = i;
            front++;
            visited[i] = 1;
        }
    }
    while (front != rear)
    {
        int curr = queue[++front];
        printf("%d ", curr);
        visited[curr] = 2;
        for (int i = 1; i < graph->size; i++)
        {
            if (graph->adj[curr][i] == 1 && visited[i] == 0)
            {
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}
```
