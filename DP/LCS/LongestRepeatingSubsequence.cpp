/*

Problem statement: Given a string, print the longest repeating subsequence such that the two subsequence don’t have same string character at same position, i.e., 
any i’th character in the two subsequences shouldn’t have the same index in the original string.

Input: str = "aabb"
Output: "ab"

Input: str = "aab"
Output: "a"
The two subsequence are 'a'(first) and 'a' (second). Note that 'b' cannot be considered as part of subsequence as it would be at same index in both.

Approach: This problem is just the modification of Longest Common Subsequence problem. The idea is to find the LCS(str, str) where str is the input string with the 
restriction that when both the characters are same, they shouldn’t be on the same index in the two strings.

*/

int lcs(int x, int y, string s1, string s2){
    
    int dp[x + 1][y + 1];
    for(int i = 0;i <= x; i++) {
        for(int j = 0; j <= y; j++) {
            dp[i][j] = 0;
        }
    }
    for(int i = 1;i <= x; i++) {
        for(int j = 1; j <= y; j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if(s1[i - 1] == s2[j - 1] && i != j) {
                dp[i][j] = max(dp[i - 1][j - 1] + 1, dp[i][j]);
            } 
        }
    }
    return dp[x][y];
}

int LongestRepeatingSubsequence(string str){
    return lcs(str.length(),str.length(),str,str);
}
