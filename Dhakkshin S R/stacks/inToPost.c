#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define RED "\x1B[31m"
#define GREEN "\x1B[32m"
#define YELLOW "\x1B[33m"
#define RESET "\x1B[0m"

struct Stack
{
    int top;
    int* arr;
    int max;
};

enum operators {
    PLUS,
    MINUS,
    MULTIPLY,
    DIVIDE,
    MODULUS,
    LEFT_PAREN,
    RIGHT_PAREN
};

struct Stack creatStack(int size);
int precedence (char operator);
void push(struct Stack* a, int data);
int pop(struct Stack* a);
char enumToChar(int x);
void display(struct Stack* a);
int peek(struct Stack* a);

int main(void)
{
    char* expression = "((1+2)-(3+4)*5)";
    int len = (strlen(expression));
    char* postfix = malloc(sizeof(char) * len);
    struct Stack operatorStack = creatStack(len);
    struct Stack* opPtr = &operatorStack;
    int i = 0;
    int j = 0;
    while(i < len)
    {
        char scanned = expression[i];
        i++;
        int x = precedence(scanned);
        if (x == -1)
        {
            postfix[j] = scanned;
            j++;
            continue;
        }

        else
        {
            if (x == LEFT_PAREN)
            {
                push(opPtr, LEFT_PAREN);
                display(opPtr);
            }
            else if (x == RIGHT_PAREN)
            {
                int a = pop(opPtr);
                display(opPtr);
                while (a != LEFT_PAREN)
                {
                    postfix[j] = enumToChar(a);
                    j++;
                    a = pop(opPtr);
                    display(opPtr);
                }

            }
            else
            {
                // if (peek(opPtr) < x)
                // {
                //     push(opPtr, x);
                //     display(opPtr);
                // }
                // // else if (peek(opPtr) == x)
                // // {
                // //     postfix[j] = enumToChar(pop(opPtr));
                // //     j++;
                // // }
                // else
                // {
                //     postfix[j] = enumToChar(pop(opPtr));
                //     j++;
                // }
                push(opPtr, x);
                display(opPtr);
            }
        }

    }
    int x = 0;
    while(x < j)
    {
        printf("%c", postfix[x]);
        x++;
    }
    printf("\n");
}

char enumToChar(int x)
{
    switch (x)
    {
    case PLUS:
        return '+';
        break;
    case MINUS:
        return '-';
        break;
    case MULTIPLY:
        return '*';
        break;
    case DIVIDE:
        return '/';
        break;
    case MODULUS:
        return '%';
        break;
    case LEFT_PAREN:
        return '(';
        break;
    case RIGHT_PAREN:
        return ')';
        break;
    default:
        return -1;
        break;
    }
}

int precedence (char operator)
{
    switch (operator)
    {
    case '+':
        return PLUS;
        break;
    case '-':
        return MINUS;
        break;
    case '*':
        return MULTIPLY;
        break;
    case '/':
        return DIVIDE;
        break;
    case '%':
        return MODULUS;
        break;
    case '(':
        return LEFT_PAREN;
        break;
    case ')':
        return RIGHT_PAREN;
        break;
    default:
        // printf(RED "Invalid operator!!\n" RESET);
        return -1;
        break;
    }
}

void push(struct Stack* a, int data)
{
    if (a->top == a->max-1)
    {
        printf(RED "Overflow!!\n" RESET);
        return;
    }
    else
    {
        a->top = a->top + 1;
        a->arr[a->top] = data;
        return;
    }
}

int pop(struct Stack* a)
{
    if (a->top == -1)
    {
        printf(RED "Underflow!!\n" RESET);
        return -1;
    }
    else
    {
        int z =  a->arr[a->top];
        a->top = a->top - 1;
        return z;
    }
}

void display(struct Stack* a)
{
    if (a->top == -1)
    {
        printf(RED "Underflow!!\n" RESET); 
        return;
    }
    else
    {
        for (int i = a->top; i >= 0; i--)
        {
            printf(GREEN "| %d |\n" RESET, a->arr[i]);
        }
        printf(GREEN "|___|\n\n" RESET);
        return;
    }
}

int peek(struct Stack* a)
{
    if (a->top == -1)
    {
        printf(RED "Underflow!!\n" RESET);
        return -1; 
    }
    else
    {
        printf("The top element is: ");
        printf(GREEN "%d\n" RESET, a->arr[a->top]);
        return a->arr[a->top];
    }
}

struct Stack creatStack(int size)
{
    struct Stack a;
    a.arr = malloc(sizeof(int) * size);
    a.top = -1;
    a.max = size;
    return a;
}