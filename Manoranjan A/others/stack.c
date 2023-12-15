
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Define the node structure for the linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Define the stack structure
typedef struct Stack {
    Node* top;
} Stack;

// Function to create a new node
Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to create a new stack
Stack* newStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

// Function to push a new element onto the stack
void push(Stack* stack, int data) {
    Node* node = newNode(data);
    node->next = stack->top;
    stack->top = node;
}

// Function to pop the top element off the stack
int pop(Stack* stack) {
    if (stack->top == NULL) {
        printf("Error: stack is empty\n");
        return -1;
    }
    int data = stack->top->data;
    Node* temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    return data;
}

// Function to peek at the top element of the stack
int peek(Stack* stack) {
    if (stack->top == NULL) {
        printf("Error: stack is empty\n");
        return -1;
    }
    return stack->top->data;
}

// Function to check if the stack is empty
int isEmpty(Stack* stack) {
    return stack->top == NULL;
}

// Function to evaluate a postfix expression
int evaluatePostfix(char* expression) {
    Stack* stack = newStack();
    for (int i = 0; expression[i] != '\0'; i++) {
        if (isdigit(expression[i])) {
            push(stack, expression[i] - '0');
        } else {
            int operand2 = pop(stack);
            int operand1 = pop(stack);
            switch (expression[i]) {
                case '+':
                    push(stack, operand1 + operand2);
                    break;
                case '-':
                    push(stack, operand1 - operand2);
                    break;
                case '*':
                    push(stack, operand1 * operand2);
                    break;
                case '/':
                    push(stack, operand1 / operand2);
                    break;
            }
        }
    }
    int result = pop(stack);
    free(stack);
    return result;
}

// Function to convert an infix expression to postfix
char* infixToPostfix(char* expression) {
    Stack* stack = newStack();
    char* postfix = (char*)malloc(sizeof(char) * 100);
    int j = 0;
    for (int i = 0; expression[i] != '\0'; i++) {
        if (isdigit(expression[i])) {
            postfix[j++] = expression[i];
        } else if (expression[i] == '(') {
            push(stack, expression[i]);
        } else if (expression[i] == ')') {
            while (!isEmpty(stack) && peek(stack) != '(') {
                postfix[j++] = pop(stack);
            }
            if (!isEmpty(stack) && peek(stack) != '(') {
                printf("Error: invalid expression\n");
                return NULL;
            } else {
                pop(stack);
            }
        } else {
            while (!isEmpty(stack) && precedence(expression[i]) <= precedence(peek(stack))) {
                postfix[j++] = pop(stack);
            }
            push(stack, expression[i]);
        }
    }
    while (!isEmpty(stack)) {
        postfix[j++] = pop(stack);
    }
    postfix[j] = '\0';
    free(stack);
    return postfix;
}

// Function to get the precedence of an operator
int precedence(char operator) {
    switch (operator) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return -1;
    }
}
int main() {
    Stack* stack = newStack();
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    printf("%d\n", pop(stack)); // 3
    printf("%d\n", pop(stack)); // 2
    printf("%d\n", pop(stack)); // 1
    printf("%d\n", pop(stack)); // Error: stack is empty, -1
    printf("%d\n", isEmpty(stack)); // 1 (true)
    free(stack);

    char* infix = "2+3*4";
    char* postfix = infixToPostfix(infix);
    printf("%s\n", postfix); // 234*+
    printf("%d\n", evaluatePostfix(postfix)); // 14
    free(postfix);

    return 0;
}
