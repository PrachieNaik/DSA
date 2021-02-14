/*

Problem statement: Given a value N, find the number of ways to make change for N cents, if we have infinite supply of each of S = { S1, S2, .. , SM } valued coins. 

Input:
m = 4 , n = 3
S[] = {1,2,3}
Output: 4
Explanation: Four Possible ways are:
{1,1,1,1},{1,1,2},{2,2},{1,3}.

Approch: This problem is variation of unbounded knapsack.

*/

long long int count( int coins[], int size, int value )
{
    long long int dp[size + 1][value + 1];
    for(int j = 0; j <= value ;j++) {
        dp[0][j] = 0;
    }
    for(int i = 0; i <= size ;i++) {
         dp[i][0] = 1;
    }
    for(int i = 1; i <= size ;i++) {
        for(int j = 1; j <= value ;j++) {
            if(j - coins[i - 1] >= 0) {
                dp[i][j] = dp[i][j - coins[i - 1]] + dp[i - 1][j];
            }
            else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[size][value];
}
