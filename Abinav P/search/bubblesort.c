// bubble sort in single forloop and double forloop

// #include<Stdio.h>
// #include<stdlib.h>
// int *bsort(int *array,int number){
//     int i,j,temp;
//     for(i=0;i<number;i++){
//         for(j=0;j<number-i-1;j++){
//             if(array[j]>array[j+1]){
//                 temp=array[j];
//                 array[j]=array[j+1];
//                 array[j+1]=temp;
//             }
//         }
//     }
//     return array;
// }
// int *bsort(int array[],int number){
//     for(int i=0;i<number;i++){
//         if(array[i]>array[i+1]){
//             int temp=array[i];
//             array[i]=array[i+1];
//             array[i+1]=temp;
//         }
//     }
// }

// void main(){
//     int number;
//     printf("Enter the number of elements: ");
//     scanf("%d",&number);
//     int *array=(int *)malloc(number*sizeof(int));   
//     for(int i=0;i<number;i++){
//         scanf("%d",&array[i]);
//     }
//     array=bsort(array,number);
//     for(int i=0;i<number;i++){
//         printf("%d ",array[i]);
//     }
// }


// //bubble sort in ascending order and descending order
// #include<stdio.h>
// #include "customfunctions.h"
// void main(){
//    int number;
//    printf("Enter the number of elements: ");
//    scanf("%d",&number);
//    int *array=(int *)malloc(number*sizeof(int));
//     for(int i=0;i<number;i++){
//          scanf("%d",&array[i]);
//     }
//     int sorted=bubblesort(array,number);
//     for(int i=0;i<number;i++){
//         printf("%d ",array[i]);
//     }

//     int descending=bubblesortdescending(array,number);
//     printf("\n");
//     for(int i=0;i<number;i++){
//         printf("%d ",array[i]);
//     }
// }

//randomize elements in an array
// #include<stdio.h>
// #include "customfunctions.h"
// void main(){
//     int array[]={1,2,3,4,5};
//     int number=sizeof(array)/sizeof(array[0]);
//     int *randomized=randomize(array,number);
//     for(int i=0;i<number;i++){
//         printf("%d ",randomized[i]);
//     }
// }


// #include<Stdio.h>
// #include<Stdlib.h>
// #include<time.h>
// void main(){
//     srand(time(NULL));
//     printf("%d",rand());
// }


// #include<stdio.h>
// void main(){
//     int k=0;
//     for(int i=0;i<100-1;i++)    {
//         for(int j=0;j<100-i-1;j++){
//            k++;
//            printf("%d ",k);
//         }
//     }
// }


//storing 1 lakh numbers in a file in ascending order
// #include<stdio.h>
// #include "customfunctions.h"
// void main(){
//     FILE *fp;
//     fp=fopen("ascending.txt","w");
//     int number=100000;
//     int array[number];
//     for(int i=0;i<number;i++){
//         array[i]=i+1;
//     }
//     int *ascending_array=bubblesort(array,number);
//     for(int i=0;i<number;i++){
//         fprintf(fp,"%d ",ascending_array[i]);
//     }
//     fclose(fp);
//}


//storing 1 lakh numbers in a file in descending order
// #include<stdio.h>
// #include "customfunctions.h"
// void main(){
//     FILE *fp;
//     fp=fopen("descending.txt","w");
//     int number=100000;
//     int array[number];
//     for(int i=0;i<number;i++){
//         array[i]=number-i;
//     }
//     int *descending_array=bubblesortdescending(array,number);
//     for(int i=0;i<number;i++){
//         fprintf(fp,"%d ",descending_array[i]);
//     }
//     fclose(fp);
// }

//storing 1 lakh numbers in a file in random order
// #include<stdio.h>
// #include "customfunctions.h"
// void main(){
//     FILE *fp;
//     fp=fopen("random.txt","w");
//     int number=100000;
//     int array[number];
//     for(int i=0;i<number;i++){
//         array[i]=i+1;
//     }
//     int *random_array=randomize(array,number);
//     for(int i=0;i<number;i++){
//         fprintf(fp,"%d ",random_array[i]);
//     }
//     fclose(fp);
// }


//#include<stdio.h>
// #include<stdlib.h>
// #include "customfunctions.h"
// void main(){
//     FILE *fp;
//     fp=fopen("nearlysorted.txt","w");
//     int *array1to100=(int *)malloc(100*sizeof(int));
//     for(int i=0;i<100;i++){
//         array1to100[i]=i+1;
//     }
//     int *ascending_array=bubblesort(array1to100,100);
//     for(int i=0;i<100;i++){
//         fprintf(fp,"%d ",ascending_array[i]);
//     }
//     int *array100to150=(int *)malloc(50*sizeof(int));
//     for(int i=0;i<50;i++){
//         array100to150[i]=i+100;
//     }
//     int *random_array=randomize(array100to150,50);
//     for(int i=0;i<50;i++){
//         fprintf(fp,"%d ",random_array[i]);
//     }
//     int *array151to412=(int *)malloc(262*sizeof(int));
//     for(int i=0;i<262;i++){
//         array151to412[i]=i+151;
//     }
//     int *new_array=bubblesort(array151to412,262);
//     for(int i=0;i<262;i++){
//         fprintf(fp,"%d ",new_array[i]);
//     }
//     int *array413to512=(int *)malloc(100*sizeof(int));
//     for(int i=0;i<100;i++){
//         array413to512[i]=i+413;
//     }
//     int *random_array2=randomize(array413to512,100);
//     for(int i=0;i<100;i++){
//         fprintf(fp,"%d ",random_array2[i]);
//     }
//     int *array513to860=(int *)malloc(348*sizeof(int));
//     for(int i=0;i<348;i++){
//         array513to860[i]=i+513;
//     }
//     int *new_array2=bubblesort(array513to860,348);
//     for(int i=0;i<348;i++){
//         fprintf(fp,"%d ",new_array2[i]);
//     }
//     int *array860to960=(int *)malloc(100*sizeof(int));
//     for(int i=0;i<100;i++){
//         array860to960[i]=i+860;
//     }
//     int *random_array3=randomize(array860to960,100);
//     for(int i=0;i<100;i++){
//         fprintf(fp,"%d ",random_array3[i]);
//     }
//     int *array961to1000=(int *)malloc(40*sizeof(int));
//     for(int i=0;i<40;i++){
//         array961to1000[i]=i+961;
//     }
//     int *new_array3=bubblesort(array961to1000,40);
//     for(int i=0;i<40;i++){
//         fprintf(fp,"%d ",new_array3[i]);
//     }
//     fclose(fp);
    


// }

#include<stdio.h>
#include<stdlib.h>
int main(){
    FILE *fptr;
    fptr=fopen("merelysorted.txt","w");
    int n=100000;
    int *p=(int *)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++){
        p[i]=i+1;
    }
    //meresort(p,100,150);
    //meresort(p,860,900);
    //meresort(p,413,512);
    for(int i=0;i<n;i++){
        fprintf(fptr,"%d\n",p[i]);
    }
    printf("done");
    fclose(fptr);
    return 0;
}

int *bubblesor(int *a,int n){
    for(int k=0;k<n-1;k++){
        for(int i=0;i<n-k-1;i++){
            if(a[i]>a[i+1]){
                swap(&a[i],&a[i+1]);
            }
        }
    }
}

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}