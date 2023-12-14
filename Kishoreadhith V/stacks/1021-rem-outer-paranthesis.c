#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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
        return -99999999;
    }
    return arr[(*top)--];
}

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

char* removeOuterParentheses(char* s) {
    int len = strlen(s);
    char * stack = (char *) malloc (len * sizeof(char));
    int top = -1;
    char * ans = (char *) malloc (len * sizeof(char));
    for (int i = 0; i < len; i++)
    {
        if(s[i] == '('){
            push(stack, &top, s[i], len);
            if(top != 0){
                ans[i] = '(';
            }
        }
        else if(s[i] == ')'){
            pop(stack, &top);
            if(top != -1){
                ans[i] = ')';
            }
        } else {
            ans[i] = s[i];
        }
    }
    return ans;
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

int isValid(char* s) {
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
    if(top == -1){
        return 1;
    }
    return 0;
}