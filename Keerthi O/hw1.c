#include<stdio.h>
int* bubblesort(int *p,int n){
  int a=0;
  for(int i=0;i<n-1;i++){
    for(int j=0;j<n-i-1;j++){
        a=1+a;
      if(p[j]>p[j+1]){
        int temp=p[j];
        p[j]=p[j+1];
        p[j+1]=temp;
        
        
    }
      // else{
      //   continue;
      // }
  
      }
   // break;
}  printf("%d",a);
  return p;
}
int main(){
//   int n;
//   printf("enter number:");
//   scanf("%d",&n);
//   int *p=(int*)malloc(sizeof(int)*n);
//   for(int i=0;i<n;i++){
//     printf("enter the element");
//     scanf("%d",p+i);
  FILE *fp=fopen("filens.txt","r");
    if(fp==NULL){
        printf("error");
        return 0;
        }
    else{
        int n=100000;
        int *p=(int*)malloc(sizeof(int)*n);
        for(int i=0;i<n;i++){
            fscanf(fp,"%d",p+i);
        }
        bubblesort(p,n);
        fclose(fp);
        free(p);
    }
    // int *result=bubblesort(p,n);
    // for(int i=0;i<n;i++){
    //   printf("%d",result[i]);
    
  }
