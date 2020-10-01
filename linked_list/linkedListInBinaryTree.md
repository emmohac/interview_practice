# Linked List in Binary Tree

Given a binary tree root and a linked list with head as the first node.

Return True if all the elements in the linked list starting from the head correspond to some downward path connected in the binary tree otherwise return False.

In this context downward path means a path that starts at some node and goes downwards.

Example:

```
root:
            1
        /       \
       2         3
    /     \    /    \
   4       5  6      7
 /  \     /
8    9   10

list: [1,2,4,9]
result: true

root:
            1
        /       \
       2         3
    /     \    /    \
   4       5  6      7
 /  \     /
8    9   10

list: [1,3,7,9]
result: false
```
