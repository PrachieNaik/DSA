/*

Problem statement: Given an array of integers and integer K, each integer in the array represents the cost to reach the corresponding index and K
represents the maximum jump one can take. The goal is to find the minimum cost to reach the last index in the array starting from the beginning.
Input:
  arr = [20, 30, 40, 25, 15, 20, 28], K = 3
Output: 
  73
Explanation:
  Since K = 3, we can start from 30, and then take 3 jumps to 15,     and lastly 28 (30 + 15 + 28). Alternatively, start from 20, take 3 jumps to 25,
  and lastly 28 (20 + 25 + 28). Either way costs $73.
  
Approach: Dynamic programming

Time complexity: O(n*k)
In this bottom-up approach, we start from the first index and store each position's most optimal cost to an array. Each position has k options so in
the inner for loop, the algorithm has to run k times to compare and pick the cheapest. Therefore, the runtime reduces from O(k^n) to O(n*k)

Space Complexity: O(n)
We need an array of size of n to store the results. Therefore, the space complexity becomes O(n).

*/

int Solution::solve(const vector<int> &a,int k) {
    int n = a.size();
    int dp[n];
	for(int i = 0;i < k;i++) {
	    dp[i] = a[i];
	}
	for(int i = k;i < n;i++) {
	    dp[i] = INT_MAX;
	}
	for(int i = 1;i < n;i++) {
	    for(int j = 1;j <= k;j++) {
	        if(i - j > 0) {
	            dp[i] = min(dp[i],dp[i - j] + a[i - j]);
	        }
	    }
	}
	return dp[n - 1];
}
