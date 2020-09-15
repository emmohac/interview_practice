# Linked List Cycle II

Given a linked list, return the node where the cycle begins. If there is no cycle
then return nullptr

pos is used to denote the index of the pointer where the cycle begins.
pos = -1 means there is no cycle.

Example:

```
head: 1->2->3->4->5, pos = 1
result: 2

head: 1->2, pos = 0
result: 1

head: 1, pos = -1
result: nullptr
```
