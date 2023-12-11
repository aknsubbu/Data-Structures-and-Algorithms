// #include<stdio.h>
// #include<stdlib.h>

// struct stack create_stack(int size);
// void push(struct stack *stack_ptr,int data);
// int pop(struct stack *a);
// void peek(struct stack *a);
// void display(struct stack *a);


// struct stack{
//     int top;
//     int *arr;
//     int max;
// };


// void main(){
//     printf("Enter the size of the stack:");
//     int n;
//     scanf("%d",&n);
//     struct stack stack=create_stack(n);
//     struct stack *stack_ptr=&stack;
//     int choice;
//     while(1){
//         printf("enter the choice of your interest:\n1.push\n2.pop\n3.peek\n4.display\n");
//         scanf("%d",&choice);
//         switch(choice){
//             case 1:
//                printf("enter the element to be pushed in the stack:");
//                int data;
//                scanf("%d",&data);
//                push(stack_ptr,data);
//                break;
//             case 2:
//                printf("the popped element is :");
//                printf("%d\n",pop(stack_ptr));
//                break;   
//             case 3:
//                peek(stack_ptr);
//                break;  
//             case 4:
//                display(stack_ptr);
//                break;   
//             default:
//                printf("invalid choice");
//                return;
//                break ;  
//         }
//     }
// }


// struct stack create_stack(int size){
//     struct stack a;
//     a.top=-1;
//     a.max=size;
//     a.arr=malloc(size*sizeof(int));
//     return a;
// }


// void push(struct stack *a,int data){
//      if(a->top==a->max-1){
//         printf("the stack is overflowing :...!\n");
//         return;
//      }else{
//         a->top=a->top+1;
//         a->arr[a->top]=data;
//         return;
//      }
// }

// int pop(struct stack *a){
//     if(a->top==-1){
//         printf("The stack is underflow!\n");
//         return;
//     }else{
//         int z=a->arr[a->top];
//         a->top=a->top-1;
//         return z;
//     }
// }

// void peek(struct stack *a){
//     if(a->top==-1){
//         printf("The stack is empty..!\n");
//         return ;
//     }
//     else{
//         printf("The top element is :%d\n",a->arr[a->top]);
//         return;
//     }
// }

// void display(struct stack *a){
//     if(a->top==-1){
//         printf("the stack is empty...!\n");
//         return;
//     }else{
//         for(int i=a->top;i>=0;i--){
//             printf("%d ",a->arr[i]);
//         }
//         printf("\n");
//         return;
//     }
// }


//Stack using Arrays

#include<stdio.h>
#include<stdlib.h>

struct stack create_stack(int size);
void push(struct stack *stack_ptr,int data);
int pop(struct stack *a);
void peek(struct stack *a);
void display(struct stack *a);

struct stack{
    int top;
    int *arr;
    int max;

};

void main(){
    printf("Enter the size of the stack:");
    int n;
    scanf("%d",&n);
    struct stack stack=create_stack(n);
    struct stack *stack_ptr=&stack;
    int choice;
    while(1){
        printf("enter the choice of your interest:\n1.push\n2.pop\n3.peek\n4.display\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
               printf("enter the element to be pushed in the stack:");
               int data;
               scanf("%d",&data);
               push(stack_ptr,data);
               break;
            case 2:
               printf("the popped element is :");
               printf("%d\n",pop(stack_ptr));
               break;   
            case 3:
               peek(stack_ptr);
               break;  
            case 4:
               display(stack_ptr);
               break;   
            default:
               printf("invalid choice");
               return;
               break ;  
        }
    }
}


struct stack create_stack(int size){
    struct stack a;
    a.top=-1;
    a.max=size;
    a.arr=malloc(size*sizeof(int));
    return a;
}


void push(struct stack *a,int data){
     if(a->top==a->max-1){
        printf("the stack is overflowing :...!\n");
        return;
     }else{
        a->top=a->top+1;
        a->arr[a->top]=data;
        return;
     }
}

int pop(struct stack *a){
    if(a->top==-1){
        printf("The stack is underflow!\n");
        return;
    }else{
        int z=a->arr[a->top];
        a->top=a->top-1;
        return z;
    }
}

void peek(struct stack *a){
    if(a->top==-1){
        printf("The stack is empty..!\n");
        return ;
    }
    else{
        printf("The top element is :%d\n",a->arr[a->top]);
        return;
    }
}

void display(struct stack *a){
    if(a->top==-1){
        printf("the stack is empty...!\n");
        return;
    }else{
        for(int i=a->top;i>=0;i--){
            printf("%d ",a->arr[i]);
        }
        printf("\n");
        return;
    }
}

