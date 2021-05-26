/*

Problem statement: Given a Binary Search Tree and a node value X. Delete the node with the given value X from the BST. If no node with value x exists, 
then do not make any change. 

Example 1:

Input:
      2
    /   \
   1     3
X = 12
Output: 1 2 3
Explanation: In the given input there is no node with value 12 , so the tree will remain same.

Constraints:
1 <= N <= 10^5

*/

//Function to delete a node from BST.
Node *deleteNode(Node *root,  int X)
{
    if(root == NULL)
    return NULL;
    
    //Node to be deleted exsists in right subtree
    if(root->data < X) {
        root->right = deleteNode(root->right,X);
        return root;
    }
    
    //Node to be deleted exsists in left subtree
    if(root->data > X) {
        root->left = deleteNode(root->left,X);
        return root;
    }
    
    //we will reach here if the root is to be deleted
    
    //if both child exists then find Precedecer, replace it with root, now the problem will be reduced to deleting the node with zero or one child
    if(root->left && root->right) {
        Node * temp = root->left;
        while(temp->right) {
            temp = temp->right;
        }
        root->data = temp->data;
        root->left = deleteNode(root->left,temp->data);
        return root;
    }
    
    //if np child then simply delete 
    if(root->left == NULL && root->right == NULL) {
        delete root;
        return NULL;
    }
    
    //if one chile then replace root with it's child
    
    if(root->left == NULL) {
        delete root;
        return root->right;
    }
    if(root->right == NULL) {
        delete root;
        return root->left;
    }
}
