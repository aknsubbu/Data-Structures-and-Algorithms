#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    char * postfix = (char *) malloc (len * sizeof(char));
    char * operators = (char *) malloc (len * sizeof(char));
    int top = -1;
    for (int i = 0; i < len; i++)
    {
        if (infix[i] >= '0' && infix[i] < '9')
        {
            push(postfix, &top, infix[i], len);
        }
        else if(infix[i] == '('){
            push(operators, &top, infix[i], len);
        }
        else if(infix[i] == ')'){
            char op;
            while (op = pop(operators, &top) != '(')
            {
                push(postfix, &top, op, len);
            }
        }
        else if(infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '%'){
            char op;
            while (precedence(op = pop(operators, &top)) >= precedence(infix[i]))
            {
                push(postfix, &top, op, len);
            }
            push(operators, &top, infix[i], len);
        }

    }
    return postfix;    
}

int main(){
    printf("Postfix expression: %s\n", toPostfix("((a+b)/(c-d))"));
    return 0;
}