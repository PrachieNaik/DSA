/*

Problem statement: Given the root of a binary search tree and K as input, find Kth smallest element in BST

Constraints:
1<=Number of nodes<=100000

Approach 1: Using Inorder Traversal (O(n) time and O(h) auxiliary space) 
The Inorder Traversal of a BST traverses the nodes in increasing order. So the idea is to traverse the tree in Inorder. While traversing, keep track of the count
of the nodes visited. If the count becomes k, print the node. 

*/

int KthSmallestElement(Node *root, int &K)
    {
        if(root == NULL)
        return -1;
        int left = KthSmallestElement(root->left,K);
    
        if(left != -1) 
        return left;
        
        
        K--;
        if(K == 0) {
            return root->data;
        }
        return KthSmallestElement(root->right,K);
    }
