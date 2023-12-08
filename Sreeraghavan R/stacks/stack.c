#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void peek(int* array,int top){
    printf("%d\n",array[top]);
}

int push(int* arr,int size,int top,int val){
    if(++top<=size){
        arr[top] = val;
        return top;
    }
    printf("Stack Overflow\n");
    return top;
}

int pop(int* arr,int* top){
    if((*top)<0){
        printf("Stack Overflow");
        return *top;
    }
    int temp = arr[*top];
    (*top)--;
    return temp;
}


void display(int* arr,int top){
    for(int i = 0;i<=top;i++) printf("%d ",arr[i]);
    printf("\n");
}


int main(){
    int array[10] = {1,2,3,4,5,6};
    int len = 10;
    int top = 5;
    display(array,top);
    top = push(array,len,top,7);
    display(array,top);

    
    int popped = pop(array,&top);
    printf("The popped value is %d\n",popped);
    display(array,top);

    top = push(array,len,top,8);
    display(array,top);

}
