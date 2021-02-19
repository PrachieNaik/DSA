/*

Problem statement: Given a binary tree (not a binary search tree) and two values say n1 and n2, write a program to find the least common ancestor.
Let T be a rooted tree. The lowest common ancestor between two nodes n1 and n2 is defined as the lowest node in T that has both n1 and n2 as descendants 
(where we allow a node to be a descendant of itself).

Constraints:
1 <= Number of nodes <= 1000
1 <= Data of a node <= 1000

Method 1 (By Storing root to n1 and root to n2 paths): 
    1) Find a path from the root to n1 and store it in a vector or array. 
    2) Find a path from the root to n2 and store it in another vector or array. 
    3) Traverse both paths till the values in arrays are the same. Return the common element just before the mismatch. 
    
    Time Complexity: The time complexity of the above solution is O(n). The tree is traversed twice, and then path arrays are compared. 
    
Method 2 (Using Single Traversal) 
    Method 1 finds LCA in O(n) time but requires three tree traversals plus extra spaces for path arrays. If we assume that the keys n1 and n2 are present in 
    Binary Tree, we can find LCA using a single traversal of Binary Tree and without extra storage for path arrays. 
    
    The idea is to traverse the tree starting from the root. If any of the given keys (n1 and n2) matches with the root, then the root is LCA (assuming that both 
    keys are present). If the root doesn’t match with any of the keys, we recur for the left and right subtree. The node which has one key present in its left 
    subtree and the other key present in the right subtree is the LCA. If both keys lie in the left subtree, then the left subtree has LCA also, otherwise, 
    LCA lies in the right subtree.  
    
    Note that the above method assumes that keys are present in Binary Tree. If one key is present and the other is absent, then it returns the present key as 
    LCA (Ideally should have returned NULL). We can extend this method to handle all cases bypassing two boolean variables v1 and v2. v1 is set as true when n1 
    is present in the tree and v2 is set as true if n2 is present in the tree. 
    
    Time Complexity: The time complexity of the above solution is O(n) as the method does a simple tree traversal in a bottom-up fashion. 

*/


/* If n1 and n2 are present, return pointer to LCA. If both are not present, return NULL. Else if left subtree contains any of them return pointer to left.*/

Node* lca(Node* root ,int n1 ,int n2 )
{
   if(root == NULL)
   return NULL;
   
   if(root->data == n1)
   return root;
   
   if(root->data == n2) 
   return root;
   
   Node * leftLca = lca(root->left,n1,n2);
   Node * rightLca = lca(root->right,n1,n2);
   if(leftLca && rightLca)
   return root;
   
   return leftLca ? leftLca : rightLca;
}

