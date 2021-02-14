/*

Problem statement: Given a value V and array coins[] of size M, the task is to make the change for V cents, given that you have an infinite supply of each of coins{coins1, coins2, ..., coinsm} valued coins. Find the minimum number of coins to make the change. If not possible to make change then output -1

Input: V = 30, M = 3, coins[] = {25, 10, 5}
Output: 2
Explanation: Use one 25 cent coin
and one 5 cent coin

Approch: This problem is variation of unbounded knapsack.

*/

int minCoins(int coins[], int size, int value) 
{ 
    int dp[size + 1][value + 1];
    for(int i = 0; i <= size; i++) {
        dp[i][0] = 0;
    }
    for(int i = 1; i <= value; i++) {
        dp[0][i] = INT_MAX - 1;
    }
    for(int i = 1; i <= size; i++) {
        for(int j = 1; j <= value; j++) {
            if(j - coins[i-1] >= 0) {
                dp[i][j] = min(1 + dp[i][j - coins[i - 1]], dp[i-1][j]);
            } else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[size][value] >= INT_MAX-1 ? -1: dp[size][value];
} 
	  
