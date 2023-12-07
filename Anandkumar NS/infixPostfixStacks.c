#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h> 

#define SIZE 100

char push();
char pop();
void display();
int precedence(char);
int isOperator(char);

char stack[SIZE];
int top = -1;

int main(){
    char infix[SIZE], postfix[SIZE];
    int i, j;
    char ch, elem;
    printf("Enter Infix Expression : ");
    scanf("%s", infix);
    i = 0;
    j = 0;
    while (infix[i] != '\0'){
        ch = infix[i];
        if (ch == '('){
        push(ch);
        }
        else if (isalnum(ch)){
        postfix[j] = ch;
        j++;
        }
        else if (isOperator(ch) == 1){
        elem = pop();
        while (isOperator(elem) == 1 && precedence(elem) >= precedence(ch)){
            postfix[j] = elem;
            j++;
            elem = pop();
        }
        push(elem);
        push(ch);
        }
        else if (ch == ')'){
        elem = pop();
        while (elem != '('){
            postfix[j] = elem;
            j++;
            elem = pop();
        }
        }
        else{
        printf("\nInvalid Arithmetic Expression.\n");
        exit(0);
        }
        i++;
    }
    while (top > -1){
        postfix[j] = pop();
        j++;
    }
    postfix[j] = '\0';
    printf("\nArithmetic expression in Postfix notation : ");
    puts(postfix);
    return 0;
}


char push(char elem){
    top++;
    stack[top] = elem;
    return elem;
}

char pop(){
    if (top == -1){
        printf("\nStack is Empty\n");
        return -1;
    }
    char elem;
    elem = stack[top];
    top--;
    return elem;
}

void display(){
    int i;
    if (top == -1)
    printf("\nStack is Empty\n");
    else{
    printf("\nStack Elements :\n");
    for (i = top; i >= 0; i--)
        printf(" %c\n", stack[i]);
    }
}

int precedence(char elem){
    switch (elem){
        case '#':
        return 0;
        case '(':
        return 1;
        case '+':
        case '-':
        return 2;
        case '*':
        case '/':
        return 3;
        case '^':
        return 4;
    }
}

int isOperator(char elem){
    switch (elem){
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
        return 1;
        default:
        return 0;
    }
}

