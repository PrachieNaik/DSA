/*

Problem statement: Given a Binary Tree, find diameter of it.
The diameter of a tree is the number of nodes on the longest path between two end nodes in the tree.

Constraints:
1 ≤ N ≤ 10^4
1 ≤ S ≤ 10^6

Approach: Dynamic programming
     
Time Complexity: O(n)

*/

int diameterUtil(Node* root, int *ans) {
    //base case
    if(root == NULL)
        return 0;
        
    //Induction
    int left = diameterUtil(root->left,ans);
    int right = diameterUtil(root->right, ans);
    
    //hypothesis
    int temp = 1+ max(left,right);
    int res = max(temp, (1+left+right));
    *ans = max(*ans,res);
    
    //return temporary answer
    return temp;
}

/* Computes the diameter of binary tree with given root.  */
int diameter(Node* root) {
    int ans = 0;
    diameterUtil(root,&ans);
    return ans;
}
