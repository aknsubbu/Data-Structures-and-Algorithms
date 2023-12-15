// //bubble sort
// #include<stdio.h>
// #include<Stdlib.h>
// #include<time.h>

// int *bubble(double sampleLengthVar, int* sampleArrayPtr){
//     int temp;
//     for(i)
//     for(int i=0;i<sampleLengthVar-1;i++){
//         for(int j=0;j<sampleLengthVar-i-1;j++){
//             if(sampleArrayPtr[j]>sampleArrayPtr[j+1]){
//                 temp=sampleArrayPtr[j];
//                 sampleArrayPtr[j]=sampleArrayPtr[j+1];
//                 sampleArrayPtr[j+1]=temp;
//             }
//         }
//     }

//     return sampleArrayPtr;
// }

// int* readFile(char filename[]){
//     FILE *fp;
//     fp = fopen(filename, "r");

//     int  sampleElement;
//     double sampleLengthVar=100000;
//     //fscanf(fp, "%d", &sampleLengthVar);
//     printf("Scanning a sample of length: %f\n", sampleLengthVar);

//     printf("    ALLOC-PTR_START\n");
//     int* sampleArrayPtr = (int*)malloc(sampleLengthVar * sizeof(int));
//     printf("    ALLOC-PTR_END\n");

//     for(int i = 0; i < sampleLengthVar; i++){
//         fscanf(fp, "%d", &sampleElement);
//         sampleArrayPtr[i] = sampleElement;
//     }
//     fclose(fp);
//     return sampleArrayPtr;
// }

// int main(){
//     int *sampleArrayPtr;
//     sampleArrayPtr=readFile("nearlysorted.txt");
//     double sampleLengthVar;
//     sampleLengthVar=100000;
//     clock_t start,end;
//     start=clock();
//     int *result=bubble(sampleLengthVar,sampleArrayPtr);
//     end=clock();
//     double time_taken=((double)(end-start))/CLOCKS_PER_SEC;
//     printf("Time taken: %f\n",time_taken);
//     FILE *fp;
//     fp=fopen("bubble.txt","w");
//     for(int i=0;i<sampleLengthVar;i++){
//         fprintf(fp,"%d ",result[i]);
//     }
//     fclose(fp);
//     return 0;
// }

// insertion sort

// #include<stdio.h>
// #include<Stdlib.h>
// #include<time.h>

// int *insertion(double sampleLengthVar, int* sampleArrayPtr){
//     int key,j;
//     for(int i=1;i<sampleLengthVar;i++){
//         key=sampleArrayPtr[i];
//         j=i-1;
//         while(j>=0 && sampleArrayPtr[j]>key){
//             sampleArrayPtr[j+1]=sampleArrayPtr[j];
//             j=j-1;
//         }
//         sampleArrayPtr[j+1]=key;
//     }
//     return sampleArrayPtr;
// }

// int* readFile(char filename[]){
//     FILE *fp;
//     fp = fopen(filename, "r");

//     int  sampleElement;
//     double sampleLengthVar=100000;
//     //fscanf(fp, "%d", &sampleLengthVar);
//     printf("Scanning a sample of length: %f\n", sampleLengthVar);

//     printf("    ALLOC-PTR_START\n");
//     int* sampleArrayPtr = (int*)malloc(sampleLengthVar * sizeof(int));
//     printf("    ALLOC-PTR_END\n");

//     for(int i = 0; i < sampleLengthVar; i++){
//         fscanf(fp, "%d", &sampleElement);
//         sampleArrayPtr[i] = sampleElement;
//     }
//     fclose(fp);
//     return sampleArrayPtr;
// }

// int main(){
//     int *sampleArrayPtr;
//     sampleArrayPtr=readFile("nearlysorted.txt");
//     double sampleLengthVar;
//     sampleLengthVar=100000;
//     clock_t start,end;
//     start=clock();
//     int *result=insertion(sampleLengthVar,sampleArrayPtr);
//     end=clock();
//     double time_taken=((double)(end-start))/CLOCKS_PER_SEC;
//     printf("Time taken: %f\n",time_taken);
//     FILE *fp;
//     fp=fopen("bubble.txt","w");
//     for(int i=0;i<sampleLengthVar;i++){
//         fprintf(fp,"%d ",result[i]);
//     }
//     fclose(fp);
//     return 0;
// }

// BINARY SEARCH
// #include<stdio.h>
// #include<Stdlib.h>
// #include<time.h>

// int binarySearch(int *sampleArrayPtr, int low, int high, int key){
//     if(high>=low){
//         int mid=low+(high-low)/2;
//         if(sampleArrayPtr[mid]==key){
//             return mid;
//         }
//         if(sampleArrayPtr[mid]>key){
//             return binarySearch(sampleArrayPtr,low,mid-1,key);
//         }
//         return binarySearch(sampleArrayPtr,mid+1,high,key);
//     }
//     return -1;
// }

// int* readFile(char filename[]){
//     FILE *fp;
//     fp = fopen(filename, "r");

//     int  sampleElement;
//     double sampleLengthVar=100000;
//     //fscanf(fp, "%d", &sampleLengthVar);
//     printf("Scanning a sample of length: %f\n", sampleLengthVar);

//     printf("    ALLOC-PTR_START\n");
//     int* sampleArrayPtr = (int*)malloc(sampleLengthVar * sizeof(int));
//     printf("    ALLOC-PTR_END\n");

//     for(int i = 0; i < sampleLengthVar; i++){
//         fscanf(fp, "%d", &sampleElement);
//         sampleArrayPtr[i] = sampleElement;
//     }
//     fclose(fp);
//     return sampleArrayPtr;
// }

// int main(){
//     int *sampleArrayPtr;
//     sampleArrayPtr=readFile("random.txt");
//     double sampleLengthVar;
//     sampleLengthVar=100000;
//     // int input;
//     // srand(time(0));
//     // input=rand()%100000;
//     //printf("Input: %d\n",input);
//     int mid=sampleLengthVar/2;
//     clock_t start,end;
//     start=clock();
//     int *result=binarySearch(sampleArrayPtr,0,sampleLengthVar-1,rand()%100000);
//     end=clock();
//     double time_taken=((double)(end-start))/CLOCKS_PER_SEC;
//     printf("Time taken: %f\n",time_taken);
//     FILE *fp;
//     fp=fopen("binary.txt","w");
//     for(int i=0;i<sampleLengthVar;i++){
//         fprintf(fp,"%d ",result[i]);
//     }
//     fclose(fp);
//     return 0;
// }

// linear search
//  #include<stdio.h>
//  #include<Stdlib.h>
//  #include<time.h>

// int linearSearch(int *sampleArrayPtr, int sampleLengthVar, double key){
//     for(int i=0;i<sampleLengthVar;i++){
//         if(sampleArrayPtr[i]==key){
//             return i;
//         }
//     }
//     return -1;
// }

// int* readFile(char filename[]){
//     FILE *fp;
//     fp = fopen(filename, "r");

//     int  sampleElement;
//     double sampleLengthVar=100000;
//     //fscanf(fp, "%d", &sampleLengthVar);
//     printf("Scanning a sample of length: %f\n", sampleLengthVar);

//     printf("    ALLOC-PTR_START\n");
//     int* sampleArrayPtr = (int*)malloc(sampleLengthVar * sizeof(int));
//     printf("    ALLOC-PTR_END\n");

//     for(int i = 0; i < sampleLengthVar; i++){
//         fscanf(fp, "%d", &sampleElement);
//         sampleArrayPtr[i] = sampleElement;
//     }
//     fclose(fp);
//     return sampleArrayPtr;
// }

// int main(){
//     int *sampleArrayPtr;
//     sampleArrayPtr=readFile("nearlysorted.txt");
//     double sampleLengthVar;
//     sampleLengthVar=100000;
//     // int input;
//     // srand(time(0));
//     // input=rand()%100000;
//     // printf("Input: %d\n",input);
//     clock_t start,end;
//     start=clock();
//     int result=linearSearch(sampleArrayPtr,sampleLengthVar,100000);
//     end=clock();
//     printf("Result: %d\n",result);
//     printf("%d\n",sampleArrayPtr[result]);
//     double time_taken=((double)(end-start))/CLOCKS_PER_SEC;
//     printf("Time taken: %f\n",time_taken);
//     return 0;
// }
