void swap(int a, int b, int * array){
    int temp = *(array + a);
    *(array + a) = *(array + b);
    *(array + b) = temp;
}