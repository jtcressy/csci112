## CSCI 112 (CS2) - Binary Tree Data Structure

### Program 4

Construct a binary search tree and perform the acitons detailed below. Note that the tree values will be read in from an input file using the first value read as the root node and using a fixed root as shown in class.

1. Call a ``read`` function to read in the data from the input file, and call an ``insert`` function to insert each value into the tree
2. Print the tree values to the output file using a recursive **in-order** traversal. Use Improved version of the traversal. **Print all values along a single row.**
3. Delete node 71. Print the tree again with a **post-order** recursive traversal.
4. Delete node 38. Use the leftmost node of the right sub-tree for the replacement of a two-child node. Print the tree with a **pre-order** recursive traversal
5. Code an iterative version of a preorder traversal of the tree, and print the tree using this function.
***Extra Credit***: Code the inorder iterative traversal for the tree and print the treee using this function.

Data for data file:
```
38
57
93
23
11
18
50
30
25
53
71
80
52
35
20
49
7
```