#include <stdio.h>
#include <stdlib.h>
#include "utilities.h"
#include <time.h>


int main(){
    //defining the array
    FILE* fa = fopen("ascsorted.txt","r");
    FILE* fd = fopen("descsorted.txt","r");
    FILE* fr = fopen("random.txt","r");
    FILE* fn = fopen("nearlysorted.txt","r");


    int* la = (int*)malloc(100000*sizeof(int));
    for(int i = 0;i<100000;i++){
        fscanf(fa,"%d ",la+i);
    }
    int* ld = (int*)malloc(100000*sizeof(int));
    for(int i = 0;i<100000;i++){
        fscanf(fd,"%d ",ld+i);
    }
    int* lr = (int*)malloc(100000*sizeof(int));
    for(int i = 0;i<100000;i++){
        fscanf(fr,"%d ",lr+i);
    }
    int* ln = (int*)malloc(100000*sizeof(int));
    for(int i = 0;i<100000;i++){
        fscanf(fn,"%d ",ln+i);
    }
    
    clock_t startla = clock();
    bsortf(la,100000);
    clock_t endla = clock();
    double timela = (double)(endla - startla) / CLOCKS_PER_SEC;
    printf("Time spent for ascsorted: %f\n", timela);

    clock_t startld = clock();
    bsortf(ld,100000);
    clock_t endld = clock();
    double timeld = (double)(endld - startld) / CLOCKS_PER_SEC;
    printf("Time spent for descsorted: %f\n", timeld);

    clock_t startlr = clock();
    bsortf(lr,100000);
    clock_t endlr = clock();
    double timelr = (double)(endlr - startlr) / CLOCKS_PER_SEC;
    printf("Time spent for random: %f\n", timelr);

    clock_t startln = clock();
    bsortf(ln,100000);
    clock_t endln = clock();
    double timeln = (double)(endln - startln) / CLOCKS_PER_SEC;
    printf("Time spent for nearlysorted: %f\n", timeln);
}   

