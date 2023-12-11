#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float floatPeek(float* array,int top){
    return array[top];
}

int intPeek(int* array,int top){
    return array[top];
}

int floatPush(float* arr,int size,int top,float val){
    if(++top<=size){
        arr[top] = val;
        return top;
    }
    printf("Stack Overflow\n");
    return top;
}

float floatPop(float* arr,int* top){
    if((*top)<0){
        printf("Stack Overflow");
        return *top;
    }
    float temp = arr[*top];
    (*top)--;
    return temp;
}

int intPush(int* arr,int size,int top,float val){
    if(++top<=size){
        arr[top] = val;
        return top;
    }
    printf("Stack Overflow\n");
    return top;
}

int intPop(int* arr,int* top){
    if((*top)<0){
        printf("Stack Overflow");
        return *top;
    }
    int temp = arr[*top];
    (*top)--;
    return temp;
}

void floatDisplay(float* arr,int top){
    for(int i = 0;i<=top;i++) printf("%f ",arr[i]);
    printf("\n");
}

void charDisplay(int* arr,int top){
    for(int i = 0;i<=top;i++) printf("%c ",arr[i]);
    printf("\n");
}

void evalPostFix(char* exp){
    int i = 0;
    float op1,op2;
    int size = strlen(exp);
    float array[size];
    int top = -1;
    while(exp[i] != '\0'){
        //for number
        if(exp[i] > 47 && exp[i] < 58){
            int num = 0;
            while(exp[i] != ' '){
                num *= 10;
                num += exp[i]-48;
                i++;
            }
            top = floatPush(array,size,top,num);
        }

        //+
        if(exp[i] == 43){
            op2 = floatPop
        (array,&top);
            op1 = floatPop
        (array,&top);
            float temp = op1 + op2;
            top = floatPush(array,size,top,temp);
            
        }

        //-
        if(exp[i] == 45){
            op2 = floatPop
        (array,&top);
            op1 = floatPop
        (array,&top);
            float temp = op1 - op2;
            top = floatPush(array,size,top,temp);
            
        }

        //*
        if(exp[i] == 42){
            op2 = floatPop
        (array,&top);
            op1 = floatPop
        (array,&top);
            float temp = op1 * op2;
            top = floatPush(array,size,top,temp);
            
        }

        ///
        if(exp[i] == 47){
            op2 = floatPop
        (array,&top);
            op1 = floatPop
        (array,&top);
            float temp = op1 / op2;
            top = floatPush(array,size,top,temp); 
        }
        i++;
    floatDisplay(array,top);
    }
}

int precedence(char c){
    switch(c){
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return -1;
    }
}

int isOperator(char c){
    switch(c){
        case '+':
        case '-':
        case '*':
        case '/':
            return 1;
        default:
            return 0;
    }
}

float* conversion(char* exp){
    int size = strlen(exp);
    int stk[size];
    int i = 0;
    int top = -1;
    


    while(exp[i] != '\0'){
        //for number
        if(exp[i] > 47 && exp[i] < 58){
            int num = 0;
            while(exp[i] != ' '){
                num *= 10;
                num += exp[i]-48;
                i++;
            }
           printf("%d ",num);
        }

        if(exp[i] == '('){
            top = intPush(stk,size,top,exp[i]);
        }

        if(exp[i] == ')'){
            while(intPeek(stk,top) != '(') printf("%c ",intPop(stk,&top));
            intPop(stk,&top);
        }

        if(isOperator(exp[i])){
            while(precedence(intPeek(stk,top)) >= precedence(exp[i])) printf("%c ",intPop(stk,&top));
            top = intPush(stk,size,top,exp[i]);
        }

        i++;
    }   
}


int main(){
    char* pFix = "2 4 5 / 5 3 - * + 5 4 / -";
    char* iFix = "(2 + 4 / 5 * ( 5 - 3 ) - ( 5 / 4 ))";
    evalPostFix(pFix);
    conversion(iFix);
}
