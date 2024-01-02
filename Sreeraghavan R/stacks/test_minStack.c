#include <stdio.h>
#include "MinStack.h"

int main() {
    // Create a new MinStack object
    MinStack* obj = minStackCreate();

    // Push elements onto the stack
    minStackPush(obj, 5);
    minStackPush(obj, 3);
    minStackPush(obj, 7);

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