/*

Problem statement: Given two Binary Trees. Check whether they are Isomorphic or not.

Note: 
Two trees are called isomorphic if one can be obtained from another by a series of flips, i.e. by swapping left and right children of several nodes.
Any number of nodes at any level can have their children swapped. Two empty trees are isomorphic.

Example 1:

Input:
 T1    1     T2:   1
     /   \        /  \
    2     3      3    2
   /            /
  4            4
Output: No

Example 2:

Input:
T1    1     T2:    1
    /  \         /   \
   2    3       3     2
  /                    \
  4                     4
Output: Yes

Constraints:
1 ≤ number of nodes ≤ 10^4

Approach: We simultaneously traverse both trees. Let the current internal nodes of two trees being traversed be n1 and n2 respectively. There are following
two conditions for subtrees rooted with n1 and n2 to be isomorphic.
1) Data of n1 and n2 is same.
2) One of the following two is true for children of n1 and n2
……a) Left child of n1 is isomorphic to left child of n2 and right child of n1 is isomorphic to right child of n2.
……b) Left child of n1 is isomorphic to right child of n2 and right child of n1 is isomorphic to left child of n2.

Time Complexity: The above solution does a traversal of both trees. So time complexity is O(min(m,n)*2) or O(min(m,n)) where m and n are number of nodes in given trees.
*/

/* Given a binary tree, print its nodes in reverse level order */
bool isIsomorphic(node* n1, node *n2)
{
     // Both roots are NULL, trees isomorphic by definition
     if (n1 == NULL && n2 == NULL)
        return true;
      
     // Exactly one of the n1 and n2 is NULL, trees not isomorphic
     if (n1 == NULL || n2 == NULL)
        return false;
      
     if (n1->data != n2->data)
        return false;
      
     // There are two possible cases for n1 and n2 to be isomorphic
     // Case 1: The subtrees rooted at these nodes have NOT been "Flipped".
     // Both of these subtrees have to be isomorphic, hence the &&
     // Case 2: The subtrees rooted at these nodes have been "Flipped"
     return 
     (isIsomorphic(n1->left,n2->left) && isIsomorphic(n1->right,n2->right))||
     (isIsomorphic(n1->left,n2->right) && isIsomorphic(n1->right,n2->left));
}
