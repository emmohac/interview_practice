# Delete a Node From Binary Search Tree
Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:
- Search for a node to remove.
- If the node is found, delete the node.

Example:
```
root:
            5
          /   \
         3     6
       /   \     \
      2     4     7
to_delete = 3

result:
            5
          /   \
         4     6
       /         \
      2           7
```

