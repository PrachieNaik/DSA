/*

Problem statement: Given a binary tree of size N. Your task is to complete the function sumOfLongRootToLeafPath(), that find the sum of all nodes on the longest
path from root to leaf node.
If two or more paths compete for the longest path, then the path having maximum sum of nodes is being considered.

Examples:

Input : Binary tree:
        4        
       / \       
      2   5      
     / \ / \     
    7  1 2  3    
      /
     6
Output : 13

Constraints:
1<=T<=10^3
1<=N<=10^3

Approach: Recursively find the length and sum of nodes of each root to leaf path and accordingly update the maximum sum.

Time Complexity: O(n)
Space Complexity: O(h) // recursion stack
*/

void sumOfLongRootToLeafPathUtil(Node *root,int &ans,int sum,int level,int &maxLevel) {
    if(root == NULL)
    return;
    level++;
    sum += root->data;
    if(maxLevel<=level) {
        maxLevel = level;
        ans = max(ans,sum);
    }
    sumOfLongRootToLeafPathUtil(root->left,ans,sum,level,maxLevel);
    sumOfLongRootToLeafPathUtil(root->right,ans,sum,level,maxLevel);
}
int sumOfLongRootToLeafPath(Node* root)
{
	// Code here
	int ans = 0;
	int maxLevel = 0;
	sumOfLongRootToLeafPathUtil(root,ans,0,0,maxLevel);
	return ans;
}
