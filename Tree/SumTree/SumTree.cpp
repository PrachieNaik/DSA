/*

Problem statement: Given a Binary Tree of size N , where each node can have positive or negative values. Convert this to a tree where each node contains the sum
of the left and right sub trees of the original tree. The values of leaf nodes are changed to 0.

Example 1:

Input:
             10
          /      \
        -2        6
       /   \     /  \
     8     -4   7    5

Output:
            20
          /    \
        4        12
       /  \     /  \
     0     0   0    0

Explanation:

           (4-2+12+6)
          /           \
      (8-4)          (7+5)
       /   \         /  \
      0     0       0    0
 
Constraints:
1 ≤ N ≤ 10^4

Approach: Do a traversal of the given tree. In the traversal, store the old value of the current node, recursively call for left and right subtrees and change
the value of current node as sum of the values returned by the recursive calls. Finally return the sum of new value and value (which is sum of values in the 
subtree rooted with this node).

Time Complexity: The solution involves a simple traversal of the given tree. So the time complexity is O(n) where n is the number of nodes in the given Binary Tree.
Space Complexity: O(h) // recursion stack
*/

// Convert a given tree to a tree where 
// every node contains sum of values of 
// nodes in left and right subtrees in the original tree 
int toSumTree(node *Node) 
{ 
    // Base case 
    if(Node == NULL) 
    return 0; 
  
    // Store the old value 
    int old_val = Node->data; 
  
    // Recursively call for left and
    // right subtrees and store the sum as 
    // new value of this node 
    Node->data = toSumTree(Node->left) + toSumTree(Node->right); 
  
    // Return the sum of values of nodes
    // in left and right subtrees and 
    // old_value of this node 
    return Node->data + old_val; 
} 
  
