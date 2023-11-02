#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    int level;
    printf("Enter the number of levels: ");
    scanf("%d", &level);

    int* tree = malloc(sizeof(int) * (pow(2, level) - 1));

    printf("Enter positive numbers only. enter -1 for no node");

    for(int i = 0;)
}

// start gettting input from root and fill left and right for each node.