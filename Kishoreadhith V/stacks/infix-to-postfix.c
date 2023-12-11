#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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
int main() {
    char *postfix1 = toPostfix("2+(3*1)-9");
    float result = eval_postfix(postfix1);
    printf("%s = %f\n", postfix1, result);
    char *postfix2 = toPostfix("(a+b)/(c-d)");
    char *postfix3 = toPostfix("a+b/c-d");
    char *postfix4 = toPostfix("a+b/c*d^e/f-g-h");
    printf("%s\n", postfix1);
    printf("%s\n", postfix2);
    printf("%s\n", postfix3);
    printf("%s\n", postfix4);
    return 0;
}

