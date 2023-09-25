void swap(int*l, int i, int j){
    int temp = l[i];
    l[i] = l[j];
    l[j] = temp;
}

void bsortf(int* l,int n){   
    int check = 1;
    int i = 0;
    double sum = 0.0;
    for(i;i<n;i++){
        if(check){
            check = 0;
            for(int j = i;j<n-1;j++){
                sum+= 1;
                if(l[j] > l[j+1]){
                    swap(l,j,j+1);                   
                    check = 1;
            }
        }
        }else{
            break;
        }
    }
    
}


int* readrandom(int len){
    FILE* fr = fopen("random.txt","r");
    int* lr = (int*)malloc(len*sizeof(int));
    for(int i = 0;i<len;i++){
        fscanf(fr,"%d ",lr+i);
    }
    return lr;
}

int power10(int exp){
    int res = 1;
    for(int i = 0;i<exp;i++){
        res = res*10;
    }
    return res;
}