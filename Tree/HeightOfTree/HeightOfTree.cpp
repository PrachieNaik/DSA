/*

Problem statement: Given a binary tree, find its height.

Constraints:
1 <= Number of nodes <= 10^5
1 <= Data of a node <= 10^5

Approach: Recursively calculate height of left and right subtrees of a node and assign height to the node as max of the heights of two children plus 1

Algorithm: maxDepth()
    1. If tree is empty then return 0
    2. Else
         (a) Get the max depth of left subtree recursively  i.e., call maxDepth( tree->left-subtree)
         (a) Get the max depth of right subtree recursively  i.e., call maxDepth( tree->right-subtree)
         (c) Get the max of max depths of left and right subtrees and add 1 to it for the current node.
             max_depth = max(max dept of left subtree, max depth of right subtree) + 1
         (d) Return max_depth
    
Time Complexity: O(n)
Space Complexity: O(1)


*/

/* Compute the "maxDepth" of a tree -- the number of nodes along the longest path from the root node down to the farthest leaf node.*/
int maxDepth(node* node) 
{ 
    if (node == NULL) 
        return 0; 
    else
        return max ( maxDepth ( node -> left ) , maxDepth ( node -> right ) ) + 1;
} 
