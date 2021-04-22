/*

Problem statement:Find the distance between two keys in a binary tree, no parent pointers are given. The distance between two nodes is the minimum number of edges
to be traversed to reach one node from another.

We first find the LCA of two nodes. Then we find the distance from LCA to two nodes. 
    
Time Complexity: O(n) 
Auxiliary Space: O(h) where h is the height of the tree. 

*/

Node* LCA(Node * root, int n1,int n2)
{
    // Your code here
    if (root == NULL)
       return root;
    if (root->key == n1 || root->key == n2)
       return root;
 
    Node* left = LCA(root->left, n1, n2);
    Node* right = LCA(root->right, n1, n2);
 
    if (left != NULL && right != NULL)
         return root;
    if (left == NULL && right == NULL)
           return NULL;
    if (left != NULL)
        return LCA(root->left, n1, n2);
 
    return LCA(root->right, n1, n2);
}
 
// Returns level of key k if it is present in
// tree, otherwise returns -1
int findLevel(Node *root, int k, int level)
{
    if(root == NULL) return -1;
    if(root->key == k) return level;
 
    int left = findLevel(root->left, k, level+1);
   if (left == -1)
       return findLevel(root->right, k, level+1);
    return left;
}
 
int findDistance(Node* root, int a, int b)
{
    // Your code here
    Node* lca = LCA(root, a , b);
 
    int d1 = findLevel(lca, a, 0);
    int d2 = findLevel(lca, b, 0);
 
    return d1 + d2;
}
