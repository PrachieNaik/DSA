/*

Problem statement: Given a 2D integer array A of size M x N, you need to find a path from top left to bottom right which minimizes the sum of all numbers
along its path.

NOTE: You can only move either down or right at any point in time.

Input Format
First and only argument is an 2D integer array A of size M x N.

Output Format
Return a single integer denoting the minimum sum of a path from cell (1, 1) to cell (M, N).

Example Input

 A = [  [1, 3, 2]
        [4, 3, 1]
        [5, 6, 1]
     ]

Example Output: 9

Example Explanation

 The path is 1 -> 3 -> 2 -> 1 -> 1
 So ( 1 + 3 + 2 + 1 + 1) = 8

*/

int Solution::minPathSum(vector<vector<int> > &A) {
    int n = A.size();
    
    if(n == 0) 
    return 0;
    
    int m = A[0].size();
    
    int dp[n][m];
    
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            dp[i][j] = A[i][j];
            
            if(i > 0 && j > 0){
                dp[i][j] += min(dp[i - 1][j] , dp[i][j - 1]);
            } else if(i > 0) {
                dp[i][j] += dp[i - 1][j];
            } else if(j > 0) {
                dp[i][j] += dp[i][j - 1];
            }  
        }
    }
    return dp[n-1][m-1];
}
