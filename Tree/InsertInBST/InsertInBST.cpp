/*

Problem statement: Insert a key in BST

Approach:
A new key is always inserted at the leaf. We start searching a key from the root until we hit a leaf node. Once a leaf node is found, the new node is added as
a child of the leaf node. 

Time Complexity: The worst-case time complexity of search and insert operations is O(h) where h is the height of the Binary Search Tree. In the worst case, we
may have to travel from root to the deepest leaf node. The height of a skewed tree may become n and the time complexity of search and insert operation may become O(n). 

*/

Insert(BST* root, int value)
{
    if (!root)
    {
        // Insert the first node, if root is NULL.
        return new BST(value);
    }
 
    // Insert data.
    if (value > root->data)
    {
        // Insert right node data, if the 'value'
        // to be inserted is greater than 'root' node data.
 
        // Process right nodes.
        root->right = Insert(root->right, value);
    }
    else
    {
        // Insert left node data, if the 'value'
        // to be inserted is greater than 'root' node data.
 
        // Process left nodes.
        root->left = Insert(root->left, value);
    }
 
    // Return 'root' node, after insertion.
    return root;
}
