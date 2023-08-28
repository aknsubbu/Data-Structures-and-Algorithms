// #include<stdio.h>
// #include "swap.h"
// void main(){
//     int temp,swaps=0;
//     int array[]={5,3,1,4,2};
//    for(int i=5-1;i>1;i++){
//         for(int j = 0; j < i; j++){
//             if(array[j] > array[j + 1]){
//                 swap(&array[j],&array[j+1]);
//                 swaps++;
//             }
//         }
//     }
//     for(int i=0;i<5;i++){
//         printf("%d ",array[i]);
//     }
//     printf("the number of swaps done is %d",swaps);
// }



//insertion sort
// #include<stdio.h>

#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int *insertion(int sampleLengthVar, int* sampleArrayPtr){
    
    int i,j,key;
    for(i=1;i<sampleLengthVar;i++){
        key=sampleArrayPtr[i];
        j=i-1;
        while(j>=0 && sampleArrayPtr[j]>key){
            sampleArrayPtr[j+1]=sampleArrayPtr[j];
            j=j-1;
        }
        sampleArrayPtr[j+1]=key;
    }
    for(int i=0;i<sampleLengthVar;i++){
        printf("%d ",sampleArrayPtr[i]);
    }
    return sampleArrayPtr; 
}



int* readFile(char filename[]){
    FILE *fp;
    fp = fopen(filename, "r");
    
    int sampleLengthVar, sampleElement;

    fscanf(fp, "%d", &sampleLengthVar);
    printf("Scanning a sample of length: %d\n", sampleLengthVar);

    printf("    ALLOC-PTR_START\n");
    int* sampleArrayPtr = (int*)malloc(sampleLengthVar * sizeof(int));
    printf("    ALLOC-PTR_END\n");

    printf("    SCN-START\n");
    for (int iterable = 0; iterable < sampleLengthVar; iterable++){
        printf("    SCN-ITR: %d\r", iterable);
        fscanf(fp, "%d", &sampleElement);
        *(sampleArrayPtr + iterable) = sampleElement;
    }
    printf("\n");
    printf("    SCN-END\n");

    fclose(fp);

    int *result=insertion(sampleArrayPtr, sampleLengthVar);
    fp=fopen("insertion.txt","w");
    for(int i=0;i<sampleLengthVar;i++){
        fprintf(fp,"%d ",result[i]);
    }
    fclose(fp);
    return 0;
 }


int run(char filename[]){
    printf("Scanning for and sorting `%s` \n", filename);
    clock_t start = clock(); // start the timer

    readFile(filename);

    clock_t end = clock(); // end the timer
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time spent: %f\n", time_spent);
    printf("\n\n");
}



void main(){
    run("./descending.txt");
}

