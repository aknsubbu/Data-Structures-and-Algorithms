#include<stdio.h>
#include<stdlib.h>

int push(int *arr,int top,int num,int data){
     if(top+1==num){
        printf("the stack is overflown");
        return NULL;
     }
     else{
        arr[top+1]=data;
        return top;
     }
}

int pop(int *arr,int top,int numberofelements){
    if(--top<0){
        printf("the stack is underflown");
        return NULL;
    }else{
        free(arr[top]);
        top--;
        return top;
    }
}

int main(){
    int length;
    printf("enter the length of the stack:");
    scanf("%d",&length);
    int *arr=(int *)malloc(length*sizeof(int));
}

//evaluvating expression

push pop evaluvating prefix to postfix and evaluvating postfix and array , linked list

(3+2)*(4-5)/6*2/1