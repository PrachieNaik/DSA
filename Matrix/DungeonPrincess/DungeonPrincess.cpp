/*

Problem statement: The demons had captured the princess (P) and imprisoned her in the bottom-right corner of a dungeon. The dungeon consists of M x N rooms
laid out in a 2D grid. Our valiant knight (K) was initially positioned in the top-left room and must fight his way through the dungeon to rescue the princess.

The knight has an initial health point represented by a positive integer. If at any point his health point drops to 0 or below, he dies immediately.

Some of the rooms are guarded by demons, so the knight loses health (negative integers) upon entering these rooms; other rooms are either empty (0’s) or
contain magic orbs that increase the knight’s health (positive integers).

In order to reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step.

Write a function to determine the knight’s minimum initial health so that he is able to rescue the princess.

*/

int Solution::calculateMinimumHP(vector<vector<int> > &A) {
    int n = A.size();
    if(n == 0)
    return 0;
    int m = A[0].size();
    int dp[n][m];
    for(int i = n - 1;i >= 0;i--) {
        for(int j = m - 1;j >= 0;j--) {
            dp[i][j] = A[i][j];
            if(i < n-1 && j < m -1) {
                dp[i][j] += max(dp[i + 1][j], dp[i][j + 1]);
            }
            else if(i == n - 1 && j != m -1)
            dp[i][j] += dp[i][j + 1];
            else if(j == m - 1 && i != n - 1)
            dp[i][j] += dp[i + 1][j]; 
            
            if(dp[i][j]>0) 
            dp[i][j]=0;         // need to do this since the knight will be traversing from top to down, the cell it will reach in future doesnt add up any
                                // power at the current cell so only negative values are useful here, if dp[i][j] is positive that means that at that cell he
                                // doesnt need any extra energy to move right or down
        }
    }
    return 1 + abs(dp[0][0]); //+ 1 because knight needs 1 energy to start
}
