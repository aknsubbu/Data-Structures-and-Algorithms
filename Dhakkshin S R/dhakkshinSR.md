# Data Structures

## Bubble Sort



### 28/08/2023
## Insertion Sort
###
1.  Let the “sorted list” consist of one item – the first item in the input list
2.  Let the “unsorted list” consist of all input items except the first one
3.  Repeat the following steps until the unsorted list is empty
    1.  Let the “insert item” be the first item in the unsorted list
    2.  Let the “current item” be the last item in the sorted list
    3.  Repeat until the “insert item” has been inserted into the sorted list
        1.  If the beginning of the sorted list has been reached then
            1.  Place the “insert item” at the beginning of the sorted list
            2.  Note that the “insert item” has been inserted
        2.  If the “current item” is less than or equal to the “insert item” then
            1.  Place the “insert item” immediately after the “current item”
            2.  Note that the “insert item” has been inserted
        3.  If the “insert item” has not yet been inserted then
            1.  If the “current Item” is not the first item in the sorted list
                - then   Let the item immediately preceding the present
       "current item” be the new “current item”
                - else   Note that the beginning of the sorted list has been reached
4.  Halt (The sorted list now contains all of the input items, in order.)