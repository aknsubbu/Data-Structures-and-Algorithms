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

int main() {
    char *postfix1 = toPostfix("()");
    char *postfix2 = toPostfix("(a+b)/(c-d)");
    char *postfix3 = toPostfix("a+b/c-d");
    char *postfix4 = toPostfix("a+b/c*d^e/f-g-h");
    printf("%s\n", postfix1);
    printf("%s\n", postfix2);
    printf("%s\n", postfix3);
    printf("%s\n", postfix4);
    return 0;
}
