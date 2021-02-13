/*

Problem statement: Given an array arr[] of length N and an integer X, the task is to find the number of subsets with sum equal to X.

Input: arr[] = {1, 2, 3, 3}, X = 6
Output: 3
All the possible subsets are {1, 2, 3},
{1, 2, 3} and {3, 3}

Keywords: Choice

Approach: Modification to subset sum problem. For subset sum we were storing true or false, for this we have to add the number of subsets.

dp[i][C] = dp[i + 1][C – arr[i]] + dp[i + 1][C]

*/

int countSubsetSum(int set[], int n, int sum)
{
    // The value of subset[i][j] will be true if
    // there is a subset of set[0..j-1] with sum
    // equal to i
    int subset[n + 1][sum + 1];
 
    // If sum is 0, then answer is true
    for (int i = 0; i <= n; i++)
        subset[i][0] = 1;
 
    // If sum is not 0 and set is empty,
    // then answer is false
    for (int i = 1; i <= sum; i++)
        subset[0][i] = 0;
 
    // Fill the subset table in botton up manner
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (j < set[i - 1])
                subset[i][j] = subset[i - 1][j];
            else {
                subset[i][j] = subset[i - 1][j] + subset[i - 1][j - set[i - 1]];
            }
        }
    }
 
    return subset[n][sum];
}
