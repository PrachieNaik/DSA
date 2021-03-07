/*

Problem statement: Given a NxN matrix of positive integers. There are only three possible moves from a cell Matrix[r][c].

    Matrix [r+1] [c]
    Matrix [r+1] [c-1]
    Matrix [r+1] [c+1]
    
    Starting from any column in row 0, return the largest sum of any of the paths up to row N-1.

Input: N = 2 Matrix = {{348, 391},{618, 193}}
Output: 1009
Explaination: The best path is 391 -> 618. It gives the sum = 1009.

Constraints:
1 ≤ N ≤ 100
1 ≤ Matrix[i][j] ≤ 1000

Keywords: largest sum, 3 choices

Approach: Dynamic Programming

Time complexity: O(N^2)
Space complexity: O(N^2)

*/

int maximumPath(int N, vector<vector<int>> Matrix)
{
    int dp[N][N];
    for(int i = 0;i < N ;i++) {
        dp[N - 1][i] = Matrix[N-1][i];
    }
    for(int i = N-2;i >= 0;i--) {
        for(int j = 0;j < N;j++) {
            dp[i][j] = 0;
            if(j - 1 >= 0) {
                dp[i][j] = max(dp[i+1][j-1] + Matrix[i][j], dp[i][j]);
            } 
            if(j + 1 < N) {
                dp[i][j] = max(dp[i+1][j+1] + Matrix[i][j], dp[i][j]);
            }
            dp[i][j] = max(dp[i+1][j] + Matrix[i][j], dp[i][j]);
        }
    }
    int ans = 0;
    for(int i = 0;i < N ;i++) {
        ans = max(dp[0][i], ans);
    }
    return ans;
}
