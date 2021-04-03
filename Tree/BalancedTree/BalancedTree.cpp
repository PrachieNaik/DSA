/*

Problem statement: Given a binary tree, find if it is height balanced or not. A tree is height balanced if difference between heights of left and right subtrees is
not more than one for all nodes of tree. 

Constraints:
1<= N <= 10^4

Approach: To check if a tree is height-balanced, get the height of left and right subtrees. Return true if difference between heights is not more than 1 and left 
and right subtrees are balanced, otherwise return false. Calculate the height in the same recursion rather than calling a height() function separately. 
     
Time complexity – O(n)  

*/

bool isBalancedUtil(Node *root, int *height) {
    int leftHeight = 0, rightHeight = 0;
    bool leftBalanced = 0, rightBalanced = 0;
    
    if(root == NULL)
    {
        *height = 0;
        return 1;
    }
    
    leftBalanced = isBalancedUtil(root->left, &leftHeight);
    rightBalanced = isBalancedUtil(root->right, &rightHeight);
    
    *height = max(leftHeight,rightHeight) + 1;
    
    if( abs(leftHeight - rightHeight) >= 2 || !leftBalanced || !rightBalanced)
    return 0;
    
    return 1;
    
}


// This function should return tree if passed  tree 
// is balanced, else false. 
bool isBalanced(Node *root)
{
    int height = 0;
    return isBalancedUtil(root,&height);
}
