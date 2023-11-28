#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Heap{
    int* arr;
    int last, size;
};

struct Heap* createHeap(int size){
    struct Heap *heap = (struct Heap*) malloc (sizeof(struct Heap));
    heap->arr = (int *) calloc (size, sizeof(int));
    heap->size = size;
    heap->last = -1;
}

int index_check(int index, int num){
    if ((index >= pow(2, num) - 1) || (index < 0))
    {
        return 0;
    }
    return 1;
}

int left_child(int index){
    return (2 * index) + 1;
}
int right_child(int index){
    return (2 * index) + 2;
}

int parent(int index){
    return (index - 1) / 2;
}

void percolate_up(int *arr, int index){
    if (index == 0)
    {
        return;
    }
    if (arr[parent(index)] > arr[index])
    {
        int temp = arr[parent(index)];
        arr[parent(index)] = arr[index];
        arr[index] = temp;
    } else {
        return;
    }    
    percolate_up(arr, parent(index));
}

void percolate_down(int *arr, int index, int last){
    if(index > last){
        return;
    }
    if (arr[index] < arr[left_child(index)] && arr[index] < arr[right_child(index)])
    {
        return;
    }
    if (arr[left_child(index)] < arr[right_child(index)])
    {
        // left child is smaller
        if (arr[index] > arr[left_child(index)])
        {
            int temp = arr[index];
            arr[index] = arr[left_child(index)];
            arr[left_child(index)] = temp;
            percolate_down(arr, left_child(index), last);
        }
    } else {
        if (arr[index] > arr[right_child(index)])
        {
            int temp = arr[index];
            arr[index] = arr[right_child(index)];
            arr[right_child(index)] = temp;
            percolate_down(arr, right_child(index), last);
        }
    }
    
}

void insert(struct Heap *h, int val) {
    if (h->last + 1 >= h->size) {
        h->size++;
        h->arr = (int *)realloc(h->arr, h->size * sizeof(int));

        for (int i = h->last + 1; i < h->size; ++i) {
            h->arr[i] = 0;  
        }
    }
    h->last++;
    h->arr[h->last] = val;
    percolate_up(h->arr, h->last);
}

void delete_min(struct Heap *h){
    h->arr[0] = h->arr[h->last];
    // h->arr[h->last] = 0;
    h->last--;
    h->size--;
    percolate_down(h->arr, 0, h->last);
}

void display_tree(int *tree, int index, int size, int level){
    if(index > size){
        return;
    }
    if(tree[index] == 0){
        return;
    }
    
    display_tree(tree, 2 * index + 2, size, level + 1);
    for(int i = 0; i < level; i++){
        printf("|\t");
    }
    printf("|------>%d\n", tree[index]);
    display_tree(tree, 2 * index + 1, size, level + 1);
}

int main(){
    int n, data;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    struct Heap *heap = createHeap(n);
    heap->size = n;
    for (int i = 0; i < n; i++)
    {
        printf("Enter data: ");
        scanf("%d", &data);
        insert(heap, data);
    }
    display_tree(heap->arr, 0, heap->size, 0);
    printf("____________________________________\n\n");
    delete_min(heap);
    display_tree(heap->arr, 0, heap->size, 0);
}