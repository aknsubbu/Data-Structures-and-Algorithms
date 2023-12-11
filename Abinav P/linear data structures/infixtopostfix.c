#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int precedence(char c){
    switch(c){
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default :
            return -1;    
    }
}

void push(int *stack,int data,int *top){
    if(*top==99){
        printf("the stack is full....!");
        return;
    }
    stack[++(*top)]=data;
}

char pop(int *stack,int *top){
    if(*top==-1){
        printf("the stack is empty....!");
        return -1;
    }
    return stack[(*top)--];
}

char * topostfix(char *infix){
    int len=strlen(infix);
    int *postfix=malloc((len+1)*sizeof(int));
    int *operators=malloc((len+1)*sizeof(int));
    int top=-1,pin=-1;
    for(int i=0;i<len;i++){
        if(isalnum(infix[i])){
            postfix[++pin]=infix[i];
        }
        else if(infix[i]=='('){
            push(operators,infix[i],&top);
        }
        else if(infix[i]==')'){
            while(operators[top]!='('){
                postfix[++pin]=pop(operators,&top);
            }
            if(top>-1 && operators[top]=='('){
                pop(operators,&top);
            }
            else{
                printf("the expression is invalid....!");
                return NULL;
            }
        }
        else if(precedence(infix[i])){
            char op;
            while((top>-1 && precedence(operators[top]) >= precedence(infix[i]) )&& operators[top]!='('){
                op=pop(operators,&top);
                postfix[++pin]=op;
            }
            push(operators,infix[i],&top);
        }
    }
    while(top>-1){
        if(operators[top]=='('){
            printf("the expression is invalid....!");
            return NULL;
        }
        postfix[++pin]=pop(operators,&top);
    }
    postfix[++pin]='\0';
    return postfix;
}

int main(){
    char *postfix1=topostfix("()");
}