/*

Problem statement:Given a BST (Binary Search Tree) that may be unbalanced, convert it into a balanced BST that has minimum possible height.

Examples :

Input:
       30
      /
     20
    /
   10
   
Output:
     20
   /   \
 10     30

Approach:
An Efficient Solution can construct balanced BST in O(n) time with minimum possible height. Below are steps.

Traverse given BST in inorder and store result in an array. This step takes O(n) time. Note that this array would be sorted as inorder traversal of BST always
produces sorted sequence.
Build a balanced BST from the above created sorted array using the recursive approach discussed here. This step also takes O(n) time as we traverse every element
exactly once and processing an element takes O(1) time.

*/

/* This function traverse the skewed binary tree and
   stores its nodes pointers in vector nodes[] */
void storeBSTNodes(Node* root, vector<Node*> &nodes)
{
    // Base case
    if (root==NULL)
        return;
  
    // Store nodes in Inorder (which is sorted
    // order for BST)
    storeBSTNodes(root->left, nodes);
    nodes.push_back(root);
    storeBSTNodes(root->right, nodes);
}
  
/* Recursive function to construct binary tree */
Node* buildTreeUtil(vector<Node*> &nodes, int start,
                   int end)
{
    // base case
    if (start > end)
        return NULL;
  
    /* Get the middle element and make it root */
    int mid = (start + end)/2;
    Node *root = nodes[mid];
  
    /* Using index in Inorder traversal, construct
       left and right subtress */
    root->left  = buildTreeUtil(nodes, start, mid-1);
    root->right = buildTreeUtil(nodes, mid+1, end);
  
    return root;
}
  
// This functions converts an unbalanced BST to
// a balanced BST
Node* buildTree(Node* root)
{
    // Store nodes of given BST in sorted order
    vector<Node *> nodes;
    storeBSTNodes(root, nodes);
  
    // Constucts BST from nodes[]
    int n = nodes.size();
    return buildTreeUtil(nodes, 0, n-1);
}
