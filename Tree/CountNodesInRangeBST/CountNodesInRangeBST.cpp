/*

Problem statement:Given a Binary Search Tree (BST) and a range l-h(inclusive), count the number of nodes in the BST that lie in the given range.

The values smaller than root go to the left side
The values greater and equal to the root go to the right side
Example 1:

Input:
      10
     /  \
    5    50
   /    /  \
  1    40  100
l = 5, h = 45
Output: 3
Explanation: 5 10 40 are the node in the range

Constraints:
1 <= Number of nodes <= 100
1 <= l < h < 10^3

Approach:
The idea is to traverse the given binary search tree starting from root. For every node being visited, check if this node lies in range, if yes, then add 1
to result and recur for both of its children. If current node is smaller than low value of range, then recur for right child, else recur for left child.

Time complexity of the above Approach is O(h + k) where h is height of BST and k is number of nodes in given range.

*/

void inorder(Node *root,int &ans,int l,int h) {
    if(root == NULL)
    return;
    if(root->data >= l) {
        inorder(root->left,ans,l,h);
    }
    if(root->data >= l && root->data <= h) {
        ans = ans + 1;
    }
    if(root->data <= h) {
        inorder(root->right,ans,l,h);
    }
}
//Function to count number of nodes in BST that lie in the given range.
int getCount(Node *root, int l, int h)
{ 
    int ans = 0;
    inorder(root,ans,l,h);
    return ans;
}
