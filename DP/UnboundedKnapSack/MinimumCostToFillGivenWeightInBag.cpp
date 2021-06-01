/*

Problem statement: You are given a bag of size W kg and you are provided costs of packets different weights of oranges in array cost[] where cost[i] 
is basically the cost of ‘i’ kg packet of oranges. Where cost[i] = -1 means that ‘i’ kg packet of orange is unavailable
Find the minimum total cost to buy exactly W kg oranges and if it is not possible to buy exactly W kg oranges then print -1. It may be assumed that there
is an infinite supply of all available packet types.
Note: array starts from index 1. 

Examples: 

Input  : W = 5, cost[] = {20, 10, 4, 50, 100}
Output : 14
We can choose two oranges to minimize cost. First orange of 2Kg and cost 10. Second orange of 3Kg
and cost 4. 

Approach:
This problem is can be reduced to Unbounded Knapsack. So in the cost array, we first ignore those packets which are not available i.e; cost is -1 and
then traverse the cost array and create two array val[] for storing the cost of ‘i’ kg packet of orange and wt[] for storing weight of the corresponding
packet. Suppose cost[i] = 50 so the weight of the packet will be i and the cost will be 50. 
Algorithm :

Create matrix min_cost[n+1][W+1], where n is number of distinct weighted packets of orange and W is the maximum capacity of the bag.
Initialize the 0th row with INF (infinity) and 0th Column with 0.
Now fill the matrix
if wt[i-1] > j then min_cost[i][j] = min_cost[i-1][j] ;
if wt[i-1] <= j then min_cost[i][j] = min(min_cost[i-1][j], val[i-1] + min_cost[i][j-wt[i-1]]);
If min_cost[n][W]==INF then output will be -1 because this means that we cant not make make weight W by using these weights else output will be min_cost[n][W].

Time Complexity : O(n*w) 
Space complexity : O(n*w) 

Space Optimized Solution If we take a closer look at this problem, we may notice that this is a variation of Rod Cutting Problem. Instead of doing maximization, 
here we need to do minimization.

/* Returns the best obtainable price for
   a rod of length n and price[] as prices
   of different pieces 
int minCost(int cost[], int n)
{
   int dp[n+1];
   dp[0] = 0;
   
   // Build the table val[] in bottom up
   // manner and return the last entry
   // from the table
   for (int i = 1; i<=n; i++)
   {
       int min_cost = INT_MAX;
       for (int j = 0; j < i; j++)
         if(j < n && cost[j]!=-1)
             min_cost = min(min_cost, cost[j] + dp[i-j-1]);
       dp[i] = min_cost;
   }
   
   return dp[n];
}

*/

// cost[] initial cost array including unavailable packet
// W capacity of bag
int MinimumCost(int cost[], int n, int W)
{
    // val[] and wt[] arrays
    // val[] array to store cost of 'i' kg packet of orange
    // wt[] array weight of packet of orange
    vector<int> val, wt;
 
    // traverse the original cost[] array and skip
    // unavailable packets and make val[] and wt[]
    // array. size variable tells the available number
    // of distinct weighted packets
    int size = 0;
    for (int i=0; i<n; i++)
    {
        if (cost[i]!= -1)
        {
            val.push_back(cost[i]);
            wt.push_back(i+1);
            size++;
        }
    }
 
    n = size;
    int min_cost[n+1][W+1];
 
    // fill 0th row with infinity
    for (int i=0; i<=W; i++)
        min_cost[0][i] = INF;
 
    // fill 0'th column with 0
    for (int i=1; i<=n; i++)
        min_cost[i][0] = 0;
 
    // now check for each weight one by one and fill the
    // matrix according to the condition
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=W; j++)
        {
            // wt[i-1]>j means capacity of bag is
            // less then weight of item
            if (wt[i-1] > j)
                min_cost[i][j] = min_cost[i-1][j];
 
            // here we check we get minimum cost either
            // by including it or excluding it
            else
                min_cost[i][j] = min(min_cost[i-1][j],
                     min_cost[i][j-wt[i-1]] + val[i-1]);
        }
    }
 
    // exactly weight W can not be made by given weights
    return (min_cost[n][W]==INF)? -1: min_cost[n][W];
}
