/*

Problem statement: Given a binary matrix mat of size n * m, find out the maximum size square sub-matrix with all 1s.

Example 1:

Input: n = 2, m = 2
mat = {{1, 1}, 
       {1, 1}}
Output: 2
Explaination: The maximum size of the square sub-matrix is 2. The matrix itself is the maximum sized sub-matrix in this case.

Constraints:
1 ≤ n, m ≤ 50
0 ≤ mat[i][j] ≤ 1 

Algorithm:
Let the given binary matrix be M[R][C]. The idea of the algorithm is to construct an auxiliary size matrix S[][] in which each entry S[i][j] represents size of the
square sub-matrix with all 1s including M[i][j] where M[i][j] is the rightmost and bottommost entry in sub-matrix.

1) Construct a sum matrix S[R][C] for the given M[R][C].
     a)    Copy first row and first columns as it is from M[][] to S[][]
     b)    For other entries, use following expressions to construct S[][]
         If M[i][j] is 1 then
            S[i][j] = min(S[i][j-1], S[i-1][j], S[i-1][j-1]) + 1
         Else If M[i][j] is 0
            S[i][j] = 0
2) Find the maximum entry in S[R][C]
3) Using the value and coordinates of maximum entry in S[i], print 
   sub-matrix of M[][]
   
Time Complexity: O(m*n) where m is number of rows and n is number of columns in the given matrix.
Auxiliary Space: O(m*n) where m is number of rows and n is number of columns in the given matrix.

*/

int maxSquare(int n, int m, vector<vector<int>> mat){
    int dp[n][m];
    int ans = 0;
    for(int i = 0;i < n;i++) {
        for(int j = 0; j < m;j++) {
            dp[i][j] = 0;
        }
        
    }
    for(int i = 0;i < n;i++) {
        for(int j = 0; j < m;j++) {
            if(i == 0 || j == 0) {
                dp[i][j] = mat[i][j];
            } else if(mat[i][j] == 1) {
                dp[i][j] = min(dp[i - 1][j],min(dp[i][j - 1],dp[i - 1][j - 1])) + 1;
            }
            ans = max(ans,dp[i][j]);
        }
    }
    return ans;
}
