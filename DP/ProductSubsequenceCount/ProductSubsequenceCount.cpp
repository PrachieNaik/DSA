/*

Problem statement: Given a non negative array, find the number of subsequences having product smaller than K.

Examples:

Input : [1, 2, 3, 4] 
        k = 10
Output :11 
The subsequences are {1}, {2}, {3}, {4}, {1, 2}, {1, 3}, {1, 4}, {2, 3}, {2, 4}, {1, 2, 3}, {1, 2, 4}

Input  : [4, 8, 7, 2] 
         k = 50
Output : 9

Approach: 
This problem can be solved using dynamic programming where dp[i][j] = number of subsequences having product less than i using first j terms of the array. 
Which can be obtained by : number of subsequences using first j-1 terms + number of subsequences that can be formed using j-th term.

Time Complexity : O(n*k)
Auxiliary Space : O(n*K)

*/

// Function to count numbers of such subsequences
// having product less than k.
int productSubSeqCount(vector<int> &arr, int k)
{
    int n = arr.size();
    int dp[k + 1][n + 1];
    memset(dp, 0, sizeof(dp));
  
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= n; j++) {
     
            // number of subsequence using j-1 terms
            dp[i][j] = dp[i][j - 1];
    
            // if arr[j-1] > i it will surely make product greater
            // thus it won't contribute then
            if (arr[j - 1] <= i && arr[j - 1] > 0)
  
                // number of subsequence using 1 to j-1 terms
                // and j-th term
                dp[i][j] += dp[i/arr[j-1]][j-1] + 1;
        }
    }
    return dp[k][n];
}
