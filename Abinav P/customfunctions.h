//bubble sort  in ascending order

int *bubblesort(int *array, int size){
    int i, j, temp;
    for(i = 0; i < size; i++){
        for(j = 0; j < size - i - 1; j++){
            if(array[j] > array[j + 1]){
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
    return array;
}

//bubble sort in descending order

int bubblesortdescending(int *array, int size){
    int i, j, temp;
    for(i = 0; i < size; i++){
        for(j = 0; j < size - i - 1; j++){
            if(array[j] < array[j + 1]){
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
    return array;
}

//randomize elements in array
int *randomize(int arr[],int n){
    srand ( time(NULL) );
 
    // Start from the last element and swap one by one. We don't
    // need to run for the first element that's why i > 0
    for (int i = n-1; i > 0; i--)
    {
        // Pick a random index from 0 to i
        int j = rand() % (i+1);
 
        // Swap arr[i] with the element at random index
        swap(&arr[i], &arr[j]);
    }

}

void swap(int *a,int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}