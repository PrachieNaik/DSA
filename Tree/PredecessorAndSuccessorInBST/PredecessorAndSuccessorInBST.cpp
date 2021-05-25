/*

Problem statement: There is BST given with root node with key part as integer only. You need to find the inorder successor and predecessor of a given key. 
In case, if the either of predecessor or successor is not found print -1.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains n denoting the number of
edges of the BST. The next line contains the edges of the BST. The last line contains the key.

Output:
Print the predecessor followed by successor for the given key. If the predecessor or successor is not found print -1.

Constraints:
1<=T<=100
1<=n<=100
1<=data of node<=100
1<=key<=100

Example:
Input:
2
6
50 30 L 30 20 L 30 40 R 50 70 R 70 60 L 70 80 R
65
6
50 30 L 30 20 L 30 40 R 50 70 R 70 60 L 70 80 R
100

Output:
60 70
80 -1

Approach:
1. If root is NULL then return
2. if key is found then
    a. If its left subtree is not null
        Then predecessor will be the right most child of left subtree or left child itself.
    b. If its right subtree is not null
        The successor will be the left most child of right subtree or right child itself.
    return
3. If key is smaller then root node
        set the successor as root
        search recursively into left subtree
    else
        set the predecessor as root
        search recursively into right subtree 

*/

// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    // Base case
    if (root == NULL)  return ;
 
    // If key is present at root
    if (root->key == key)
    {
        // the maximum value in left subtree is predecessor
        if (root->left != NULL)
        {
            Node* tmp = root->left;
            while (tmp->right)
                tmp = tmp->right;
            pre = tmp ;
        }
 
        // the minimum value in right subtree is successor
        if (root->right != NULL)
        {
            Node* tmp = root->right ;
            while (tmp->left)
                tmp = tmp->left ;
            suc = tmp ;
        }
        return ;
    }
 
    // If key is smaller than root's key, go to left subtree
    if (root->key > key)
    {
        suc = root ;
        findPreSuc(root->left, pre, suc, key) ;
    }
    else // go to right subtree
    {
        pre = root ;
        findPreSuc(root->right, pre, suc, key) ;
    }
}
