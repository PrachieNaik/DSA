/*

Problem statement: Given two strings. The task is to find the length of the longest common substring.

Input: S1 = "ABCDGH", S2 = "ACDGHR"
Output: 4
Explanation: The longest common substring is "CDGH" which has length 4.

Constraints:
1<=n, m<=1000

Approch: Dynamic Programming can be used to find the longest common substring in O(m*n) time. The idea is to find length of the longest common suffix for all substrings of both strings and store these lengths in a table. 

    The longest common suffix has following optimal substructure property.
    
    If last characters match, then we reduce both lengths by 1 
    LCSuff(X, Y, m, n) = LCSuff(X, Y, m-1, n-1) + 1 if X[m-1] = Y[n-1] 
    
    If last characters do not match, then result is 0, i.e., 
    LCSuff(X, Y, m, n) = 0 if (X[m-1] != Y[n-1])
    
    Now we consider suffixes of different substrings ending at different indexes. 
    The maximum length Longest Common Suffix is the longest common substring. 
    LCSubStr(X, Y, m, n) = Max(LCSuff(X, Y, i, j)) where 1 <= i <= m and 1 <= j <= n 

Time Complexity: O(m*n) 
Auxiliary Space: O(m*n)

*/

int longestCommonSubstr (string s1, string s2, int lengthS1, int lengthS2)
{
    int dp[lengthS1 + 1][lengthS2 + 1];
    memset(dp,0,sizeof(dp));
    
    int ans = 0;
    for(int i = 1; i <= lengthS1; i++) {
        for(int j = 1; j <= lengthS2; j++) {
            if(s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                ans = max(ans, dp[i][j]);
            } else {
                dp[i][j] = 0;
            }
        }
    }
    return ans;
}
