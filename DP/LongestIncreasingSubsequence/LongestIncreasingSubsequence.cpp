/*

Problem statement: Given an array of integers, find the length of the longest (strictly) increasing subsequence from the given array.

Input:
N = 16
A[]={0,8,4,12,2,10,6,14,1,9,5,13,3,11,7,15}
Output: 6
Explanation:Longest increasing subsequence 0 2 6 9 13 15, which has length 6

Constraints:
1 ≤ N ≤ 10^5
0 ≤ A[i] ≤ 10^6

Keywords: longest

Approach: Dynamic Programming

Time complexity: O(N^2)
Space complexity: O(N)

*/

int longestSubsequence(int n, int a[])
{
    int dp[n];
    dp[0] = 1;
    
    for(int i = 1;i < n;i++) {
        dp[i] = 1;
        for(int j = 0;j < i;j++) {
            if(a[j] < a[i]) {
                dp[i] = max(dp[i],dp[j] + 1);
            }
        }
    }
    return *max_element(dp,dp+n);
}
