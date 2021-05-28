/*

Problem statement: Given a Binary Tree. Return 1 if, for every node X in the tree other than the leaves, its value is equal to the sum of its left subtree's
value and its right subtree's value. Else return 0.

An empty tree is also a Sum Tree as the sum of an empty tree can be considered to be 0. A leaf node is also considered a Sum Tree.

Input:

          10
        /    \
      20      30
    /   \ 
   10    10

Output: 0
Explanation: The given tree is not a sum tree. For the root node, sum of elements in left subtree is 40 and sum of elements in right subtree is 30. Root 
element = 10 which is not equal to 30+40.

Constraints:
1 ≤ number of nodes ≤ 10^4

Approach 1: Get the sum of nodes in the left subtree and right subtree. Check if the sum calculated is equal to the root’s data. Also, recursively check
if the left and right subtrees are SumTrees.
    
   // A utility function to get the sum
    // of values in tree with root as root
    int sum(struct node *root)
    {
        if (root == NULL)
            return 0;
         
        return sum(root->left) + root->data +
               sum(root->right);
    }
     
    // Returns 1 if sum property holds for
    // the given node and both of its children
    int isSumTree(struct node* node)
    {
        int ls, rs;
     
        // If node is NULL or it's a leaf
        // node then return true
        if (node == NULL ||
           (node->left == NULL &&
            node->right == NULL))
            return 1;
     
       // Get sum of nodes in left and
       // right subtrees
       ls = sum(node->left);
       rs = sum(node->right);
     
       // If the node and both of its
       // children satisfy the property
       // return 1 else 0
        if ((node->data == ls + rs) &&
              isSumTree(node->left) &&
              isSumTree(node->right))
            return 1;
     
       return 0;
    }
    
    Time Complexity: O(n^2) in the worst case. The worst-case occurs for a skewed tree.
    
Approach 2: use the following rules to get the sum directly. 
    1) If the node is a leaf node then the sum of the subtree rooted with this node is equal to the value of this node. 
    2) If the node is not a leaf node then the sum of the subtree rooted with this node is twice the value of this node (Assuming that the tree rooted
    with this node is SumTree).

    Time Complexity: O(n) where n is the number of nodes in the binary tree.
*/

/* Utillity function to check if
the given node is leaf or not */
int isLeaf(node *node)
{
    if(node == NULL)
        return 0;
    if(node->left == NULL && node->right == NULL)
        return 1;
    return 0;
}
 
/* returns 1 if SumTree property holds for the given
    tree */
int isSumTree(node* node)
{
    int ls; // for sum of nodes in left subtree
    int rs; // for sum of nodes in right subtree
 
    /* If node is NULL or it's a leaf node then
       return true */
    if(node == NULL || isLeaf(node))
        return 1;
 
    if( isSumTree(node->left) && isSumTree(node->right))
    {
       
        // Get the sum of nodes in left subtree
        if(node->left == NULL)
            ls = 0;
        else if(isLeaf(node->left))
            ls = node->left->data;
        else
            ls = 2 * (node->left->data);
 
        // Get the sum of nodes in right subtree
        if(node->right == NULL)
            rs = 0;
        else if(isLeaf(node->right))
            rs = node->right->data;
        else
            rs = 2 * (node->right->data);
 
        /* If root's data is equal to sum of nodes in left
           and right subtrees then return 1 else return 0*/
        return(node->data == ls + rs);
    }
    return 0;
}
