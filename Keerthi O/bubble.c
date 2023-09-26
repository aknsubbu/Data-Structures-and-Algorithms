#include<stdio.h>
void bubblesort(int n,int* arr){
    int a=0;
    for(int i=n-1;i>1;i--){
        for(int j=0;j<i;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
                a=a+1;
            }
        }
    }
    printf("%d",a);
}

int main(){
    int n;
    printf("enter number:");
    scanf("%d",&n);
    int *p=(int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++){
        printf("enter the element");
        scanf("%d",p+i);
    }
    bubblesort(n,p);
    for(int i=0;i<n;i++){
        printf("%d",p[i]);
    }
}