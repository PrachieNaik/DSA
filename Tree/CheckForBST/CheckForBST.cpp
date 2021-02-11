/*

Problem statement: Given a binary tree. Check whether it is a BST or not. A binary search tree (BST) is a node based binary tree data structure which has the following properties.
    • The left subtree of a node contains only nodes with keys less than the node’s key.
    • The right subtree of a node contains only nodes with keys greater than the node’s key.
    • Both the left and right subtrees must also be binary search trees.
    
    From the above properties it naturally follows that:
    • Each node (item in the tree) has a distinct key.

Constraints:
0 <= Number of edges <= 100000

Approaches:

    Method 1: For each node, check if max value in left subtree is smaller than the node and min value in right subtree greater than the node. Write a utility helper function isBSTUtil(struct node* node, int min, int max) that traverses down the tree keeping track of the narrowing min and max allowed values as it goes, looking at each node only once. The initial values for min and max should be INT_MIN and INT_MAX — they narrow from there.
     
    Time Complexity: O(n)
    Auxiliary Space : O(1) if Function Call Stack size is not considered, otherwise O(n)

    Method 2: (Using In-Order Traversal)
    1) Do In-Order Traversal of the given tree and store the result in a temp array.
    2) Check if the temp array is sorted in ascending order, if it is, then the tree is BST.
    We can avoid the use of Auxiliary Array. While doing In-Order traversal, we can keep track of previously visited node. If the value of the currently visited node is less than the previous value, then tree is not BST. 

    Time Complexity: O(n)
    Auxiliary Space : O(1) if Function Call Stack size is not considered, otherwise O(n)

*/

bool isBSTUtil(struct Node* root, Node *&prev) 
{ 
    // traverse the tree in inorder fashion and  
    // keep track of prev node 
    if (root) 
    { 
        if (!isBSTUtil(root->left, prev)) 
          return false; 
   
        // Allows only distinct valued nodes  
        if (prev != NULL && root->data <= prev->data) 
          return false; 
   
        prev = root; 
   
        return isBSTUtil(root->right, prev); 
    } 
   
    return true; 
} 
  
bool isBST(Node *root) 
{ 
   Node *prev = NULL; 
   return isBSTUtil(root, prev); 
} 
