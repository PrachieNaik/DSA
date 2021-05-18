/*

Problem statement: Given an integer A, how many structurally unique BST’s (binary search trees) exist that can store values 1…A?

Input Format:
The first and the only argument of input contains the integer, A.

Output Format:
Return an integer, representing the answer asked in problem statement.

Constraints: 1 <= A <= 18

Input 1: A = 3
Output 1: 5

Explanation 1:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
   
Approach 1: Memoization
    There can be ‘A’ root nodes, from 1 to A.
    For each root node, compute subProblem for left and right.
    Ex:
    A = 4
    root is 1 : 0 left nodes and 3 right nodes
    root is 2 : 1 left node and 2 right nodes
    root is 3 : 2 left nodes and 1 right node
    root is 4 : 3 left nodes and 0 right nodes
    
    vector<vector<int>> dp;
    int ans(int s,int e){
        int ve = 0;
        if(s == e)
        return 1;
        
        if(s > e)
        return 1;
        
        if(dp[s][e] != 0)
        return dp[s][e];
        
        for(int i = s;i <= e;i++){
           ve+= ans(s,i - 1) * ans(i + 1,e);
        }
        return dp[s][e] = ve;
    }
    
    int Solution::numTrees(int A) {
        dp.clear();
        dp.resize(A + 1,vector(A + 1,0));
        return ans(1,A);
    
    }
  
Approach 2: Lets say you know the answer for values i which ranges from 0 <= i <= n - 1. How do you calculate the answer for n.

Lets consider the number [1, n]
We have n options of choosing the root.
If we choose the number j as the root, j - 1 numbers fall in the left subtree, n - j numbers fall in the right subtree. We already know how many ways
there are to forming j - 1 trees using j - 1 numbers and n -j numbers.
So we add number(j - 1) * number(n - j) to our solution. 

*/

int numTrees(int n) {
    if(n == 0) return 1;
    if(n == 1) return 1;

    int result[n + 1];
    memset(result, 0, sizeof(result));
    result[0] = 1;
    result[1] = 1;
    
    if(n < 2) {
        return result[n];
    }

    for (int i = 2; i <= n; i++) {
        for (int k = 1; k <= i; k++) {
            result[i] = result[i] + result[k - 1] * result[i - k];
        }
    }
    
    return result[n];
}
