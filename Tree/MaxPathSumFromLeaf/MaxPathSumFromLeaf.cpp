/*

Problem statement: Given a binary tree in which each node element contains a number. Find the maximum possible sum from one leaf node to another.

Constraints:
1 ≤ N ≤ 10^4

Approaches: 

Method 1: A simple solution is to traverse the tree and do following for every traversed node X. 
    1) Find maximum sum from leaf to root in left subtree of X 
    2) Find maximum sum from leaf to root in right subtree of X. 
    3) Add the above two calculated values and X->data and compare the sum with the maximum value obtained so far and update the maximum value. 
    4) Return the maximum value.
    
    Time complexity: O(n^2)
    
Method 2: We can find the maximum sum using single traversal of binary tree. The idea is to maintain two values in recursive calls 
    1) Maximum root to leaf path sum for the subtree rooted under current node. 
    2) The maximum path sum between leaves (desired output).
    For every visited node X, we find the maximum root to leaf sum in left and right subtrees of X. We add the two values with X->data, and compare the sum with 
    maximum path sum found so far.
    
    Time Complexity: O(n)

*/

int maxPathSumUtil(Node* root, int &res) {
 
    //base condition
    if(root == NULL) {
        return 0;
    }
    
    //induction
    int leftMaxSum = maxPathSumUtil(root->left,res);
    int rightMaxSum = maxPathSumUtil(root->right,res);
    
    //hypothesis
    if(root->left!=NULL && root->right!=NULL) {
        res = max(res,root->data + rightMaxSum + leftMaxSum);
        
        //temporary answer for leaf node
        return root->data + max(leftMaxSum,rightMaxSum);
    }
    
    //temporary answer
    return (!root->left)? rightMaxSum + root->data:leftMaxSum + root->data;
    
}
int maxPathSum(Node* root)
{    
    int ans = INT_MIN;
    maxPathSumUtil(root,ans);
    return ans;
}



