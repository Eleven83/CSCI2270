# Trees

### Trees: Unlike Arrays, Linked Lists, Stack and queues, which are linear data structures, trees are hierarchical data structures.
###Tree Vocabulary: The topmost node is called root of the tree. The elements that are directly under an element are called its children. The element directly above something is called its parent. For example, ‘a’ is a child of ‘f’, and ‘f’ is the parent of ‘a’. Finally, elements with no children are called leaves.
```
      tree
      ----
       j    <-- root
     /   \
    f      k
  /   \      \
 a     h      z    <-- leaves
```
##Why Trees?
### 1. One reason to use trees might be because you want to store information that naturally forms a hierarchy. For example, the file system on a computer:
```
file system
-----------
     /    <-- root
  /      \
...       home
      /          \
   ugrad        course
    /       /      |     \
  ...      cs101  cs112  cs113

```

### 2. Trees (with some ordering e.g., BST) provide moderate access/search (quicker than Linked List and slower than arrays).
### 3. Trees provide moderate insertion/deletion (quicker than Arrays and slower than Unordered Linked Lists).
### 4. Like Linked Lists and unlike Arrays, Trees don’t have an upper limit on number of nodes as nodes are linked using pointers.
<br>

### Main applications of trees include:
1. Manipulate hierarchical data.
2. Make information easy to search (see tree traversal).
3. Manipulate sorted lists of data.
4. As a workflow for compositing digital images for visual effects.
5. Router algorithms
6. Form of a multi-stage decision-making (see business chess).




## Binary Tree: A tree whose elements have at most 2 children is called a binary tree. Since each element in a binary tree can have only 2 children, we typically name them the left and right child.

Source: GeeksForGeeks, there are advacned reads like number of nodes in a level etc.

## Types of Binary trees

### Full Binary Tree A Binary Tree is full if every node has 0 or 2 children. Following are examples of full binary tree. We can also say a full binary tree is a binary tree in which all nodes except leaves have two children.
```
               18
           /       \
         15         30
        /  \        /  \
      40    50    100   40
```
```
             18
           /    \
         15     20
        /  \
      40    50
    /   \
   30   50
```
```
               18
            /     \
          40       30
                   /  \
                 100   40

```

### In a Full Binary, number of leaf nodes is number of internal nodes plus 1
###       L = I + 1
### Where L = Number of leaf nodes, I = Number of internal nodes




### Complete Binary Tree: A Binary Tree is complete Binary Tree if all levels are completely filled except possibly the last level and the last level has all keys as left as possible

### Following are examples of Complete Binary Trees

```

               18
           /       \
         15         30
        /  \        /  \
      40    50    100   40

```
```
               18
           /       \
         15         30
        /  \        /  \
      40    50    100   40
     /  \   /
    8   7  9

```

### Practical example of Complete Binary Tree is Binary Heap.



### Perfect Binary Tree A Binary tree is Perfect Binary Tree in which all internal nodes have two children and all leaves are at same level.
### Following are examples of Perfect Binaryr Trees.
```
               18
           /       \
         15         30
        /  \        /  \
      40    50    100   40
```
```

               18
           /       \
         15         30
```

### A Perfect Binary Tree of height h (where height is number of nodes on path from root to leaf) has 2h – 1 node.

### Example of Perfect binary tree is ancestors in family. Keep a person at root, parents as children, parents of parents as their children.



### Balanced Binary Tree
### A binary tree is balanced if height of the tree is O(Log n) where n is number of nodes. For Example, AVL tree maintain O(Log n) height by making sure that the difference between heights of left and right subtrees is 1. Red-Black trees maintain O(Log n) height by making sure that the number of Black nodes on every root to leaf paths are same and there are no adjacent red nodes. Balanced Binary Search trees are performance wise good as they provide O(log n) time for search, insert and delete.



### A degenerate (or pathological) tree A Tree where every internal node has one child. Such trees are performance-wise same as linked list.
```
      10
      /
    20
     \
     30
      \
      40
```

# BSTs - Binary Search trees

### Binary Search Tree is a node-based binary tree data structure which has the following properties:

### The **left** subtree of a node contains only nodes with keys **lesser than the node’s key**.
### The **right** subtree of a node contains only nodes with keys **greater than the node’s key**.
### The **left and right subtree** each **must also be a binary search tree**.


![Binary Search Tree](https://upload.wikimedia.org/wikipedia/commons/9/9b/Binary_search_tree_example.gif)
