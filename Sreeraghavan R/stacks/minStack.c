
#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int* min;
    int* data;
    int size;
} MinStack;


MinStack* minStackCreate() {
    MinStack* new = (MinStack*)malloc(sizeof(MinStack));
    new->min = new->data = NULL;
    new->size = 0;
    return new;
}

void minStackPush(MinStack* obj, int val) {
    obj->size += 1;
    obj->data = (int*)realloc(obj->data, obj->size * sizeof(int));
    obj->min = (int*)realloc(obj->min, obj->size * sizeof(int));
    if (val < obj->min[(obj->size) - 2])
        obj->min[(obj->size) - 1] = val;
    else
        obj->min[(obj->size) - 1] = obj->min[(obj->size) - 2];
    obj->data[(obj->size) - 1] = val;
}

void minStackPop(MinStack* obj) {
    if(obj->size == 0) return;
    obj->size -= 1;
    obj->data = (int*)realloc(obj->data,obj->size * sizeof(int));
    obj->min = (int*)realloc(obj->min,obj->size * sizeof(int));
}

int minStackTop(MinStack* obj) {
    return obj->data[(obj->size)-1];
}

int minStackGetMin(MinStack* obj) {
    return obj->min[(obj->size)-1];
    
}

void minStackFree(MinStack* obj) {
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/
// int main() {
//     // Testcase 1
//     MinStack* obj = minStackCreate();
//     minStackPush(obj, 5);
//     minStackPush(obj, 2);
//     minStackPush(obj, 7);
//     minStackPush(obj, 1);
//     printf("Top element: %d\n", minStackTop(obj)); // Output: 1
//     printf("Minimum element: %d\n", minStackGetMin(obj)); // Output: 1
//     minStackPop(obj);
//     printf("Top element after pop: %d\n", minStackTop(obj)); // Output: 7
//     printf("Minimum element after pop: %d\n", minStackGetMin(obj)); // Output: 2
//     minStackFree(obj);
    
//     // Testcase 2
//     obj = minStackCreate();
//     minStackPush(obj, 10);
//     minStackPush(obj, 5);
//     minStackPush(obj, 8);
//     minStackPush(obj, 3);
//     printf("Top element: %d\n", minStackTop(obj)); // Output: 3
//     printf("Minimum element: %d\n", minStackGetMin(obj)); // Output: 3
//     minStackPop(obj);
//     printf("Top element after pop: %d\n", minStackTop(obj)); // Output: 8
//     printf("Minimum element after pop: %d\n", minStackGetMin(obj)); // Output: 5
//     minStackFree(obj);
    
    
//     return 0;
// }

int main(){
        // Create a new MinStack object
    MinStack* obj = minStackCreate();

    // Push elements onto the stack
    minStackPush(obj, -2);
    minStackPush(obj, 0);
    minStackPush(obj, -3);

    // Get the minimum value in the stack
    int min = minStackGetMin(obj);
    printf("Minimum value in the stack: %d\n", min);

    // Pop an element from the stack
    minStackPop(obj);

    // Get the top element of the stack
    int top = minStackTop(obj);
    printf("Top element of the stack: %d\n", top);

    // Get the updated minimum value in the stack
    min = minStackGetMin(obj);
    printf("Updated minimum value in the stack: %d\n", min);

    // Free the memory allocated for the stack
    minStackFree(obj);

    return 0;
}