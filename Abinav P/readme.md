# 12-7

## STACK

_the stack data structue uses the LIFO method and it has 4 main fucntions in it push(Add),pop(remove),peek(to check the last element),isempty,search_

```java
import java.util.stack;
public class Main{
    public static void main(String[] args){
        Stack<String> stack= new Stack<String>();
        stack.push("bottom");
        stack.pop();
        stack.peek();
        stack.isEmpty();
        stack.search("bottom");
        system.out.println(stack);
    }
}
```

## QUEUE

### TYPES OF QUEUE

_1. Priority Queue_  
_2. Linked list_

**Priority queue**

- arranged in ascending order
- the first element is the least
- to reverse the order use []

```java
import java.util.PriorityQueue;
public class Main{
    public static void main(String[] args){
        PriorityQueue<String> queue= new PriorityQueue<String>();
        queue.add("bottom");
        queue.remove();
        queue.peek();
        queue.isEmpty();
        queue.search("bottom");
        system.out.println(queue);
    }
}
```

### Linked list

```java
import java.util.LinkedList;
public class Main{
    public static void main(String[] args){
        LinkedList<String> queue= new LinkedList<String>();
        queue.add("bottom");
        queue.remove();
        queue.peek();
        queue.isEmpty();
        queue.search("bottom");
        system.out.println(queue);
    }
}
```

### TIME COMPLEXITY

The number of times a basic operation gets executed

complexity analysis

- Time
- Space

example
add n numbers

```
sum=0
for i=1 to n
    sum=sum+i
end
```
