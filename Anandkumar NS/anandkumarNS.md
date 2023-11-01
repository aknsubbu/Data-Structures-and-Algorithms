
# Linked Lists

## Introduction
A **linked list** is a linear data structure consisting of a sequence of elements where each element points to the next one, forming a chain-like structure. Linked lists are used to implement various data structures like stacks, queues, and dynamic data structures.

## Components of a Linked List
A linked list consists of two main components:
1. **Nodes**: Nodes are the individual elements of the linked list. Each node contains two parts:
    - Data: The data or value stored in the node.
    - Pointer/Reference: A reference or pointer to the next node in the sequence.
2. **Head**: The head is a reference to the first node in the linked list. It serves as the starting point for traversing the list.

## Types of Linked Lists
1. **Singly Linked List**: Each node has a reference to the next node, forming a unidirectional chain.
2. **Doubly Linked List**: Each node has references to both the next and the previous nodes, forming a bidirectional chain.
3. **Circular Linked List**: In this type, the last node points back to the first node, forming a closed loop.

## Operations on Linked Lists
Common operations on linked lists include:
- **Insertion**: Adding a new node to the list.
- **Deletion**: Removing a node from the list.
- **Traversal**: Iterating through the list to access or manipulate elements.
- **Search**: Finding a specific element in the list.
- **Modification**: Updating the data within a node.

## Advantages
- **Dynamic Size**: Linked lists can grow or shrink in size during runtime.
- **Efficient Insertions/Deletions**: Inserting or deleting elements from the middle of the list is more efficient than arrays.
- **No Wasted Space**: Memory is allocated dynamically for each node, so there is no wasted space.

## Disadvantages
- **Random Access**: Accessing elements at arbitrary positions is slower compared to arrays.
- **Extra Memory**: Each node requires additional memory for the pointer/reference.
- **Traversal Overhead**: Traversing a linked list requires iterating through each node.

## Use Cases
- **Stacks and Queues**: Linked lists are often used to implement stack and queue data structures.
- **Dynamic Memory Allocation**: Linked lists allow efficient memory allocation for data of varying sizes.
- **Undo/Redo Functionality**: Linked lists are suitable for implementing undo/redo functionality in applications.

## Implementation
Linked lists can be implemented in various programming languages. Here's a simple example in Python:

```python
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None
```

## Summary
Linked lists are fundamental data structures used in computer science and programming. They provide dynamic memory allocation and efficient insertion/deletion operations, making them suitable for various applications. Understanding the different types of linked lists and their operations is essential for software development.



Insert at begin
insert at end 
insert n nodes at begin
insert n nodes at end
search for a node with given data value
display (print all the nodes) -start address  and data part and the address part
insert after node x
insert before node x


# Stacks

## Introduction
A **stack** is a linear data structure that follows the Last In First Out (LIFO) principle. It has two main operations: **push** and **pop**. The push operation adds an element to the top of the stack, and the pop operation removes an element from the top of the stack. Other operations include **peek**, which returns the top element without removing it, and **isEmpty**, which checks if the stack is empty.

## Components of a Stack
A stack consists of two main components:
1. **Stack Elements**: The elements of the stack are stored in a sequential order. The element at the top of the stack is called the top element.
2. **Stack Pointer**: The stack pointer points to the top element of the stack. It is used to keep track of the top element and to implement the push and pop operations.

## Operations on Stacks
Common operations on stacks include:
- **Push**: Adding an element to the top of the stack.
- **Pop**: Removing an element from the top of the stack.
- **Peek**: Returning the top element without removing it.
- **isEmpty**: Checking if the stack is empty.

## Advantages
- **Fast Operations**: All stack operations are performed in constant time.
- **Simple Implementation**: Stacks are easy to implement using arrays or linked lists.

## Disadvantages
- **Fixed Size**: The size of the stack needs to be specified in advance.
- **No Random Access**: Elements can only be accessed in a LIFO order.

## Use Cases
- **Function Calls**: Stacks are used to store information about active function calls.
- **Expression Evaluation**: Stacks are used to evaluate expressions like infix, postfix, and prefix.
- **Backtracking**: Stacks are used to implement backtracking algorithms like N-Queens and Sudoku.

## Implementation
Stacks can be implemented in various programming languages.
    
    ```c
    #include <stdio.h>
    #include <stdlib.h>

    struct Stack {
        int top;
        unsigned capacity;
        int* array;
    };

    struct Stack* createStack(unsigned capacity) {
        struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
        stack->capacity = capacity;
        stack->top = -1;
        stack->array = (int*) malloc(stack->capacity * sizeof(int));
        return stack;
    }

    int isFull(struct Stack* stack) {
        return stack->top == stack->capacity - 1;
    }

    int isEmpty(struct Stack* stack) {
        return stack->top == -1;
    }

    void push(struct Stack* stack, int item) {
        if (isFull(stack)) {
            return;
        }
        stack->array[++stack->top] = item;
        printf("%d pushed to stack\n", item);
    }

    int pop(struct Stack* stack) {
        if (isEmpty(stack)) {
            return -1;
        }
        return stack->array[stack->top--];
    }

    int peek(struct Stack* stack) {
        if (isEmpty(stack)) {
            return -1;
        }
        return stack->array[stack->top];
    }

    int main() {
        struct Stack* stack = createStack(100);
        push(stack, 10);
        push(stack, 20);
        push(stack, 30);
        printf("%d popped from stack\n", pop(stack));
        printf("Top element is %d\n", peek(stack));
        return 0;
    }
    ```

## Summary
Stacks are fundamental data structures used in computer science and programming. They provide fast operations and are easy to implement, making them suitable for various applications. Understanding the different operations on stacks is essential for software development.


#  Queues

## Introduction
A **queue** is a linear data structure that follows the First In First Out (FIFO) principle. It has two main operations: **enqueue** and **dequeue**. The enqueue operation adds an element to the back of the queue, and the dequeue operation removes an element from the front of the queue. Other operations include **peek**, which returns the front element without removing it, and **isEmpty**, which checks if the queue is empty.

## Components of a Queue
A queue consists of two main components:
1. **Queue Elements**: The elements of the queue are stored in a sequential order. The element at the front of the queue is called the front element, and the element at the back of the queue is called the back element.
2. **Queue Pointers**: The queue pointers point to the front and back elements of the queue. They are used to keep track of the front and back elements and to implement the enqueue and dequeue operations.

## Operations on Queues
Common operations on queues include:
- **Enqueue**: Adding an element to the back of the queue.
- **Dequeue**: Removing an element from the front of the queue.
- **Peek**: Returning the front element without removing it.
- **isEmpty**: Checking if the queue is empty.

## Advantages
- **Fast Operations**: All queue operations are performed in constant time.
- **Simple Implementation**: Queues are easy to implement using arrays or linked lists.

## Disadvantages
- **Fixed Size**: The size of the queue needs to be specified in advance.
- **No Random Access**: Elements can only be accessed in a FIFO order.

## Use Cases
- **Breadth-First Search**: Queues are used to implement breadth-first search (BFS) in graph traversal.
- **Resource Sharing**: Queues are used to implement resource sharing in operating systems.
- **Scheduling**: Queues are used to implement process scheduling in operating systems.

## Implementation

Queues can be implemented in various programming languages.

```c
#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int front, rear, size;
    unsigned capacity;
    int* array;
};

struct Queue* createQueue(unsigned capacity) {
    struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (int*) malloc(queue->capacity * sizeof(int));
    return queue;
}

int isFull(struct Queue* queue) {
    return queue->size == queue->capacity;
}

int isEmpty(struct Queue* queue) {
    return queue->size == 0;
}

void enqueue(struct Queue* queue, int item) {
    if (isFull(queue)) {
        return;
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size++;
    printf("%d enqueued to queue\n", item);
}

int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        return -1;
    }
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return item;
}

int peek(struct Queue* queue) {
    if (isEmpty(queue)) {
        return -1;
    }
    return queue->array[queue->front];
}

int main() {
    struct Queue* queue = createQueue(100);
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    printf("%d dequeued from queue\n", dequeue(queue));
    printf("Front element is %d\n", peek(queue));
    return 0;
}
```

## Summary
Queues are fundamental data structures used in computer science and programming. They provide fast operations and are easy to implement, making them suitable for various applications. Understanding the different operations on queues is essential for software development.

# Trees

## Introduction
A **tree** is a hierarchical data structure consisting of nodes connected by edges. Each node contains a value or data, and it may or may not have child nodes. A tree is a recursive data structure since each node is a root node of a subtree. The topmost node is called the root node, and the nodes at the bottom are called leaf nodes.

## Components of a Tree
A tree consists of three main components:
1. **Nodes**: Nodes are the individual elements of the tree. Each node contains two parts:
    - Data: The data or value stored in the node.
    - Children: A list of references to the child nodes.
2. **Edges**: Edges are the links between the nodes. They connect the nodes to form the tree.
3. **Root**: The root is the topmost node of the tree. It serves as the starting point for traversing the tree.

## Types of Trees
1. **Binary Tree**: Each node has at most two child nodes, forming a binary tree.
2. **Binary Search Tree**: A binary tree where the left child node is less than the parent node, and the right child node is greater than the parent node.
3. **AVL Tree**: A binary search tree where the difference between the heights of the left and right subtrees is at most one.
4. **Red-Black Tree**: A binary search tree where each node is colored either red or black, and the root node is always black.
5. **B-Tree**: A self-balancing tree where each node can have more than two child nodes.

## Operations on Trees
Common operations on trees include:
- **Insertion**: Adding a new node to the tree.
- **Deletion**: Removing a node from the tree.
- **Traversal**: Iterating through the tree to access or manipulate nodes.
- **Search**: Finding a specific node in the tree.
- **Modification**: Updating the data within a node.

## Advantages
- **Fast Operations**: All tree operations are performed in logarithmic time.
- **Dynamic Size**: Trees can grow or shrink in size during runtime.
- **Hierarchical Structure**: Trees are suitable for representing hierarchical data.


## Disadvantages
- **No Random Access**: Elements can only be accessed in a hierarchical order.
- **Extra Memory**: Each node requires additional memory for the children references.
- **Complex Implementation**: Trees are more complex to implement than arrays and linked lists.

## Use Cases
- **File Systems**: Trees are used to represent file systems in operating systems.
- **Databases**: Trees are used to implement various database systems.
- **Artificial Intelligence**: Trees are used to implement various AI algorithms.

## Implementation
Trees can be implemented in various programming languages. 

```c
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int main() {
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    return 0;
}

```

## Summary
Trees are fundamental data structures used in computer science and programming. They provide fast operations and are suitable for representing hierarchical data, making them suitable for various applications. Understanding the different types of trees and their operations is essential for software development.

