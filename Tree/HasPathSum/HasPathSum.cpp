/*

Problem statement: Given a binary tree and an integer S, check whether there is root to leaf path with its sum as S.

Constraints:
1 ≤ N ≤ 10^4
1 ≤ S ≤ 10^6

Approach: Recursively check if left or right child has path sum equal to ( number – value at current node)
     
Time Complexity: O(n)

*/

bool hasPathSum(Node *root, int S) {
    
    if(root == NULL && S == 0)
        return 1;
    
    if(root == NULL)
        return 0;
        
    return hasPathSum(root->left, S-root->data) || hasPathSum(root->right, S-root->data);
}
