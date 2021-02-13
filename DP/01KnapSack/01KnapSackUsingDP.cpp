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

    In a DP[][] table let’s consider all the possible weights from ‘1’ to ‘W’ as the columns and weights that can be kept as the rows. 
    The state DP[i][j] will denote maximum value of ‘j-weight’ considering all values from ‘1 to ith’. So if we consider ‘wi’ (weight in ‘ith’ row) we can fill it in all columns which have ‘weight values > wi’. Now two possibilities can take place: 
    
    Fill ‘wi’ in the given column.
    Do not fill ‘wi’ in the given column.
    Now we have to take a maximum of these two possibilities, formally if we do not fill ‘ith’ weight in ‘jth’ column then DP[i][j] state will be same as DP[i-1][j] but if we fill the weight, DP[i][j] will be equal to the value of ‘wi’+ value of the column weighing ‘j-wi’ in the previous row. So we take the maximum of these two possibilities to fill the current state.
    
    Complexity Analysis: 

    Time Complexity: O(N*W). 
    where ‘N’ is the number of weight element and ‘W’ is capacity. As for every weight element we traverse through all weight capacities 1<=w<=W.
    Auxiliary Space: O(N*W). 
    The use of 2-D array of size ‘N*W’.
    
*/

// Returns the maximum value that  
// can be put in a knapsack of capacity W 
int knapSack(int W, int wt[], int val[], int n) 
{
    int i, w;
    int dp[n + 1][W + 1];
 
    for (i = 0; i <= n; i++) 
    {
        for (w = 0; w <= W; w++) 
        {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
                
            else if (wt[i - 1] <= w)
                dp[i][w] = max( val[i - 1]+ dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
                
            else
                dp[i][w] = dp[i - 1][w];
        }
    }
 
    return dp[n][W];
}
