# Validate Binary Search Tree  
Given a binary tree, determine if it is a valid binary search tree.  
A binary search tree is defined as:
- The left subtree of a node contains only nodes with keys less than the node's key.  
- The right subtree of a node contains only nodes with keys greater than the node's key.  
- Both the left and right subtree must also be binary tree.  
Example:  
```
root:
    2
  /   \
 1     3

result: true

root:
    1
  /   \
 2     3

result: false
```

