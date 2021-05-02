/*

Problem statement: Given two binary trees, check if the first tree is subtree of the second one. A subtree of a tree T is a tree S consisting of a node in T and
all of its descendants in T. The subtree corresponding to the root node is the entire tree; the subtree corresponding to any other node is called a proper subtree.

Approach:  Traverse the tree T in preorder fashion. For every visited node in the traversal, see if the subtree rooted with this node is identical to S.

Time Complexity: Time worst case complexity of above solution is O(mn) where m and n are number of nodes in given two trees.

*/

/* A utility function to check 
whether trees with roots as root1 and 
root2 are identical or not */
bool areIdentical(node * root1, node *root2) 
{ 
    /* base cases */
    if (root1 == NULL && root2 == NULL) 
        return true; 
  
    if (root1 == NULL || root2 == NULL) 
        return false; 
  
    /* Check if the data of both roots is 
    same and data of left and right 
    subtrees are also same */
    return (root1->data == root2->data && areIdentical(root1->left, root2->left) && areIdentical(root1->right, root2->right) ); 
} 
  
  
/* This function returns true if S 
is a subtree of T, otherwise false */
bool isSubtree(node *T, node *S) 
{ 
    /* base cases */
    if (S == NULL) 
        return true; 
  
    if (T == NULL) 
        return false; 
  
    /* Check the tree with root as current node */
    if (areIdentical(T, S)) 
        return true; 
  
    /* If the tree with root as current 
    node doesn't match then try left 
    and right subtrees one by one */
    return isSubtree(T->left, S) || isSubtree(T->right, S); 
} 
