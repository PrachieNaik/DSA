/*

Problem statement: Given a set of N items, each with a weight and a value, and a weight limit W. Find the maximum value of a collection containing any of 
the N items any number of times so that the total weight is less than or equal to W.

Input: N = 2, W = 3
val[] = {1, 1}
wt[] = {2, 1}
Output: 3
Explaination: Pick the 2nd element thrice.

Constraints:
1 ≤ N, W ≤ 1000
1 ≤ val[i], wt[i] ≤ 100

Approches:

Method 1: We can include as many instances of items as we want. If we decide to not include an element, then we can take it as processed and move ahead. 
So with a little modification to traditional knap sack, this problem can be solved with below equation.

    if(wt[i - 1] <= j) {
        dp[i][j] = val[i-1] + dp[i][j - wt[i - 1]];
        dp[i][j] = max(dp[i][j], dp[i - 1][j]);
    }
    else {
        dp[i][j] = dp[i - 1][j];
    }

Method 2: A simple 1D array, say dp[W+1] can be used such that dp[i] stores the maximum value which can achieved using all items and i capacity of knapsack.
Note that we use 1D array here which is different from classical knapsack where we used 2D array. Here number of items never changes. We always have all 
items available.

    We can recursively compute dp[] using below formula
    
    dp[i] = 0
    dp[i] = max(dp[i], dp[i-wt[j]] + val[j] 
                       where j varies from 0 
                       to n-1 such that:
                       wt[j] <= i
    
    result = d[W]

*/

// Returns the maximum value with knapsack of
// W capacity
int unboundedKnapsack(int W, int n, 
                       int val[], int wt[])
{
    // dp[i] is going to store maximum value
    // with knapsack capacity i.
    int dp[W+1];
    memset(dp, 0, sizeof dp);
 
    // Fill dp[] using above recursive formula
    for (int i=0; i<=W; i++)
      for (int j=0; j<n; j++)
         if (wt[j] <= i)
            dp[i] = max(dp[i], dp[i-wt[j]] + val[j]);
 
    return dp[W];
}
