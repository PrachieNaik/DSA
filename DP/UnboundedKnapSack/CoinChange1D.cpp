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

long long int count( int S[], int m, int n )
{
    long long table[n+1];         
    // Initialize all table values as 0         
    memset(table, 0, sizeof(table));         
    // Base case (If given value is 0)         
    table[0] = 1;         
    // Pick all coins one by one and update the table[] values         
    // after the index greater than or equal to the value of the         
    // picked coin         
    for(int i=0; i<m; i++) {         
      for(int j=S[i]; j<=n; j++) {        
        table[j] += table[j-S[i]];
      }
    }
    return table[n];  
}
