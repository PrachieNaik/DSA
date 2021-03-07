/*

Problem statement: Given an array arr of N positive integers, the task is to find the maximum sum increasing subsequence of the given array.

Input: N = 5, arr[] = {1, 101, 2, 3, 100} 
Output: 106
Explanation:The maximum sum of a increasing sequence is obtained from {1, 2, 3, 100}


Constraints:
1 ≤ N ≤ 10^3, 1 ≤ arr[i] ≤ 10^5

Keywords: maximum

Approach: Dynamic Programming

Time complexity: O(N^2)
Space complexity: O(N)

*/

int maxSumIS(int arr[], int n)  
{  
    int dp[n];
    dp[0] = arr[0];
    
    for(int i = 1;i < n;i++) {
        dp[i] = arr[i];
        for(int j = 0;j < i; j++) {
            if(arr[j] < arr[i])
                dp[i] = max(dp[i],dp[j] + arr[i]);
        }
    }
    
    return *max_element(dp,dp + n);
}  
