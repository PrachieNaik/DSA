/*

Problem statement: A binary tree and a number k are given. Print every path in the tree with sum of the nodes in the path as k.
A path can start from any node and end at any node and must be downward only, i.e. they need not be root node and leaf node; and negative numbers can
also be there in the tree.

Examples:

Input : k = 5  
        Root of below binary tree:
           1
        /     \
      3        -1
    /   \     /   \
   2     1   4     5                        
        /   / \     \                    
       1   1   2     6    
                       
Output :
3 2 
3 1 1 
1 3 1 
4 1 
1 -1 4 1 
-1 4 2 
5 
1 -1 5 

Approach: The basic idea to solve the problem is to do a preorder traversal of the given tree. We also need a container (vector) to keep track of the
path that led to that node. At each node we check if there are any path that sums to k, if any we print the path and proceed recursively to print each path.

*/

// This function prints all paths that have sum k
void printKPathUtil(Node *root, vector<int>& path, int k)
{
    // empty node
    if (!root)
        return;
  
    // add current node to the path
    path.push_back(root->data);
  
    // check if there's any k sum path
    // in the left sub-tree.
    printKPathUtil(root->left, path, k);
  
    // check if there's any k sum path
    // in the right sub-tree.
    printKPathUtil(root->right, path, k);
  
    // check if there's any k sum path that
    // terminates at this node
    // Traverse the entire path as
    // there can be negative elements too
    int f = 0;
    for (int j=path.size()-1; j>=0; j--)
    {
        f += path[j];
  
        // If path sum is k, print the path
        if (f == k)
            printVector(path, j);
    }
  
    // Remove the current element from the path
    path.pop_back();
}
  
// A wrapper over printKPathUtil()
void printKPath(Node *root, int k)
{
    vector<int> path;
    printKPathUtil(root, path, k);
}
