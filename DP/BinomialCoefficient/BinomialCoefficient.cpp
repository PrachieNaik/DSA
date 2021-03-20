/*

Problem statement: Given two integers n and r, find nCr. Since the answer may be very large, calculate the answer modulo 10^9+7.

Input: n = 3, r = 2
Output: 3
Explaination: 3C2 = 3. 

Constraints:
1 ≤ n ≤ 1000
1 ≤ r ≤ 800

Approach: Dynamic Programming

C(n, k) = C(n-1, k-1) + C(n-1, k)
C(n, 0) = C(n, n) = 1

Time Complexity : O(n*r)
Space Complexity : O(r)

*/

int nCr(int n, int r){
    int dp[n + 1][r + 1];
    if(n < r)
    return 0;
  
    for(int i = 0;i <= n;i++) {
       for(int j = 0;j <= r;j++) {
           dp[i][j] = -1;
       }
    }
  
    dp[0][0] = 1;
  
    for(int i = 1;i <= n;i++) {
       for(int j = 0;j <= r;j++) {
           if(i == j || j == 0) {
              dp[i][j] = 1;
           }
           else if(i == 0) {
              dp[i][j] = 0;
           }
           else {
              dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j] ) % 1000000007;
           }
       }
    }
    return dp[n][r];
}
