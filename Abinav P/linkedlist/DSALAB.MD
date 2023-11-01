## 1. Pow(x, n)

### Problem statement:

Implement pow(x, n), which calculates x raised to the power n (i.e., xn).


### Solution

```c
double myPow(double x, int n) {
    if (n == 0) {
        return 1.0;
    }
    
    double half = myPow(x, n / 2);
    
    if (n % 2 == 0) {
        return half * half;
    }
    
    else if (n > 0) {
        return half * half * x;
    } else {
        return half * half / x;
    }
}
```

### Time complexity

O(logn)

### Space complexity

O(logn)

### runtime info

__Runtime:__ 1 ms, faster than 100.00% of C online submissions for Pow(x, n).

__Memory Usage:__ 5.6 MB, less than 100.00% of C online submissions for Pow(x, n).


## 2. Two Sum

### Problem statement:

Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

```c
int* twoSum(int* nums, int  N, int target, int* returnSize){
    int *arr = malloc(2*sizeof(int));
    *returnSize = 0;
    for(int i=0; i < N-1; i++){
        for(int j=i+1; j < N; j++){
            if(nums[i] + nums[j] == target){
                arr[0] = i; 
                arr[1] = j;
                *returnSize+=2;
                return arr;
            }
        }
    }
    return arr;
}

```

### Time complexity

O(n^2)

### Space complexity

O(1)

### runtime info

__Runtime:__ 75 ms, faster than 79.2% of C online submissions for Two Sum.

__Memory Usage:__ 6.6 MB, less than 19.30% of C online submissions for Two Sum.


## 3. Reverse Integer

### Problem statement:

Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

```c
int reverse(int x) {
    int reversed = 0;

    while (x != 0) {
        
        if (reversed > INT_MAX / 10 || reversed < INT_MIN / 10) {
            return 0;
        }
        
        reversed = reversed * 10 + x % 10;
        x /= 10;
    }

    return reversed;
}
```

### Time complexity

O(n)

### Space complexity

O(1)

### runtime info

__Runtime:__ 6 ms, faster than 11.4% of C online submissions for Reverse Integer.

__Memory Usage:__ 5.6 MB, less than 27.73% of C online submissions for Reverse Integer. 

## 4.Remove Duplicates from Sorted Array

### Problem statement:

Given a sorted array nums, remove the duplicates in-place such that each element appears only once and returns the new length.

```c
int removeDuplicates(int* nums, int numsSize){
      if (numsSize <= 1) {
        return numsSize; 
    }
    
    int uniqueCount = 1;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] != nums[i - 1]) {
            nums[uniqueCount] = nums[i]; 
            uniqueCount++;
        }
    }
    
    return uniqueCount;
}
```

### Time complexity

O(n)

### Space complexity

O(1)

### runtime info

__Runtime:__ 15 ms, faster than 21.55% of C online submissions for Remove Duplicates from Sorted Array.


__Memory Usage:__ 8.1 MB, less than 14.52% of C online submissions for Remove Duplicates from Sorted Array.


## 5. Plus One

### Problem statement:

Given a non-empty array of decimal digits representing a non-negative integer, increment one to the integer.

The digits are stored such that the most significant digit is at the head of the list, and each element in the array contains a single digit.

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int carry = 1; 
    for (int i = digitsSize - 1; i >= 0; i--) {
        int sum = digits[i] + carry;
        digits[i] = sum % 10;  
        carry = sum / 10;      
    }
    if (carry > 0) 
    {
        (*returnSize) = digitsSize + 1;
        int *result = malloc((*returnSize) * sizeof(int));
        result[0] = carry;
        for (int i = 0; i < digitsSize; i++)
        {
            result[i + 1] = digits[i];
        }
        return result;
    } 
    else
    {
        (*returnSize) = digitsSize;
        return digits;
    }
}
```

### Time complexity

O(n)

### Space complexity

O(1)

### runtime info

__Runtime:__ 0 ms, faster than 100.00% of C online submissions for Plus One.

__Memory Usage:__ 5.8 MB, beats 90.22% of C online submissions for Plus One.


## 6. Roman to Integer  

### Problem statement:

Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

```java
class Solution {
    public int romanToInt(String s) {
        int currVal = 0;
        int prevVal = 0;
        int res = 0;
        for(int i = s.length() - 1; i >= 0; i--) {
            switch(s.charAt(i)) {
                case 'I' :
                    currVal = 1;
                    break;
                case 'V' :
                    currVal = 5;
                    break;
                case 'X' :
                    currVal = 10;
                    break;
                case 'L' :
                    currVal = 50;
                    break;
                case 'C' :
                    currVal = 100;
                    break;
                case 'D' :
                    currVal = 500;
                    break;
                case 'M' :
                    currVal = 1000;
                    break;
            }
            if(currVal < prevVal) {
                res -= currVal;
            } else {
                res += currVal;
            }
            prevVal = currVal;
        }
        return res;
    }
}

```


### Time complexity

O(n)

### Space complexity

O(1)

### runtime info

__Runtime:__ 2 ms, faster than 100% of Java online submissions for Roman to Integer.

__Memory Usage:__ 43.4 MB, less than 84.2% of Java online submissions for Roman to Integer.


## 7. find the duplicate number

### Problem statement:

Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

```python
class Solution(object):
    def findDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        output=set()
        return next(num for num in nums if num in output or output.add(num))
```

### Time complexity

O(n)

### Space complexity

O(1)

### runtime info

__Runtime:__ 463 ms, faster than 82.98% of Python online submissions for Find the Duplicate Number.

__Memory Usage:__ 25.9 MB, less than 5.26% of Python online submissions for Find the Duplicate Number.


## 8. Remove duplicates from sorted list

### Problem statement:

Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.

```java

class Solution {
   public ListNode deleteDuplicates(ListNode head) {
        ListNode current = head;

        while (current != null && current.next != null) {
            if (current.val == current.next.val) {
                current.next = current.next.next;
            } else {
                current = current.next;
            }
        }

        return head;
    }
}
```

### Time complexity

O(n)

### Space complexity

O(1)

### runtime info

__Runtime:__ 0 ms, faster than 100.00% of Java online submissions for Remove Duplicates from Sorted List.

__Memory Usage:__ 38.4 MB, less than 5.03% of Java online submissions for Remove Duplicates from Sorted List.


## 9. convert binary number in a linked list to integer

### Problem statement:

Given head which is a reference node to a singly-linked list. The value of each node in the linked list is either 0 or 1. The linked list holds the binary representation of a number.

Return the decimal value of the number in the linked list.

```java
class Solution {
    public int getDecimalValue(ListNode head) {
        String sol="";
        while(head!=null){
          sol+=head.val;
          head=head.next;
        }
        int x=Integer.parseInt(sol,2);
        return x;
    }
}
```

### Time complexity

O(n)

### Space complexity

O(1)

### runtime info

__Runtime:__ 9 ms, faster than 5.78% of Java online submissions for Convert Binary Number in a Linked List to Integer.

__Memory Usage:__ 40.3 MB, less than 26.83% of Java online submissions for Convert Binary Number in a Linked List to Integer.


## 10. Remove Element

### Problem statement:

Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The relative order of the elements may be changed.

```java
class Solution {
    public int removeElement(int[] nums, int val) {
     int k=0;
     for(int i=0;i<nums.length;i++){
         if(nums[i]!=val){
           nums[k]=nums[i];
           k++;   
         }
     }   
     return k;
    }
}
```

### Time complexity

O(n)

### Space complexity

O(1)

### runtime info

__Runtime:__ 0 ms, faster than 100.00% of Java online submissions for Remove Element.

__Memory Usage:__ 40.4 MB, less than 79.55% of Java online submissions for Remove Element.


## 11. Median of Two Sorted Arrays

### Problem statement:

Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

```java
class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
    ArrayList<Integer>list=new ArrayList<>();
    for(int i:nums1)list.add(i);
    for(int j:nums2)list.add(j);
    Collections.sort(list);
    int size=list.size();
    return (double)(list.get((size-1)/2)+list.get((size)/2))/2;
    }
}
```

### Time complexity

O(nlogn)

### Space complexity

O(n)

### runtime info

__Runtime:__ 3 ms, faster than 42.86% of Java online submissions for Median of Two Sorted Arrays.

__Memory Usage:__ 40.4 MB, less than 71.55% of Java online submissions for Median of Two Sorted Arrays.

## 12.Reverse Linked List

### Problem statement:

Given the head of a singly linked list, reverse the list, and return the reversed list.

```java

class Solution {
    public ListNode reverseList(ListNode head) {
        ListNode prev = null;  
        ListNode current = head;
    
        
        while(current != null) { 
            ListNode next = current.next; 
            current.next = prev;
            prev = current;
            current = next;
        }
       return prev; 
    }
}
```

### Time complexity


O(n)

### Space complexity

O(1)

### runtime info

__Runtime:__ 0 ms, faster than 100.00% of Java online submissions for Reverse Linked List.

__Memory Usage:__ 38.5 MB, less than 79.55% of Java online submissions for Reverse Linked List.

## 13. Remove Linked List Elements

### Problem statement:

Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.

```java

class Solution {
    public ListNode removeElements(ListNode head, int val) {
        if (head == null) {
            return null;
        }

        ListNode dummy = new ListNode();
        dummy.next = head;
        ListNode cur = dummy;

        while (cur.next != null) {
            if (cur.next.val == val) {
                cur.next = cur.next.next;
                // Here cannot move cur to cur.next as we need to validate the next node.
            } else {
                cur = cur.next;
            }
        }

        return dummy.next;
    }
}
```

### Time complexity

O(n)

### Space complexity

O(1)

### runtime info

__Runtime:__ 1 ms, faster than 78.95% of Java online submissions for Remove Linked List Elements.

__Memory Usage:__ 39.9 MB, less than 5.03% of Java online submissions for Remove Linked List Elements.


## Result :

   Thus the above programs are executed and its output is verified.
   
