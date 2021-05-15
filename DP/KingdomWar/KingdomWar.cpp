/*

Problem statement: Two kingdoms are on a war right now, kingdom X and kingdom Y. As a war specialist of kingdom X, you scouted kingdom Y area.

A kingdom area is defined as a N x M grid with each cell denoting a village.
Each cell has a value which denotes the strength of each corresponding village.
The strength can also be negative, representing those warriors of your kingdom who were held hostages.

There’s also another thing to be noticed.

The strength of any village on row larger than one (2<=r<=N) is stronger or equal to the strength of village which is exactly above it.
The strength of any village on column larger than one (2<=c<=M) is stronger or equal to the strength of vilage which is exactly to its left.
(stronger means having higher value as defined above).
So your task is, find the largest sum of strength that you can erase by bombing one sub-matrix in the grid.

Input format:

First line consists of 2 integers N and M denoting the number of rows and columns in the grid respectively.
The next N lines, consists of M integers each denoting the strength of each cell.

1 <= N <= 1500
1 <= M <= 1500
-200 <= Cell Strength <= 200

Output:
The largest sum of strength that you can get by choosing one sub-matrix.

Example:
Input:
3 3
-5 -4 -1
-3 2 4
2 5 8

Output:
19

Explanation:
Bomb the sub-matrix from (2,2) to (3,3): 2 + 4 + 5 + 8 = 19

Approach: A simple observation is to notice that the strength on each row is larger or equal to the row above and the strength on each column is also 
larger or equal to the column on its left.

This means, we don’t really need to check every single sub-array.

Note: Using Kadane’s 2D Max Sub-Matrix Sum O(N^3) will lead to TLE

Note 2: Maximum answer might be negative. we can assume that the largest sub-array strength may start from any point, but will definitely end on 
bottom-right cell (N,M).

Therefore, we can use dynamic programming to find the sum of sub-matrix starting from the bottom-right cell (N,M) going up and left.

DP[i][j] = DP[i+1][j] + DP[i][j+1] - DP[i+1][j+1]
Find the maximum answer from DP[i][j] for each (i,j)

*/

int Solution::solve(vector<vector<int> > &A) {
    
  int m = A.size(),n = A[0].size(),ans=INT_MIN; 
    
	vector<vector<int>> dp(m+1,vector<int> (n+1,0));// Stores the sums of submatrices starting at the index and ending at last element
	
	for(int i=m-1;i>=0;i--) { // Start iteration at last element and move left and up
		for(int j=n-1;j>=0;j--) { // Sum of sub matrix includes current element
			dp[i][j]=A[i][j];
		    dp[i][j] += dp[i+1][j] + dp[i][j+1] - dp[i+1][j+1]; // ans will be the submatrix having largest sum
			ans = max(ans,dp[i][j]);
		}
	}
	return ans;
}
