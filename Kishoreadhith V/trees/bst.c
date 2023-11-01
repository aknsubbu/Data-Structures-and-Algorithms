#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int * bst_insert(int num){
    int *bst = (int *)calloc((int)((pow(2, (double)(num))) - 1), sizeof(int));
    for (int i = 0; i < num; i++)
    {
        int data;
        printf("Enter data: ");
        scanf("%d", &data);
        int index = 0;
        while (bst[index] != 0)
        {
            if (data < bst[index])
            {
                index = 2 * index + 1;
            }
            else
            {
                index = 2 * index + 2;
            }
        }
        bst[index] = data;
                
    }
    return bst;
    
}

// void bst_display(int *bst, int num){
//     int prev_lvl = 0;
//     for (int i = 0; i < pow(2, num) - 1; i++)
//     {
//         if (bst[i] != 0)
//         {
//             int lvl = log2(i + 1);
//             if (prev_lvl != lvl)
//             {
//                 printf("\n");
//                 prev_lvl = lvl;
//             }
//             printf("%d ", bst[i]);
//         }
//     }
    
// }

void display_array(int *arr, int size){
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }   
}




int main(){
    int num;
    printf("Enter number of nodes: ");
    scanf("%d", &num);
    int *bst = bst_insert(num);
    display_array(bst, num);
    return 0;
}