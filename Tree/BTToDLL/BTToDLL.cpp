/*

Problem statement: Given a Binary Tree (BT), convert it to a Doubly Linked List(DLL) In-Place. The left and right pointers in nodes are to be used as previous
and next pointers respectively in converted DLL. The order of nodes in DLL must be same as Inorder of the given Binary Tree. The first node of Inorder traversal 
(leftmost node in BT) must be the head node of the DLL.

Constraints:
1 ≤ N ≤ 10^5
1 ≤ Node Data ≤ 10^5

Approach: If the left subtree exists, process the left subtree
Recursively convert the left subtree to DLL.
Then find the inorder predecessor of the root in the left subtree (the inorder predecessor is the rightmost node in the left subtree).
Make the inorder predecessor as the previous root and the root as the next in order predecessor.
 If the right subtree exists, process the right subtree (Below 3 steps are similar to the left subtree).
Recursively convert the right subtree to DLL.
Then find the inorder successor of the root in the right subtree (in order the successor is the leftmost node in the right subtree).
Make the inorder successor as the next root and the root as the previous inorder successor.
Find the leftmost node and return it (the leftmost node is always the head of a converted DLL).

*/

Node * bToDLLUtil(Node *root) {
    if(root == NULL)
    return root;
    
    Node * left = bToDLLUtil(root->left);
    if(left) {
        while(left->right)
        left = left -> right;
        left -> right = root;
        root -> left = left;
    }
    Node * right = bToDLLUtil(root->right);
    if(right) {
        while(right->left)
        right = right -> left;
        right -> left = root;
        root -> right = right;
    }
    return root;
}
//Function to convert binary tree to doubly linked list and return it.
Node * bToDLL(Node *root)
{
    if(root == NULL)
    return root;
    Node * ans = bToDLLUtil(root);
    while(ans->left)
    ans = ans->left;
    return ans;
}
