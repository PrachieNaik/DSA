/*

Problem statement: Given a rod of length n inches and an array of prices that contains prices of all pieces of size smaller than n. Determine the maximum value obtainable by cutting up the rod and selling the pieces. For example, if length of the rod is 8 and the values of different pieces are given as following, then the maximum obtainable value is 22 (by cutting in two pieces of lengths 2 and 6) 

length   | 1   2   3   4   5   6   7   8  
--------------------------------------------
price    | 1   5   8   9  10  17  17  20
And if the prices are as following, then the maximum obtainable value is 24 (by cutting in eight pieces of length 1) 

length   | 1   2   3   4   5   6   7   8  
--------------------------------------------
price    | 3   5   8   9  10  17  17  20

Approch: This problem is exactly same as unbounded knapsack.

*/

// Returns the maximum value with rode of
// L length
int knapSack(int N, int L, int price[], int length[])
{
    int dp[N + 1][L + 1];
    for(int i = 0; i <= N ;i++) {
        for(int j = 0; j <= L ;j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            }
            else if(length[i - 1] <= j) {
                dp[i][j] = price[i-1] + dp[i][j - length[i - 1]];
                dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            }
            else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[N][L];
}
