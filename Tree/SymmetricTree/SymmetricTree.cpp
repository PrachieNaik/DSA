/*

Problem statement: Given a Binary Tree. Check whether it is Symmetric or not, i.e. whether the binary tree is a Mirror image of itself or not.

Constraints:
1<=Number of nodes<=100

Approach: 

    The idea is to write a recursive function isMirror() that takes two trees as an argument and returns true if trees are the mirror and false if trees are not mirrored. The isMirror() function recursively checks two roots and subtrees under the root.
*/

// Returns true if trees 
// with roots as root1 and root2 are mirror
bool isMirror(struct Node* root1, struct Node* root2)
{
    // If both trees are emptu, 
    // then they are mirror images
    
    if (root1 == NULL && root2 == NULL)
        return true;
 
    // For two trees to be mirror 
    // images, the following
    // three conditions must be true 
    // 1 - Their root node's
    // key must be same 2 - left 
    // subtree of left tree and right subtree
    // of right tree have to be mirror images
    // 3 - right subtree of left tree and left subtree
    // of right tree have to be mirror images
    
    if (root1 && root2 && root1->key == root2->key)
        return isMirror(root1->left, root2->right)
               && isMirror(root1->right, root2->left);
 
    // if none of above conditions is true then root1
    // and root2 are not mirror images
    
    return false;
}
 
// Returns true if a tree is 
// symmetric i.e. mirror image of itself
bool isSymmetric(struct Node* root)
{
    // Check if tree is mirror of itself
    return isMirror(root, root);
}
