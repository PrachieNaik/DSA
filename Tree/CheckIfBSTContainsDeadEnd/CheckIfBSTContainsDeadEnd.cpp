/*

Problem statement: Given a Binary search Tree that contains positive integer values greater then 0. The task is to complete the function isDeadEnd which returns
true if the BST contains a dead end else returns false. Here Dead End means, we are not able to insert any element after that node.

Input :   
               8
             /   \ 
           5      9
         /  \     
        2    7 
       /
      1     
          
Output : Yes
Explanation : Node "1" is the dead End because after that we cant insert any element.       

Constraints:
1<=T<=100
1<=N<=200

Approach:
First of all, it is given that it is a BST and nodes are greater than zero, root node can be in the range [1, ∞] and if root val is say, val, then left sub-tree
can have the value in the range [1, val-1] and right sub-tree the value in range [val+1, ∞].
we need to traverse recursively and when the the min and max value of range coincided it means that we cannot add any node further in the tree.
Hence we encounter a dead end.
*/

// Returns true if tree with given root contains
// dead end or not. min and max indicate range
// of allowed values for current node. Initially
// these values are full range.
bool deadEnd(Node* root, int min=1, int max=INT_MAX)
{
    // if the root is null or the recursion moves
    // after leaf node it will return false
    // i.e no dead end.
    if (!root)
        return false;
  
    // if this occurs means dead end is present.
    if (min == max)
        return true;
  
    // heart of the recursion lies here.
    return deadEnd(root->left, min, root->data - 1) || deadEnd(root->right, root->data + 1, max);
}
