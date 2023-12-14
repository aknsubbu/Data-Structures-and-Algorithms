#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

void initialize(Stack *s) {
    s->top = -1;
}

void push(Stack *s, int value) {
    if (s->top == MAX_SIZE - 1) {
        printf("Stack overflow\n");
        exit(1);
    }
    s->data[++s->top] = value;
}

int pop(Stack *s) {
    if (s->top == -1) {
        printf("Stack underflow\n");
        exit(1);
    }
    return s->data[s->top--];
}

int evaluatePostfix(char *expression) {
    Stack stack;
    initialize(&stack);

    int i, operand1, operand2, result;
    char ch;

    for (i = 0; expression[i] != '\0'; i++) {
        ch = expression[i];

        if (isdigit(ch)) {
            push(&stack, ch - '0');
        } else {
            operand2 = pop(&stack);
            operand1 = pop(&stack);

            switch (ch) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
                default:
                    printf("Invalid operator\n");
                    exit(1);
            }

            push(&stack, result);
        }
    }

    return pop(&stack);
}

int main() {
    char expression[] = "1 2 + 3 4 - *";
    int result = evaluatePostfix(expression);
    printf("Result: %d\n", result);

    return 0;
}
