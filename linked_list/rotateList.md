# Rotate List  

Given a linked list, rotate the list to the right by k places, where k is non-negative number (k can be greater than length of linked list)  
Example:

```
head: 1->2->3->4->5, k = 2
result: 4->5->1->2->3
__Explanation__:  
result: 5->1->2->3->4 when k = 1
result: 4->5->1->2->3 when k = 2  

head: 1->2->3, k = 4
result: 2->1->3  
__Explanation__:
result: 3->1->2 k = 1
result: 2->3->1 k = 2
result: 1->2->3 k = 3
result: 3->1->2 k = 4
```

