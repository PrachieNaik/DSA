/*

Problem statement: Given a binary tree, the task is to find the maximum path sum. The path may start and end at any node in the tree.

Constraints:
1 ≤ N ≤ 10^4

Approach: For each node there can be four ways that the max path goes through the node:
    1. Node only
    2. Max path through Left Child + Node
    3. Max path through Right Child + Node
    4. Max path through Left Child + Node + Max path through Right Child
    
    The idea is to keep trace of four paths and pick up the max one in the end. An important thing to note is, root of every subtree need to return maximum path 
    sum such that at most one child of root is involved. This is needed for parent function call. In below code, this sum is stored in ‘max_single’ and returned 
    by the recursive function.
    
    Time Complexity: O(n)

*/

int findMaxSumUtil(Node* root, int &ans) {
    
    //base condition
    if(root == NULL)
    return 0;
    
    //induction
    int leftSum = findMaxSumUtil(root->left,ans);
    int rightSum = findMaxSumUtil(root->right,ans);
    
    //hypothesis
    int max_single = max( root->data + max(leftSum,rightSum) , root->data);
    int max_top = max( leftSum + rightSum + root->data, max_single);
    ans = max(ans,max_top);
    
    //temporary answer
    return max_single;
}

// This function should returns sum of maximum sum path from any node in a tree rooted with given root.
int findMaxSum(Node* root)
{
    int ans = INT_MIN;
    findMaxSumUtil(root,ans);
    return ans;
}
