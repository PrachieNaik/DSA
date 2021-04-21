/*

Problem statement: Given an array A[] of size N, find the longest subsequence such that difference between adjacent elements is one.

Example 1:

Input: N = 7
A[] = {10, 9, 4, 5, 4, 8, 6}
Output: 3
Explaination: The three possible subsequences 
{10, 9, 8} , {4, 5, 4} and {4, 5, 6}.

Let arr[0..n-1] be the input array and dp[i] be the length of the longest subsequence (with differences one) ending at index i such that arr[i] is the last element 
of the subsequence.

Then, dp[i] can be recursively written as: dp[i] = 1 + max(dp[j]) where 0 < j < i and [arr[j] = arr[i] -1  or arr[j] = arr[i] + 1] dp[i] = 1, if no such j exists.

To find the result for a given array, we need to return max(dp[i]) where 0 < i < n.

Time Complexity: O(N^2)
Auxiliary Space: O(N)

*/

int longestSubsequence(int N, int A[])
{
    int dp[N];
    for(int i = 0;i < N;i++) {
        dp[i] = 1;
    }
    dp[0] = 1;
    for(int i = 1;i < N;i++) {
        for(int j = i - 1;j >= 0;j--) {
            if(A[j] + 1 == A[i] || A[j] - 1 == A[i]) {
                dp[i] = max(dp[i],dp[j] + 1);
            }
        }
    }
    return *(max_element(dp,dp+N));
}
