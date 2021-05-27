/*

Problem statement: Given a Binary Tree, check if all leaves are at same level or not.

Example 1:

Input: 
            1
          /   \
         2     3

Output: 1

Explanation: 
Leaves 2 and 3 are at same level.

Constraints:
1 ≤ N ≤ 10^3

Approach: The idea is to first find the level of the leftmost leaf and store it in a variable leafLevel. Then compare level of all other leaves with
leafLevel, if same, return true, else return false. We traverse the given Binary Tree in a Preorder fashion. An argument leaflevel is passed to all calls.
The value of leafLevel is initialized as 0 to indicate that the first leaf is not yet seen yet. The value is updated when we find first leaf. Level of 
subsequent leaves (in preorder) is compared with leafLevel. 

Time Complexity: The function does a simple traversal of the tree, so the complexity is O(n).

*/

/* Recursive function which checks whether
all leaves are at same level */
bool checkUtil(struct Node *root,
            int level, int *leafLevel)
{
    // Base case
    if (root == NULL) return true;
 
    // If a leaf node is encountered
    if (root->left == NULL &&
        root->right == NULL)
    {
        // When a leaf node is found
        // first time
        if (*leafLevel == 0)
        {
            *leafLevel = level; // Set first found leaf's level
            return true;
        }
 
        // If this is not first leaf node, compare
        // its level with first leaf's level
        return (level == *leafLevel);
    }
 
    // If this node is not leaf, recursively
    // check left and right subtrees
    return checkUtil(root->left, level + 1, leafLevel) &&
            checkUtil(root->right, level + 1, leafLevel);
}
 
/* The main function to check
if all leafs are at same level.
It mainly uses checkUtil() */
bool check(struct Node *root)
{
    int level = 0, leafLevel = 0;
    return checkUtil(root, level, &leafLevel);
}
