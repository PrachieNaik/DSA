/*

Problem statement: Given a Binary Tree of size N , You have to count leaves in it.

Constraints:
1<= N <= 104

Approach: getLeafCount(node)
    1) If node is NULL then return 0.
    2) Else If left and right child nodes are NULL return 1.
    3) Else recursively calculate leaf count of the tree using below formula.
        Leaf count of a tree = Leaf count of left subtree + 
                                     Leaf count of right subtree
     
    Time complexity – O(n)  

*/

int countLeavesUtil(Node* root, int ans) {
    if(root == NULL)
    return ans;
    
    if(root->left == NULL && root->right == NULL)
    return ans+1;
    
    return countLeavesUtil(root->left, ans) + countLeavesUtil(root->right, ans);
}

int countLeaves(Node* root)
{
    int ans = 0;
    if(root == NULL) {
        return 0;
    }
    return countLeavesUtil(root, ans);
}
