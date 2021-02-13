/*

Problem statement: You are given weights and values of N items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. Note that we have only one quantity of each item. In other words, given two integer arrays val[0..N-1] and wt[0..N-1] which represent values and weights associated with N items respectively. Also given an integer W which represents knapsack capacity, find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W. You cannot break an item, either pick the complete item, or don’t pick it (0-1 property).

Input:
N = 3
W = 4
values[] = {1,2,3}
weight[] = {4,5,1}

Output: 3

Constraints:
1 ≤ N ≤ 1000
1 ≤ W ≤ 1000
1 ≤ wt[i] ≤ 1000
1 ≤ v[i] ≤ 1000

Keywords: Maximum, Choice, Optimize

Approach:

Memoization Technique (an extension of recursive approach): This method is basically an extension to the recursive approach so that we can overcome the problem 
of calculating redundant cases and thus increased complexity. We can solve this problem by simply creating a 2-D array that can store a particular state (n, w)
if we get it the first time. Now if we come across the same state (n, w) again instead of calculating it in exponential complexity we can directly return its 
result stored in the table in constant time. This method gives an edge over the recursive approach in this aspect.
    
    Complexity Analysis: 

    Time Complexity: O(N*W). 
    As redundant calculations of states are avoided.
    Auxiliary Space: O(N*W). 
    The use of 2D array data structure for storing intermediate states
    
*/

static int dp[1001][1001];

int knapSackUtil (int W, int wt[], int val[], int n) {
    
    if(W==0 || n==0)
    return 0;
   
    if(dp[n-1][W] != -1) {
       return dp[n-1][W];
    }
    
    int ans = 0;
    if(wt[n-1] <= W) {
       ans = val[n-1] + knapSackUtil(W - wt[n-1], wt, val, n-1);
    }
    
    dp[n-1][W] = max( ans, knapSackUtil(W, wt, val, n-1) );
    return dp[n-1][W];
}

// Returns the maximum value that  
// can be put in a knapsack of capacity W 
int knapSack(int W, int wt[], int val[], int n) 
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < W + 1; j++)
            dp[i][j] = -1;
            
    return knapSackUtil(W, wt, val, n);
}
