/*

Problem statement: A frog jumps either 1, 2, or 3 steps to go to the top. In how many ways can it reach the top. As the answer will be large find the answer modulo 
1000000007.

Input:
N = 4
Output: 7
Explanation: Below are the 7 ways to reach 4
1 step + 1 step + 1 step + 1 step
1 step + 2 step + 1 step
2 step + 1 step + 1 step
1 step + 1 step + 2 step
2 step + 2 step
3 step + 1 step
1 step + 3 step

Constraints:
1 ≤ N ≤ 105

Keywords: choose between 3 steps

Approach: Dynamic Programming

Time complexity: O(N)
Space complexity: O(1)

*/

long long countWays(int n){
    long long dp[3];
    dp[0]=1;
    dp[1]=1;
    dp[2]=2;
    
    for (int i=3;i<=n;i++)
        dp[i % 3] = (dp[(i - 1) % 3] + dp[(i - 2) % 3] + dp[(i - 3) % 3])%1000000007;
        
    return dp[n % 3];
}
