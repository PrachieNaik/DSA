/*

Problem statement: Given a number N. Find the minimum number of operations required to reach N starting from 0. You have 2 operations available:

    Double the number
    Add one to the number

Input: N = 8
Output: 4
Explanation: 0 + 1 = 1, 1 + 1 = 2, 2 * 2 = 4, 4 * 2 = 8

Constraints: 1 <= N <= 106

Keywords: Minimum, 2 operations(choice)

Approach: Dynamic Programming

Time complexity: O(N)
Space complexity: O(1)

*/

int minOperation(int n)
{
    int dp[n+1];
    dp[0] = 0;
    
    for(int i = 1;i <= n; i++) {
        if(i % 2 == 0 && i/2 >= 0)
        dp[i] = min(dp[i-1] + 1, dp[i/2] + 1);
        else
        dp[i] = dp[i-1] + 1;
    }
    return dp[n];
}
