/*

Problem statement: Given a Binary Search Tree (with all values unique) and two node values. Find the Lowest Common Ancestors of the two nodes in the BST.

Approaches:

Method 1: For Binary search tree, while traversing the tree from top to bottom the first node which lies in between the two numbers n1 and n2 is the LCA of the nodes, i.e. the first node n with the lowest depth which lies in between n1 and n2 (n1<=n<=n2) n1 < n2. So just recursively traverse the BST in, if node's value is greater than both n1 and n2 then our LCA lies in the left side of the node, if it's is smaller than both n1 and n2, then LCA lies on the right side. Otherwise, the root is LCA (assuming that both n1 and n2 are present in BST).

    Algorithm:
    
    Create a recursive function that takes a node and the two values n1 and n2.
    If the value of the current node is less than both n1 and n2, then LCA lies in the right subtree. Call the recursive function for thr right subtree.
    If the value of the current node is greater than both n1 and n2, then LCA lies in the left subtree. Call the recursive function for thr left subtree.
    If both the above cases are false then return the current node as LCA.
    
	Complexity Analysis:

    Time Complexity: O(h).
    The time Complexity of the above solution is O(h), where h is the height of the tree.
    Space Complexity: O(1).
    If recursive stack space is ignored, the space complexity of the above solution is constant.

Method 2: Iterative Implementation: The above solution uses recursion. The recursive solution requires extra space in the form of the function call stack. So an iterative solution can be implemented which does not occupy space in the form of the function call stack.
	
	Complexity Analysis:

    Time Complexity: O(h).
    The Time Complexity of the above solution is O(h), where h is the height of the tree.
    Space Complexity: O(1).
    The space complexity of the above solution is constant.

*/

/* Function to find LCA of n1 and n2. The function assumes that both 
n1 and n2 are present in BST */
struct node *lca(struct node* root, int n1, int n2) 
{ 
    while (root != NULL) 
    { 
        // If both n1 and n2 are smaller than root, then LCA lies in left 
        if (root->data > n1 && root->data > n2) 
        root = root->left; 
  
        // If both n1 and n2 are greater than root, then LCA lies in right 
        else if (root->data < n1 && root->data < n2) 
        root = root->right; 
  
        else break; 
    } 
    return root; 
} 
