/*
Problem statement: Given a value V and array coins[] of size M, the task is to make the change for V cents, given that you have an infinite supply of each
of coins{coins1, coins2, ..., coinsm} valued coins. Find the minimum number of coins to make the change. If not possible to make change then output -1
Input: V = 30, M = 3, coins[] = {25, 10, 5}
Output: 2
Explanation: Use one 25 cent coin
and one 5 cent coin
Approch: This problem is variation of unbounded knapsack.
*/

// m is size of coins array (number of different coins)
int minCoins(int coins[], int m, int V)
{
    // table[i] will be storing the minimum number of coins
    // required for i value.  So table[V] will have result
    int table[V+1];

    // Base case (If given value V is 0)
    table[0] = 0;

    // Initialize all table values as Infinite
    for (int i=1; i<=V; i++)
        table[i] = INT_MAX;

    // Compute minimum coins required for all
    // values from 1 to V
    for (int i=1; i<=V; i++)
    {
        // Go through all coins smaller than i
        for (int j=0; j<m; j++)
          if(i - coins[j] >= 0 && table[i-coins[j]] != INT_MAX) {
              table[i] = min(table[i],table[i-coins[j]] + 1);
          }
    }
  
      if(table[V]==INT_MAX)
        return -1;
  
    return table[V];
}
